#include "BinaryTreeMaze.h"
#include "Cell.h"
#include "Grid.h"
#include "RNG.h"
#include <iostream>

// Binary Tree Maze Generation Algie
void BinaryTreeMaze::generateMaze(Grid *grid)
{
  int m = grid->getRowLength();
  int n = grid->getColLength();

  RNG rngEngine(1337);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if ((i == 0) && (j == n - 1)) {
        // top right corner, do nothing
        continue;
      }
      else if (i == 0) {
        // link east; we're along north wall
        grid->operator()(i, j)->link(grid->operator()(i, j + 1));
        //        std::cout << "Linking cell at (" << i << ", " << j << ") EAST"
        //                  << std::endl;
      }
      else if (j == n - 1) {
        // link north; we're along east wall
        grid->operator()(i, j)->link(grid->operator()(i - 1, j));
        //        std::cout << "Linking cell at (" << i << ", " << j << ")
        //        NORTH"
        //                  << std::endl;
      }
      else {
        // random choice between north and east
        int r = rngEngine.getRandInt() % 2;
        if (r) {
          grid->operator()(i, j)->link(grid->operator()(i - 1, j));
          //          std::cout << "Linking cell at (" << i << ", " << j << ")
          //          NORTH"
          //                    << std::endl;
        }
        else {
          grid->operator()(i, j)->link(grid->operator()(i, j + 1));
          //          std::cout << "Linking cell at (" << i << ", " << j << ")
          //          EAST"
          //                    << std::endl;
        }
      }
    }
  }
}
