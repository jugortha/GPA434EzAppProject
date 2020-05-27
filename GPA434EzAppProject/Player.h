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

private:
    Polygon mPolygon;
    Vect2d mAcceleration;
    
};

#endif // PLAYER_H