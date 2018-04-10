#ifndef AKUARIUM_HPP
#define AKUARIUM_HPP
#include "List.hpp"
#include "Coin.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include "Makanan.hpp"
#include "Snail.hpp"

class Akuarium
{
private:
    /**List of entities**/
    List<Coin> coin;
    List<Guppy> guppy;
    List<Piranha> piranha;
    List<Makanan> makanan;
    /********************/
    Snail * snail;
    //Max Aquarium size
    int xMaxSize, yMaxSize;
    int money;

public:
    Akuarium(int xMax,int yMax);//Inisialisasi akuarium dengan randomisasi posisi setiap entitas (sebesar (xmax ymax))
    //mereturn array of char.
    //'C' untuk koin pada arr[0]
    //'G' untuk guppy pada arr[1]
    //'P' untuk piranha pada arr[2]
    //'M' untuk makanan pada arr[3]
    //digunakan array untuk mengcover kemungkinan 2 object di tempat yang sama.

    void AddToAkuarium(Guppy * G);
    void AddToAkuarium(Piranha * P);
    void AddToAkuarium(Coin * C);
    void AddToAkuarium(Makanan * M);
    List<Coin> * getCList();
    List<Guppy> * getGList();
    List<Piranha> * getPList();
    List<Makanan> * getMList();
    Snail * getSnail();
    int getMoney();
    void setMoney(int money);
    //List yang direturn ini bisa diubah sekaligus - karena berupa reference.
    
    void update(double sec_since_last);
    //Updates all of the objects in the lists


};
#endif