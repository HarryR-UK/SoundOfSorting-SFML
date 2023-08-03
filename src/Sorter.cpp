#include "../include/Sorter.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include <algorithm>
#include <sstream>
#include <thread>


#define LOG(x) std::cout << x << '\n';

Sorter::~Sorter()
{
    if(m_slider != nullptr)
        delete m_slider;
}

Sorter::Sorter()
{
    initText();
    initButtons();
    m_algorithms.setSortDelay(m_sortDelay);
    
}


void Sorter::initText()
{
    if(!m_font.loadFromFile("../res/fonts/open-sans/OpenSans-Semibold.ttf"))
    {
        LOG("[ERROR]: CANNOT LOAD FILE (SORTER CLASS)");
    }

    m_infoText.setString("NULL");
    m_infoText.setFont(m_font);
    m_infoText.setCharacterSize(20);
    m_infoText.setFillColor(sf::Color::White);
    m_infoText.setPosition(sf::Vector2f(30,100));
}

void Sorter::initButtons()
{
    Button& bubbleButton = addButton(sf::Vector2f(75,50), "BUBBLE", sf::Vector2f(100,40), m_font, m_mousePosView, SortTypes::BUBBLE);
    Button& insertionButton = addButton(sf::Vector2f(210,50), "INSERTION", sf::Vector2f(150,40), m_font, m_mousePosView, SortTypes::INSERTION);
    Button& selectionSort = addButton(sf::Vector2f(370,50), "SELECTION", sf::Vector2f(150,40), m_font, m_mousePosView, SortTypes::SELECTION);
}

void Sorter::initSlider()
{
    sf::Vector2f size{700, 10};
    sf::Vector2f pos{m_ptrWindow->getSize().x - (size.x * 0.5f) - 50, 30};
    m_slider = new Slider(pos, size, m_mousePosView, m_maxSortDelay, m_sortDelay);
}
void Sorter::updateText()
{
    std::stringstream ss;
    std::string sortType_S;
    switch(m_currentSort)
    {
        case SortTypes::BUBBLE:
            sortType_S = "BUBBLE";
            break;
        case SortTypes::INSERTION:
            sortType_S = "INSERTION";
            break;
        case SortTypes::SELECTION:
            sortType_S = "SELECTION";
            break;
        default:
            sortType_S = "";
            break;
    }
     ss << "CURRENT TYPE: " << sortType_S << '\n'
        ;
    m_infoText.setString(ss.str());
}



void Sorter::initBars()
{
    randomiseBars();
    
}




void Sorter::getInput(  )
{
    if(!m_isSorting)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            if(!m_keyHeld)
            {
                m_keyHeld = true;
                m_currentSort = SortTypes::BUBBLE;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            if(!m_keyHeld)
            {
                m_keyHeld = true;
                m_currentSort = SortTypes::INSERTION;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            if(!m_keyHeld)
            {
                m_keyHeld = true;
                m_currentSort = SortTypes::SELECTION;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if(!m_keyHeld && !m_finishSort)
            {
                m_keyHeld = true;
                sortBars();
            }

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            if(!m_keyHeld)
            {
                m_keyHeld = true;
                randomiseBars();
            }

        }
        else
            m_keyHeld = false;


    }



}

void Sorter::randomiseBars()
{
    m_finishSort = false;
    // initbars
    m_bars.clear();
    m_barHeights.clear();
    int maxNumberofBars = 200;
    m_barSize = (float) m_ptrWindow->getSize().x / maxNumberofBars;
    int outlineThic = 1;
    m_barMaxHeight = m_ptrWindow->getSize().y - 200;

    //SORTED
    for(std::size_t i = 0; i < maxNumberofBars; ++i)
    {
        int barHeight = i * m_barMaxHeight / maxNumberofBars;
        m_barHeights.push_back(barHeight);
    }

    // generates a random number
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_barHeights.begin(), m_barHeights.end(), g);

    //randomise 
    for(std::size_t j = 0; j < m_barHeights.size(); ++j)
    {
        int ranHeight = m_barHeights[j];

        if(m_barHeights[j] != -1)
        {
            Bar& bar = addBar(ranHeight);
            bar.barShape.setOutlineColor(sf::Color::Black);
            bar.barShape.setOutlineThickness(outlineThic);
            bar.barShape.setSize(sf::Vector2f(m_barSize - outlineThic, bar.height - outlineThic));
            bar.barShape.setPosition(sf::Vector2f(j*m_barSize, m_ptrWindow->getSize().y - bar.height));
            bar.barShape.setFillColor(sf::Color::White);


        }

        for(int x = 0; x < m_barHeights.size(); ++x)
        {
            if(m_barHeights[x] == ranHeight)
            {
                m_barHeights[x] = -1;
            }
        }
    }
}




void Sorter::sortBars() {
    switch (m_currentSort) {
        case SortTypes::BUBBLE:
            m_isSorting = true;
            m_sortingThread = std::thread(&SortingAlgorithms::bubbleSort, &m_algorithms, std::ref(m_bars), std::ref(m_isSorting));
            break;
        case SortTypes::INSERTION:
            m_isSorting = true;
            m_sortingThread = std::thread(&SortingAlgorithms::insertionSort, &m_algorithms, std::ref(m_bars), std::ref(m_isSorting));
            break;
        case SortTypes::SELECTION:
            m_isSorting = true;
            m_sortingThread = std::thread(&SortingAlgorithms::selectionSort, &m_algorithms, std::ref(m_bars), std::ref(m_isSorting));
            break;
        default:
            break;
    }

}



void Sorter::setWindow(sf::RenderWindow &window)
{
    m_ptrWindow = &window;
}

void Sorter::setDelay(float delay)
{
    //if(!m_isSorting)
        m_sortDelay += delay;
}


int& Sorter::getDelay()
{
    return m_sortDelay;
}

Bar& Sorter::addBar(float barHeight)
{
    return m_bars.emplace_back(barHeight);
}

Button& Sorter::addButton(sf::Vector2f pos, std::string s, sf::Vector2f size, sf::Font &font, sf::Vector2f& mousePos, int type)
{
    return m_buttons.emplace_back(pos, s, size, font, mousePos, type);
}

void Sorter::update()
{
    constrainDelay();

    getInput();
    updateMousePos();

    updateText();

    updateButtons();

    updateSlider();
    
    if(!m_isSorting && m_sortingThread.joinable())
    {
        joinSortThread();
    }

        

}

void Sorter::updateSlider()
{
    m_slider->update();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(m_slider->checkHover())
        {
            m_isGrabbing = true;
        }
    }
    else {
        m_isGrabbing = false;
    }

    if(m_isGrabbing)
    {
        m_slider->followMouse();
    }

    if(m_slider->getHolderPosition().x > m_slider->getBckgPos().x + (m_slider->getBckgSize().x * 0.5f))
    {
        m_slider->setHolderPosition(m_slider->getBckgPos().x + (m_slider->getBckgSize().x * 0.5f));
    }
    else if(m_slider->getHolderPosition().x < m_slider->getBckgPos().x - (m_slider->getBckgSize().x * 0.5f))
    {
        m_slider->setHolderPosition(m_slider->getBckgPos().x - (m_slider->getBckgSize().x * 0.5f));
    }
}

void Sorter::updateMousePos()
{
    m_mousePosView = m_ptrWindow->mapPixelToCoords(sf::Mouse::getPosition(*m_ptrWindow));
}

void Sorter::updateButtons()
{
    for(auto &button : m_buttons)
    {
        button.update();
        if(button.checkHover() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_currentSort = button.activate();
        }
        else{
            button.setDefault();
        }
    }
}

void Sorter::constrainDelay()
{
    if(m_sortDelay < 75)
        m_sortDelay = 75;
    if(m_sortDelay > m_maxSortDelay)
        m_sortDelay = m_maxSortDelay;
}

void Sorter::render(sf::RenderTarget &target)
{
    for(auto &bar : m_bars)
    {
        target.draw(bar.barShape);
    }
    
    renderUI(target);
    m_slider->render(*m_ptrWindow);


    /*
    */
}

void Sorter::renderUI( sf::RenderTarget& target )
{
    target.draw(m_infoText);
    for(auto &button : m_buttons)
    {
        target.draw(button.bkgShape);
        target.draw(button.mainText);
    }

}

void Sorter::joinSortThread()
{
    m_sortingThread.join();
    m_finishSort = true;
}
