#include "SFML/System/Vector2.hpp"
#ifndef GAME_H
#pragma once

#include <iostream>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Sorter.h"

#include "../include/Time.h"

class Game
{
    private:
        sf::RenderWindow* m_window;
        sf::VideoMode m_videoMode;

        sf::Event m_event;
        sf::Cursor m_cursor;


        // Screen Info
        int m_screenWidth;
        int m_screenHeight;

        void initVariables();
        void initWindow();
        void initFont();
        void initText();


        // FONT
        sf::Font m_mainFont;

        // Mouse Pos
        sf::Vector2i m_mousePosScreen;
        sf::Vector2i m_mousePosWindow;
        sf::Vector2f m_mousePosView;


        // Objects
        Sorter m_sorter;
        

    public:
        Game();
        virtual ~Game();

        void startGLoop();

        void update();
        void updateMousePos();

        void pollEvents();
        void getInput();

        void render();


        const bool isRunning() const;

        const int WINDOW_WIDTH;
        const int WINDOW_HEIGHT;

        // Accessors
        sf::RenderWindow* getWindow();


};


#endif
