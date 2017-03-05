#ifndef PROG3D_EXERCICE_HPP
#include "Exercice.hpp"

#else

#ifndef PROG3D_TP2_HPP
#define PROG3D_TP2_HPP

/****** EXERCICE 1 ******/

class TP2Exo1 : public Exercice {

    Point p0, p1;
    Vecteur v0, v1;

    Curve courbe;

public:

    TP2Exo1();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

/****** EXERCICE 2 ******/

class TP2Exo2 : public Exercice {

    Point p0, p1, p2, p3;

    Curve courbe;

public:

    TP2Exo2();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

/****** EXERCICE 3 ******/

class TP2Exo3 : public Exercice {

    Point p0, p1, p2, p3;

    Curve courbe;

public:

    TP2Exo3();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_TP2_HPP

#endif