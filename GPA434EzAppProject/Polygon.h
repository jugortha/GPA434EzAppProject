#pragma once
#ifndef POLYGON_H
#define POLYGON_H


#include "Color.h"
#include <vector>
#include "Vect2d.h"
#include <EzApp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm> 


class Polygon
{
public:
    Polygon();
    ~Polygon();

   
    // Mutateurs
    void setColors(Color fillColor, Color outlineColor, float outlineWidth = 1.0f);
  
    // Accesseurs
    Vect2d position() const;
    Vect2d velocity() const;
    Vect2d acceleration() const;
    float radius() const;
    float angle() const;
    void setAngle(float Angle);
    void setRadius(float radius);
    void setVelocity(float velocityX, float velocityY);
    void changePosition(float newXpos, float newYpos);
    void steerAngle(float angulardisplacement);
    
    // Utilitaires
    void addAcceleration(Vect2d& acceleration);
    void processTime(float elapsedTime);
    
    // build
    void buildRegular(size_t verticesCount, float circunscribedRadius);
    void buildCustom(std::vector<Vect2d>& mPointsCloud);
    float buildIrregular(size_t verticesCount, float minRadius, float maxRadius);
    void buildCircle(float radius, float sideLength = 10.0f);

    void draw(ezapp::Screen& screen, float rotation = 0.0f, float scale = 1.0f);

private:
    std::vector<Vect2d> mVertices;
    Color mFillColor;
    Color mOutlineColor;
    float mOutlineWidth;
    Vect2d mPosition;
    Vect2d mVelocity;
    Vect2d mAcceleration;
    float mRadialVelocity;
    float mRadius;
    float mAngle;
};


#endif // POLYGON_H