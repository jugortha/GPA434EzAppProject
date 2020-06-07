#include "Player.h"
#include "Color.h"
#include <cmath>
#include "Vect2d.h"
#define SCR_REF_OFFSET 3.14159265f * (1.5f)
Player::Player()
    : mColor(1.0f, 1.0f, 0.0f, 1.0f), 
    mLayout{{40,0},{4,8},{-12,22},{-8,0},{-12 ,-22},{4,-8}},
    mGasPedal{false}
{
    mShape.buildCustom(mLayout);
  mShape.setColors(mColor, Color(0.0f, 0.0f, 0.0f, 1.0f), 1.0f);
 
}



Player::~Player()
{
}

void Player::draw(ezapp::Screen& screen)
{
    
    mShape.draw(screen, SCR_REF_OFFSET + mShape.angle(),1);
}

void Player::streeringWheel(float rotationRAD)
{
    mShape.steerAngle(rotationRAD);
}

bool Player::getGas()
{
    return mGasPedal;
}

void Player::setGas(bool gasPadelStatus)
{
   mGasPedal = gasPadelStatus;
}
void Player::updatePlayer(size_t screenWidth, size_t screenHeight)
{
    if (mGasPedal)
    { 
        float newXpos{ mShape.position().x() + (mShape.velocity().x() * cos(mShape.angle()+ SCR_REF_OFFSET)) };
        float newYpos{ mShape.position().y() + (mShape.velocity().y() * sin(mShape.angle() + SCR_REF_OFFSET)) };
        
        //Warpping
        if (newXpos > screenWidth) { newXpos = 0.0f; }
        if (newXpos < 0) { newXpos = (float) screenWidth; }
        if (newYpos > screenHeight) { newYpos = 0.0f; }
        if(newYpos < 0) { newYpos = (float) screenHeight; }
    
        this->mShape.changePosition(newXpos, newYpos);
    }       
        
    

}
    







