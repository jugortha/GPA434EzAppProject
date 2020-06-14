#include "Color.h"




Color::Color()
    : Color(0.0f, 0.0f, 0.0f, 1.0f) // liste d'initialization membres - Member initializer list => constructeur délégué
{
}

Color::Color(float red, float green, float blue, float alpha)
    : mRed{ red },
    mGreen{ green },
    mBlue{ blue },
    mAlpha{ alpha } // liste d'initialization membres - Member initializer list
{

}

Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    : Color((float)red / 255.0f, (float)green / 255.0f, (float)blue / 255.0f, (float)alpha / 255.0f)
{
}

Color::~Color()
{
    // do nothing
}

float Color::red()  const
{
    return mRed;
}

float Color::green()  const
{
    return mGreen;
}

float Color::blue()  const
{
    return mBlue;
}

float Color::alpha()  const
{
    return mAlpha;
}

void Color::setRed(float red)
{
    mRed = red;
}

void Color::setGreen(float green)
{
    mGreen = green;
}

void Color::setBlue(float blue)
{
    mBlue = blue;
}

void Color::setAlpha(float alpha)
{
    mAlpha = alpha;
}

void Color::set(float red, float green, float blue, float alpha)
{
    setRed(red);
    setGreen(green);
    setBlue(blue);
    setAlpha(alpha);
}

void Color::set(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    set((float)red / 255.0f, (float)green / 255.0f, (float)blue / 255.0f, (float)alpha / 255.0f);
}

Color Color::processGradient(Color const& other, float ratio, bool includeAlpha)  const
{
    Color gradientColor;

    if (ratio < 0.0f) ratio = 0.0f;
    if (ratio > 1.0f) ratio = 1.0f;

    gradientColor.setRed(linearInterpolation(0.0f, mRed, 1.0f, other.mRed, ratio));
    gradientColor.setGreen(linearInterpolation(0.0f, mGreen, 1.0f, other.mGreen, ratio));
    gradientColor.setBlue(linearInterpolation(0.0f, mBlue, 1.0f, other.mBlue, ratio));
    if (includeAlpha) {
        gradientColor.setAlpha(linearInterpolation(0.0f, mAlpha, 1.0f, other.mAlpha, ratio));
    }
    else {
        gradientColor.setAlpha(mAlpha);
    }

    return gradientColor;
}

void Color::invert(bool includeAlpha)
{
    mRed = 1.0f - mRed;
    mGreen = 1.0f - mGreen;
    mBlue = 1.0f - mBlue;

    if (includeAlpha) {
        mAlpha = 1.0f - mAlpha;
    }
}

float Color::linearInterpolation(float x1, float y1, float x2, float y2, float x)  const
{
    return y1 + (x - x1) / (x2 - x1) * (y2 - y1); // on ne valide pas la division par 0
}

