# C++ Points Deviation Detection

Implements a C++17 `detectDefects()` exercise for detecting point deviations.

The function returns points where `std::abs(point.z - expectedZ) > tolerance`,
preserving their original order. A point exactly at the tolerance is accepted.
Use finite coordinates and a finite, non-negative tolerance, in consistent units.
This example uses metres and compares against a horizontal surface.

## Compile and run on macOS

In Terminal:

```bash
cd /Users/maksimandpreeti/Desktop/Maksim/Robotics-Projects/Cpp-Points-Deviation-Detection
clang++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o inspection
./inspection
```

Expected output:

```text
Defects found: 2
x=2, z=0.18
x=4, z=-0.22
```

If `clang++` is unavailable, install Apple's Command Line Tools with
`xcode-select --install`, then rerun the compile command.

Edit the `points` vector in `main.cpp` to change the sample data. The arguments
`0.0` and `0.10` in `detectDefects(points, 0.0, 0.10)` set the expected surface
height and allowed deviation. Recompile after making changes.

## Vector copy example

`create_copy.cpp` copies a vector, then modifies the copy to demonstrate that
the original points remain unchanged.

```bash
clang++ -std=c++17 -Wall -Wextra -pedantic create_copy.cpp -o create_copy
./create_copy
```

Expected output:

```text
points[1].x: 1
points2[1].x: 12
```
