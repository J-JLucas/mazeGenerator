/* Author: Josh Lucas
 * A Maze is represented by a grid of cells;
 * The Grid class is simply a NxM matrix of Cell objects.
 * The Cell class represents a single cell in a maze.
 */
#pragma once

class Cell {
private:
  bool visited;

public:
  Cell() : visited(false) {}
  bool isVisited() { return visited; }
};

class Grid {
private:
  int m, n;
  Cell *cells;

public:
  // allocate m*n memory for the grid and instantiates each cell
  Grid(int m, int n) : m(m), n(n) { cells = new Cell[m * n]; }
  ~Grid() { delete[] cells; }

  Cell &operator()(int row, int column);
};
