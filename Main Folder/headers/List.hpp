#define NULL 0
template <class T>
class List
{
private:
    T data;
    List *Next;
public:
    List();
    List(T Head);
    int find (T elmt);
    bool isEmpty();
    void add (T elmt);
    void remove (T elmt);
    T get(int index);
};

template <class T>
List<T>::List()
{
    data = NULL;
    Next = NULL;
}


template <class T>
int List<T>::find(T elmt)
//Jika tidak ditemukan, maka mereturn -1 sebagai value.
{
    int i;
    for(i = 0; Next != NULL && data != elmt ; i++)
    {

    }
    if(Next == NULL && data != elmt)
        return -1;
    else
        return i;
}

template <class T>
bool List<T>::isEmpty()
{
    return (data == NULL && Next == NULL);
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
        while(currList->Next != NULL)
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
    while (currList->Next != NULL && !found)
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
