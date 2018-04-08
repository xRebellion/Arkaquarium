#ifndef POSITION_HPP
#define POSITION_HPP
class Position
{
private:
    double x;
    double y;
    int xMaxPos, yMaxPos;
public:
    Position(int xMaxPos, int yMaxPos);//Initialize (Randomized)
    Position (double x, double y, int xMaxPos, int yMaxPos); //Initialize (x,y)
    double getX() const; //get X
    double getY() const; //get Y
    int getXMax() const;
    int getYMax() const;
    void setX(double x);// set X
    void setY(double y);// set Y
    void setXMax(int xMax);
    void setYMax(int yMax);
};


#endif