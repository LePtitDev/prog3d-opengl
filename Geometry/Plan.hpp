#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_PLAN_HPP
#define PROG3D_PLAN_HPP

class Plan {

public:

    Point p;
    Vecteur n;

    Plan();
    Plan(const Point&, const Vecteur&);
    Plan(const Point&, const Vecteur&, const Vecteur&);
    Plan(const Plan&);

};

#endif //PROG3D_PLAN_HPP

#endif
