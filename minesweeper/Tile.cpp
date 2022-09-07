#include "Tile.h"
Tile::Tile() {
	xpos = 0;
	ypos = 0;
}
void Tile::fillTile() {
	this->filled = 1;
}
void Tile::setPos(int x, int y) {
	this->xpos = x;
	this->ypos = y;
}
bool Tile::isFilled() {
	return filled;
}
void Tile::setVal(int v) {
	this->val = v;
}
int Tile::getVal() {
	return val;
}
void Tile::assignImages()  {
	if (!clicked) {
		sprite.setTexture(this->getDefault()); 
		if (xpos % 2 == 0 && ypos % 2 == 0 || xpos % 2 == 1 && ypos % 2 == 1)
			sprite.setColor(sf::Color(101,67,33));
		else
			sprite.setColor(sf::Color(181, 101, 29));
	}
	if (clicked) {
		if (this->getVal() != 0)
			sprite.setTexture(this->getImg(val));
		if (this->isFilled()) {
			sprite.setTexture(this->getBomb());
		}
		if (xpos % 2 == 0 && ypos % 2 == 0 || xpos % 2 == 1 && ypos % 2 == 1)
			//sprite.setColor(sf::Color::White);
			sprite.setColor(sf::Color(25,25,255));
		else
			//sprite.setColor(sf::Color(144, 238, 144));
			sprite.setColor(sf::Color(68,0,102));
		//color of selected boxes was given by Fatima Zahid
	}
	
}

const sf::Sprite& Tile::getSprite() const  {
	return sprite;
}
void Tile::updateTile()  {
	sprite.setPosition(sf::Vector2f(100.f * xpos, 100.f * ypos));
}
void Tile::click() {
	clicked = 1;
}
bool Tile::is_clicked() {
	return clicked;
}