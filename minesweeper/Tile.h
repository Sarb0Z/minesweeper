#pragma once
#include "initGraphic.h"
class Tile: public initGraphic
{
private:
	int xpos;
	int ypos;
	bool filled = 0;
	int val = 0;
	sf::Sprite sprite;
	bool clicked = 0;
public:
	Tile();
	void fillTile(); //sets bomb in this instance of tile
	void setPos(int x, int y);//used to initialize tile position
	bool isFilled();//checks if tile has a bomb
	void setVal(int v);//how many bombs surround this tile?
	int getVal();//returns value we set above
	void assignImages() override;//assigns graphics
	const sf::Sprite& getSprite() const;//returns graphic
	void updateTile() override;//updates graphic position in window
	bool is_clicked();//if this tile has been clicked
	void click();//clicks tile
};

