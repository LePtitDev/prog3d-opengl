#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_CONE_HPP
#define PROG3D_CONE_HPP

class Cone {

    Point p;
    Vecteur v;
    double r;

    Curve courbe;

public:

    Cone();
    Cone(const Point&, const Vecteur&, double, long);
    Cone(const Cone&);

    static Curve CurveByCone(const Cone&, long);

    void Draw();

};

#endif //PROG3D_CONE_HPP

#endif