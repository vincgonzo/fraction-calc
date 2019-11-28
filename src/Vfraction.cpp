#include "Vfraction.h"

using namespace std;

// Constructor =================
Vfraction::Vfraction(): m_numerator(0), m_denominator(1)
{
}
Vfraction::Vfraction(int Num, int Den) : m_numerator(Num), m_denominator(Den)
{
}

Vfraction::Vfraction(int Num) : m_numerator(Num), m_denominator(1)
{
}

// Methods =====================
void Vfraction::simpleF()
{
    int cNb = pgcd(m_numerator, m_denominator);
    cout << m_numerator/cNb << '/' << m_denominator/cNb << endl;
}

void Vfraction::display(ostream &flux) const
{
    if(m_denominator == 1)
        flux << m_numerator;
    else
        flux << m_numerator << '/' << m_denominator;
}

// Operators ================
ostream& operator<<(ostream &flux, Vfraction const& a )
{
    a.display(flux);
    return flux;
}

Vfraction operator+(const Vfraction& a, const Vfraction &b)
{
    Vfraction copie(a);
    copie+=b;
    return copie;
}

Vfraction& Vfraction::operator+=(Vfraction const& other)
{
    m_numerator = other.m_denominator * m_numerator + m_denominator * other.m_numerator;
    m_denominator = m_denominator * other.m_denominator;

    return *this;
}

Vfraction operator*(Vfraction const& a, Vfraction const& b)
{
    Vfraction copie(a);
    copie*=b;
    return copie;
}

Vfraction& Vfraction::operator*=(Vfraction const& autre)
{
    m_numerator *= autre.m_numerator;
    m_denominator *= autre.m_denominator;

    return *this;
}

/*Vfraction::cNumerator(Vfraction const &b) const
{

}
Vfraction::cNumerator(Vfraction const &b) const
{

}*/

bool Vfraction::isEgal(Vfraction const &b) const
{
    return (m_numerator == b.m_numerator && m_denominator == b.m_denominator);
}


// == Operator ==


bool operator==(Vfraction const& a, Vfraction const& b)
{
   return a.isEgal(b);
}

bool operator!=(Vfraction const& a, Vfraction const& b)
{
   return !(a.isEgal(b));   //Souvenez-vous du ! qui veut dire "NON"
}

// Functions ======================
int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}
