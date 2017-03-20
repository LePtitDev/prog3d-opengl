#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_BOX_HPP
#define PROG3D_BOX_HPP

class Box {

    std::array<Point, 8> P;
    std::array<Vecteur, 3> V;

public:

    Box();
    Box(const Point&, const Vecteur&, const Vecteur&, const Vecteur&);
    Box(const Box&);

    const Point& GetPoint(int) const;
    const Vecteur& GetVector(int) const;

    void Draw() const;

    bool Inside(const Point&) const;

};

#endif //PROG3D_BOX_HPP

#endif