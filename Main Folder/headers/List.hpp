#ifndef LIST_HPP
#define LIST_HPP
template <class T>
class List
{
private:
    T data;
    List<T> *Next;
public:
    List();
    int find (T elmt);
    bool isEmpty();
    void add (T elmt);
    void remove (T elmt);
    T get(int index);
    List<T> * getNext(int index);
};

template <class T>
List<T>::List()
{
    Next = nullptr;
}


template <class T>
int List<T>::find(T elmt)
//Jika tidak ditemukan, maka mereturn -1 sebagai value.
{
    int i;
    for(i = 0; Next != nullptr && data != elmt ; i++)
    {

    }
    if(Next == nullptr && data != elmt)
        return -1;
    else
        return i;
}

template <class T>
bool List<T>::isEmpty()
{
    return (data == nullptr && Next == nullptr);
}

template <class T>
void List<T>::add(T elmt)
{
    List * currList = this;
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
    List * currList = this;
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
    List * currList = this;
    
    for (int i = 0; i < index; i++)
    {
        currList = currList->Next;
    }
    return currList->data;
    
    
}

template <class T>
List<T> * List<T>::getNext(int index)
{
    List * currList = this;
    
    for (int i = 0; i < index; i++)
    {
        currList = currList->Next;
    }
    return currList->Next;
}
#endif