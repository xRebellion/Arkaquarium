#include "Snail.hpp"
#include <math.h>
	//initialize snail di posisi (x, ymaxpos)
    Snail::Snail(int x, int xmax, int ymax):Position(x,ymax,xmax,ymax),catchRadius(75),speed(80) {
    }
    //Bergerak menuju koin paling dekat dasar (y = ymax dibanding koin lain)	
    int Snail::moveToCoin(List<Coin>& Lcoin, double sec_since_last) {
    	if (!Lcoin.isEmpty()) {
    		Coin * TargetCoin;
    		TargetCoin = findMaxY(Lcoin);
			double a = atan2(0,(*TargetCoin).getX()-this->getX());
			double xdir = speed*cos(a)*sec_since_last; 
			if(xdir < 0 && (abs((*TargetCoin).getX()-this->getX()) > 10)) direction = 'L'; else direction = 'R';
    		if(abs((*TargetCoin).getX()-this->getX()) > 10) setX(getX() + xdir);
			return catchCoin(Lcoin);
    	} 
    }
    //mengembalikan index dengan y maksimum.
    Coin * Snail::findMaxY(List<Coin>& Lcoin) {
    	double iMinDist = 0;
	    double minDist = getYMax()- (*Lcoin.getDataAddr(0)).getY();
	    for(int i = 0; Lcoin.getAddr(i) != nullptr; i++) {
	        
	        double dist = getYMax()-(*Lcoin.getDataAddr(i)).getY();
	        if(minDist > dist) {
	            minDist = dist;
	            iMinDist = i;
	        }
   		}
    	return Lcoin.getDataAddr(iMinDist);
    }

    //menghapus koin dari list koin yang ada apabila berada di dekat snail.
    int Snail::catchCoin(List<Coin>& Lcoin) {
    	Coin *TargetCoin;
    	double distance;
		int coinVal = 0;
    	TargetCoin = findMaxY(Lcoin);
    	distance = sqrt(pow(getX() - (*TargetCoin).getX() ,2) + pow(getY() - (*TargetCoin).getY(), 2));
    	if (distance < catchRadius) {
			coinVal = (*TargetCoin).getValue();
    		Lcoin.remove(*TargetCoin);
			delete TargetCoin;
    	}
		return coinVal;
    }
	char Snail::getDirection()
	{
		return direction;
	}