#ifndef QUEUE_H
#define QUEUE_H
#include "Container.h"
#include <iostream>
#include <vector>

template <typename T>
class Queue : public Container<T>
{
    Box<T>* first;
    int size;
    char type;
public:
    Queue();
    Queue(std::vector<T>& v);
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
Queue<T>::Queue(std::vector<T> &v)
{
    Queue();
    int counter = 0;
    while (!v.empty())
    {
        push(v[counter]);
        counter++;
    }
}

template <typename T>
Queue<T>::Queue()
{
    first = nullptr;
    size = 0;
    type = 'Q';
}

template <typename T>
void Queue<T>::push(const T& x)
{
    if (first == nullptr)
    {
        Box<T>* b = new Box<T>(x, nullptr, nullptr);
        first = b;
    }
    else
    {
        Box<T>* c = new Box<T>(x, nullptr, nullptr);
        Box<T>* crr = first;
        while(crr->next != nullptr)
        {
            crr = crr->next;
        }
        crr->next = c;
        c->prev = crr;
    }
    size++;
}

template <typename T>
void Queue<T>::pop()
{
    first = first->next;
    first->prev = nullptr;
    size--;
}

template <typename T>
T Queue<T>::top()
{
    return first->data;
}

template <typename T>
void Queue<T>::print() const
{
    Box<T>* crr = first;
    std::cout << "Q ";
    while (crr != nullptr)
    {
        std::cout << crr->data << " ";
        crr = crr->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool Queue<T>::member(const T& x)
{
    Box<T>* b = first;
    while (b != nullptr)
    {
        if (b->data == x)
            return true;
        b = b->next;
    }
    return false;
}

template <typename T>
int Queue<T>::getSize()
{
    return size;
}

template <typename T>
void Queue<T>::filter(bool (*condition) (const T& x))
{
    Box<T>* crr = first;
    while (crr->next != nullptr)
    {
        if (condition(crr->data) == false)
        {
            if (crr == first)
            {
                first = crr->next;
                first->prev = nullptr;
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
        crr->prev->next = nullptr;
        size--;
    }
}

template <typename T>
void Queue<T>::toText() const
{
    std::ofstream out ("Containers.txt", std::fstream::app);
    Box<T>* q = first;
    out << type << " ";
    while (q != nullptr)
    {
        out << q->data << " ";
        q = q->next;
    }
    out << std::endl;
    out.close();
}

template <typename T>
bool Queue<T>::conditionSearch(bool (*condition) (const T&))
{
    Box<T>* crr = first;
    while (crr != nullptr)
    {
        if (condition(crr->data))
            return true;
        crr = crr->next;
    }
    return false;
}

template <typename T>
void Queue<T>::sort()
{
    std::vector<T> numbs;
    Box<T>* crr = first;
    while (crr != nullptr)
    {
        numbs.push_back(crr->data);
        crr = crr->next;
    }
    Sort(numbs);
    crr = first;
    for (unsigned int i = 0; i < numbs.size(); i++)
    {
        crr->data = numbs[i];
        crr = crr->next;
    }
}

#endif // QUEUE_H
