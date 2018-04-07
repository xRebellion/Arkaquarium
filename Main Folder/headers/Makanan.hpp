#include "Position.hpp"
#include "List.hpp"
class Makanan: public Position
{
private:
    const int speed;
public:
    Makanan(int x, int xmax, int ymax, int spd); //selalu muncul di y = 0
    void moveDown();//bergerak ke bawah secara terus menerus hingga sampai bawah.
    bool isOnBottom(); //mengecek apakah makanan sudah di y = ymaxpos atau belum.
    void checkAndErase(List<Makanan>& makanan); //Kalau sudah, hapus dari list of makanan. (kalau di paling bawah saja)

};
