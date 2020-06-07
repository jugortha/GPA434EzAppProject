#include "Player.h"
#include "Color.h"
#include <cmath>

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
   
    mShape.draw(screen, 3.14159265f * (3.5f) + mShape.angle(),1);
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
void Player::updatePlayerPos()
 {
    if (mGasPedal)
    {
        float newXpos{ mShape.position().x() + (mShape.velocity().x() * cos(mShape.angle())) };
        float testvar{ cos(mShape.angle()) };
        float newYpos{ mShape.position().y() + (mShape.velocity().y() * sin(mShape.angle())) };

        mShape.position().setX(newXpos);
        mShape.position().setY(newYpos);
    }
    
}






