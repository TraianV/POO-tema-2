#ifndef UNTITLED_COADA_H
#define UNTITLED_COADA_H
#include "vector.h"
#include "complex"
#include<iostream>

class coada : public vector
{
public:
    friend class vector;
    friend class complex;
    coada &push(const complex &x);
    coada &pop();
};



#endif
