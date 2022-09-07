#pragma once
#include <SFML/Graphics.hpp>
class initGraphic 
{
private:
	sf::Texture* texture;
public:
	initGraphic();

	//returns textures used in game
	sf::Texture& getImg(int val);
	sf::Texture& getBomb();
	sf::Texture& getDefault();

	//pure virtual functions
	//because we do not yet know what texture each tile 
	//will be assigned
	virtual void assignImages() = 0;
	virtual const sf::Sprite& getSprite() const = 0;
	virtual void updateTile() = 0;
	
};

