#include "BinaryTree.h"
#include "Grid.h"

// Binary Tree Maze Generation Algie
void BinaryTree::runBinaryTree(Grid *grid)
{
  int m = grid->getRowLength();
  int n = grid->getColLength();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if ((i == 0) && (j == n - 1)) {
        // top right corner, do nothing
      }
      else if (i == 0) {
        // link east; we're along north wall
      }
      else if (j == n - 1) {
        // link north; we're along east wall
      }
      else {
        // random choice
        // int r = rand();
      }
    }
  }
}
