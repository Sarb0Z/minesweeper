#include "Game.h"
Game::Game() {
	won = 0;
	lost = 0;
}
void Game::endGame(Tile**&board) {
	int count = 0;
	//if tile was clicked and
	//there was a bomb
	//game over you lost
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j].is_clicked()) {
				if (board[i][j].isFilled()) {
					lost = 1;
				}
				else
					count++;
			}
			
		}
	}
	//if 20 tiles have been clicked
	//and no bomb
	//game over you won
	if (count == 20 && !lost) {
		won = 1;
	}
}

void Game::startGame() {
	//renders window
	sf::RenderWindow window(sf::VideoMode(500, 500), "MINESWEEPER");
	//initializes variables used in main game
	Tile** x;
	sf::Event e;
	sf::Font font;
	sf::Text text;
	font.loadFromFile("Debrosee.ttf");
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Black);
	text.setPosition(150.f, 150.f);
	int clickedx;
	int clickedy;

	//we initialize the grid for a new game
	Grid game(x);
	game.initTiles();
	game.set_Val();
	
	//main game loop
	while (window.isOpen()) {

		while (window.pollEvent(e))
		{
			//event window closed
			if (e.type == e.Closed) {
				window.close();
			}
			//event tile clicked
			if (e.type == sf::Event::MouseButtonPressed)
			{
				clickedx = sf::Mouse::getPosition(window).x / 100;
				clickedy = sf::Mouse::getPosition(window).y / 100;
				if (clickedx < 5 && clickedy < 5) {
					x[clickedx][clickedy].click();
					//game.boundaryFill8(clickedx, clickedy);
					//game.boundaryFill8(clickedx,clickedy);
					//game.uncoverTiles(clickedx,clickedy);
				}

			}
			//check if win or lose condition fulfilled
			//if not
			if (!(won || lost)) {

				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						x[i][j].assignImages();
						x[i][j].updateTile();
						//draw the tiles
						window.draw(x[i][j].getSprite());
					}
				}
				//call win or lose checker
				endGame(x);

			}
			//in case of game win or lose
			if (lost) {
				text.setString("YOU LOST");
				window.draw(text);

			}
			if (won) {
				text.setString("YOU WON");
				window.draw(text);
			}
			//refresh window
			
			window.display();
			window.clear(sf::Color(255, 165, 0));
		}
	}
}

