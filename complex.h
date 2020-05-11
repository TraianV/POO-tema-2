#ifndef UNTITLED_COMPLEX_H
#define UNTITLED_COMPLEX_H
#include <fstream>
class complex
{
    float re,im;
public:
    friend class vector;
    friend class stiva;
    friend class coada;
    complex(float,float );
    complex(complex const &);
    complex(){re=0;im=0;};
    ~complex()=default;
    float get_re()
    {
        return this->re;
    }
    float get_im()
    {
        return this->im;
    }
    complex& operator =(complex const &)=default;
    void set_re(float x)
    {
        this->re=x;
    }
    void set_im(float x)
    {
        this->im=x;
    }
    friend std::istream & operator >>(std::istream &, complex &);
    friend std::ostream & operator <<(std::ostream &, const complex &);
};



#endif
