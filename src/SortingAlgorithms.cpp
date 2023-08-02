#include "../include/SortingAlgorithms.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/System/Vector3.hpp"
#include <unistd.h>

void SortingAlgorithms::setSortDelay(int &delay)
{
    this->ptrSortingDelay = &delay;
}

void SortingAlgorithms::bubbleSort(std::vector<Bar> &bars, bool& isSorting)
{
    bool swapped;
    int i, j;
    int barSize = bars.size();
    for(std::size_t i = 0; i < barSize; ++i)
    {
        swapped = false;
        for(std::size_t j = 0; j < barSize - 1; ++j)
        {
            if(bars[j].barShape.getSize().y > bars[j+1].barShape.getSize().y)
            {
                bars[j].barShape.setFillColor(sf::Color::Red);
                bars[j+1].barShape.setFillColor(sf::Color::Blue);

                usleep(*this->ptrSortingDelay);

                float tempPositionX = bars[j].barShape.getPosition().x;
                bars[j].barShape.setPosition(sf::Vector2f(bars[j+1].barShape.getPosition().x, 
                            bars[j].barShape.getPosition().y));
                bars[j+1].barShape.setPosition(sf::Vector2f(tempPositionX, bars[j+1].barShape.getPosition().y));
                
                Bar tempBar = bars[j];
                bars[j] = bars[j+1];
                bars[j+1] = tempBar;

                bars[j].barShape.setFillColor(sf::Color::White);
                bars[j+1].barShape.setFillColor(sf::Color::White);

                swapped = true;
            }

        }
        if(!swapped)
        {
            for(auto &bar : bars)
            {
                bar.barShape.setFillColor(sf::Color::Green);
                usleep(800);
            }
            usleep(100);
            for(auto &bar : bars)
            {
                bar.barShape.setFillColor(sf::Color::White);
                usleep(800);
            }

            break;

        }

    }

    isSorting = false;

}

void SortingAlgorithms::insertionSort(std::vector<Bar> &bars,bool& isSorting)
{
    int i, j;
    float tempPositionX;
    int barSize = bars.size();
    for(i = 1; i < barSize; ++i)
    {
        j = i;
        bars[i].barShape.setFillColor(sf::Color::Cyan);
        bars[i].barShape.setFillColor(sf::Color::Cyan);
        while(j > 0 && bars[j-1].height > bars[j].height)
        {
            bars[j].barShape.setFillColor(sf::Color::Red);
            bars[j-1].barShape.setFillColor(sf::Color::Blue);

            usleep(*this->ptrSortingDelay);

            tempPositionX = bars[j].barShape.getPosition().x;
            bars[j].barShape.setPosition(sf::Vector2f(bars[j-1].barShape.getPosition().x, bars[j].barShape.getPosition().y));
            bars[j-1].barShape.setPosition(sf::Vector2f(tempPositionX, bars[j-1].barShape.getPosition().y));

            Bar tempBar = bars[j];
            bars[j] = bars[j-1];
            bars[j-1] = tempBar;

            

            bars[j].barShape.setFillColor(sf::Color::White);
            bars[j-1].barShape.setFillColor(sf::Color::White);
            --j;
            
        }
    }
    for(auto &bar : bars)
    {
        bar.barShape.setFillColor(sf::Color::Green);
        usleep(800);
    }
    usleep(100);
    for(auto &bar : bars)
    {
        bar.barShape.setFillColor(sf::Color::White);
        usleep(800);
    }

    isSorting = false;


    
}

void SortingAlgorithms::selectionSort(std::vector<Bar> &bars,bool& isSorting)
{
    int i, j, minIdx;
    int maxBars = bars.size();
    for(i = 0; i < maxBars; ++i)
    {
        minIdx = i;
        bars[i].barShape.setFillColor(sf::Color::Blue);
        bars[minIdx].barShape.setFillColor(sf::Color::Red);
        for(j = i+1; j < maxBars; ++j)
        {
            bars[j].barShape.setFillColor(sf::Color::Cyan);
            if(bars[j].height < bars[minIdx].height)
            {
                bars[j].barShape.setFillColor(sf::Color::Magenta);
                minIdx = j;
            }
        }

        bars[i].barShape.setFillColor(sf::Color::White);
        bars[minIdx].barShape.setFillColor(sf::Color::White);

        if(minIdx != i)
        {
            bars[minIdx].barShape.setFillColor(sf::Color::Red);
            bars[i].barShape.setFillColor(sf::Color::Blue);

            usleep(*this->ptrSortingDelay);

            float tempPositionX = bars[minIdx].barShape.getPosition().x;
            bars[minIdx].barShape.setPosition(bars[i].barShape.getPosition().x, bars[minIdx].barShape.getPosition().y);
            bars[i].barShape.setPosition(sf::Vector2f(tempPositionX, bars[i].barShape.getPosition().y));

            Bar tempBar = bars[minIdx];
            bars[minIdx] = bars[i];
            bars[i] = tempBar;



            bars[minIdx].barShape.setFillColor(sf::Color::White);
            bars[i].barShape.setFillColor(sf::Color::White);




        }
    }


    for(auto &bar : bars)
    {
        bar.barShape.setFillColor(sf::Color::Green);
        usleep(800);
    }
    usleep(100);
    for(auto &bar : bars)
    {
        bar.barShape.setFillColor(sf::Color::White);
        usleep(800);
    }

    isSorting = false;


}
