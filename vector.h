#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H
#include "complex.h"
#include <iostream>

class vector
{
    complex *v;
    int dim;
public:
    friend class complex;
    friend class stiva;
    friend class coada;
    vector(complex *vec,int n);
    vector();
    vector(vector const &);
    ~vector();
    int get_n()
    {
        return this->dim;
    }
    void set_n(int n)
    {
        this->dim=n;
    }
    complex* get_v()
    {
        return this->v;
    }
    void set_v(int n)
    {
        delete[] this->v;
        this->v=new complex[n];
    }
    complex operator[](const int ) const;
    vector & operator=(const vector &vec);
    void set_v(int i,complex x)
    {
        this->v[i]=x;
    }
    friend std::istream & operator >>(std::istream &in, vector &);
    friend std::ostream & operator <<(std::ostream &out,const vector &);
};



#endif
