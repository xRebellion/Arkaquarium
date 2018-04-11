#include "Makanan.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

// Constructor Test
int main()
{
    Makanan B(50,50,100,100);
    // Getter Test
    cout << B.getID() << endl;

    // Move Down Test
    while (!B.isOnBottom()) {
        cout << B.getY() << "; ";
        B.moveDown(1);
    }
    cout << endl;
}


