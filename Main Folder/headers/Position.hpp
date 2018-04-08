#ifndef POSITION_HPP
#define POSITION_HPP
class Position
{
private:
    int x;
    int y;
    int xMaxPos, yMaxPos;
public:
    Position(int xMaxPos, int yMaxPos);//Initialize (Randomized)
    Position (int x, int y, int xMaxPos, int yMaxPos); //Initialize (x,y)
    int getX() const; //get X
    int getY() const; //get Y
    int getXMax() const;
    int getYMax() const;
    void setX(int x);// set X
    void setY(int y);// set Y
    void setXMax(int xMax);
    void setYMax(int yMax);
};


#endif