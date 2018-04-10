#ifndef IKAN_HPP
#define IKAN_HPP

#include "Position.hpp"
#include "CoinSpit.hpp"
#include <math.h>


class Ikan : public Position, public CoinSpit
{
protected:
	int growthStage;
	int growth;
	const int growthThreshold;
	const int catchRadius;
	char direction;
	int hunger;
	const int hungerThreshold;
	const int spd;
	int id;
	double move_tick_rate;
	double coin_tick_rate;
	double xdest, ydest;
public:
    Ikan(int x, int y, int xmax, int ymax,int gThreshold, int cRadius, int hThreshold, int spd, int id); // Generates a fish
	
    void checkGrow(); //Mengecek apakah growth > growthThreshold dan growthStage < 3. Jika iya, tambahkan growthstage.
	void moveTo(int x, int y, double sec_since_last); //Bergerak ke suatu posisi tertentu
	
	bool isHungry(); //Apakah ikan kelaparan atau tidak (hunger > hungerThreshold?)
	bool checkDeath(); //Mengecek apakah ikan sudah seharusnya mati atau tidak (hunger > 0?)
	void reduceHunger(double sec); //Periodically reduce hunger
	int getID();
	
	//
};

#endif