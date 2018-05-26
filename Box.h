#ifndef BOX_H
#define BOX_H

template <typename T>
struct Box
{
    T data;
    Box* next;
    Box* prev;
    Box() {next = nullptr; prev = nullptr;}
    Box(const T& _data, Box<T>* _next, Box<T>* _prev) : data(_data), next(_next), prev(_prev) {}
};

#endif // BOX_H
