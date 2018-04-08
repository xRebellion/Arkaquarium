#include "Akuarium.hpp"
#include <stdlib.h>
#include <time.h>

Akuarium::Akuarium(int xMax,int yMax)
{
    xMaxSize = xMax;
    yMaxSize = yMax;
}

char * Akuarium::GetObjOnPos(int x, int y) //Mencari objek pada x y sekian pada setiap list of object
{
    char * obj = new char[4];
    for(int i = 0; i < 4 ; i++)
    {
        obj[i] = '_';
    }

    for(int i = 0; coin.getAddr(i) != nullptr ; i++)
    {
        if(round(coin.get(i).getX()) == x && round(coin.get(i).getY()) == y)
        {
            obj[0] = 'C';
        }
    }

    for(int i = 0; guppy.getAddr(i) != nullptr ; i++)
    {
        if(round(guppy.get(i).getX()) == x && round(guppy.get(i).getY()) == y)
        {
            obj[1] = 'G';
        }
    }

    for(int i = 0; piranha.getAddr(i) != nullptr ; i++)
    {
        if(piranha.get(i).getX() == x && piranha.get(i).getY() == y)
        {
            obj[2] = 'P';
        }
    }

    for(int i = 0; makanan.getAddr(i) != nullptr ; i++)
    {
        if(makanan.get(i).getX() == x && makanan.get(i).getY() == y)
        {
            obj[3] = 'M';
        }
    }
    return obj;
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

void Akuarium::update(double sec_since_last)
{ //update's deaths currently only handles natural deaths (e.g: fish too hungry, coin reached bottom, etc.)
    
    //////
    //COIN
    //////
    for(int i = 0; coin.getAddr(i) != nullptr ; i++)
    {
        coin.get(i).moveDown(sec_since_last);
        if(coin.get(i).isOnBottom())
        {
            Coin * temp = coin.getDataAddr(i); //deletes already unused objects, frees up space.
            coin.remove(*temp);
            delete temp;
        }
    }

    ///////
    //GUPPY
    ///////
    for(int i = 0; guppy.getAddr(i) != nullptr ; i++)
    {
        
        (*guppy.getDataAddr(i)).move(makanan, sec_since_last);
        (*guppy.getDataAddr(i)).reduceHunger(sec_since_last);
        if(guppy.get(i).checkDeath())
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
        piranha.get(i).move(guppy, sec_since_last);
        if(piranha.get(i).checkDeath())
        {
            Piranha * temp = piranha.getDataAddr(i);
            piranha.remove(*temp);
            delete temp;
        }
    }

    /////////
    //MAKANAN
    /////////
    for(int i = 0; makanan.getAddr(i) != nullptr ; i++)
    {
        makanan.get(i).moveDown(sec_since_last);
        if(makanan.get(i).isOnBottom())
        {
            Makanan * temp = makanan.getDataAddr(i);
            makanan.remove(*temp);
            delete temp;
        }
    }
}