#include "Position.hpp"
#include <iostream>
using namespace std;
int main()
{
    Position P(10,10,800,600);
    cout <<"Pos Created (x,y,xmax,ymax) = ("<< P.getX() << "," << P.getY() << "," 
    << P.getXMax() << "," <<P.getYMax() <<")" << endl;

    P.setX(150);
    P.setY(350);
    P.setXMax(1000);
    P.setYMax(1000);

    cout <<"P (x,y,xmax,ymax) = ("<< P.getX() << "," << P.getY() << "," 
    << P.getXMax() << "," <<P.getYMax() <<")" << endl;

}