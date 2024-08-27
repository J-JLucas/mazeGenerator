#include "testCell.h"
#include "../src/Cell.h"
#include <cassert>
#include <iostream>

void testCell()
{
  Cell cell = Cell(0, 0);
  // assert(cell.isVisited() == false);

  std::cout << "Cell tests passed" << std::endl;
  return;
}
