
#include "../include/Time.h"

void Time::initDeltaTime()
{
    Time::deltaTime = Time::deltaClock.restart().asSeconds() * Time::MULTIPLIER;
}

void Time::updateFps()
{
    fpsTime = fpsClock.getElapsedTime();
    fps = 1.f / fpsTime.asSeconds();
    fpsClock.restart().asSeconds();
}

float Time::getFps()
{
    return fps;
}
