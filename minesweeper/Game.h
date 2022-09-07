#pragma once
#include "Grid.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Game :
    public Grid
{
private:
    bool won;
    bool lost;
public:
    Game();
    //our main game loop
    void startGame();

    //checks for game ending conditions
    void endGame(Tile**& board);  
};

