#include "SidewinderMaze.h"
#include "Cell.h"
#include "Grid.h"
#include "RNG.h"
#include <vector>
// #include <iostream>

/* Sidewinder Maze Generation Algie
 * As the Sidewinder Algie moves through the grid,
 * for each row, we maintain a "cluster" of cells.
 * for each cell, we add the cell to the cluster and "flip a coin",
 * if tails we link the cell east and continue
 * if heads we choose a random cell from the cluster and link it to it's
 * northern neighbor, then clear the cluster and continue
 */

void SidewinderMaze::generateMaze(Grid *grid)
{
  int m = grid->getRowLength();
  int n = grid->getColLength();

  RNG rngEngine(1337);

  for (int i = 0; i < m; i++) {
    std::vector<Cell *> cluster;

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
      else {
        // add cell to cluster
        cluster.push_back(grid->operator()(i, j));

        // flip coin
        int r = rngEngine.getRandInt() % 2;

        if (r || (j == n - 1)) {
          // heads or are at the east wall and must go north
          int random = rngEngine.getRandInt() % cluster.size();
          int row = cluster[random]->getRow();
          int col = cluster[random]->getColumn();
          cluster[random]->link(grid->operator()(
              row - 1, col)); // link random cell to it's northern neighbor
          cluster.clear();
          //          std::cout << "Linking cell at (" << i << ", " << j << ")
          //          NORTH"
          //                    << std::endl;
        }
        else {
          // tails
          grid->operator()(i, j)->link(grid->operator()(i, j + 1));
          //          std::cout << "Linking cell at (" << i << ", " << j << ")
          //          EAST"
          //                    << std::endl;
        }
      }
    }
  }
}
