#include "Grid.h"
#include <ctime>
#include <cstdlib>

Grid::Grid(){
	board = new Tile*[5];
	for (int i = 0; i < 5; i++) {
		board[i] = new Tile[5];
		for (int j = 0; j < 5; j++) {
			//std::cout << i << j << " ";
			board[i][j].setPos(i, j);
			
		}
		/*std::cout << std::endl;*/
	}
	
}
Grid::Grid(Tile** &x) {
	x = new Tile * [5];

	for (int i = 0; i < 5; i++) {
		x[i] = new Tile[5];

		for (int j = 0; j < 5; j++) {
			/*std::cout << i << j << " ";*/
			x[i][j].setPos(i, j);

		}
		/*std::cout << std::endl;*/
	}
	board = x;

}

void Grid::initTiles() {
	int num, count = 0;
	bool stop_generation = 0;
	/*std::cout << std::endl;*/
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!(i == 0 && j == 0)) {
				num = (unsigned int)rand() % 4;
				if (num == 0 && !stop_generation) {
					board[i][j].fillTile();
					count++;
				}
				if (i == 4 && j == 4 && count == 4) {
					board[i][j].fillTile();
					count++;
				}
				if (i == 4 && j == 3 && count == 3) {
					board[i][j].fillTile();
					board[i][j + 1].fillTile();
					count = 5;
				}
				if (count == 5) {
					stop_generation = 1;
				}
				/*std::cout << board[i][j].isFilled();*/
			}
			/*std::cout << std::endl;*/
		}
	}
			
}
void Grid::set_Val() {
	int value;
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			value = 0;
			if (x != 0) {
				if (board[x - 1][y].isFilled()) {
					value++;
				}
			}
			if (x != 4) {
				if (board[x + 1][y].isFilled()) {
					value++;
				}
			}
			if (y != 0) {
				if (board[x][y - 1].isFilled()) {
					value++;
				}
			}
			if (y != 4) {
				if (board[x][y + 1].isFilled()) {
					value++;
				}
			}
			if (x != 0 && y != 0) {
				if (board[x - 1][y - 1].isFilled()) {
					value++;
				}
			}
			if (x != 0 && y != 4) {
				if (board[x - 1][y + 1].isFilled()) {
					value++;
				}
			}
			if (x != 4 && y != 0) {
				if (board[x + 1][y - 1].isFilled()) {
					value++;
				}
			}
			if (x != 4 && y != 4) {
				if (board[x + 1][y + 1].isFilled()) {
					value++;
				}
			}
			board[x][y].setVal(value);
		}
	}
	
	
}
//unused game mode
void Grid::boundaryFill8(int x, int y)
{

	if (board[x][y].getVal() != 0 && (board[x][y].getVal() == 1 || board[x][y].getVal() == 2 || board[x][y].getVal() == 3 || board[x][y].getVal() == 4 || board[x][y].getVal() == 5))
	{
		board[x][y].click();
		if (x != 4)
			boundaryFill8(x + 1, y);
		if (y != 4)
			boundaryFill8(x, y + 1);
		if (x != 0)
			boundaryFill8(x - 1, y);
		if (y != 0)
			boundaryFill8(x, y - 1);
		if (x != 0 && y != 0)
			boundaryFill8(x - 1, y - 1);
		if (x != 0 && y != 4)
			boundaryFill8(x - 1, y + 1);
		if (x != 4 && y != 0)
			boundaryFill8(x + 1, y - 1);
		if (x != 4 && y != 4)
			boundaryFill8(x + 1, y + 1);
	}
}
void Grid::uncoverTiles(int x, int y) {
	
	if (x != 0) {
		if (!board[x - 1][y].isFilled()) {
			board[x - 1][y].click();
		}
	}
	if (x != 4) {
		if (!board[x + 1][y].isFilled()) {
			board[x + 1][y].click();
		}
	}
	if (y != 0) {
		if (!board[x][y - 1].isFilled()) {
			board[x][y - 1].click();
		}
	}
	if (y != 4) {
		if (!board[x][y + 1].isFilled()) {
			board[x][y + 1].click();
		}
	}
	if (x != 0 && y != 0) {
		if (!board[x - 1][y - 1].isFilled()) {
			board[x - 1][y - 1].click();
		}
	}
	if (x != 0 && y != 4) {
		if (!board[x - 1][y + 1].isFilled()) {
			board[x - 1][y + 1].click();
		}
	}
	if (x != 4 && y != 0) {
		if (!board[x + 1][y - 1].isFilled()) {
			board[x + 1][y - 1].click();
		}
	}
	if (x != 4 && y != 4) {
		if (!board[x + 1][y + 1].isFilled()) {
			board[x + 1][y + 1].click();
		}
	}
}