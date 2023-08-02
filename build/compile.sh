#!/bin/bash

g++ -std=c++20 ../src/*.cpp -o SoundOfSorting -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-window -lsfml-graphics -lsfml-system -lsfml-network -lsfml-audio

./SoundOfSorting
