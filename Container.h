#ifndef CONTAINER_H
#define CONTAINER_H
#include "Box.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

template <typename T>
class Container
{
public:

    Container<T>* next;
    Container<T>() : next(nullptr) {}

    virtual void push(const T& x) = 0;
    virtual void pop() = 0;
    virtual T top() = 0;
    virtual void print() const = 0;
    virtual bool member(const T& x) = 0;
    virtual int getSize() = 0;
    virtual void filter (bool (*condition) (const T&)) = 0;
    virtual void toText() const = 0;
    virtual bool conditionSearch (bool (*condition) (const T&)) = 0;
    virtual void sort() = 0;

};

#endif // CONTAINER_H
