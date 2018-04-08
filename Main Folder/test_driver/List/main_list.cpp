//Driver List
#include "List.hpp"
//#include "Guppy.hpp"
//#include "Piranha.hpp"
#include <iostream>
using namespace std;

int main()
{
    //List<Guppy> g;
    //List<Piranha> p;
    List<int> iL;
    int x = 10;
    int y = 20;
    cout << x << " " << y << endl;
    iL.add(&x);
    iL.add(&y);
    cout << iL.get(0) << " " << iL.get(1) << endl;
    x = 40;
    y = 50;
    cout << iL.get(0) << " " << iL.get(1) << endl;
    cout << x << " " << y << endl;
    x = 100;
    y = 100;
    cout<< iL.find(40) << endl;
}