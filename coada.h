#ifndef UNTITLED_COADA_H
#define UNTITLED_COADA_H
#include "vector.h"
#include "complex.h"
#include<iostream>

class coada
{
    vector vec;
public:
    friend class vector;
    friend class complex;
    coada(vector vec);
    coada (const coada &c);
    ~coada();
    coada &push(complex x);
    coada &pop();
    vector get_v()
    {
        return this->vec;
    }
    friend std::istream & operator >>(std::istream &, coada & );
    friend std::ostream & operator <<(std::ostream &, coada & );
};



#endif
