#pragma once
#ifndef WORLDSIMULATION_H
#define WORLDSIMULATION_H

#include <EzApp>
#include "Color.h"
#include "Player.h"
#include "Asteroid.h"
#define PI 3.14159265f

class WorldSimulator
{
public:
    WorldSimulator(size_t width = 800, size_t height = 600);
    ~WorldSimulator();

    bool processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer);
    void processDisplay(ezapp::Screen& screen);
    void userInput(ezapp::Keyboard const& keyboard);
    void userDefence(ezapp::Keyboard const& keyboard);
    void asteroidGeneration(int milestone); 
    void CollisionDetector(void);
    void updateAsteroidsSwarm(ezapp::Screen& screen) ;
    void CollisionAnimation(ezapp::Screen& screen);
    void screenText(ezapp::Screen& screen) ;
private:
    float bestScore;
    size_t mWidth, mHeight;
    Color mBackgroundColor;
    Player mPlayer;
    std::vector<Asteroid> mAsteroids;
    int asteroidMilestone;
    bool mCollisionIndicator;
     int mTimeCounter;
     float mTimeCounter2;
};
#endif // WORLDSIMULATION_H