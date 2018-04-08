#include "Guppy.hpp"
#include <stdlib.h>

int Guppy::n_guppy = 0;

Guppy::Guppy():Ikan(0,0,0,0,0,0,0,0,-999)
{//Empty guppy 

}

Guppy::Guppy(int x, int y, int xmax, int ymax):Ikan(x,y,xmax,ymax,500,10,5000,3,n_guppy)
{//alive guppy
    n_guppy++;
}
void Guppy::move(List<Makanan>& makanan, double sec_since_last)
{
    if (isHungry() && !makanan.isEmpty())
    {
        Makanan NearestFood = findNearestFood(makanan);
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
bool Guppy::checkFood(List<Makanan>& makanan)
{
    return(sqrt(pow(findNearestFood(makanan).getX(),2)) + pow(findNearestFood(makanan).getY(),2))< catchRadius;
}
void Guppy::eat(List<Makanan>& makanan)
{
    if (checkFood(makanan))
    {
        makanan.remove(findNearestFood(makanan));
        growth += rand()%50 + 100;
    }
}

Makanan Guppy::findNearestFood(List<Makanan>& makanan)
{
    double iMinDist = 0;
    double minDist = sqrt(pow(makanan.get(0).getX(),2) + pow(makanan.get(0).getY(),2));
    for(int i = 0; makanan.getAddr(i) != nullptr; i++)
    {
        
        double dist = sqrt(pow(makanan.get(i).getX(),2) + pow(makanan.get(i).getY(),2));
        if(minDist > dist)
        {
            minDist = dist;
            iMinDist = i;
        }
    }
    return makanan.get(iMinDist);
    
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
        Lcoin.add(Coin(getX(),getY(),growthStage*25));
    }
}


bool Guppy::operator== (const Guppy& G)
{
    return this->id == G.id;
}

bool Guppy::operator== (std::nullptr_t)
{
    return this->id == -999;
}