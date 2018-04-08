#include "Piranha.hpp"
#include <stdlib.h>

int Piranha::n_piranha = 0;

Piranha::Piranha():Ikan(0,0,0,0,0,0,0,0,-999)
{//Empty guppy 

}

Piranha::Piranha(int x, int y, int xmax, int ymax):Ikan(x,y,xmax,ymax,500,10,5000,3,n_piranha)
{//alive guppy
    n_piranha++;
}
void Piranha::move(List<Guppy>& guppy, double sec_since_last)
{
    if (isHungry() && !guppy.isEmpty())
    {
        Guppy NearestFood = *(findNearestFood(guppy));
        moveTo(NearestFood.getX(),NearestFood.getY(),sec_since_last);
    } else
    {
        move_tick_rate += sec_since_last;
        coin_tick_rate += sec_since_last;
        double random_number = 0.5+(rand()%4500)/1000;
        if (move_tick_rate > random_number)
        {
            xdest = rand()%getXMax();
            ydest = rand()%getYMax();
        }
        moveTo(xdest, ydest, sec_since_last);
    }
}
bool Piranha::checkFood(List<Guppy>& guppy)
{
    return(sqrt(pow((*findNearestFood(guppy)).getX(),2)) + pow((*findNearestFood(guppy)).getY(),2))< catchRadius;
}
void Piranha::eat(List<Guppy>& guppy)
{
    if (checkFood(guppy))
    {
        Guppy * temp = (findNearestFood(guppy));
        guppy.remove(*temp);
        delete temp;
        growth += rand()%50 + 100;
    }
}

Guppy * Piranha::findNearestFood(List<Guppy>& guppy)
{
    double iMinDist = 0;
    double minDist = sqrt(pow(guppy.get(0).getX(),2) + pow(guppy.get(0).getY(),2));
    for(int i = 0; guppy.getAddr(i) != nullptr; i++)
    {
        
        double dist = sqrt(pow(guppy.get(i).getX(),2) + pow(guppy.get(i).getY(),2));
        if(minDist > dist)
        {
            minDist = dist;
            iMinDist = i;
        }
    }
    return guppy.getDataAddr(iMinDist);
    
}

bool Piranha::checkSpitCoin()
{
    return coin_tick_rate > 5; // makes coins fall every 5s
}
void Piranha::spitCoin(List<Coin>& Lcoin) // Membuat ikan mengeluarkan coin
{
    if(checkSpitCoin())
    {
        coin_tick_rate = 0;
        Lcoin.add(new Coin(getX(),getY(),growthStage*40,getXMax(),getYMax()));
    }
}


bool Piranha::operator== (const Piranha& P)
{
    return this->id == P.id;
}

bool Piranha::operator== (std::nullptr_t n)
{
    return this->id == -999;
}