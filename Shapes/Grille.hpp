#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_GRILLE_HPP
#define PROG3D_GRILLE_HPP

class Grille3D {

public:

    Point pos;
    Vecteur ortho;
    unsigned int nbX, nbY, nbZ;

    Grille3D();
    Grille3D(const Point&, const Vecteur&);
    Grille3D(const Point&, const Vecteur&, unsigned int);
    Grille3D(const Grille3D&);

    void Draw() const;

    Box Get(unsigned int, unsigned int, unsigned int) const;

};

#endif //PROG3D_GRILLE_HPP

#endif