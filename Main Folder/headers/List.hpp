#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
using namespace std;
//List Of References - supaya tidak perlu create object tak terpakai
//setiap kali menambah elemen linkedlist.
template <class T>
class List
{
private:
    T * data;
    List<T> *Next;
public:
    List();
    int find (T elmt);
    bool isEmpty();
    void add (T * elmt);
    void remove (T elmt);
    T get(int index);
    List<T> * getAddr(int index);
};

template <class T>
List<T>::List()
{
    data = nullptr;
    Next = nullptr;
}


template <class T>
int List<T>::find(T elmt)
//Jika tidak ditemukan, maka mereturn -1 sebagai value.
{
    int i;
    List<T> * currList = this;
    for(i = 0; Next != nullptr && (data != &elmt || *data != elmt) ; i++)
    {
        currList = currList->Next;
    }
    cout << "i went here";
    if(Next == nullptr && (data != &elmt && *data != elmt))
        return -1;
    else
        return i;
}

template <class T>
bool List<T>::isEmpty()
{
    return (data == nullptr && Next == nullptr);
}

template<class T>
void List<T>::add (T * elmt)
{
    List<T> * currList = this;
    if (isEmpty())
    {
        data = elmt;
    } else
    {
        while(currList->Next != nullptr)
        {
            currList = currList->Next;
        }
        currList->Next = new List();
        currList = currList->Next;
        currList->data = elmt;
    }
}

template <class T>
void List<T>::remove(T elmt)
{
    List<T> * currList = this;
    bool found = false;
    while (currList->Next != nullptr && !found)
    {
        if(currList->Next->data == elmt)
            found = true;
        else
            currList = currList->Next;
    }
    if(found)
    {
        currList->Next = currList->Next->Next;
    }
}

template <class T>
T List<T>::get(int index)
{
    List<T> * currList = this;
    
    for (int i = 0; i < index; i++)
    {
        currList = currList->Next;
    }
    return *(currList->data);
    
    
}

template <class T>
List<T> * List<T>::getAddr(int index)
{
    List<T> * currList = this;
    
    for (int i = 0; i < index; i++)
    {
        currList = currList->Next;
    }
    return currList;
}
#endif