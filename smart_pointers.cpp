#include <iostream>
#include <memory>
#include <vector>

struct PointCloud {
    std::vector<double> points;

    ~PointCloud() {
        std::cout << "Point cloud deleted\n";
    }
};

int main() {
    auto cloud = std::make_shared<PointCloud>();

    // Each component keeps ownership of the same object.
    auto detectorCloud = cloud;
    auto visualizerCloud = cloud;
    std::cout << "detectorCloud" << detectorCloud << " \n";
    std::cout << "visualizerCloud" << visualizerCloud << " \n";

    // A status display wants to observe it without keeping it alive.
    std::weak_ptr<PointCloud> statusCloud = cloud;

    cloud.reset();           // Release the original owner's share.
    detectorCloud.reset();   // Detector finishes.

    // Still alive because the visualizer owns it.
    if (auto temporaryOwner = statusCloud.lock()) {
        std::cout << "Point cloud is still available\n";
    }

    visualizerCloud.reset(); // Last owner releases it: object deleted.

    if (statusCloud.expired()) {
        std::cout << "Point cloud is no longer available\n";
    }
}