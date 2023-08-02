#include "../include/Slider.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"

Slider::Slider( sf::Vector2f pos, sf::Vector2f size, sf::Vector2f& mousePosView, int& maxDelay, int& currentDelay )
    : m_mousePosView(mousePosView)
      ,m_maxDelay(maxDelay)
      , m_sortDelay(currentDelay)
{
    m_bckg.setSize(size);
    m_bckg.setOrigin(sf::Vector2f(size.x * 0.5f, size.y * 0.5f));
    m_bckg.setPosition(pos);
    m_bckg.setFillColor(sf::Color(0, 37, 82));
    m_bckg.setOutlineThickness(2);
    m_bckg.setOutlineColor(sf::Color(0,20,43));
    initShapes();
}

void Slider::initShapes()
{

    m_holder.setFillColor(sf::Color(222,222,222));
    m_holder.setSize(sf::Vector2f(20,30));
    m_holder.setPosition(m_bckg.getPosition());
    m_holder.setOutlineColor(sf::Color::White);
    m_holder.setOutlineThickness(1);
    m_holder.setOrigin(sf::Vector2f(m_holder.getSize().x / 2.f, m_holder.getSize().y / 2.f));
}

void Slider::update()
{
    // LOGIC : size of bck is 100% so is maxDelay
    m_percentOfMax = 
}


bool Slider::checkHover()
{
    if(m_holder.getGlobalBounds().contains(m_mousePosView))
        return true;

    return false;
    
}

void Slider::followMouse()
{
    if(m_holder.getPosition().x > m_bckg.getPosition().x + (m_bckg.getSize().x * 0.5))
    {
        return;
    }
    if(m_holder.getPosition().x < m_bckg.getPosition().x - (m_bckg.getSize().x * 0.5))
    {
        return;
    }
    m_holder.setPosition(sf::Vector2f(m_mousePosView.x, m_holder.getPosition().y));
}

void Slider::render(sf::RenderTarget &target)
{
    target.draw(m_bckg);
    target.draw(m_holder);
}


sf::Vector2f Slider::getBckgSize()
{
    return m_bckg.getSize();
}
sf::Vector2f Slider::getBckgPos()
{
    return m_bckg.getPosition();
}
sf::Vector2f Slider::getHolderPosition()
{
    return m_holder.getPosition();
}

void Slider::setHolderPosition(float posX)
{
    m_holder.setPosition(sf::Vector2f(posX, m_holder.getPosition().y));
}

