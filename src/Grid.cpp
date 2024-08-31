#include "Grid.h"
#include "Cell.h"
#include "RNG.h"
#include <iostream>

/* Grid */
Grid::~Grid()
{
  for (int i = 0; i < m * n; ++i) {
    cells[i].~Cell();
  }
  operator delete[](cells);
}

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

// Prints the grid to the console
void Grid::printGrid()
{
  const std::string body = "   ";
  const std::string hWall = "---";
  const char vWall = '|', corner = '+';

  // print northern most wall
  std::cout << corner;
  for (int i = 0; i < getColLength(); i++) {
    std::cout << hWall << corner;
  }
  std::cout << "\n";

  // print cell walls
  // for each row, build a 2 strings;
  // 1 for horizontal walls, 1 for vertical walls
  for (int i = 0; i < getRowLength(); i++) {
    std::string top;    // represents the east walls
    std::string bottom; // represents the north walls
    top = top + vWall;
    bottom = bottom + corner;

    // add each cells wall info to the row strings
    for (int j = 0; j < getColLength(); j++) {
      Cell *cell = &cells[i * n + j];
      if (!cell) {
        *cell = Cell(-1, -1);
      }
      top += body;
      top += cell->isLinked(&(cell->getEast())) ? " " : "|";
      bottom += cell->isLinked(&(cell->getSouth())) ? "   " : "---";
      bottom += corner;
    }
    // print the wall row strings
    std::cout << top << "\n" << bottom << std::endl;
  }
}

// Returns a pointer to a random cell from the grid
Cell *Grid::getRandCell()
{
  int r_i = rngEngine.getRandInt() % m;
  int r_j = rngEngine.getRandInt() % n;
  return &cells[r_i * n + r_j];
}
