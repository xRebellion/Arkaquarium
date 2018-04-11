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
    List<T> *Head;
    List<T> *Next;
public:
    List();
    int find (T elmt);
    bool isEmpty();
    void add (T * elmt);
    void remove (T elmt);
    T get(int index);
    T * getDataAddr(int index);
    List<T> * getAddr(int index);
};

template <class T>
List<T>::List()
{
    data = nullptr;
    Head = nullptr;
    Next = nullptr;
}


template <class T>
int List<T>::find(T elmt)
//Jika tidak ditemukan, maka mereturn -1 sebagai value.
{
    int i;
    List<T> * currList = Head;
    for(i = 0; currList->Next != nullptr && currList->data != &elmt && *(currList->data) != elmt ; i++)
    {
        currList = currList->Next;
    }

    if(currList->Next == nullptr && (currList->data != &elmt && *(currList->data) != elmt))
    {
        return -1;
    }
    else
        return i;
}

template <class T>
bool List<T>::isEmpty()
{
    return (Head == nullptr);
}

template<class T>
void List<T>::add (T * elmt)
{
    List<T> * currList = Head;
    if (isEmpty())
    {
        Head = this;
        data = elmt;
        Next = nullptr;
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
    if (!isEmpty())
    {
        List<T> * currList = Head;
        if(currList->data == &elmt || *(currList->data) == elmt)
        {
            Head = currList->Next;
        } else
        {
            while (currList->Next != nullptr && currList->Next->data != &elmt && *(currList->Next->data) != elmt)
            {
                currList = currList->Next;
            }
            if(currList->Next->data == &elmt || *(currList->Next->data) == elmt)
            {
                //List<T>*temp = currList->Next;
                currList->Next = currList->Next->Next;
                //delete temp;
            }
        }
    }
}

template <class T>
T List<T>::get(int index)
{
    List<T> * currList = Head;
    
    for (int i = 0; i < index; i++)
    {
        currList = currList->Next;
    }
    return *(currList->data);
    
    
}

template <class T>
T * List<T>::getDataAddr(int index)
{
    List<T> * currList = Head;
    
    for (int i = 0; i < index; i++)
    {
        currList = currList->Next;
    }
    return currList->data;
    
    
}

template <class T>
List<T> * List<T>::getAddr(int index)
{
    if(!isEmpty())
    {
        List<T> * currList = Head;
        for (int i = 0; i < index && currList != nullptr; i++)
        {
            currList = currList->Next;
        }
        return currList;
    }
    return nullptr;
}
#endif