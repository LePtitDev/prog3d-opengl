#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_VECTEUR_HPP
#define PROG3D_VECTEUR_HPP

class Vecteur {

public:

    double x, y, z;

    Vecteur();
    Vecteur(double, double, double);
    Vecteur(const Vecteur&);

    static Vecteur VectorByPoints(const Point&, const Point&);

    double GetNorm() const;
    double GetScalar(const Vecteur&) const;
    double GetAngle(const Vecteur&) const;
    Vecteur GetVectoriel(const Vecteur&) const;

    void Normalize();

    Vecteur operator+() const;
    Vecteur operator-() const;
    Vecteur operator+(const Vecteur&) const;
    Vecteur operator-(const Vecteur&) const;
    Vecteur operator*(double) const;

};

std::ostream& operator<<(std::ostream&, const Vecteur&);

#endif //PROG3D_VECTEUR_HPP

#endif
