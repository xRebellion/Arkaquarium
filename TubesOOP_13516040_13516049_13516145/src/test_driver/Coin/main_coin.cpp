#include "Coin.hpp"
#include <iostream>
using namespace std;

int main()
{
    Coin C (10,10,10,10,10);
    cout <<"Coin created: (x,y,val,xmax,ymax) = (" << C.getX() << "," << C.getY() << "," 
    << C.getValue() << "," <<C.getXMax() << "," <<C.getYMax() <<")" << endl;

    cout <<"Coin ID: " << C.getID() << endl;
    cout <<"NCoin: " << C.getNcoin() << endl;

    Coin C2 (0,0,55,800,600);
    cout <<"Coin created: (x,y,val,xmax,ymax) = (" << C2.getX() << "," << C2.getY() << "," 
    << C2.getValue() << "," <<C2.getXMax() << "," <<C2.getYMax() <<")" << endl;

    cout <<"Coin ID: " << C2.getID() << endl;
    cout <<"NCoin: " << C2.getNcoin() << endl;

    cout << endl;

    cout << "Movement: " << endl;
    C2.moveDown(1);
    cout <<"C2: (x,y,val,xmax,ymax) = (" << C2.getX() << "," << C2.getY() << "," 
    << C2.getValue() << "," <<C2.getXMax() << "," <<C2.getYMax() <<")" << endl;

    return 0;
}