#include <Position.hpp>
#include <stdlib.h>
	//Initialize (Randomized) 
	Position::Position(int xMaxPos, int yMaxPos) {	
		srand(time(NULL));
		x = rand() % xMaxPos;
		y = rand() % yMaxPos;
	}
	//Initialize (x,y)
	Position::Position (int x, int y, int xMaxPos, int yMaxPos) {
		this->x = x;
		this->y = y;
		this->xMaxPos = xMaxPos;
		this->yMaxPos = yMaxPos;
	} 
	//get X
    int Position::getX() const {
    	return x;
    }
    //get Y
    int Position::getY() const {
    	return y;
    }
    // set X
    void Position::setX(int x) {
    	this->x = x;
    }
    // set Y
    void Position::setY(int y) {
    	this->y = y;
    }