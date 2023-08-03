#include <cstdlib>
#include<iostream>

#include "../include/Game.h"
#include "SFML/Window/VideoMode.hpp"
sf::RenderWindow IGNORE(sf::VideoMode(1,1), "IGNORE");
int main()
{
    std::srand(static_cast<unsigned>(time(NULL)));

    Game game;
    game.startGLoop();
    return 0;
}
