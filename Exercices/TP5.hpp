#ifndef PROG3D_EXERCICE_HPP
#include "Exercice.hpp"

#else

#ifndef PROG3D_TP5_HPP
#define PROG3D_TP5_HPP

/****** EXERCICE 1 ******/

class TP5Exo1 : public Exercice {

    Camera camera;

    Voxel v;

public:

    TP5Exo1();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

/****** EXERCICE 2 ******/

class TP5Exo2 : public Exercice {

    Camera camera;

    Volume v;

    static Cylinder cy;
    static Ball ba;

public:

    TP5Exo2();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

    static bool InsideBall(void*, double, double, double);

    static bool InsideCylinder(void*, double, double, double);

};

/****** EXERCICE 3 ******/

class TP5Exo3 : public Exercice {

    Camera camera;

    int v1_show, v2_show;
    Volume v1, v2, v3;

    static Cylinder cy;
    static Ball ba;

public:

    TP5Exo3();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

    static bool InsideBall(void*, double, double, double);

    static bool InsideCylinder(void*, double, double, double);

};

#endif //PROG3D_TP5_HPP

#endif