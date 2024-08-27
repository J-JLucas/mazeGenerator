/* Author: Josh Lucas
 * A Maze is represented by a grid of cells;
 */
#pragma once

#include <unordered_map>

/* The Cell class represents a single cell in a maze */
class Cell {
private:
  int i, j;                                   // coordinates of the cell
  std::unordered_map<Cell *, bool> neighbors; // a map of the cell's neighbors
  Cell *north;
  Cell *east;
  Cell *south;
  Cell *west;

public:
  Cell(int i, int j) {}

  int getRow() { return i; }
  void setRow(int row) { i = row; }
  int getColumn() { return j; }
  void setColumn(int col) { j = col; }
  std::unordered_map<Cell *, bool> &getNeighbors() { return neighbors; }

  Cell &getNorth();
  Cell &getEast();
  Cell &getSouth();
  Cell &getWest();
  void setNorth(Cell *cell);
  void setEast(Cell *cell);
  void setSouth(Cell *cell);
  void setWest(Cell *cell);

  void link(Cell *cell, bool bidirectional = true);
  void unlink(Cell *cell, bool bidirectional = true);
  bool isLinked(Cell *cell) { return neighbors[cell]; }
};
