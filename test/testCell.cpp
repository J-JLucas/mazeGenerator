#include "testCell.h"
#include "../src/Cell.h"
#include <cassert>
#include <iostream>

void testCell()
{
  // Test getRow() and getCol()
  Cell c1 = Cell(2, 4);
  Cell c2 = Cell(1, 4);
  assert(c1.getRow() == 2 && "getRow() should == 2");
  assert(c1.getColumn() == 4 && "getColumn() should == 4");
  assert(c2.getRow() == 1 && "getRow() should == 1");
  assert(c2.getColumn() == 4 && "getColumn() should == 4");

  // test reference is set
  c1.setNorth(&c2);
  c2.setSouth(&c1);

  assert(c1.getNorth() == c2 && "c1's north should be c2");
  assert(c2.getSouth() == c1 && "c2's south should be c1");

  /** Test Neighbor linkage **/

  // Bidirectional link
  c1.link(&c2);
  assert(c1.isLinked(&c2) && "c1 should be linked to c2");
  assert(c2.isLinked(&c1) && "c2 should be linked to c1");

  // Unlink
  c2.unlink(&c1);
  assert(!c1.isLinked(&c2) && "c1 should not be linked to c2");
  assert(!c2.isLinked(&c1) && "c2 should not be linked to c1");

  // Uni-directional link
  c1.link(&c2, false);
  assert(c1.isLinked(&c2) && "c1 should be linked to c2");
  assert(!c2.isLinked(&c1) && "c2 should not be linked to c1");
  c1.unlink(&c2);

  // Test uni-directional unlink
  c1.link(&c2);
  c1.unlink(&c2, false);
  assert(!c1.isLinked(&c2) && "c1 should not be linked to c2");
  assert(c2.isLinked(&c1) && "c2 should be linked to c1");

  std::cout << "Cell tests passed" << std::endl;
  return;
}
