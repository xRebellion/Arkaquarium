#include "Guppy.hpp"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int Guppy::n_guppy = 0;

Guppy::Guppy():Ikan(0,0,0,0,0,0,0,0,-999)
{//Empty guppy 

}

Guppy::Guppy(int x, int y, int xmax, int ymax):Ikan(x,y,xmax,ymax,500,100,7500,50,n_guppy)
{//alive guppy
    n_guppy++;
}
void Guppy::move(List<Makanan>& makanan, double sec_since_last)
{
    if (isHungry() && !makanan.isEmpty())
    {
        Makanan NearestFood = (*findNearestFood(makanan));
        moveTo(NearestFood.getX(),NearestFood.getY(),sec_since_last);
        eat(makanan);
    } else
    {
        move_tick_rate += sec_since_last;
        coin_tick_rate += sec_since_last;
        
        srand((id+1)*time(0));
        double random_number = 1.5 + (rand()%3500)/1000.0;

        
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
bool Guppy::checkFood(List<Makanan>& makanan)
{
    //cout<<sqrt(pow(getX()-(*findNearestFood(makanan)).getX(),2)) + pow(getY()-(*findNearestFood(makanan)).getY(),2)<<endl;
    return(sqrt(pow(getX()-(*findNearestFood(makanan)).getX(),2)) + pow(getY()-(*findNearestFood(makanan)).getY(),2))< catchRadius;
}
void Guppy::eat(List<Makanan>& makanan)
{
    if (checkFood(makanan))
    {
        Makanan * temp = findNearestFood(makanan);
        makanan.remove(*temp);
        growth += rand()%50 + 100;
        hunger = 20000;
    }
}

Makanan * Guppy::findNearestFood(List<Makanan>& makanan)
{
    double iMinDist = 0;
    double minDist = sqrt(pow(getX()-(*makanan.getDataAddr(0)).getX(),2) + pow(getY()-(*makanan.getDataAddr(0)).getY(),2));
    for(int i = 0; makanan.getAddr(i) != nullptr; i++)
    {
        
        double dist = sqrt(pow(getX()-(*makanan.getDataAddr(i)).getX(),2) + pow(getY()-(*makanan.getDataAddr(i)).getY(),2));
        if(minDist > dist)
        {
            minDist = dist;
            iMinDist = i;
        }
    }
    
    return makanan.getDataAddr(iMinDist);
    
}

bool Guppy::checkSpitCoin()
{
    return coin_tick_rate > 5; // makes coins fall every 5s
}
void Guppy::spitCoin(List<Coin>& Lcoin) // Membuat ikan mengeluarkan coin
{
    if(checkSpitCoin())
    {
        coin_tick_rate = 0;
        Lcoin.add(new Coin(getX(),getY(),growthStage*25,getXMax(),getYMax()));
    }
}


bool Guppy::operator== (const Guppy& G)
{
    return this->id == G.id;
}

bool Guppy::operator!= (const Guppy& G)
{
    return this->id != G.id;
}

bool Guppy::operator== (std::nullptr_t)
{
    return this->id == -999;
}

Guppy Guppy::operator=(const Guppy& G)
{
    hunger = G.hunger;
    growthStage = G.growthStage;
    growth = G.growth;
    this->id = G.id;
    move_tick_rate = G.move_tick_rate;
    coin_tick_rate = G.coin_tick_rate;
    xdest = G.xdest;
    ydest = G.ydest;
    setX(G.getX());
    setY(G.getY());
    setXMax(G.getXMax());
    setYMax(G.getYMax());
    return *this;
}