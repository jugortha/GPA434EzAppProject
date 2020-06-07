#pragma once
#ifndef WORLDSIMULATION_H
#define WORLDSIMULATION_H

#include <EzApp>
#include "Color.h"
#include "Player.h"
#include "Asteroid.h"

class WorldSimulator
{
public:
    WorldSimulator(size_t width = 800, size_t height = 600);
    ~WorldSimulator();

    bool processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer);
    void processDisplay(ezapp::Screen& screen);
    void userInput(ezapp::Keyboard const& keyboard);
 
private:
    size_t mWidth, mHeight;
    Color mBackgroundColor;
    Player mPlayer;
    std::vector<Asteroid> mAsteroids;
};
#endif // WORLDSIMULATION_H