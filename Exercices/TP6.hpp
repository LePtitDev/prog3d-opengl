#ifndef PROG3D_EXERCICE_HPP
#include "Exercice.hpp"

#else

#ifndef PROG3D_TP6_HPP
#define PROG3D_TP6_HPP

/****** EXERCICE 1 ******/

class TP6Exo1 : public Exercice {

    Lumiere lumiere;
    Camera camera;

    int mesh;
    Mesh buddha, bunny, max, triceratops;

public:

    TP6Exo1();

    void OnDraw();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_TP6_HPP

#endif