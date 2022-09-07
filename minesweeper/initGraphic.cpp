#include "initGraphic.h"
initGraphic::initGraphic() {
	texture = new sf::Texture[11];
	texture[0].loadFromFile("numbers/0-Number-PNG.png");
	texture[1].loadFromFile("numbers/1-Number-PNG.png");
	texture[2].loadFromFile("numbers/2-Number-PNG.png");
	texture[3].loadFromFile("numbers/3-Number-PNG.png");
	texture[4].loadFromFile("numbers/4-Number-PNG.png");
	texture[5].loadFromFile("numbers/5-Number-PNG.png");
	texture[6].loadFromFile("numbers/6-Number-PNG.png");
	texture[7].loadFromFile("numbers/7-Number-PNG.png");
	texture[8].loadFromFile("numbers/8-Number-PNG.png");
	texture[9].loadFromFile("download.jpg");
	texture[10].loadFromFile("white.png");
	
}
sf::Texture 
&initGraphic::getImg(int val) {
	return texture
		[val];
}
sf::Texture
&initGraphic::getBomb() {
	return texture
		[9];
}
sf::Texture 
& initGraphic::getDefault() {
	return texture
		[10];
}