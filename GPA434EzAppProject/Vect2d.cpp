#include "Vect2d.h"




Vect2d::Vect2d()
	: Vect2d(0.0f, 0.0f)
{
}

Vect2d::Vect2d(float x, float y)
    : mX{ x }, mY{ y }
{
}

Vect2d::~Vect2d()
{
    // rien à faire
}

float Vect2d::x() const
{
    return mX;
}

float Vect2d::y() const
{
    return mY;
}

float Vect2d::norm_squared() const
{
    return mX * mX + mY * mY;
}

float Vect2d::norm() const
{
    return std::sqrt(norm_squared());
}

float Vect2d::theta() const
{
    return std::atan2(mY, mX);
}

void Vect2d::setX(float x) 
{
    mX = x;
}

void Vect2d::setY(float y) 
{
    mY = y;
}

void Vect2d::set(float x, float y)
{
   setX(x);
    setY(y);
}

void Vect2d::setPolar(float norm, float thetaRadians)
{
    setX(norm * std::cos(thetaRadians));
    setY(norm * std::sin(thetaRadians));
}

void Vect2d::reset()
{
    mX = mY = 0.0f;
}

float Vect2d::distance_squared(Vect2d const& other) const
{
    return std::pow(mX - other.mX, 2.0f) + std::pow(mY - other.mY, 2.0f);
}

float Vect2d::distance(Vect2d const & other) const
{
    return std::sqrt(distance_squared(other));
}

std::string Vect2d::toString() const
{
    std::stringstream stream;
    stream << "(" << mX << ", " << mY << ")";
    return stream.str();
}

