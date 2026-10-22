#include <cmath>
#include <iostream>
#include <vector>

struct Point3D {
    double x;
    double y;
    double z;
};

int main() {
    std::vector<Point3D> points = {
        {0.0, 0.0,  0.01},
        {1.0, 0.0, -0.03},
        {2.0, 0.0,  0.18},
        {3.0, 0.0,  0.02},
        {4.0, 0.0, -0.22}
    };

    std::vector<Point3D> points2 = points;
    points2[1].x = 12.0;
    std::cout << "points[1].x: " << points[1].x << "\n";
    std::cout << "points2[1].x: " << points2[1].x << "\n";

    return 0;
}
