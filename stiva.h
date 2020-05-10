#ifndef UNTITLED_STIVA_H
#define UNTITLED_STIVA_H
#include "vector.h"
#include "complex"
#include<iostream>

class stiva  : protected vector
{
public:
    stiva &push(complex const &x);
    stiva &pop();
};



#endif
