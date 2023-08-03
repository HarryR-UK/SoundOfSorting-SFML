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
    m_bckg.setFillColor(sf::Color(110, 165, 255));
    m_bckg.setOutlineThickness(2);
    m_bckg.setOutlineColor(sf::Color::White);
    initShapes();
    initText();
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

void Slider::initText()
{
    // DO
    if(!m_font.loadFromFile("../res/fonts/open-sans/OpenSans-Semibold.ttf"))
    {
        std::cout << "ERROR LOADING FONT SLIDER CLASS" << '\n';
    }
    m_sliderDelayInfo.setFillColor(sf::Color::White);
    m_sliderDelayInfo.setCharacterSize(20);
    m_sliderDelayInfo.setFont(m_font);
    m_sliderDelayInfo.setString("DELAY: ");
    m_sliderDelayInfo.setOrigin(m_sliderDelayInfo.getGlobalBounds().width * 0.5f, m_sliderDelayInfo.getGlobalBounds().height * 0.5f);
    m_sliderDelayInfo.setPosition(sf::Vector2f(m_bckg.getPosition().x - 30, m_bckg.getPosition().y + 30));
}

void Slider::update()
{

    float backgroundWidth = m_bckg.getSize().x;

    float backgroundPositionX = m_bckg.getPosition().x;

    float holderPosX = m_holder.getPosition().x;

    float percentageOfSize = (holderPosX - (backgroundPositionX - backgroundWidth * 0.5f)) / backgroundWidth;

    percentageOfSize = std::max(0.f, std::min(percentageOfSize, 1.0f));

    float perOne = m_maxDelay / backgroundWidth;
    m_sortDelay = percentageOfSize * m_maxDelay;
    m_sortDelay = std::max<float>(m_sortDelay, 75.f);


    std::stringstream ss;
    ss << "DELAY :" << m_sortDelay << '\n';
    m_sliderDelayInfo.setString(ss.str());
    


    

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
    target.draw(m_sliderDelayInfo);
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

