#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Polygon.h"
#include "Vect2d.h"
#define SCR_REF_OFFSET 3.14159265f * (1.5f)
class Player
{
    
public:
    Player();

    ~Player();

    
         void draw(ezapp::Screen& screen) ;
       void streeringWheel(float rotationRAD) ;
       bool GasPedal() const;
       void setGasPedal(bool gasPadelStatus);
       bool Shealding() const;
       void setShealding(bool ShealdingStatus);
       float Mileage() const;
       void updatePlayer(size_t screenWidth, size_t screenHeight);

private:
    
    
     
   
    Polygon mShape;
    Color mColor1;
    std::vector<Vect2d> mLayout;
    bool mGasPedal;
    bool mShealding;
    Polygon mSheald;// Changing color circle shield activated with "Space" bar
    Color mColor2;//Player color
    Color mColor3;//Shield transitioning colors (original)
    Color mColor4;//Shield transitioning colors
    float mColorGardientModulation;
    float mMileage;//Displeyed in top left of the screen 
    friend class WorldSimulator;
}
;
#endif // PLAYER_H