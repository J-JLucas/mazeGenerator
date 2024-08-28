#include "Cell.h"

/* Cell */

void Cell::link(Cell *cell, bool bidirectional)
{
  neighbors[cell] = true;
  if (bidirectional) {
    // link other cell to this
    cell->neighbors[this] = true;
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
