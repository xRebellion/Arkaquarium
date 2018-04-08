#include <Coin.hpp>
#include <stdlib.h>

    Coin::Coin():Position(0,0,0,0),speed(1) {
   		id = -999;
    }
    //memunculkan sebuah koin dengan posisi x y dengan value val.
    Coin::Coin(int x, int y, int val, int xmax, int ymax):Position(x, y, xmax, ymax),speed(1) {
    	id = n_coin;
    	n_coin++;
    }
    //bergerak ke bawah secara terus menerus hingga sampai bawah.
    void Coin::moveDown() {
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
    int Makanan::getID() {
    	return id;
	}
    void Coin::setValue(int val) {
    	value = val;
    }

    bool Coin::operator==(const Coin& C) {
    	return this->id == C.id;
    }
    bool Coin::operator==(std::nullptr_t n) {
    	return this->id == -999;
    }