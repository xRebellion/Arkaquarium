#include "List.hpp"
#include "Coin.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include "Makanan.hpp"

class Akuarium
{
private:
    /**List of entities**/
    List<Coin> coin;
    List<Guppy> guppy;
    List<Piranha> piranha;
    List<Makanan> makanan;
    /********************/

    //Max Aquarium size
    int xMaxSize, yMaxSize;

public:
    Akuarium(int xMax,int yMax);//Inisialisasi akuarium dengan randomisasi posisi setiap entitas (sebesar (xmax ymax))
    char GetObjOnPos(int x, int y); //Mencari objek pada x y sekian pada setiap list of object
    //mereturn char. Misal: 'C' untuk koin, 'G' untuk guppy, dst.
};
