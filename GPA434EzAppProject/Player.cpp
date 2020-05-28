#include "Player.h"
#include "Color.h"

Player::Player()  
{
 mShape.setColors(Color(1.0f, 1.0f, 0.0f, 1.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 1.0f);
}

Player::~Player()
{
}

void Player::draw(ezapp::Screen& screen)
{
   
    mShape.draw(screen);
}