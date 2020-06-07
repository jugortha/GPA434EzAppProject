#pragma once
#ifndef ASTEROID_H
#define ASTEROID_H

#include <EzApp>
#include "Polygon.h"
#include "Vect2d.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define SCR_REF_OFFSET 3.14159265f * (1.5f)

class Asteroid
{
    public:
        Asteroid(float minRad, float maxRad, float minPosX, float maxPosX, float minPosY, float maxPosY, float minVel, float maxVel, int minVx, int maxVx,float minAngle, float maxAngle);
   
        ~Asteroid();
    
    void randomize(float minRad, float maxRad, float minPosX, float maxPosX, float minPosY, float maxPosY, float minVel, float maxVel, int minVx, int maxVx, float minAngle, float maxAngle);
    void draw(ezapp::Screen& screen);
    void updateAsteroid(size_t screenWidth, size_t screenHeight);
    private:
        friend class WorldSimulator;
    Polygon mShape;
    Color fillColor;
    Color outlineColor;
    float fRandom(float min, float max);
    float random(float min, float max);
};
#endif // ASTEROID_H
