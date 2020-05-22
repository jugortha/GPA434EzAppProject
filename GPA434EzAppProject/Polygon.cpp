#include "Polygon.h"

#include <algorithm>


Polygon::Polygon()
    : mVertices(3),
    mFillColor(1.0f, 1.0f, 1.0f, 1.0f),
    mOutlineColor(),
    mOutlineWidth{ 1.0f }
{
}

Polygon::~Polygon()
{
}

void Polygon::setColors(Color fillColor, Color outlineColor, float outlineWidth)
{
    mFillColor = fillColor;
    mOutlineColor = outlineColor;
    mOutlineWidth = outlineWidth;
}

void Polygon::buildRegular(size_t verticesCount, float circunscribedRadius)
{
    mVertices.resize(std::max((size_t)3, verticesCount)); // Cap a trois points minimum

    for (size_t i{}; i < mVertices.size(); ++i) {
        mVertices[i].setPolar(circunscribedRadius, i * 2.0f * 3.141592654f / mVertices.size());
    }
}

void Polygon::draw(ezapp::Screen& screen, float x, float y, float rotation, float scale)
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
    screen.drawPolygon(x, y, rotation, scale);
}
