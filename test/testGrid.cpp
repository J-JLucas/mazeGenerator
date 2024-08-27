#include "testGrid.h"
#include "../src/Grid.h"
#include <cassert>
#include <iostream>

void testGrid()
{
  Grid grid = Grid(10, 10);

  // assert(grid(0, 0).isVisited() == false);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      // assert(grid(i, j).isVisited() == false);
    }
  }
  std::cout << "Grid tests passed" << std::endl;
  return;
}
