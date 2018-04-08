#include "Ikan.hpp"
#include "oop.hpp"



Ikan::Ikan(int x, int y, int xmax, int ymax,int gThreshold, int cRadius, int hThreshold, int spd, int id):
growthThreshold(gThreshold), hungerThreshold(hThreshold), catchRadius(cRadius), spd(spd), Position(x, y, xmax,ymax)
{
    hunger = 10000;
    growthStage = 1;
    growth = 0;
    this->id = id;
    move_tick_rate = 0;
    coin_tick_rate = 0;
    xdest = 0;
    ydest = 0;
}
void Ikan::checkGrow()
{
    if (growth >= growthThreshold && growthStage < 3)
    {
        growthStage++;
        growthStage -= growthThreshold;
    }
}

void Ikan::moveTo(int x, int y, double sec_since_last)
{
    double a = atan2(this->getY()-y,this->getX()-x);
    setX(this->getX() + spd*cos(a)*sec_since_last);
    setY(this->getY() + spd*sin(a)*sec_since_last);
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