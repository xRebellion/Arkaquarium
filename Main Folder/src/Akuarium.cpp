#include "Akuarium.hpp"
#include <stdlib.h>
#include <time.h>

Akuarium::Akuarium(int xMax,int yMax):egg_price(500)
{
    xMaxSize = xMax;
    yMaxSize = yMax;
    snail = new Snail(xMax/2, xMax, yMax);
    money = 200;
    egg_bought = 0;
}


void Akuarium::AddToAkuarium(Guppy * G)
{
    guppy.add(G);
}
void Akuarium::AddToAkuarium(Piranha * P)
{
    piranha.add(P);
}
void Akuarium::AddToAkuarium(Coin * C)
{
    coin.add(C);
}
void Akuarium::AddToAkuarium(Makanan * M)
{
    makanan.add(M);
}

List<Coin> * Akuarium::getCList()
{
    return &coin;
}
List<Guppy> * Akuarium::getGList()
{
    return &guppy;
}
List<Piranha> * Akuarium::getPList()
{
    return &piranha;
}
List<Makanan> * Akuarium::getMList()
{
    return &makanan;
}
Snail * Akuarium::getSnail()
{
    return snail;
}
int Akuarium::getMoney()
{
    return money;
}
void Akuarium::setMoney(int money)
{
    this->money = money;
}
int Akuarium::buyEgg()
{
    egg_bought++;
    money -= egg_price;
}

int Akuarium::getEggBought()
{
    return egg_bought;
}
const int Akuarium::getEggPrice()
{
    return egg_price;
}

void Akuarium::update(double sec_since_last)
{ //update's deaths currently only handles natural deaths (e.g: fish too hungry, coin reached bottom, etc.)
    
    //////
    //COIN
    //////
    for(int i = 0; coin.getAddr(i) != nullptr ; i++)
    {
        (*coin.getDataAddr(i)).moveDown(sec_since_last);
        if((*coin.getDataAddr(i)).isOnBottom())
        {
            Coin * temp = coin.getDataAddr(i);
            coin.remove(*temp);
            delete temp;
        }
    }

    ///////
    //GUPPY
    ///////
    for(int i = 0; guppy.getAddr(i) != nullptr ; i++)
    {
        //cout << guppy.getAddr(i) <<" ";
        (*guppy.getDataAddr(i)).move(makanan, sec_since_last);
        (*guppy.getDataAddr(i)).reduceHunger(sec_since_last);
        (*guppy.getDataAddr(i)).spitCoin(coin,(*guppy.getDataAddr(i)).getGrowthStage()*25);
        if((*guppy.getDataAddr(i)).checkDeath())
        {
            Guppy * temp = guppy.getDataAddr(i); //deletes already unused objects, frees up space.
            guppy.remove(*temp);
            delete temp;
        }
    }

    ////////
    //PIRANHA
    ///////
    for(int i = 0; piranha.getAddr(i) != nullptr ; i++)
    {
        //cout << piranha.getAddr(i) <<" ";
        (*piranha.getDataAddr(i)).move(guppy, coin, sec_since_last);
        (*piranha.getDataAddr(i)).reduceHunger(sec_since_last);
        if((*piranha.getDataAddr(i)).checkDeath())
        {
            Piranha * temp = piranha.getDataAddr(i); //deletes already unused objects, frees up space.
            piranha.remove(*temp);
            delete temp;
        }
    }

    /////////
    //MAKANAN
    /////////
    for(int i = 0; makanan.getAddr(i) != nullptr ; i++)
    {
        (*makanan.getDataAddr(i)).moveDown(sec_since_last);
        if((*makanan.getDataAddr(i)).isOnBottom())
        {
            Makanan * temp = makanan.getDataAddr(i);
            makanan.remove(*temp);
            delete temp;
        }
    }

    //Snail
    money = money + (*snail).moveToCoin(coin,sec_since_last);
}