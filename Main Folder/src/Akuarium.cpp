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

    for(int i = 0; coin.getAddr(i) != NULL ; i++)
    {
        if(coin.get(i).getX() == x && coin.get(i).getY() == y)
        {
            obj[0] = 'C';
        }
    }

    for(int i = 0; guppy.getAddr(i) != NULL ; i++)
    {
        if(guppy.get(i).getX() == x && guppy.get(i).getY() == y)
        {
            obj[1] = 'G';
        }
    }

    for(int i = 0; piranha.getAddr(i) != NULL ; i++)
    {
        if(piranha.get(i).getX() == x && piranha.get(i).getY() == y)
        {
            obj[2] = 'P';
        }
    }

    for(int i = 0; makanan.getAddr(i) != NULL ; i++)
    {
        if(makanan.get(i).getX() == x && makanan.get(i).getY() == y)
        {
            obj[3] = 'M';
        }
    }
    return obj;
}

List<Coin> Akuarium::GetCoinList()
{
    return coin;
}

List<Guppy> Akuarium::GetGuppyList()
{
    return guppy;
}

List<Piranha> Akuarium::GetPiranhaList()
{
    return piranha;
}

List<Makanan> Akuarium::GetMakananList()
{
    return makanan;
}
void Akuarium::update(double sec_since_last)
{ //update's deaths currently only handles natural deaths (e.g: fish too hungry, coin reached bottom, etc.)
//not yet updates from other sources.
    
    for(int i = 0; coin.getAddr(i) != NULL ; i++)
    {
        coin.get(i).moveDown();
        if(coin.get(i).isOnBottom())
        {
            coin.remove(coin.get(i));
        }
    }

    for(int i = 0; guppy.getAddr(i) != NULL ; i++)
    {
        guppy.get(i).move(makanan, sec_since_last);
        if(guppy.get(i).checkDeath())
        {
            guppy.remove(guppy.get(i));
        }
    }

    for(int i = 0; piranha.getAddr(i) != NULL ; i++)
    {
        piranha.get(i).move(guppy, sec_since_last);
        if(piranha.get(i).checkDeath())
        {
            piranha.remove(piranha.get(i));
        }
    }

    for(int i = 0; makanan.getAddr(i) != NULL ; i++)
    {
        makanan.get(i).moveDown();
        if(makanan.get(i).isOnBottom())
        {
            makanan.remove(makanan.get(i));
        }
    }
}