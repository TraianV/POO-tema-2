//
// Created by visan on 18-Apr-20.
//

#include "coada.h"
#include "vector.h"
#include "complex.h"
#include <fstream>
coada::coada()
{
    this->vec.set_n(0);
}
coada::coada (const coada &c)
{
    this->vec=c.vec;
}
coada::~coada()
{
    if(this->vec.get_n()>0)
    {
        this->vec.set_n(0);
        delete []this->vec.get_v();
    }
}
coada & coada::add(complex x)
{
    vector v;
    int i;
    v.set_n(this->vec.get_n()+1);
    v.set_v(this->vec.get_n()+1);
    for(i=0;i<this->vec.get_n();i++)
        v.set_v(i,this->vec.get_v()[i]);
    v.set_v(this->vec.get_n(),x);
    this->vec=v;
    return *this;
}
coada & coada::pop()
{
    vector v;
    int i;
    if(this->vec.get_n()>0)
    {
        v.set_n(this->vec.get_n()-1);
        v.set_v(this->vec.get_n()-1);
        for(i=1;i<this->vec.get_n();i++)
            v.set_v(i-1,this->vec.get_v()[i]);
        this->vec=v;
        return *this;
    }
    return *this;
}
std::istream &operator>>(std::istream & in, coada &c)
{
    int i;
    complex x;
    if(c.vec.get_n()>0)
    {
        delete []c.vec.get_v();
    }
    in>>i;
    c.vec.set_n(i);
    c.vec.set_v(c.vec.get_n());
    for(i=0;i<c.vec.get_n();i++)
    {
        in>>x;
        c.add(x);
    }
    return in;
}
std::ostream & operator <<(std::ostream & out,coada &c)
{
    int i;
    if(c.get_v().get_n()>0)
        for(i=0;i<c.get_v().get_n();i++)
            out<<c.get_v().get_v()[i]<<' ';
    return out;
}