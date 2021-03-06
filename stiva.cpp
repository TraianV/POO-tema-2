#include "vector.h"
#include "complex"
#include "stiva.h"
stiva & stiva::push(complex const &x)
{
    vector vec;
    int i;
    vec.set_n(this->get_n()+1);
    vec.set_v(this->get_n()+1);
    for(i=0;i<this->get_n();i++)
        vec.set_v(i,this->get_v()[i]);
    vec.set_v(this->get_n(),x);
    delete [] this->v;
    this->v=new complex[vec.dim];
    for(i=0;i<vec.dim;i++)
        this->v[i]=vec.v[i];
    this->dim=vec.dim;
    return *this;
}
stiva & stiva::pop()
{
    vector vec;
    int i;
    if(this->dim>0)
    {
        vec.set_n(this->dim-1);
        vec.set_v(this->dim-1);
        for(i=0; i<this->dim-1; i++)
            vec.set_v(i,this->v[i]);
        delete [] this->v;
        this->v=new complex[vec.dim];
        for(i=0; i<vec.dim; i++)
            this->v[i]=vec.v[i];
        this->dim=vec.dim;
        return *this;
    }
    else
    {
        std::cout<<"stiva vida\n";
        return *this;
    }
}
