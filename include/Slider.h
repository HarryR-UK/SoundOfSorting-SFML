#ifndef SLIDER_H
#define SLIDER_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#pragma once

class Slider
{
    // Attributes
    private:
        sf::RectangleShape m_holder;
        sf::RectangleShape m_bckg;
        int& m_maxDelay;
        int& m_sortDelay;
        float m_percentOfMax = 0.0f;

        sf::Vector2f& m_mousePosView;

        sf::Text m_sliderDelayInfo;
        sf::Font m_font;

    // Methods
    private:
        void initShapes( );
        void initText( );

    // Attributes
    public:

    // Methods
    public:
        Slider( sf::Vector2f ,sf::Vector2f ,sf::Vector2f&, int&, int& );
        bool checkHover( );
        void update( );
        void render( sf::RenderTarget& target );
        sf::Vector2f getBckgSize();
        sf::Vector2f getBckgPos();
        sf::Vector2f getHolderPosition();
        void setHolderPosition(float posX);
        void followMouse( );

};

#endif
