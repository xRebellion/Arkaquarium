#include "Position.hpp"
#include <stdlib.h>

Position::Position(int xMaxPos, int yMaxPos)
{
    this->xMaxPos = xMaxPos;
    this->yMaxPos = yMaxPos;
    x= rand()%xMaxPos;
    y= rand()%yMaxPos;
}
Position::Position (double x, double y, int xMaxPos, int yMaxPos)
{
    this->x = x;
    this->y = y;
    this->xMaxPos = xMaxPos;
    this->yMaxPos = yMaxPos;
}

double Position::getX() const
{
    return x;
}

double Position::getY() const
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
void Position::setX(double x)
{
    this->x = x;
}
void Position::setY(double y)
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