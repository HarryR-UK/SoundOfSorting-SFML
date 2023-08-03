#ifndef SORTER_H
#define SORTER_H
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
#include <random>
#include <sstream>
#include <thread>

#include "Bar.h"
#include "SortTypes.h"
#include "SortingAlgorithms.h"
#include "Button.h"
#include "Time.h"
#include "Slider.h"

#include "SFML/System/Vector2.hpp"
#include <vector>
#include <functional>
#include <unistd.h>

#pragma once

class Sorter
{
    private:
        sf::RenderWindow* m_ptrWindow;
        float m_barSize = 5;
        float m_barMaxHeight = 0;
        std::vector<Bar> m_bars;
        std::vector<int> m_barHeights;

        int m_currentSort = SortTypes::BUBBLE;

        bool m_keyHeld = false;
        bool m_mouseHeld = false;

        bool m_isSorting = false;
        bool m_finishSort = false;
        bool m_isGrabbing = false;


        int m_sortDelay = 200;
        int m_maxSortDelay = 9999;

        // UI
        sf::Font m_font;
        sf::Text m_infoText;

        std::thread m_sortingThread;

        
        SortingAlgorithms m_algorithms;
        Slider* m_slider = nullptr;

        std::vector<Button> m_buttons;
        
        sf::Vector2f m_mousePosView;

    private:
        void getInput(  );
        void sortBars( );
        void randomiseBars();
        void constrainDelay();

        void initText();
        void initButtons();


        void updateText();
        void updateButtons();
        void updateMousePos();
        void updateSlider();

        void renderUI( sf::RenderTarget& target );

    public:

    public:
        Sorter();
        ~Sorter();

        Bar& addBar( float barHeight );
        Button& addButton(sf::Vector2f pos, std::string s, sf::Vector2f size, sf::Font& font, sf::Vector2f& mousePos, int type);

        void update(  );
        void render( sf::RenderTarget& target );
        void initBars();
        void joinSortThread();

        void setWindow( sf::RenderWindow& window );
        void setDelay(float delay);

        int& getDelay();
        void initSlider();
};


#endif
