/* Author: Josh Lucas
 * A Maze is represented by a grid of cells;
 */
#pragma once

/* The Grid class is simply a NxM matrix of Cell objects */
#include <random>

class Grid {
private:
  int m, n;
  class Cell *cells;
  std::mt19937 rng;
  std::uniform_int_distribution<> r_distrib;
  std::uniform_int_distribution<> c_distrib;

protected:
  void initGrid();
  void initCells();

public:
  Grid(int m, int n)
      : m(m), n(n), rng(std::random_device{}()), r_distrib(0, m - 1),
        c_distrib(0, n - 1)
  {
    initGrid();
    initCells();
  }
  ~Grid();

  Cell &operator()(int row, int column);

  Cell &getRandCell();

  int getRowLength() { return m; }
  int getColLength() { return n; }
};
