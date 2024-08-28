#include "Grid.h"
#include "Cell.h"
#include "RNG.h"
#include <iostream>

/* Grid */
Grid::~Grid() { operator delete[](cells); }

// Allocate m*n memory for the grid of cells
void Grid::initGrid()
{
  // Operator keyword allows for raw memory chunk allocation
  cells = static_cast<Cell *>(operator new[](m * n * sizeof(Cell)));
}

// Instantiate cell objects and populate the grid
void Grid::initCells()
{
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cells[i * n + j] = Cell(i, j);

      if (i > 0) {
        cells[i * n + j].setNorth(&cells[(i - 1) * n + j]);
      }
      if (j < n - 1) {
        cells[i * n + j].setEast(&cells[(i * n) + j + 1]);
      }
      if (i < m - 1) {
        cells[i * n + j].setSouth(&cells[(i + 1) * n + j]);
      }
      if (j > 0) {
        cells[i * n + j].setWest(&cells[(i * n) + j - 1]);
      }
    }
  }
}

// Access operator for cell object pointer at row, column
Cell *Grid::operator()(int row, int column)
{
  if (row < 0 || row >= m || column < 0 || column >= n) {
    return nullptr;
  }
  return &cells[row * n + column];
}

// Returns a pointer to a random cell from the grid
Cell *Grid::getRandCell()
{
  int r_i = rngEngine.getRandInt() % m;
  int r_j = rngEngine.getRandInt() % n;
  std::cout << "Random cell: " << r_i << ", " << r_j << std::endl;
  return &cells[r_i * n + r_j];
}
