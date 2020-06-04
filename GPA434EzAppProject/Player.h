#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Polygon.h"
#include "Vect2d.h"

class Player
{
    
public:
    Player();

       ~Player();

    

       void draw(ezapp::Screen& screen);
private:
    
   
    Polygon mShape;
    Color mColor;
    std::vector<Vect2d> mLayout;
};

#endif // PLAYER_H