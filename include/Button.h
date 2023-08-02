#ifndef BUTTON_H
#define BUTTON_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include <string>
#pragma once

struct Button
{
    Button(sf::RenderWindow& window, sf::Vector2f pos, std::string s, sf::Font& font);
    std::string content;
    sf::Vector2f position;
    sf::Text mainText;
    sf::RectangleShape bkgShape;
    sf::Color bkgShapeColor = sf::Color(69,69,69);
};

#endif
