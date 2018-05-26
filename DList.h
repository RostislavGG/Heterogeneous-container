#ifndef DLIST_H
#define DLIST_H
#include "Container.h"
#include <iostream>
#include <vector>

template <typename T>
class DList : public Container<T>
{
    Box<T>* start;
    Box<T>* end;
    int size;
    char type;
public:
    DList();
    DList(std::vector<T> &v);
    void push(const T& x);
    void pop();
    T top();
    void print() const;
    bool member(const T& x);
    int getSize();
    void filter(bool (*condition) (const T&));
    void toText() const;
    bool conditionSearch (bool (*condition) (const T&));
    void sort();
};

template <typename T>
DList<T>::DList(std::vector<T> &v)
{
    DList();
    int counter = 0;
    while (!v.empty())
    {
        push(v[counter]);
        counter++;
    }
}

template <typename T>
DList<T>::DList()
{
    start = nullptr;
    end = nullptr;
    size = 0;
    type = 'D';
}

template <typename T>
void DList<T>::push(const T& x)
{
    if (start == nullptr && end == nullptr)
    {
        Box<T>* n = new Box<T>(x, nullptr, nullptr);
        start = n;
        end = n;
    }
    else
    {
        Box<T>* c = new Box<T>(x, nullptr, nullptr);
        c->prev = end;
        end->next = c;
        end = c;
    }
    size++;
}

template <typename T>
void DList<T>::pop()
{
    if (start == end)
    {
        start = nullptr;
        end = nullptr;
    }
    else
    {
        end = end->prev;
        end->next = nullptr;
    }
    size--;
}

template <typename T>
T DList<T>::top()
{
    return end->data;
}

template <typename T>
void DList<T>::print() const
{
    Box<T>* b = start;
    std::cout << "D" << " ";
    while (b != nullptr)
    {
        std::cout << b->data << " ";
        b = b->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool DList<T>::member(const T& x)
{
    Box<T>* b = start;
    while (b != nullptr)
    {
        if (b->data == x)
            return true;
        b = b->next;
    }
    return false;
}

template <typename T>
int DList<T>::getSize()
{
    return size;
}

template <typename T>
void DList<T>::filter(bool (*condition) (const T& x))
{
    Box<T>* crr = start;
    while (crr->next != nullptr)
    {
        if (condition(crr->data) == false)
        {
            if (crr == start)
            {
                start = crr->next;
                start->prev = nullptr;
            }
            else
            {
                crr->next->prev = crr->prev;
                crr->prev->next = crr->next;
            }
            size--;
        }
        crr = crr->next;
    }
    if (condition(crr->data) == false)
    {
        end = crr->prev;
        crr->prev->next = nullptr;
        size--;
    }
}

template <typename T>
void DList<T>::toText() const
{
    std::ofstream out ("Containers.txt", std::fstream::app);
    Box<T>* d = start;
    out << type << " ";
    while (d != nullptr)
    {
        out << d->data << " ";
        d = d->next;
    }
    out << std::endl;
    out.close();
}

template <typename T>
bool DList<T>::conditionSearch(bool (*condition) (const T&))
{
    Box<T>* crr = start;
    while (crr != nullptr)
    {
        if (condition(crr->data))
            return true;
        crr = crr->next;
    }
    return false;
}

template <typename T>
void DList<T>::sort()
{
    std::vector<T> numbs;
    Box<T>* crr = start;
    while (crr != nullptr)
    {
        numbs.push_back(crr->data);
        crr = crr->next;
    }
    Sort(numbs);
    crr = start;
    for (unsigned int i = 0; i < numbs.size(); i++)
    {
        crr->data = numbs[i];
        crr = crr->next;
    }
}


#endif // DLIST_H
