#include<iostream>
#include<fstream>
#include"complex.h"
#include"vector.h"
#include "stiva.h"
#include "coada.h"
using namespace std;

int main()
{
    int n,i;
    complex x;
    stiva a;
    coada b;
    ifstream f("date.in");
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>x;
        a.add(x);
        b.add(x);
    }
    cout<<a<<endl<<b;
    f>>n;
    for (i=0;i<n;i++) {
        a.pop();
        b.pop();
    }
    cout<<endl<<a<<endl<<b;
    f.close();
    return 0;
}
