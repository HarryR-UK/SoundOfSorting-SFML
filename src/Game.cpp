#include "../include/Game.h"
#include "SFML/Window/Keyboard.hpp"
#include <vector>

const bool Game::isRunning() const
{
    return m_window->isOpen();
}

Game::~Game()
{
    delete m_window;
}


Game::Game()
    : WINDOW_WIDTH(sf::VideoMode::getDesktopMode().width / 1.2)
      ,WINDOW_HEIGHT(sf::VideoMode::getDesktopMode().height / 1.2)
      , m_sorter()
{
    initVariables();
    initWindow();
    initFont();
    initText();


    m_sorter.setWindow(*m_window);
    m_sorter.initBars();
}


void Game::initVariables()
{
    m_window = nullptr;
    

    m_screenWidth = sf::VideoMode::getDesktopMode().width;
    m_screenHeight = sf::VideoMode::getDesktopMode().height;


}

void Game::initWindow()
{
    m_videoMode.height = WINDOW_HEIGHT;
    m_videoMode.width = WINDOW_WIDTH;

    m_window = new sf::RenderWindow(m_videoMode, "SORTING!", sf::Style::Close | sf::Style::None);
}

void Game::initFont()
{
}

void Game::initText()
{

}


void Game::pollEvents()
{
    while(m_window->pollEvent(m_event))
    {
        switch (m_event.type) {
            case sf::Event::Closed:
                m_window->close();
                break;
            default:
                break;
        }
    }
}


void Game::getInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_sorter.setDelay(10);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    { 
        if(m_sorter.getDelay() > 0)
            m_sorter.setDelay(-10);
    }
}

void Game::updateMousePos()
{
    m_mousePosScreen = sf::Mouse::getPosition();
    m_mousePosWindow = sf::Mouse::getPosition(*m_window);
    m_mousePosView = m_window->mapPixelToCoords(m_mousePosWindow);
    
    

}

void Game::update()
{
    pollEvents();
    getInput();
    updateMousePos();

    // TODO : CHANGE DELAY
    m_sorter.update();
}


void Game::render()
{
    m_window->clear();

    m_sorter.render(*m_window);

    m_window->display();
}

void Game::startGLoop()
{
    while(this->isRunning())
    {
        Time::initDeltaTime();
        Time::updateFps();

        this->update();

        this->render();

    }
}
