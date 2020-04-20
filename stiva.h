#ifndef UNTITLED_STIVA_H
#define UNTITLED_STIVA_H
#include "vector.h"
#include "complex.h"
#include<iostream>

class stiva
{
    vector vec;
public:
    friend class vector;
    friend class complex;
    stiva();
    stiva (const stiva &s);
    ~stiva();
    stiva &add(complex x);
    stiva &pop();
    vector get_v(){return this->vec;}
    friend std::istream & operator >>(std::istream &, stiva & );
    friend std::ostream & operator <<(std::ostream &, stiva & );
};



#endif
