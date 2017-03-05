#ifndef PROG3D_EXERCICE_HPP
#include "Exercice.hpp"

#else

#ifndef PROG3D_TP3_HPP
#define PROG3D_TP3_HPP

/****** EXERCICE 1 ******/

class TP3Exo1 : public Exercice {

    Camera camera;

    Curve courbe;
    Vecteur droite;

    Surface surface;

public:

    TP3Exo1();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

/****** EXERCICE 2 ******/

class TP3Exo2 : public Exercice {

    Camera camera;

    Curve courbe1;
    Curve courbe2;

    Surface surface;

public:

    TP3Exo2();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};


/****** EXERCICE 3 ******/

class TP3Exo3 : public Exercice {

    Camera camera;

    Surface P;

    Surface surface;

public:

    TP3Exo3();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_TP3_HPP

#endif