#include "Position.hpp"
#include <stdlib.h>

Position::Position(int xMaxPos, int yMaxPos)
{
    this->xMaxPos = xMaxPos;
    this->yMaxPos = yMaxPos;
    x= rand()%xMaxPos;
    y= rand()%yMaxPos;
}
Position::Position (int x, int y, int xMaxPos, int yMaxPos)
{
    this->x = x;
    this->y = y;
    this->xMaxPos = xMaxPos;
    this->yMaxPos = yMaxPos;
}

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}

int Position::getXMax() const
{
    return xMaxPos;
}
int Position::getYMax() const
{
    return yMaxPos;
}
void Position::setX(int x)
{
    this->x = x;
}
void Position::setY(int y)
{
    this->y = y;
}
void Position::setXMax(int xMax)
{
    this->xMaxPos = xMax;
}
void Position::setYMax(int yMax)
{
    this->yMaxPos = yMax;
}