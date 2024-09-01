#include "testGM.h"
#include "../src/Grid.h"
#include "../src/SidewinderMaze.h"
#include <iostream>
#define m 10
#define n 20

void testGraphicMaze()
{
  Grid grid(m, n);
  SidewinderMaze::generateMaze(&grid);
  grid.writeImage();

  std::cout << "testGraphicMaze passed" << std::endl;
}
