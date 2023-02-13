// random maze procedural generator using DFS algie
// based off of material I found here:
// https://en.wikipedia.org/wiki/Maze_generation_algorithm

#include <iostream>

//maze is a mxn grid of cells
#define m 4
#define n 5

class Cell {
	public:
		bool visited;
	Cell(){
		visited = false;
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
