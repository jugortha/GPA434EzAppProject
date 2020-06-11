#include "Player.h"
#include "Color.h"
#include <cmath>
#include "Vect2d.h"

Player::Player()
    : mColor1(1.0f, 1.0f, 0.0f, 1.0f),
    mColor2(1.0f, 1.0f, 0.0f, 1.0f),   // jaune
    mColor3(1.0f, 0.0f, 1.0f, 1.0f),  // magenta
    mColor4(0.0f, 0.0f, 0.0f, 1.0f),
    mLayout{{40,0},{4,8},{-12,22},{-8,0},{-12 ,-22},{4,-8}},
    mGasPedal{false},
    mShealding{false},
    mColorGardientModulation{0.0f},
    mMileage{0.0f}
{
    
    mShape.buildCustom(mLayout);
  mShape.setColors(mColor1, Color(0.0f, 0.0f, 0.0f, 1.0f), 1.0f);
  
  //SHEALD
  mSheald.buildCircle(35.0f);
  mSheald.setColors(mColor4, Color(0.0f, 0.0f, 0.0f, 1.0f), 5.0f);

} 



Player::~Player()
{
}

void Player::draw(ezapp::Screen& screen) 
{
    if (mShealding)
    {
        mColor4 = mColor2.processGradient(mColor3, std::sin(mColorGardientModulation) * 0.5f + 0.5f, false);
        mColorGardientModulation += 0.04f;
        mSheald.setColors(mColor4, Color(0.0f, 0.0f, 0.0f, 1.0f), 5.0f);
        mSheald.draw(screen);
    }
    else mShape.draw(screen, SCR_REF_OFFSET + mShape.angle(),1.1f);

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


bool Player::getShealding()
{
    return mShealding;
}



void Player::setShealding(bool ShealdingStatus)
{
    mShealding = ShealdingStatus;
}

float Player::Mileage()  const {
    return mMileage;
}

void Player::updatePlayer(size_t screenWidth, size_t screenHeight)
{
    if (mGasPedal)
    { 
        float newXpos{ mShape.position().x() + (mShape.velocity().x() * cos(mShape.angle()+ SCR_REF_OFFSET)) };
        float newYpos{ mShape.position().y() + (mShape.velocity().y() * sin(mShape.angle() + SCR_REF_OFFSET)) };
        mMileage += !mShealding * sqrt(pow((mShape.velocity().x() * cos(mShape.angle() + SCR_REF_OFFSET)), 2) + pow((mShape.velocity().y() * sin(mShape.angle() + SCR_REF_OFFSET)),2));

        //Warpping
        if (newXpos > screenWidth) { newXpos = 0.0f; }
        if (newXpos < 0) { newXpos = (float) screenWidth; }
        if (newYpos > screenHeight) { newYpos = 0.0f; }
        if(newYpos < 0) { newYpos = (float) screenHeight; }
    
        this->mShape.changePosition(newXpos, newYpos);
        this->mSheald.changePosition(newXpos, newYpos);
    }       
}
    







