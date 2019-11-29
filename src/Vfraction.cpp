#include "Vfraction.h"

using namespace std;

// Constructor =================

Vfraction::Vfraction(int Num, int Den) : m_numerator(Num), m_denominator(Den)
{
    //simpleF();
}


// Methods =====================
void Vfraction::simpleF()
{
    int cNb = pgcd(m_numerator, m_denominator);

    m_numerator/=cNb;
    m_denominator/=cNb;
}

double Vfraction::fractionToNbr()
{
    return double(m_numerator) / double(m_denominator);
}

int Vfraction::getNum() const
{
    return m_numerator;
}

int Vfraction::getDen() const
{
    return m_denominator;
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

    simpleF();
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

    simpleF();
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

bool Vfraction::estPlusPetitQue(Vfraction const& autre) const
{
    return (m_numerator * autre.m_denominator < m_denominator * autre.m_numerator);
}

// == Operator ==

bool operator<(Vfraction const& a, Vfraction const& b) //Vrai si a<b donc si a est plus petit que b
{
    return a.estPlusPetitQue(b);
}

bool operator>(Vfraction const& a, Vfraction const& b) //Vrai si a>b donc si b est plus petit que a
{
    return b.estPlusPetitQue(a);
}

bool operator<=(Vfraction const& a, Vfraction const& b) //Vrai si a<=b donc si b n'est pas plus petit que a
{
    return !(b.estPlusPetitQue(a));
}

bool operator>=(Vfraction const& a, Vfraction const& b) //Vrai si a>=b donc si a n'est pas plus petit que b
{
    return !(a.estPlusPetitQue(b));
}

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
