#include <iostream>
#include <numeric>
#include <string>

#include "src/Vfraction.h"

using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{

    Vfraction a(7,8);      //Déclare une fraction valant 4/5
    Vfraction b(2);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
    Vfraction c,d;         //Déclare deux fractions valant 0
    cout << a << endl;

    cout << a.fractionToNbr() << endl;
    cout << b << endl;

    c = a+b;               //Calcule 4/5 + 2/1 = 14/5

    d = a*b;               //Calcule 4/5 * 2/1 = 8/5


    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;
    cout << "==========================" << endl;

    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;




    return 0;
}
