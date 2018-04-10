#include "Coin.hpp"
#include <stdlib.h>
int Coin::n_coin = 0;

Coin::Coin():Position(0,0,0,0),speed(1) {
    id = -999;
    value = 0;
}
//memunculkan sebuah koin dengan posisi x y dengan value val.
Coin::Coin(int x, int y, int val, int xmax, int ymax):Position(x, y, xmax, ymax),speed(38) {
    value = val;
    id = n_coin;
    n_coin++;
}
//bergerak ke bawah secara terus menerus hingga sampai bawah.
void Coin::moveDown(double sec_since_last) {
    setY(getY()- speed*sec_since_last);
}
//mengecek apakah koin sudah sampai bawah (y = yMaxPos) atau belum.
bool Coin::isOnBottom() const {
    return getY() > getYMax();
}
//getter setter
int Coin::getValue() const {
    return value;
}
int Coin::getID() {
    return id;
}
int Coin::getNcoin()
{
    return n_coin;
}
void Coin::setValue(int val) {
    value = val;
}

bool Coin::operator==(const Coin& C) {
    return this->id == C.id;
}
bool Coin::operator!=(const Coin& C) {
    return this->id != C.id;
}
bool Coin::operator==(std::nullptr_t n) {
    return this->id == -999;
}