#pragma once
#include "Tile.h"
class Grid
{
private:
    Tile **board;
    
public:
    Grid();
    //constructor used when
    //we want grid to use a different 
    //tile array
    Grid(Tile** &x);

    //used to initialise the tiles with
    //new game settings
    void set_Val();
    void initTiles();

    //for different game modes
    //not used in base game
    void uncoverTiles(int x, int y);
    void boundaryFill8(int x, int y);

    //destructor deletes the board 
    //once game ends
    ~Grid() {
        for (int i = 0; i < 5; i++)
            delete[]board[i];
    }
};

