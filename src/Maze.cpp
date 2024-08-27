#include "Maze.h"

Cell &Grid::operator()(int row, int column) { return cells[row * n + column]; }
