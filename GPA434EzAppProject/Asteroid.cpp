#include "Asteroid.h"


Asteroid::Asteroid(float minRad, float maxRad, float minPosX, float maxPosX, float minPosY, float maxPosY, float minVel, float maxVel, int minVx, int maxVx,float minAngle, float maxAngle)
    :fillColor(fRandom(0,1), fRandom(0, 1), fRandom(0, 1), 1.0f), outlineColor(0.0f, 0.0f, 0.0f, 1.0f)
    {
    randomize(minRad,  maxRad,  minPosX,  maxPosX,  minPosY,  maxPosY,  minVel,  maxVel,  minVx,  maxVx, minAngle,  maxAngle);
    mShape.setColors(fillColor, outlineColor, 2.5f);

     }

Asteroid::~Asteroid()
{
}

void Asteroid::randomize(float minRad, float maxRad, float minPosX, float maxPosX, float minPosY, float maxPosY, float minVel, float maxVel,int minVx, int maxVx, float minAngle, float maxAngle)
{
  
    mShape.changePosition( random(minPosX, maxPosX), random(minPosY, maxPosY));
    mShape.setVelocity(random(minVel, maxVel), random(minVel, maxVel));
    mShape.setRadius(mShape.buildIrregular((int)random(minVx, maxVx), minRad, maxRad));
    mShape.setAngle(random(minAngle, maxAngle));

}


float Asteroid::fRandom(float min, float max)
{
    srand((int)time(NULL));
    return ((float) (rand()) / (float)(max - min) + min);
   
}

float Asteroid::random(float min, float max)
{
    srand((int)time(NULL));
    return rand() % (int)(max - min) + min;

}

void Asteroid::draw(ezapp::Screen& screen)
{
    
        mShape.draw(screen);
}

void Asteroid::updateAsteroid(size_t screenWidth, size_t screenHeight){
    float newXpos{ mShape.position().x() + (mShape.velocity().x() * cos(mShape.angle() + SCR_REF_OFFSET)) };
    float newYpos{ mShape.position().y() + (mShape.velocity().y() * sin(mShape.angle() + SCR_REF_OFFSET)) };
   
    //Warpping
    if (newXpos > screenWidth) { newXpos = 0.0f; }
    if (newXpos < 0) { newXpos = (float)screenWidth; }
    if (newYpos > screenHeight) { newYpos = 0.0f; }
    if (newYpos < 0) { newYpos = (float)screenHeight; }

    this->mShape.changePosition(newXpos, newYpos);
}