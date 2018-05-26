#ifndef LIST_H
#define LIST_H
#include "Container.h"


template <typename T>
class List
{
public:
    Container<T>* first;
    List(): first(nullptr) {}
    void add(Container<T>*);
    bool findEle(const T&);
    void loadBalancing(const T&);
    void letFilter(bool (*condition) (const T&));
    void addContainer();
    void printAll();
    void toTextAll();
    bool searchForCondition(bool (*condition) (const T&));
    void sortAll();
};


template <typename T>
void List<T>::add(Container<T>* n)
{
    if (this->first == nullptr)
        this->first = n;
    else
    {
        Container<T>* c = this->first;
        while (c->next != nullptr)
        {
            c = c->next;
        }
        c->next = n;
    }
}

template <typename T>
bool List<T>::findEle(const T& x)
{
    if (first == nullptr)
    {
        return false;
    }
    Container<T>* crr = first;
    while (crr != nullptr)
    {
        if (crr->member(x))
            return true;
        crr = crr->next;
    }
    return false;
}

template <typename T>
void List<T>::loadBalancing(const T& x)
{
    Container<T>* crr = first;
    std::vector<int> sizes;
    while (crr != nullptr)
    {
        sizes.push_back(crr->getSize());
        crr = crr->next;
    }
    int smallest = 100000;
    unsigned int i = 0;
    while (i < sizes.size())
    {
        if (smallest > sizes[i])
        {
            smallest = sizes[i];
        }
        i++;
    }
    crr = first;
    while (crr != nullptr)
    {
        if (crr->getSize() == smallest)
        {
            crr->push(x);
            break;
        }
        crr = crr->next;
    }
}

template <typename T>
void List<T>::letFilter(bool (*condition) (const T& x))
{
    Container<T>* c = first;
    while (c != nullptr)
    {
        c->filter(condition);
        c = c->next;
    }
}

template <typename T>
void List<T>::printAll()
{
    Container<T>* crr = first;
    while (crr != nullptr)
    {
        crr->print();
        crr = crr->next;
    }
}

template <typename T>
void List<T>::addContainer()
{
    if (first == nullptr)
    {
        first = this->add();
    }
    else
    {
        Container<T>* c = first;
        while (c != nullptr)
        {
            c = c->next;
        }
        c = this->add();
    }
}

template <typename T>
void List<T>::toTextAll()
{
    Container<T>* c = first;
    while (c != nullptr)
    {
        c->toText();
        c = c->next;
    }
}

template <typename T>
bool List<T>::searchForCondition(bool (*condition) (const T& x))
{
    Container<T>* c = first;
    while (c != nullptr)
    {
        if (c->conditionSearch(condition) == true)
            return true;
        c = c->next;
    }
    return false;
}

template <typename T>
void List<T>::sortAll()
{
    Container<T>* c = first;
    while (c != nullptr)
    {
        c->sort();
        c = c->next;
    }
}

#endif // LIST_H
