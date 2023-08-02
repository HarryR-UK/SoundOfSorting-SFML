#include "../include/SortingAlgorithms.h"
#include <unistd.h>

void SortingAlgorithms::bubbleSort(std::vector<Bar> &bars, int sortDelay, bool& isSorting)
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

                usleep(sortDelay);
                /*
                 */
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

void SortingAlgorithms::insertionSort(std::vector<Bar> &bars, int sortDelay,bool& isSorting)
{

}

void SortingAlgorithms::selectionSort(std::vector<Bar> &bars, int sortDelay, bool& isSorting)
{

}
