#include "Guppy.hpp"
#include "Piranha.hpp"
#include "List.hpp"
#include "Makanan.hpp"
#include "Coin.hpp"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>

using namespace std;
int main(){

    // Constructor Test
    double tick_rate = 0;
    const double sec = 0.01;
    Piranha P(50,50,100,100);
    List<Guppy> g;
    List<Coin> c;
    
    g.add(new Guppy(75,75,100,100));
    P.reduceHunger(10);
    cout <<"Is there guppy = "<<!g.isEmpty() << endl;
    while (tick_rate < 0.5)
    {
        tick_rate += sec;
        P.move(g,c,sec);
        cout << "Piranha Current Pos = " << P.getX() <<" " << P.getY() <<endl;
    }
    
    
    cout <<"Is there guppy = "<<!g.isEmpty() << endl;
    cout <<"Is there coin = "<<!c.isEmpty()<< endl;
    //expected output: coin is not empty.
    

    // Operator Test
    
}

