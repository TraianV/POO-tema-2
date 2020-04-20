#include "vector.h"
#include "complex.h"
#include "stiva.h"
#include "coada.h"
#include<fstream>
vector::vector(const vector &vec)
{
int i;
this->dim=vec.dim;
this->v=new complex[this->dim];
for(i=0; i<this->dim; i++)
    this->v[i]=vec.v[i];
}
vector::vector(complex *vec, int n) {
        int i;
        this->dim=n;
        this->v=new complex[n];
        for(i=0; i<n; i++)
            this->v[i]=vec[i];
    }
vector::vector()
{
    this->dim=0;
}
vector::~vector()
{
    if(this->dim>0)
    {
        delete []this->v;
        this->dim=0;
    }
}
complex vector::operator[](const int n) const
{
    return this->v[n];
}
vector & vector::operator=(const vector &vec)
{
    int i;
    if(this->dim>0)
        delete []this->v;
    this->v=new complex[vec.dim];
    this->dim=vec.dim;
    for(i=0; i<vec.dim; i++)
        this->v[i]=vec.v[i];
    return *this;
}
std::istream &operator >> (std::istream & in, vector & vec)
{
    int i;
    if(vec.dim>0)
        delete []vec.v;
    std::cout<<"Dimensiunea vectorului:";
    in>>vec.dim;
    vec.v=new complex[vec.dim];
    for(i=0; i<vec.dim; i++)
        in>>vec.v[i];
    return in;
}
std::ostream &operator<<(std::ostream & out,const vector &vec)
{
    int i;
    for(i=0; i<vec.dim; i++)
        out<<vec.v[i]<<' ';
    return out;
}
