#include <iostream>
#include <stdexcept>
#include<clocale>
using namespace std;
class ListElem
{
public:
    int inf;
    ListElem* next;
    ListElem(int inform)
    {
        inf = inform;
        next = NULL;
    }
};

class List
{
    ListElem* first;

    ListElem* last;
    
    size_t size;

    ListElem* find(size_t index)
    {
        if (index == 0)
        {
            return first;
        }
        else if (index == (size - 1))
        {
            return last;
        }
        else
        {
            ListElem* Search = first;
            for (int i = 0;i < index;i++)
            {
                Search = Search->next;
            }
            return Search;
        }
    }

public:

    List()
    {
        first = NULL;
        last = first;
        size = 0;
    }

    void push_back(int inf)
    {
        ListElem* New = new ListElem(inf);
        if (last == NULL)
        {
            last = New;
            first = last;
        }
        else
        {
            last->next = New;
            last = last->next;
        }
        size++;
    }

    void push_front(int inf)
    {
        ListElem* New = new ListElem(inf);
        if (last == NULL)
        {
            last = New;
            first = last;
        }
        else
        {
            New->next = first;
            first = New;
        }
        size++;
    }

    void pop_back()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                delete last;
                first = NULL;
                last = first;
            }
            else
            {
                ListElem* newlast = first;
                while (newlast->next != last)
                    newlast = newlast->next;
                delete last;
                last = newlast;
            }
            size--;
        }
        else
        {
            throw runtime_error("Ошибка: список пуст");
        }
    }

    void pop_front()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                delete last;
                first = NULL;
                last = first;
            }
            else
            {
                ListElem* newfirst = first->next;
                delete first;
                first = newfirst;
            }
            size--;
        }
        else
        {
            throw runtime_error("Ошибка: список пуст");
        }
    }

    void insert(size_t index, int inf)
    {
        if (index == 0)
        {
            push_front(inf);
        }
        else if (index == size)
        {
            push_back(inf);
        }
        else if (index < size)
        {
            ListElem* New = new ListElem(inf);
            ListElem* Prev = first;
            ListElem* Next = Prev->next;
            for (int i = 0;i < index-1;i++)
            {
                Prev = Prev->next;
                Next = Prev->next;
            }
            Prev->next = New;
            New->next = Next;
            size++;
        }
        else
        {
            throw out_of_range("Ошибка: элемента с таким индексом не существует");
        }
    }

    int at(size_t index)
    {
        if (index < size)
        {
            return find(index)->inf;
        }
        else
        {
            throw out_of_range("Ошибка: элемента с таким индексом не существует");
        }
    }

    void remove(size_t index)
    {
        if (index >= size)
        {
            throw out_of_range("Ошибка: элемента с таким индексом не существует");
        }
        else if (index == (size - 1))
        {
            pop_back();
        }
        else if (index == 0)
        {
            pop_front();
        }
        else
        {
            ListElem* Prev = find(index - 1);
            ListElem* Remove = Prev->next;
            ListElem* Next = Remove->next;
            Prev->next = Next;
            delete Remove;
            size--;
        }   
    }

    size_t get_size()
    {
        return size;
    }

    void print_to_console()
    {
        ListElem* Cur = first;
        while (Cur != NULL)
        {
            cout << Cur->inf << ' ';
            Cur = Cur->next;
        }
        cout << endl;
    }
    
    bool isEmpty()
    {
        if (first == NULL)
            return true;
        else
            return false;
    }

    void clear()
    {
        while (!isEmpty())
            pop_front();
    }

    void set(size_t index, int inf)
    {
        if (index >= size)
        {
            throw out_of_range("Ошибка: элемента с таким индексом не существует");
        }
        else
        {
            find(index)->inf = inf;
        }
    }

    void swap(size_t index1, size_t index2)
    {
        if ((index1 >= size) || (index2 >= size))
        {
            throw out_of_range("Ошибка: элемента с таким индексом не существует");
        }
        else
        {
            int temp;
            ListElem* E1 = find(index1);
            ListElem* E2 = find(index2);
            temp = E1->inf;
            E1->inf = E2->inf;
            E2->inf = temp;
        }
    }

    ~List()
    {
        clear();
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    List L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.print_to_console();
    L.swap(2, 4);
    L.print_to_console();
    try
    {
        L.swap(10, 11);
    }
    catch (exception& exception)
    {
        cout << exception.what() << endl;
    }
}