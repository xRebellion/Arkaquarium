#ifndef IKAN_HPP
#define IKAN_HPP

#include "Position.hpp"
#include "CoinSpit.hpp"

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
public:
    Ikan(int x, int y, int xmax, int ymax,int gThreshold, int cRadius, int hThreshold, int spd); // Generates a fish
	
	virtual void move() = 0; //Menentukan pergerakan ikan berdasarkan hunger, makanan ikan, dst.

    void checkGrow(); //Mengecek apakah growth > growthThreshold dan growthStage < 3. Jika iya, tambahkan growthstage.
	void moveTo(int x, int y); //Bergerak ke suatu posisi tertentu
	
	bool isHungry(); //Apakah ikan kelaparan atau tidak (hunger > hungerThreshold?)
	bool checkDeath(); //Mengecek apakah ikan sudah seharusnya mati atau tidak (hunger > 0?)
	void reduceHunger(); //Periodically reduce hunger
	
	
	//
};

#endif