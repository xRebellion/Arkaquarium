#include "Akuarium.hpp"

int main()
{
    Akuarium akuarium(800,600);
    List<Coin> * coin = akuarium.getCList();
    List<Guppy> * guppy = akuarium.getGList();
    List<Piranha> * piranha = akuarium.getPList();
    List<Makanan> * makanan = akuarium.getMList();
    cout <<"empty coin = "<< (*coin).isEmpty() << endl;
    cout <<"empty guppy = "<< (*guppy).isEmpty() << endl;
    cout <<"empty piranha = "<< (*piranha).isEmpty() << endl;
    cout <<"empty makanan = "<< (*makanan).isEmpty() << endl;

    akuarium.AddToAkuarium(new Coin(10,10,10,10,10));
    akuarium.AddToAkuarium(new Guppy(10,10,10,10));
    akuarium.AddToAkuarium(new Piranha(10,10,10,10));
    akuarium.AddToAkuarium(new Makanan(10,10,10,10));

    cout <<"empty coin = "<< (*coin).isEmpty() << endl;
    cout <<"empty guppy = "<< (*guppy).isEmpty() << endl;
    cout <<"empty piranha = "<< (*piranha).isEmpty() << endl;
    cout <<"empty makanan = "<< (*makanan).isEmpty() << endl;

    akuarium.setMoney(10000);
    cout <<"money = "<< akuarium.getMoney()<<endl;
    akuarium.buyEgg();
    cout <<"buying egg."<<endl;
    cout <<"money = "<< akuarium.getMoney()<<endl;
    cout <<"egg bought = "<<akuarium.getEggBought()<<endl;
    cout <<"egg price = " << akuarium.getEggPrice()<<endl;
    

}