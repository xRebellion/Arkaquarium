#ifndef MAKANAN_HPP
#define MAKANAN_HPP
#include "Position.hpp"
#include "List.hpp"
class Makanan: public Position
{
private:
    const int speed;
    int id_makanan;
    static int n_makanan;

public:
    Makanan();
    Makanan(int x, int y, int xmax, int ymax); //selalu muncul di y = 0
    void moveDown();//bergerak ke bawah secara terus menerus hingga sampai bawah.
    bool isOnBottom(); //mengecek apakah makanan sudah di y = ymaxpos atau belum.
    void checkAndErase(List<Makanan>& makanan); //Kalau sudah, hapus dari list of makanan. (kalau di paling bawah saja)

    bool operator==(const Makanan& M);
};
#endif