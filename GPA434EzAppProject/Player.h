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
       void streeringWheel(float rotationRAD);
       bool getGas();
       void setGas(bool gasPadelStatus);
       bool getShealding();
       void setShealding(bool ShealdingStatus);
       float getMileage();
       void updatePlayer(size_t screenWidth, size_t screenHeight);


private:
    
   
    Polygon mShape;
    Color mColor1;
    std::vector<Vect2d> mLayout;
    bool mGasPedal;
    bool mShealding;
    Polygon mSheald;
    Color mColor2;
    Color mColor3;
    Color mColor4;
    float mColorGardientModulation;
    float mMileage;
}
;
#endif // PLAYER_H