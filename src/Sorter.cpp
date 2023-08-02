#include "../include/Sorter.h"
#include <sstream>
#include <thread>


#define LOG(x) std::cout << x << '\n';

Sorter::~Sorter()
{

}

Sorter::Sorter()
{
    initText();
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
    m_infoText.setPosition(sf::Vector2f(10,20));
}

void Sorter::updateText()
{
    std::stringstream ss;
    ss << "FPS :" << Time::getFps() << '\n'
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
            if(!m_keyHeld)
            {
                m_keyHeld = true;
                sortBars();
            }

        }
        else
            m_keyHeld = false;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            randomiseBars();

    }



}

void Sorter::randomiseBars()
{

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
            m_sortingThread = std::thread(&SortingAlgorithms::bubbleSort, &m_algorithms, std::ref(m_bars), m_sortDelay, std::ref(m_isSorting));
            break;
        case SortTypes::INSERTION:
            //m_isSorting = true;
            //m_sortingThread = std::thread(&SortingAlgorithms::insertionSort, &m_algorithms, std::ref(m_bars), sortDelay, std::ref(m_isSorting));
            break;
        case SortTypes::SELECTION:
            //m_isSorting = true;
            //m_sortingThread = std::thread(&SortingAlgorithms::selectionSort, &m_algorithms, std::ref(m_bars), sortDelay, std::ref(m_isSorting));
            break;
        default:
            break;
    }

}



void Sorter::setWindow(sf::RenderWindow &window)
{
    m_ptrWindow = &window;
}

Bar& Sorter::addBar(float barHeight)
{
    return m_bars.emplace_back(barHeight);
}

void Sorter::update()
{
    updateText();
    getInput();
    constrainDelay();
    
    if(!m_isSorting && m_sortingThread.joinable())
    {
        joinSortThread();
    }
        

}

void Sorter::constrainDelay()
{
    if(m_sortDelay < 0)
        m_sortDelay = 0;
    if(m_sortDelay > 9999)
        m_sortDelay = 9999;
}

void Sorter::render(sf::RenderTarget &target)
{
    for(auto &bar : m_bars)
    {
        target.draw(bar.barShape);
    }
    
    renderUI(target);


    /*
    */
}

void Sorter::renderUI( sf::RenderTarget& target )
{
    target.draw(m_infoText);
}

void Sorter::joinSortThread()
{
    m_sortingThread.join();
}
