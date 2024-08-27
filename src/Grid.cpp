#include "Grid.h"
#include "Cell.h"

/* Grid */
Grid::~Grid()
{
  for (int i = 0; i < m * n; i++) {
    cells[i].~Cell();
  }
  operator delete[](cells);
}

void Grid::initGrid()
{
  // operator keyword allows for raw memory chunk allocation
  cells = static_cast<Cell *>(operator new[](m * n * sizeof(Cell)));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      Cell *cell = new Cell(i, j);
      cells[i * n + j] = *cell;
    }
  }
}

void Grid::configCells() {}

Cell &Grid::operator()(int row, int column) { return cells[row * n + column]; }
