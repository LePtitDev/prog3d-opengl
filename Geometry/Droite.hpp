#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_DROITE_HPP
#define PROG3D_DROITE_HPP

class Droite {

public:

    Point p;
    Vecteur v;

    Droite();
    Droite(const Point&, const Vecteur&);
    Droite(const Droite&);

};

#endif //PROG3D_DROITE_HPP

#endif
