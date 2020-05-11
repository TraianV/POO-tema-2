#include "coada.h"
#include "complex"
coada & coada::push(const complex &x)
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
coada & coada::pop()
{
    vector vec;
    int i;
    if(this->dim>0)
    {
        vec.set_n(this->dim-1);
        vec.set_v(this->dim-1);
        for(i=1; i<this->dim; i++)
            vec.v[i-1]=this->v[i];
        delete [] this->v;
        this->v=new complex[vec.dim];
        for(i=0;i<vec.dim;i++)
            this->v[i]=vec.v[i];
        this->dim=vec.dim;
        return *this;
    }
    else
    {
        std::cout<<"coada vida\n";
        return *this;
    }

}
