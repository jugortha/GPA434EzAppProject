#pragma once
#ifndef VECT_2D_H
#define VECT_2D_H


#include <string>


class Vect2d
{
public:
    // Constructeurs + Destructeur
    Vect2d(float x = 0.0f, float y = 0.0f);
    ~Vect2d();

    // Accesseurs
    float x();
    float y();
    float norm_squared();
    float norm();
    float theta(); // radians

    // Mutateurs
    void setX(float x);
    void setY(float y);
    void set(float x, float y);
    void setPolar(float norm, float thetaRadians);

    // Utilitaires
    float distance_squared(Vect2d other);
    float distance(Vect2d other);

    std::string toString();

private:
    float mX;
    float mY;
};


#endif // VECT_2D_H