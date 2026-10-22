#include <cmath>
#include <iostream>
#include <vector>

struct Point3D {
    double x;
    double y;
    double z;
};

// Return points whose distance from the expected horizontal surface exceeds
// tolerance. Coordinates and tolerance use the same units (metres here).
std::vector<Point3D> detectDefects(
    const std::vector<Point3D>& points,
    double expectedZ,
    double tolerance)
{
    std::vector<Point3D> defects;

    for (const auto& point : points) {
        const double deviation = std::abs(point.z - expectedZ);
        if (deviation > tolerance) {
            defects.push_back(point);
        }
    }

    return defects;
}

int main() {
    const std::vector<Point3D> points = {
        {0.0, 0.0,  0.01},
        {1.0, 0.0, -0.03},
        {2.0, 0.0,  0.18},
        {3.0, 0.0,  0.02},
        {4.0, 0.0, -0.22}
    };

    const auto defects = detectDefects(points, 0.0, 0.10);

    std::cout << "Defects found: " << defects.size() << "\n";

    for (const auto& p : defects) {
        std::cout << "x=" << p.x << ", z=" << p.z << "\n";
    }

    return 0;
}
