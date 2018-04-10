#include "Ikan.hpp"
#include "oop.hpp"
#include <stdio.h>
#include <time.h>


Ikan::Ikan(int x, int y, int xmax, int ymax,int gThreshold, int cRadius, int hThreshold, int spd, int id):
growthThreshold(gThreshold), hungerThreshold(hThreshold), catchRadius(cRadius), spd(spd), Position(x, y, xmax,ymax)
{
    srand(time(0));
    hunger = 15000;
    growthStage = 1;
    growth = 0;
    this->id = id;
    move_tick_rate = 0;
    coin_tick_rate = 0;
    xdest = rand()%xmax;
    ydest = rand()%ymax;
}
void Ikan::checkGrow()
{
    if (growth >= growthThreshold && growthStage < 3)
    {
        growthStage++;
        growth -= growthThreshold;
    }
}

void Ikan::moveTo(int x, int y, double sec_since_last)
{
    double a = atan2(y-this->getY(),x-this->getX());
    double xdir = spd*cos(a)*sec_since_last; 
    setX(getX() + xdir);
    setY(getY() + spd*sin(a)*sec_since_last);
    if(xdir < 0)
    {
        direction = 'L';
    } else
    {
        direction = 'R';
    }
}

bool Ikan::isHungry()
{
    return hunger < hungerThreshold;
}
bool Ikan::checkDeath()
{
    return hunger < 0;
}
void Ikan::reduceHunger(double sec)
{
    hunger -= sec*1000;
}
int Ikan::getID()
{
    
    return id;
}
int Ikan::getGrowthStage()
{
    return growthStage;
}
char Ikan::getDirection()
{
    return direction;
}