#ifndef SNAIL_HPP
#define SNAIL_HPP   

#include "Position.hpp"
#include "Coin.hpp"
#include "List.hpp"
class Snail: public Position
{
private:
    const int catchRadius;
public:
    Snail(int x, int xmax, int ymax); //initialize snail di posisi (x, ymaxpos)
    void moveToCoin(List<Coin> Lcoin); //Bergerak menuju koin paling dekat dasar (y = ymax dibanding koin lain)
    int findMaxY(List<Coin> Lcoin); //mengembalikan index dengan y maksimum.
    void catchCoin(List<Coin>& Lcoin); //menghapus koin dari list koin yang ada apabila berada di dekat snail.
};

#endif

