#ifndef PROG3D_EXERCICE_HPP
#include "Exercice.hpp"

#else

#ifndef PROG3D_TP4_HPP
#define PROG3D_TP4_HPP

/****** EXERCICE 1 ******/

class TP4Exo1 : public Exercice {

    Camera camera;

    Cylinder c;

public:

    TP4Exo1();

    void OnDraw();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

/****** EXERCICE 2 ******/

class TP4Exo2 : public Exercice {

    Camera camera;

    Cone c;

public:

    TP4Exo2();

    void OnDraw();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

/****** EXERCICE 3 ******/

class TP4Exo3 : public Exercice {

    Camera camera;

    Ball b;

public:

    TP4Exo3();

    void OnDraw();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_TP4_HPP

#endif