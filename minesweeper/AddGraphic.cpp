#include "AddGraphic.h"
#include <iostream>
AddGraphic::AddGraphic() {
	std::cout << "Graphics called\n";

	texture = new sf::Texture[9];
	texture[0].loadFromFile("numbers/0-Number-PNG.png");
	texture[1].loadFromFile("numbers/1-Number-PNG.png");
	texture[2].loadFromFile("numbers/2-Number-PNG.png");
	texture[3].loadFromFile("numbers/3-Number-PNG.png");
	texture[4].loadFromFile("numbers/4-Number-PNG.png");
	texture[5].loadFromFile("numbers/5-Number-PNG.png");
	texture[6].loadFromFile("numbers/6-Number-PNG.png");
	texture[7].loadFromFile("numbers/7-Number-PNG.png");
	texture[8].loadFromFile("numbers/8-Number-PNG.png");
	sprite = new sf::Sprite[9];
	sprite[0].setTexture(texture[0]);
	sprite[1].setTexture(texture[1]);
	sprite[2].setTexture(texture[2]);
	sprite[3].setTexture(texture[3]);
	sprite[4].setTexture(texture[4]);
	sprite[5].setTexture(texture[5]);
	sprite[6].setTexture(texture[6]);
	sprite[7].setTexture(texture[7]);
	sprite[8].setTexture(texture[8]);
}

void AddGraphic::setImg(Tile&x,int val) {
	this->img=sprite[val];
}
sf::Sprite AddGraphic::getSprite(int x, int y)const  {
	return sprite[this->getTile(x, y).getVal()];
}
