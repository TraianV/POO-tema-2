#ifndef UNTITLED_COADA_H
#define UNTITLED_COADA_H
#include "vector.h"
#include "complex"
#include<iostream>

class coada : public vector
{
public:
    coada &push(const complex &x);
    coada &pop();
};



#endif
