#ifndef PROG3D_EXERCICE_HPP
#include "Exercice.hpp"

#else

#ifndef PROG3D_TP6_HPP
#define PROG3D_TP6_HPP

/****** EXERCICE 2 ******/

class TP6Exo2 : public Exercice {

    Lumiere lumiere;
    Camera camera;
    RRectangle nearR;
    Point CPos;

    int mesh;
    Mesh buddha, bunny, max, triceratops;

public:

    TP6Exo2();

    void OnDraw();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

/****** EXERCICE 3 ******/

class TP6Exo3 : public Exercice {

    Lumiere lumiere;
    Camera camera;

    int mesh;
    Mesh buddha, bunny, max, triceratops;

public:

    TP6Exo3();

    void OnDraw();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_TP6_HPP

#endif