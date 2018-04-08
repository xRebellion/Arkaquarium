#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "Ikan.hpp"
#include "Makanan.hpp"
#include "List.hpp"


class Guppy : public Ikan
{
private: 
	static int n_guppy;

public:
	Guppy();
	Guppy(int x, int y, int xmax, int ymax);
	void move(List<Makanan>& makanan, double sec_since_last); //Menentukan kemanakah dia harus bergerak.
	bool checkFood(List<Makanan>& makanan); // Mengecek apakah ada makanan ikan di sekitar guppy.
	void eat(List<Makanan>& makanan); //Memakan makanan di sekitar guppy.

	bool checkSpitCoin(); //Mengecek apakah ikan boleh mengeluarkan koin atau belum
	void spitCoin(List<Coin>& Lcoin); // Membuat ikan mengeluarkan coin
	Makanan * findNearestFood(List<Makanan>& makanan);

	bool operator== (const Guppy& G);
	bool operator==(std::nullptr_t n);
	Guppy operator=(const Guppy& G);
};
#endif