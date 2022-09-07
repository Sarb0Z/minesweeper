#pragma once
#include "Grid.h"
#include "initGraphic.h"
class AddGraphic: public Grid, public initGraphic
{
private:
    sf::Sprite sprite;
public:
    AddGraphic();
    void setImg();
};

