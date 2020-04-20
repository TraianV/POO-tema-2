#include "vector.h"
#include "complex.h"
#include<fstream>
complex::complex(float x,float y)
{
    this->re=x;
    this->im=y;
}
complex::complex(complex const &ob)
{
    this->re=ob.re;
    this->im=ob.im;
}
complex::complex()
{
    this->re=0;
    this->im=0;
}

complex::~complex()
{
    this->im=0;
    this->re=0;
}
complex& complex::operator=(complex &ob)
{
    if(this->re==ob.re && this->im==ob.im)
        return *this;
    this->re=ob.re;
    this->im=ob.im;
    return *this;
}
std::istream & operator >> (std::istream &in, complex &r)
{
    float x,y;
    in>>x;
    in>>y;
    r.set_re(x);
    r.set_im(y);
    return in;
}
std::ostream & operator << (std::ostream &out,const complex &r)
{
    if(r.re!=0)
        out<<r.re;
    if(r.im==1)
        out<<"+i";
    else
        if(r.im==-1)
            out<<"-i";
        else
            if(r.im>0)
                out<<'+'<<r.im<<'i';
            else
                if(r.im<0)
                    out<<r.im<<'i';
    return out;
}
