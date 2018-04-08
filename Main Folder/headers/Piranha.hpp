#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "Ikan.hpp"
#include "List.hpp"
#include "Guppy.hpp"
class Piranha : public Ikan
{
private:
	static int n_piranha;
public:
	Piranha();
	Piranha(int x, int y, int xmax, int ymax);
	void move(List<Guppy>& guppy, double sec_since_last); //Menentukan Piranha harus bergerak seperti apa.

	bool checkFood(List<Guppy>& guppy);
	void eat(List<Guppy>& guppy); //Memakan guppy
	Guppy findNearestFood(List<Guppy>& guppy);
	
	bool checkSpitCoin(); //Mengecek apakah ikan boleh mengeluarkan koin atau belum
	void spitCoin(List<Coin>& Lcoin); // Membuat ikan mengeluarkan coin
	bool operator== (const Piranha& P);
	bool operator==(std::nullptr_t n);
};
#endif