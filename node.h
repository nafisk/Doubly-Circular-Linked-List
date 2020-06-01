//This program holds a class that is used to utilize all the manupulating functions
#ifndef CDLL_H
#define CDLL_H
#include <iostream>
using namespace std;

template <class T>
class node{
    public:
    T info;
    node<T> *next;
    node<T> *prev;
};
#endif
