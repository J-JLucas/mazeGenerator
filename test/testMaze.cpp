#include "testMaze.h"
#include "../src/Maze.h"
#include <cassert>
#include <iostream>

void testCell()
{
  Cell cell = Cell();
  assert(cell.isVisited() == false);

  std::cout << "Cell tests passed" << std::endl;
  return;
}

void testGrid()
{
  Grid grid = Grid(10, 10);

  assert(grid(0, 0).isVisited() == false);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      assert(grid(i, j).isVisited() == false);
    }
  }
  std::cout << "Grid tests passed" << std::endl;
  return;
}

void testMaze()
{
  testCell();
  testGrid();
  std::cout << "Maze tests passed" << std::endl;
  return;
}
