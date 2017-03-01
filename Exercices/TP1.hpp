#ifndef PROG3D_EXERCICE_HPP
#include "Exercice.hpp"

#else

#ifndef PROG3D_TP1_HPP
#define PROG3D_TP1_HPP

class TP1Exo : public Exercice {

    Point p1, p2, p3;
    Vecteur v;

public:

    TP1Exo();

    void OnDraw();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_TP1_HPP

#endif