#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_PLAN_HPP
#define PROG3D_PLAN_HPP

class Plan {

    Vecteur n, u, v;

public:

    Point p;

    Plan();
    Plan(const Point&, const Vecteur&);
    Plan(const Point&, const Vecteur&, const Vecteur&);
    Plan(const Plan&);

    const Vecteur& GetU() const;
    const Vecteur& GetV() const;
    const Vecteur& GetNormal() const;

};

#endif //PROG3D_PLAN_HPP

#endif
