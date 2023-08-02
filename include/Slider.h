#ifndef SLIDER_H
#define SLIDER_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
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

    // Methods
    private:
        void initShapes( );

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
