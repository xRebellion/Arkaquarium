#include "Ikan.hpp"
#include "Makanan.hpp"
#include "List.hpp"

class Guppy : public Ikan
{
public:
	Guppy(int x, int y, int xmax, int ymax);
	void move(); //Menentukan kemanakah dia harus bergerak.
	bool checkFood(List<Makanan>& makanan); // Mengecek apakah ada makanan ikan di sekitar guppy.
	void eat(List<Makanan>& makanan); //Memakan makanan di sekitar guppy.

	bool checkSpitCoin(); //Mengecek apakah ikan boleh mengeluarkan koin atau belum
	void spitCoin(List<Coin>& Lcoin); // Membuat ikan mengeluarkan coin
};
