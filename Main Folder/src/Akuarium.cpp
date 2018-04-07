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

    for(int i = 0; coin.getNext(i) != NULL ; i++)
    {
        if(coin.get(i).getX() == x && coin.get(i).getY() == y)
        {
            obj[0] = 'C';
        }
    }

    for(int i = 0; guppy.getNext(i) != NULL ; i++)
    {
        if(guppy.get(i).getX() == x && guppy.get(i).getY() == y)
        {
            obj[1] = 'G';
        }
    }

    for(int i = 0; piranha.getNext(i) != NULL ; i++)
    {
        if(piranha.get(i).getX() == x && piranha.get(i).getY() == y)
        {
            obj[2] = 'P';
        }
    }

    for(int i = 0; makanan.getNext(i) != NULL ; i++)
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