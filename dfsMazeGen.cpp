// random maze procedural generator using DFS algie
// based off of material I found here:
// https://en.wikipedia.org/wiki/Maze_generation_algorithm

#include <iostream>
#include <vector>

//maze is a mxn grid of cells
#define m 5
#define n 5

class Cell {
    public:
	std::vector<int> location;  // 2D coordinates
        bool visited {false};

	//neighbors
	bool northLink {false};
	bool eastLink {false};
	bool southLink {false};
	bool westLink {false};
	
	Cell()
	{

	}

	bool getStatus() {
		return visited;
	}

	bool setStatus(bool b){
		return visited = b;
	}
};


int main(int argc, char *argv[]){
	Cell maze[m][n];
	Cell cell;
	cell.setStatus(true);
	std::cout << cell.getStatus() << std::endl;
	return 0;
}
