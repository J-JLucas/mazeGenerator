/* Author: Josh Lucas
 * A Maze is represented by a grid of cells;
 */
#pragma once

/* The Grid class is simply a NxM matrix of Cell objects */
#include "RNG.h"
#include <random>

class Grid {
private:
  int m, n;
  class Cell *cells;
  RNG rngEngine;
  int macropixelSize =
      16; // square size of each macropixel for graphical output
  void fillMacropixel(unsigned char *image, int x, int y, int r, int g, int b);

protected:
  void initGrid();
  void initCells();

public:
  Grid(int m, int n) : m(m), n(n), rngEngine(n * m)
  {
    initGrid();
    initCells();
  }
  ~Grid();

  Cell *operator()(int row, int column);
  void printGrid();
  void writeImage();
  Cell *getRandCell();
  int getRowLength() { return m; }
  int getColLength() { return n; }
};
