#ifndef TIME_H
#pragma once

#include <SFML/System/Clock.hpp>
#include "../include/Time.h"
#include "Global.h"

class Time{
    public:
        inline static float deltaTime;
        static void initDeltaTime();
        static float getFps();
        static void updateFps();
        
    private:
        inline static float fps;
        inline static sf::Clock deltaClock;
        inline static sf::Time fpsTime;
        inline static sf::Clock fpsClock;
        static constexpr float MULTIPLIER = TIME_DELTATIME_MULT;;

};

#endif // !TIME_H
