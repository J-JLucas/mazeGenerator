#include "testBT.h"

#include "../src/BinaryTreeMaze.h"
#include "../src/Grid.h"
#include <iostream>

#define m 10
#define n 20

void testBinaryTreeMaze()
{
  Grid grid(m, n);
  grid.printGrid();
  std::cout << std::endl;
  BinaryTreeMaze::generateMaze(&grid);
  grid.printGrid();
  std::cout << "BinaryTree Maze tests passed" << std::endl;
}
