#pragma once
#ifndef VECT_2D_H
#define VECT_2D_H

#include <string>
#include <iostream>
#include <cmath>
#include <sstream>

class Vect2d
{
public:
    // Constructeurs + Destructeur
    Vect2d();
    Vect2d(float x , float y );
    ~Vect2d();

    // Accesseurs
    float x() const;
    float y() const;
    float norm_squared() const;
    float norm() const;
    float theta() const; // radians

    // Mutateurs
    void setX(float x);
    void setY(float y);
    void set(float x, float y);
    void setPolar(float norm, float thetaRadians);

    // Utilitaires
    void reset();
    float distance_squared(Vect2d const & other) const;
    float distance(Vect2d const & other) const;

    std::string toString() const;

private:
    float mX;
    float mY;
};


#endif // VECT_2D_H