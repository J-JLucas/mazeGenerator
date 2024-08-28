#include "testGrid.h"
#include "../src/Cell.h"
#include "../src/Grid.h"
#include <cassert>
#include <iostream>

void testGrid()
{
  Grid grid = Grid(10, 10);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      // do something
    }
  }

  Cell *cell = grid.getRandCell();
  assert(cell && "getRandCell() returned nullptr");

  std::cout << "Grid tests passed" << std::endl;
  return;
}
