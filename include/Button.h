#ifndef BUTTON_H
#define BUTTON_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include <string>
#include <iostream>
#pragma once

struct Button
{
    Button( sf::Vector2f pos, std::string s, sf::Vector2f size, sf::Font& font, sf::Vector2f& mousePos, int type);
    sf::Vector2f& mousePosView;
    sf::Text mainText;
    sf::RectangleShape bkgShape;
    sf::Color bkgShapeColor = sf::Color(69,69,69);
    int textCharSize = 20;
    int sortType;

    void update();
    bool checkHover();
    int& activate();
    void setDefault();
};

#endif
