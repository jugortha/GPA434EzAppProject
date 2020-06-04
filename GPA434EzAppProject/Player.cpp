#include "Player.h"
#include "Color.h"

Player::Player()
    : mColor(1.0f, 1.0f, 0.0f, 1.0f), mLayout{{40,0},{4,8},{-12,22},{-8,0},{-12 ,-22},{4,-8}}
{
    mShape.buildCustom(mLayout);
  mShape.setColors(mColor, Color(0.0f, 0.0f, 0.0f, 1.0f), 1.0f);
 
}



Player::~Player()
{
}

void Player::draw(ezapp::Screen& screen)
{
   
    mShape.draw(screen,3.141516f * (1.5f),2);
}

