#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Box.h"
#include "Stack.h"
#include "Queue.h"
#include "DList.h"
#include "Container.h"
#include "List.h"

bool odd(const int &x)
{
    if (x % 2 == 0)
        return false;
    else
        return true;
}

template <typename T>
void Sort(std::vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        for (int j = 0; j < (int)v.size()-1; j++)
        {
            T temp;
            if (v[j] > v[j+1])
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

int main()
{
    /// TESTS
    /*
    Container<int>* s = new Stack<int>();
    for (int i = 0; i < 10; i++)
        s->push(i);
    s->push(0);
    s->push(2);
    s->push(0);
    s->print();
    s->filter(odd);
    s->print();

    Container<int>* q = new Queue<int>();
    for (int i = 10; i < 20; i += 2)
        q->push(i);
    q->print();
    q->pop();
    q->push(1);
    q->print();
    //q->toText();
    q->filter(odd);
    q->print();
    std::cout << q->member(0) << std::endl;

    Container<int>* d = new DList<int>();
    for (int i = 1; i < 20; i+= 2)
        d->push(i);
    d->pop();
    d->push(2);
    d->filter(odd);
    d->print();

    std::cout << "-------------------------------" <<std::endl;
    List<int>* l = new List<int>();
    l->add(s);
    l->add(q);
    l->add(d);
    l->printAll();
    l->sortAll();
    l->printAll();
    l->loadBalancing(1000);
    l->printAll();
    l->toTextAll();
    */

    return 0;
}
