cmake_minimum_required(VERSION 3.22)                            # set CMake mimimum version required
project(mazeGenerator VERSION 0.1)                              # set project name and version

# test suite target
add_executable(runTests test/testSuite.cpp src/Cell.cpp src/Grid.cpp src/RNG.h src/BinaryTreeMaze.cpp src/SidewinderMaze.cpp test/testCell.cpp test/testGrid.cpp test/testBT.cpp test/testSW.cpp)  # add executable target

# clock exercise program target
#add_executable(clock test/clock.cpp src/Tuple.cpp src/Canvas src/Matrix)  # add executable target
