#ifndef COIN_HPP
#define COIN_HPP
#include "Position.hpp"
#include <cstddef>
class Coin : public Position
{
private:
    int value;
    int id;
    static int n_coin;
public:
    Coin();
    Coin(int x, int y, int val, int xmax, int ymax); //memunculkan sebuah koin dengan posisi x y dengan value val.
    void moveDown(); //bergerak ke bawah secara terus menerus hingga sampai bawah.
    bool isOnBottom() const; //mengecek apakah koin sudah sampai bawah (y = yMaxPos) atau belum.
    //getter setter
    int getValue() const;
    void setValue(int val);

    bool operator==(const Coin& C);
    bool operator==(std::nullptr_t n);



};
#endif
