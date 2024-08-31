#include "testGrid.h"
#include "../src/Cell.h"
#include "../src/Grid.h"
#include <cassert>
#include <iostream>

#define m 10
#define n 10

void testGrid()
{
  Grid grid = Grid(m, n);

  // Tests cells are initialized with coordinates
  // and cardinal direction cell references are set
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      Cell *cell = grid(i, j);
      assert(cell->getRow() == i && "incorrect row coordinate");
      assert(cell->getColumn() == j && "incorrect col coordinate");

      if (i > 0) {
        assert(cell->getNorth() == *grid(i - 1, j) && "incorrect north cell");
      }
      if (j < n - 1) {
        assert(cell->getEast() == *grid(i, j + 1) && "incorrect east cell");
      }
      if (i < m - 1) {
        assert(cell->getSouth() == *grid(i + 1, j) && "incorrect south cell");
      }
      if (j > 0)
        assert(cell->getWest() == *grid(i, j - 1) && "incorrect west cell");
    }
  }

  for (int i = 0; i < 10000; i++) {
    Cell *cell = grid.getRandCell();
    assert(cell && "getRandCell() returned nullptr");
  }

  // Test memory leak caused by link() of cells
  Cell *cell1 = grid.getRandCell();
  Cell *cell2 = grid.getRandCell();
  cell1->link(cell2);

  // grid.printGrid();

  std::cout << "Grid tests passed" << std::endl;
  return;
}
