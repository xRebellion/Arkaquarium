#include "Makanan.hpp"
int Makanan::n_makanan = 0;

Makanan::Makanan():Position(0,0,0,0),speed(2)
{
    id_makanan = -999;
}
Makanan::Makanan(int x, int y, int xmax, int ymax):Position(x,y,xmax,ymax),speed(25)
{
    id_makanan = n_makanan;
    n_makanan++;
}
void Makanan::moveDown(double sec_since_last)
{
    setY(getY() + speed*sec_since_last);
}
bool Makanan::isOnBottom()
{
    return getY() > getYMax();
}

int Makanan::getID()
{
    return id_makanan;
}

bool Makanan::operator==(const Makanan& M)
{
    return this->id_makanan == M.id_makanan;
}
bool Makanan::operator!=(const Makanan& M)
{
    return this->id_makanan != M.id_makanan;
}
bool Makanan::operator==(std::nullptr_t n)
{
    return id_makanan == -999;
}

Makanan Makanan::operator=(const Makanan& M)
{
    id_makanan = M.id_makanan;
    setX(M.getX());
    setY(M.getY());
    setXMax(M.getXMax());
    setYMax(M.getYMax());
    return *this;
}