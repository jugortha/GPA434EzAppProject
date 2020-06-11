#include "Polygon.h"

#include <algorithm>


Polygon::Polygon()
    : mVertices(3),
    mFillColor(1.0f, 1.0f, 1.0f, 1.0f),
    mOutlineColor(),
    mOutlineWidth{ 1.0f },
    mPosition(600.0f, 400.0f),
    mVelocity(1.1f,1.1f),
    mAcceleration(0.0f,0.0f),
    mRadialVelocity{0.006f},
    mRadius{ 30.0f },
    mAngle{0.0f}
{
}

Polygon::~Polygon()
{
}

Vect2d Polygon::position() const
{
    return mPosition;
}

Vect2d Polygon::velocity() const
{
    return mVelocity;
}


Vect2d Polygon::acceleration() const
{
    return mAcceleration;
}

float Polygon::radius() const
{
    return mRadius;
}

void Polygon::setRadius(float radius)
{
   mRadius= radius;
}

float Polygon::angle() const
{
    return mAngle;
}

void Polygon::setAngle(float Angle)
{
    mAngle = Angle;
}

void Polygon::setVelocity(float velocityX, float velocityY) 
{
    mVelocity.set(velocityX, velocityY);
    
}

void Polygon::steerAngle(float angulardisplacement)
{
    mAngle += mRadialVelocity *angulardisplacement;
}

void Polygon::changePosition(float newXpos, float newYpos)
{
    mPosition.setX(newXpos);
    mPosition.setY(newYpos);
}



void Polygon::addAcceleration(Vect2d& acceleration)
{
    mAcceleration.set(mAcceleration.x() + acceleration.x(), mAcceleration.y() + acceleration.y());
}

void Polygon::processTime(float elapsedTime)
{
    float xPos{ mPosition.x() + mVelocity.x() * elapsedTime + 0.5f * mAcceleration.x() * elapsedTime * elapsedTime };
    float yPos{ mPosition.y() + mVelocity.y() * elapsedTime + 0.5f * mAcceleration.y() * elapsedTime * elapsedTime };
    float yVel{ mVelocity.y() + mAcceleration.y() * elapsedTime };
    float xVel{ mVelocity.x() + mAcceleration.x() * elapsedTime };
    mPosition.set(xPos, yPos);
    mVelocity.set(xVel, yVel);
    mAcceleration.reset();
}


void Polygon::setColors(Color fillColor, Color outlineColor, float outlineWidth)
{
    mFillColor = fillColor;
    mOutlineColor = outlineColor;
    mOutlineWidth = outlineWidth;
}

void Polygon::buildRegular(size_t verticesCount, float circunscribedRadius)
{
    mVertices.resize(std::max((size_t)3, verticesCount));

    for (size_t i{}; i < mVertices.size(); ++i) {
        mVertices[i].setPolar(circunscribedRadius, i * 2.0f * 3.141592654f / mVertices.size());
    }
}

void Polygon::buildCustom(std::vector<Vect2d> mPointsCloud)
{  
    mVertices.resize(std::max((size_t)3, mPointsCloud.size()));
    for (size_t i{}; i < mVertices.size(); ++i) {
        mVertices[i].set(mPointsCloud[i].x(), mPointsCloud[i].y());
    }
}

float Polygon::buildIrregular(size_t verticesCount, float minRadius, float maxRadius)
{
    mVertices.resize(std::max((size_t)3, verticesCount));
    float norm{};
    float bigestRadius{};
    srand((int)time(NULL));

    for (size_t i{}; i < mVertices.size(); ++i){
        
       
        norm = rand() % (int) (maxRadius - minRadius) + minRadius ;
        
        if (norm > bigestRadius)
        {
            bigestRadius = norm;
        }

        mVertices[i].setPolar(norm, i * 2.0f * 3.141592654f / mVertices.size());
    }
    return bigestRadius;
}
void Polygon::buildCircle(float radius, float sideLength)
{
    sideLength = std::max(1.0f, sideLength);
    buildRegular(size_t (std::max(16.0f, 2.0f * 3.141592654f * radius / sideLength)), radius);
}

void Polygon::draw(ezapp::Screen& screen, float rotation, float scale)
{
    screen.setBrush(mFillColor.red(),
        mFillColor.green(),
        mFillColor.blue(),
        mFillColor.alpha());
    screen.setPen(mOutlineColor.red(),
        mOutlineColor.green(),
        mOutlineColor.blue(),
        mOutlineColor.alpha(),
        mOutlineWidth);
    screen.setPolygonVertices(mVertices);


    //Fontion acceleration 
    //


    screen.drawPolygon(mPosition.x(), mPosition.y(), rotation, scale);
}
