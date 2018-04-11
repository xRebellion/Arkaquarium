#ifndef SNAIL_HPP
#define SNAIL_HPP   

#include "Position.hpp"
#include "Coin.hpp"
#include "List.hpp"
class Snail: public Position
{
private:
    const int catchRadius;
    const int speed;
    char direction;
public:
    Snail(int x, int xmax, int ymax); //initialize snail di posisi (x, ymaxpos)
    int moveToCoin(List<Coin>& Lcoin, double sec_since_last); //Bergerak menuju koin paling dekat dasar (y = ymax dibanding koin lain)
    Coin * findMaxY(List<Coin>& Lcoin); //mengembalikan addr coin dengan y maksimum.
    int catchCoin(List<Coin>& Lcoin); //menghapus koin dari list koin yang ada apabila berada di dekat snail.
    char getDirection();
};

#endif

