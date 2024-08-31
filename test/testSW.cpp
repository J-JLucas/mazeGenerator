#include "testSW.h"
#include "../src/Grid.h"
#include "../src/SidewinderMaze.h"
#include <iostream>

#define m 10
#define n 20

void testSidewinderMaze()
{
  Grid grid(m, n);
  grid.printGrid();
  std::cout << std::endl;
  SidewinderMaze::generateMaze(&grid);
  grid.printGrid();
  std::cout << "Sidewinder Maze tests passed" << std::endl;
}
