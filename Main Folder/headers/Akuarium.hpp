#ifndef AKUARIUM_HPP
#define AKUARIUM_HPP
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
    char * GetObjOnPos(int x, int y); //Mencari objek pada x y sekian pada setiap list of object
    //mereturn array of char.
    //'C' untuk koin pada arr[0]
    //'G' untuk guppy pada arr[1]
    //'P' untuk piranha pada arr[2]
    //'M' untuk makanan pada arr[3]
    //digunakan array untuk mengcover kemungkinan 2 object di tempat yang sama.

    List<Coin> GetCoinList();
    List<Guppy> GetGuppyList();
    List<Piranha> GetPiranhaList();
    List<Makanan> GetMakananList();
    //List yang direturn ini bisa diubah sekaligus - karena berupa reference.
    
    void update(double sec_since_last);
    //Updates all of the objects in the lists


};
#endif