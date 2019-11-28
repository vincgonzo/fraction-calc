#ifndef VFRACTION_H_INCLUDED
#define VFRACTION_H_INCLUDED

#include <iostream>
#include <string>

class Vfraction
{
    public:

    Vfraction();
    Vfraction(int Num, int Den);
    Vfraction(int Num);
    isEgal(Vfraction &b) const;
    void display(std::ostream &flux) const;
    void simpleF();

    Vfraction& operator+=(Vfraction const& other);
    Vfraction& operator*=(Vfraction const& autre);

    private:

    int m_numerator;
    int m_denominator;
};

bool operator==(Vfraction const &a, Vfraction const &b);
int pgcd(int a, int b);

Vfraction operator+(const Vfraction& a, const Vfraction &b);
Vfraction operator*(Vfraction const& a, Vfraction const& b);
std::ostream& operator<<(std::ostream &flux, Vfraction const& a);

#endif // VFRACTION_H_INCLUDED
