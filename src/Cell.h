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
  Cell(int i, int j)
      : i(i), j(j), north(nullptr), east(nullptr), south(nullptr), west(nullptr)
  {
  }

  bool operator==(const Cell &other) const;
  bool operator!=(const Cell &other) const;

  int getRow() const { return i; }
  // void setRow(int row) { i = row; }
  int getColumn() const { return j; }
  // void setColumn(int col) { j = col; }
  std::unordered_map<Cell *, bool> &getNeighbors() { return neighbors; }

  Cell &getNorth() { return *north; }
  Cell &getEast() { return *east; }
  Cell &getSouth() { return *south; }
  Cell &getWest() { return *west; }
  void setNorth(Cell *cell) { north = cell; }
  void setEast(Cell *cell) { east = cell; }
  void setSouth(Cell *cell) { south = cell; }
  void setWest(Cell *cell) { west = cell; }

  void link(Cell *cell, bool bidirectional = true);
  void unlink(Cell *cell, bool bidirectional = true);
  bool isLinked(Cell *cell) { return neighbors[cell]; }
};
