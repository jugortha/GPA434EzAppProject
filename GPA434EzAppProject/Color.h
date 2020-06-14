#pragma once
#ifndef COLOR_H
#define COLOR_H


class Color
{
    // masquage privé par défaut

public:
    Color();
    Color(float red, float green, float blue, float alpha = 1.0f);
    Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
    ~Color();

    // Accesseurs (getters)
    float red() const;
    float green() const;
    float blue() const;
    float alpha() const;

    // Mutateurs (setters)
    void setRed(float red);
    void setGreen(float green);
    void setBlue(float blue);
    void setAlpha(float alpha);
    void set(float red, float green, float blue, float alpha = 1.0f);
    void set(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);

    // Fonction utilitaire
    Color processGradient(Color const& other, float ratio, bool includeAlpha = false)  const;
    void invert(bool includeAlpha = false);

private:
    float mRed;
    float mGreen;
    float mBlue;
    float mAlpha;

    float linearInterpolation(float x1, float y1, float x2, float y2, float x)  const;
};
#endif // COLOR_H