#ifndef BAR_H
#define BAR_H
#include "SFML/Graphics/RectangleShape.hpp"
#pragma once

struct Bar{
    Bar(float newHeight);
    float height = 0;
    sf::RectangleShape barShape;
};

#endif // !BAR_H
