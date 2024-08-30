#include "testBT.h"

#include "../src/BinaryTreeMaze.h"
#include "../src/Grid.h"
#include <iostream>

void testBinaryTreeMaze()
{
  Grid grid(4, 4);
  BinaryTreeMaze::generateMaze(&grid);
  grid.printGrid();
  std::cout << "BinaryTree Maze tests passed" << std::endl;
}
