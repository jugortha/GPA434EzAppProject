#pragma once
#ifndef POLYGON_H
#define POLYGON_H


#include "Color.h"
#include <vector>
#include "Vect2d.h"
#include <EzApp>


class Polygon
{
public:
    Polygon();
    ~Polygon();

    // Mutateurs
    //void setFill(Color fillColor);
    //void setOutline(Color outlineColor, float outlineWidth = 1.0f);
    void setColors(Color fillColor, Color outlineColor, float outlineWidth = 1.0f);

    // Accesseurs
    //Color fillColor();
    //Color outlineColor();
    //float outlineWidth();
    //std::vector<Vect2d> vertices();


    // Utilitaires
    void buildRegular(size_t verticesCount, float circunscribedRadius);
    // build... ... ...

    void draw(ezapp::Screen& screen, float x = 0.0f, float y = 0.0f, float rotation = 0.0f, float scale = 1.0f);

private:
    std::vector<Vect2d> mVertices;
    Color mFillColor;
    Color mOutlineColor;
    float mOutlineWidth;
};


#endif // POLYGON_H