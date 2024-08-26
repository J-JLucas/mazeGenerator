cmake_minimum_required(VERSION 3.22)                            # set CMake mimimum version required
project(a-little-raytracer-of-sunshine VERSION 0.1)             # set project name and version

# test suite target
add_executable(runTests test/testSuite.cpp src/Tuple.cpp src/Matrix.cpp src/Canvas.cpp test/testCanvas.cpp test/testMatrix.cpp test/testTuple.cpp)  # add executable target

# projectile "mini application" target
add_executable(projectile test/projectile.cpp src/Tuple.cpp src/Canvas.cpp)  # add executable target

# clock exercise program target
add_executable(clock test/clock.cpp src/Tuple.cpp src/Canvas src/Matrix)  # add executable target
