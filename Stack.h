#ifndef STACK_H
#define STACK_H
#include "Container.h"
#include <fstream>
#include <vector>
#include <iostream>

template <typename T>
class Stack : public Container<T>
{
    Box<T>* tops;
    int size;
    char type;
public:
    Stack();
    Stack(std::vector<T>& v);
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
Stack<T>::Stack(std::vector<T> &v)
{
    Stack();
    int counter = 0;
    while (!v.empty())
    {
        push(v[counter]);
        counter++;
    }
}

template <typename T>
Stack<T>::Stack()
{
    tops = nullptr;
    size = 0;
    type = 'S';
}

template <typename T>
void Stack<T>::push(const T& x)
{
    if (tops == nullptr)
    {
        Box<T>* n = new Box<T>(x, nullptr, nullptr);
        tops = n;
    }
    else
    {
        Box<T>* c = new Box<T>(x, nullptr, nullptr);
        Box<T>* crr = tops;
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
void Stack<T>::pop()
{
    Box<T>* b = tops;
    while (b->next->next != nullptr)
        b = b->next;
    b->next = nullptr;
}

template <typename T>
T Stack<T>::top()
{
    Box<T>* b = tops;
    while (b->next != nullptr)
        b = b->next;
    return b->data;
}

template <typename T>
void Stack<T>::print() const
{
    Box<T>* crr = tops;
    std::cout << "S ";
    while (crr->next != nullptr)
    {
        crr = crr->next;
    }
    while (crr != nullptr)
    {
        std::cout << crr->data << " ";
        crr = crr->prev;
    }
    std::cout << std::endl;
}

template <typename T>
bool Stack<T>::member(const T& x)
{
    Box<T>* b = tops;
    while (b != nullptr)
    {
        if (b->data == x)
            return true;
        b = b->next;
    }
    return false;
}

template <typename T>
int Stack<T>::getSize()
{
    return size;
}

template <typename T>
void Stack<T>::filter(bool (*condition) (const T& x))
{
    Box<T>* crr = tops;
    while (crr->next != nullptr)
    {
        if (condition(crr->data) == false)
        {
            if (crr == tops)
            {
                tops = crr->next;
                tops->prev = nullptr;
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
void Stack<T>::toText() const
{
    std::ofstream out ("Containers.txt", std::fstream::app);
    out << type << " ";
    Box<T>* s = tops;
    while (s != nullptr)
    {
        out << s->data << " ";
        s = s->next;
    }
    out << std::endl;
    out.close();
}


template <typename T>
bool Stack<T>::conditionSearch(bool (*condition) (const T&))
{
    Box<T>* crr = tops;
    while (crr != nullptr)
    {
        if (condition(crr->data) == true)
        {
            return true;
        }
        crr = crr->next;
    }
    return false;
}

template <typename T>
void Stack<T>::sort()
{
    std::vector<T> numbs;
    Box<T>* crr = tops;
    while (crr != nullptr)
    {
        numbs.push_back(crr->data);
        crr = crr->next;
    }
    Sort(numbs);
    crr = tops;
    for (unsigned int i = 0; i < numbs.size(); i++)
    {
        crr->data = numbs[i];
        crr = crr->next;
    }
}

#endif // STACK_H
