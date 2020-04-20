#include "vector.h"
#include "complex.h"
#include "stiva.h"
#include <fstream>
stiva::stiva()
{
    this->vec.set_n(0);
}
stiva::stiva(const stiva &s)
{
    this->vec=s.vec;
}
stiva::~stiva()
{
    if(this->vec.get_n()>0)
    {
        this->vec.set_n(0);
        this->vec.set_v();
    }
}
stiva & stiva::add(complex x)
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
stiva & stiva::pop()
{
    vector v;
    int i;
    if(this->vec.get_n()>0)
    {
        v.set_n(this->vec.get_n()-1);
        v.set_v(this->vec.get_n()-1);
        for(i=0;i<this->vec.get_n()-1;i++)
            v.set_v(i,this->vec.get_v()[i]);
        this->vec=v;
        return *this;
    }
    else
    {
        std::cout<<"stiva vida ";
        return *this;
    }
}

std::istream &operator>>(std::istream & in,stiva &s)
{
    int i;
    complex x;
    if(s.vec.get_n()>0)
    {
        s.get_v().set_v();
    }
    in>>i;
    s.vec.set_n(i);
    for(i=0;i<s.vec.get_n();i++)
    {
        in>>x;
        s.add(x);
    }
    return in;
}
std::ostream & operator <<(std::ostream & out,stiva &s)
{
    int i;
    if(s.get_v().get_n()>0)
        for(i=0;i<s.get_v().get_n();i++)
            out<<s.get_v().get_v()[i]<<' ';
    return out;
}
