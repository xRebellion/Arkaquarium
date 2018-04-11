#include "Piranha.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;
int main(){

    // Constructor Test
    Piranha A();
    Piranha B(50,50,100,100);

    // Spit Coin Test
    while (!B.checkSpitCoin()){
        cout << B.coin_tick_rate << endl;
    }
    if (B.checkSpitCoin()){
        B.spitCoin();
        cout << B.coin_tick_rate << endl;
    }

    // Operator Test
    cout << A==B << endl;
    cout << A!=B << endl;
}

