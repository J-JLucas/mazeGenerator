#include "testSW.h"
#include "../src/Grid.h"
#include "../src/SidewinderMaze.h"
#include <iostream>

void testSidewinderMaze()
{
  Grid grid(4, 4);
  grid.printGrid();
  std::cout << std::endl;
  SidewinderMaze::generateMaze(&grid);
  grid.printGrid();
  std::cout << "Sidewinder Maze tests passed" << std::endl;
}
