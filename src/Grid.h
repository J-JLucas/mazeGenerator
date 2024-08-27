/* Author: Josh Lucas
 * A Maze is represented by a grid of cells;
 */
#pragma once

/* The Grid class is simply a NxM matrix of Cell objects */
class Grid {
private:
  int m, n;
  class Cell *cells;

protected:
  void initGrid();
  void configCells();

public:
  // allocate m*n memory for the grid and instantiates each cell
  Grid(int m, int n) : m(m), n(n)
  {
    initGrid();
    configCells();
  }
  ~Grid();

  int getRowLength() { return m; }
  int getColLength() { return n; }

  Cell &operator()(int row, int column);
};
