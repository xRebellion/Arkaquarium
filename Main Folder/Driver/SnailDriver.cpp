//Driver List
#include "Snail.hpp"
#include "List.hpp"
#include "Coin.hpp"
#include <iostream>
using namespace std;

int main()
{
    
    Snail Gary = new Snail(100,200,200,200);
    List<Coin> Lcoin;
    Coin *C1 = new Coin(100, 10, 200, 200);
    Coin *C2 = new Coin(50, 10, 200, 200);
    Lcoin.add(C1);
    Lcoin.add(C2);
    while (!Lcoin.isEmpty()) {
        Gary.moveToCoin(Lcoin);
    }
    cout << "============================================================="<<endl;
    
    return 0;
    
}