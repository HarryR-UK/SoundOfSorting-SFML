#include "../include/Button.h"
#include "SFML/System/Vector2.hpp"

Button::Button( sf::Vector2f pos, std::string s, sf::Vector2f size, sf::Font& font, sf::Vector2f& mousePos, int type)
    : mousePosView(mousePos)
      , sortType(type)
{
    bkgShape.setFillColor(bkgShapeColor);
    bkgShape.setPosition(pos);
    bkgShape.setSize(size);
    bkgShape.setOutlineThickness(1);
    bkgShape.setOutlineColor(sf::Color::White);
    bkgShape.setOrigin(bkgShape.getSize().x / 2.f, bkgShape.getSize().y / 2.f);

    mainText.setFillColor(sf::Color::White);
    mainText.setCharacterSize(textCharSize);
    mainText.setFont(font);
    mainText.setString(s);
    mainText.setOrigin(sf::Vector2f(mainText.getGlobalBounds().width / 2.f, mainText.getGlobalBounds().height / 1.2f));
    mainText.setPosition(bkgShape.getPosition());
}

void Button::update()
{
}

bool Button::checkHover()
{
    if(bkgShape.getGlobalBounds().contains(mousePosView))
    {
        return true;
    }
    
    return false;
}

int& Button::activate()
{
    bkgShape.setFillColor(sf::Color(201,201,201));
    mainText.setFillColor(sf::Color::Black);
    return this->sortType;
}

void Button::setDefault()
{
    bkgShape.setFillColor(bkgShapeColor);
    mainText.setFillColor(sf::Color::White);
}
