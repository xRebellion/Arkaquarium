#include "Snail.hpp"
#include <math.h>
	//initialize snail di posisi (x, ymaxpos)
    Snail::Snail(int x, int xmax, int ymax):Position(x,ymax,xmax,ymax) {
    	catchRadius = 50;
    }
    //Bergerak menuju koin paling dekat dasar (y = ymax dibanding koin lain)	
    void Snail::moveToCoin(List<Coin> Lcoin) {
    	if (!Lcoin.isEmpty()) {
    		Coin *TargetCoin;
    		TargetCoin = findMaxY(Lcoin);
    		moveTo(TargetCoin.getX(),TargetCoin.getY(), sec_since_last);
    	} 
    }
    //mengembalikan index dengan y maksimum.
    int Snail::findMaxY(List<Coin> Lcoin) {
    	double iMinDist = 0;
	    double minDist = *Lcoin.getDataAddr(0).getY();
	    for(int i = 0; Lcoin.getAddr(i) != nullptr; i++) {
	        
	        double dist = *Lcoin.getDataAddr(i).getY()
	        if(minDist > dist) {
	            minDist = dist;
	            iMinDist = i;
	        }
   		}
    	return Lcoin.getDataAddr(iMinDist);
    }

    //menghapus koin dari list koin yang ada apabila berada di dekat snail.
    void Snail::catchCoin(List<Coin>& Lcoin) {
    	Coin *TargetCoin;
    	double distance;
    	TargetCoin = findMaxY(Lcoin);
    	distance = sqrt(pow(getX() - TargetCoin.getX() ,2) + pow(getY() - TargetCoin.getY(), 2));
    	if (distance < catchRadius) {
    		Lcoin.remove(*TargetCoin);
    	}
    }