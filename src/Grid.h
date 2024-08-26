/*
 * The Grid class is a matrix of cells that represents a maze.
 *
 */
#pragma once

#include "Cell.h"

class Grid {
private:
  Cell *cells;

public:
  Grid(int m, int n) {}

  //~Grid() {// delete cells}
  Cell &operator()(int row, int column);
};
