#include "Position.hpp"
class Coin : public Position
{
private:
    int value;
public:
    Coin(int x, int y, int val); //memunculkan sebuah koin dengan posisi x y dengan value val.
    void moveDown(); //bergerak ke bawah secara terus menerus hingga sampai bawah.
    bool isOnBottom() const; //mengecek apakah koin sudah sampai bawah (y = yMaxPos) atau belum.

    //getter setter
    int getValue() const;
    void setValue(int val);
};
