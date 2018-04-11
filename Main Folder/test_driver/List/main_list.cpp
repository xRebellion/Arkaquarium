//Driver List
#include "List.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include <iostream>
using namespace std;

int main()
{
    
    List<Guppy> g;
    List<Piranha> p;
    Guppy * G = new Guppy(100,100,200,200);
    Guppy * G2 = new Guppy(100,200,200,100);
    Guppy * G3 = new Guppy(2,3,4,5);
    g.add(G);
    for(int i = 0; g.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(g.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    g.add(G2);
    for(int i = 0; g.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(g.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    g.add(G3);
    for(int i = 0; g.getAddr(i) != nullptr ; i++)
    {   
        cout << (*(g.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    cout <<"Find(G3) = " << g.find(*G3) << endl;
    g.remove(*G2);
    for(int i = 0; g.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(g.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    g.add(G3);
    for(int i = 0; g.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(g.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    g.remove(*G3);
    for(int i = 0; g.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(g.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    g.remove(*G3);
    for(int i = 0; g.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(g.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    g.remove(*G);
    for(int i = 0; g.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(g.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;

    cout << "============================================================="<<endl;

    Piranha * P = new Piranha(100,100,200,200);
    Piranha * P2 = new Piranha(100,200,200,100);
    Piranha * P3 = new Piranha(2,3,4,5);
    p.add(P);
    for(int i = 0; p.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(p.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    p.add(P2);
    for(int i = 0; p.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(p.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    p.add(P3);
    for(int i = 0; p.getAddr(i) != nullptr ; i++)
    {   
        cout << (*(p.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    cout <<"Find(P3) = " << p.find(*P3) << endl;
    p.remove(*P2);
    for(int i = 0; p.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(p.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    p.add(P3);
    for(int i = 0; p.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(p.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    p.remove(*P3);
    for(int i = 0; p.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(p.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    p.remove(*P3);
    for(int i = 0; p.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(p.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;
    p.remove(*P);
    for(int i = 0; p.getAddr(i) != nullptr ; i++)
    {        
        cout << (*(p.getDataAddr(i))).getID() << " ";
    }
    cout<<endl;

    cout << "============================================================="<<endl;
    
    return 0;
    
}