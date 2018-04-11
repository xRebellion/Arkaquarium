#include "Piranha.hpp"
#include <stdlib.h>
#include <time.h>

int Piranha::n_piranha = 0;

Piranha::Piranha():Ikan(0,0,0,0,0,0,0,0,-999)
{//Empty guppy 

}

Piranha::Piranha(int x, int y, int xmax, int ymax):Ikan(x,y,xmax,ymax,500,50,7500,125,n_piranha)
{//alive guppy
    n_piranha++;
}
void Piranha::move(List<Guppy>& guppy,List<Coin>& coin, double sec_since_last)
{
    if (isHungry() && !guppy.isEmpty())
    {
        Guppy NearestFood = *(findNearestFood(guppy));
        moveTo(NearestFood.getX(),NearestFood.getY(),sec_since_last);
        int val = eat(guppy);
        if(val)
        spitCoin(coin,val);
    } else
    {
        move_tick_rate += sec_since_last;

        srand((id+1)*time(0));
        double random_number = 0.5+(rand()%4500)/1000;

        if (move_tick_rate > random_number || (abs(getX()-xdest) < 1 && abs(getY()-ydest) < 1))
        {
            srand((id+1)*rand());
            xdest = rand()%getXMax();
            ydest = rand()%getYMax();
            move_tick_rate = 0;
        }
        moveTo(xdest, ydest, sec_since_last);
    }
}
bool Piranha::checkFood(List<Guppy>& guppy)
{
    return(sqrt(pow(getX()-(*findNearestFood(guppy)).getX(),2)) + pow(getY()-(*findNearestFood(guppy)).getY(),2))< catchRadius;
}
int Piranha::eat(List<Guppy>& guppy)
{
    if (checkFood(guppy))
    {
        Guppy * temp = (findNearestFood(guppy));
        guppy.remove(*temp);
        int coinVal = 100*((*temp).getGrowthStage()+1);
        delete temp;
        growth += rand()%50 + 100;
        hunger = 20000;
        checkGrow();
        return coinVal;
    }
    return 0;
}

Guppy * Piranha::findNearestFood(List<Guppy>& guppy)
{
    double iMinDist = 0;
    double minDist = sqrt(pow(getX()-(*guppy.getDataAddr(0)).getX(),2) + pow(getY()-(*guppy.getDataAddr(0)).getY(),2));
    for(int i = 0; guppy.getAddr(i) != nullptr; i++)
    {
        double dist = sqrt(pow(getX()-(*guppy.getDataAddr(i)).getX(),2) + pow(getY()-(*guppy.getDataAddr(i)).getY(),2));
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
    return true; //required for the pure virtual definition
}
void Piranha::spitCoin(List<Coin>& Lcoin, int value) // Membuat ikan mengeluarkan coin
{
    Lcoin.add(new Coin(getX(),getY(),value,getXMax(),getYMax()));
}


bool Piranha::operator== (const Piranha& P)
{
    return this->id == P.id;
}

bool Piranha::operator!= (const Piranha& P)
{
    return this->id != P.id;
}

bool Piranha::operator== (std::nullptr_t n)
{
    return this->id == -999;
}