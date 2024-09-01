#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "imageWrite/stb_image_write.h"

#include "Cell.h"
#include "Grid.h"
#include "RNG.h"
#include <iostream>

/* Grid */
Grid::~Grid()
{
  for (int i = 0; i < m * n; ++i) {
    cells[i].~Cell();
  }
  operator delete[](cells);
}

// Allocate m*n memory for the grid of cells
void Grid::initGrid()
{
  // Operator keyword allows for raw memory chunk allocation
  cells = static_cast<Cell *>(operator new[](m * n * sizeof(Cell)));
}

// Instantiate cell objects and populate the grid
void Grid::initCells()
{
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cells[i * n + j] = Cell(i, j);

      if (i > 0) {
        cells[i * n + j].setNorth(&cells[(i - 1) * n + j]);
      }
      if (j < n - 1) {
        cells[i * n + j].setEast(&cells[(i * n) + j + 1]);
      }
      if (i < m - 1) {
        cells[i * n + j].setSouth(&cells[(i + 1) * n + j]);
      }
      if (j > 0) {
        cells[i * n + j].setWest(&cells[(i * n) + j - 1]);
      }
    }
  }
}

// Access operator for cell object pointer at row, column
Cell *Grid::operator()(int row, int column)
{
  if (row < 0 || row >= m || column < 0 || column >= n) {
    return nullptr;
  }
  return &cells[row * n + column];
}

// Prints the grid to the console
void Grid::printGrid()
{
  const std::string body = "   ";
  const std::string hWall = "---";
  const char vWall = '|', corner = '+';

  // print northern most wall
  std::cout << corner;
  for (int i = 0; i < getColLength(); i++) {
    std::cout << hWall << corner;
  }
  std::cout << "\n";

  // print cell walls
  // for each row, build a 2 strings;
  // 1 for horizontal walls, 1 for vertical walls
  for (int i = 0; i < getRowLength(); i++) {
    std::string top;    // represents the east walls
    std::string bottom; // represents the north walls
    top = top + vWall;
    bottom = bottom + corner;

    // add each cells wall info to the row strings
    for (int j = 0; j < getColLength(); j++) {
      Cell *cell = &cells[i * n + j];
      if (!cell) {
        *cell = Cell(-1, -1);
      }
      top += body;
      top += cell->isLinked(&(cell->getEast())) ? " " : "|";
      bottom += cell->isLinked(&(cell->getSouth())) ? "   " : "---";
      bottom += corner;
    }
    // print the wall row strings
    std::cout << top << "\n" << bottom << std::endl;
  }
}

// Writes a graphical representation of the grid to a file
// Uses stb_image_write.h by https://github.com/nothings/stb
// output a PNG image
void Grid::writeImage()
{
  const int macropixel_size = 32; // Size of each cell
  const int border_size = 1;      // Border ring of 1 macropixel
  const int width =
      (getColLength() + 2 * border_size) * macropixel_size; // Total image width
  const int height = (getRowLength() + 2 * border_size) *
                     macropixel_size; // Total image height
  const int channels = 3;             // RGB channels

  // Create an image buffer
  unsigned char *image = new unsigned char[width * height * channels]();
  std::fill(image, image + width * height * channels, 0); // black fill

  // Iterate over each cell in the grid
  for (int i = 0; i < getRowLength(); i++) {
    for (int j = 0; j < getColLength(); j++) {
      Cell *cell = &cells[i * n + j];
      int base_x = (j + border_size) * macropixel_size;
      int base_y = (i + border_size) * macropixel_size;

      // Draw the south wall if it exists
      if (!cell->isLinked(&(cell->getSouth()))) {
        for (int dx = 0; dx < macropixel_size; ++dx) {
          int pixel_x = base_x + dx;
          int pixel_y =
              base_y + macropixel_size - 1; // Bottom row of the macropixel
          for (int k = 0; k < channels; ++k) {
            image[(pixel_y * width + pixel_x) * channels + k] =
                255; // Set pixel to white
          }
        }
      }

      // Draw the east wall if it exists
      if (!cell->isLinked(&(cell->getEast()))) {
        for (int dy = 0; dy < macropixel_size; ++dy) {
          int pixel_x = base_x + macropixel_size -
                        1; // Rightmost column of the macropixel
          int pixel_y = base_y + dy;
          for (int k = 0; k < channels; ++k) {
            image[(pixel_y * width + pixel_x) * channels + k] =
                255; // Set pixel to white
          }
        }
      }

      // Draw the north wall if we're on the top row
      if (i == 0) {
        for (int dx = 0; dx < macropixel_size; ++dx) {
          int pixel_x = base_x + dx;
          int pixel_y = base_y;
          for (int k = 0; k < channels; ++k) {
            image[(pixel_y * width + pixel_x) * channels + k] =
                255; // Set pixel to white
          }
        }
      }

      // Draw the west wall if we're on the leftmost column
      if (j == 0) {
        for (int dy = 0; dy < macropixel_size; ++dy) {
          int pixel_x = base_x;
          int pixel_y = base_y + dy;
          for (int k = 0; k < channels; ++k) {
            image[(pixel_y * width + pixel_x) * channels + k] =
                255; // Set pixel to white
          }
        }
      }
    }
  }

  // Write the image to a PNG file
  stbi_write_png("maze.png", width, height, channels, image, width * channels);

  delete[] image;
}

void Grid::fillMacropixel(unsigned char *image, int x, int y, int r, int g,
                          int b)
{
  for (int i = 0; i < macropixelSize; i++) {
    for (int j = 0; j < macropixelSize; j++) {
      int index = ((y * macropixelSize + i) * n * macropixelSize +
                   x * macropixelSize + j) *
                  3;
      image[index] = r;
      image[index + 1] = g;
      image[index + 2] = b;
    }
  }
}

// Returns a pointer to a random cell from the grid
Cell *Grid::getRandCell()
{
  int r_i = rngEngine.getRandInt() % m;
  int r_j = rngEngine.getRandInt() % n;
  return &cells[r_i * n + r_j];
}
