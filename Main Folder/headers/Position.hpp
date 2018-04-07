class Position
{
private:
    int x;
    int y;
    int xMaxPos, YMaxPos;
public:
    Position(int xMaxPos, int yMaxPos);//Initialize (Randomized)
    Position (int x, int y, int xMaxPos, int yMaxPos); //Initialize (x,y)
    int getX() const; //get X
    int getY() const; //get Y
    void setX(int x);// set X
    void setY(int y);// set Y
};


