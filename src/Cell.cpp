#include "Cell.h"

/* Cell */

bool Cell::operator==(const Cell &other) const
{
  return i == other.i && j == other.j;
}

bool Cell::operator!=(const Cell &other) const { return !(*this == other); }

void Cell::link(Cell *cell, bool bidirectional)
{
  // neighbors[cell] = true;
  auto it = neighbors.find(cell);
  if (it == neighbors.end()) {
    neighbors[cell] = true;
  }
  else {
    it->second = true;
  }

  if (bidirectional) {
    // link other cell to this
    cell->link(this, false);
  }
}

void Cell::unlink(Cell *cell, bool bidirectional)
{
  neighbors[cell] = false;
  if (bidirectional) {
    // unlink other cell from this
    cell->neighbors[this] = false;
  }
}

bool Cell::isLinked(Cell *cell)
{
  if (!cell) {
    return false; // Handle null pointers safely
  }
  auto it =
      neighbors.find(cell); // Use find() to check if the cell exists in the map
  return it != neighbors.end() &&
         it->second; // Return true if the cell is found and linked
}
