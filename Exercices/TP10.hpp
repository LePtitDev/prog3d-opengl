#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_TP10_HPP
#define PROG3D_TP10_HPP

/****** EXERCICE 1 ******/

class TP10Exo1 : public Exercice {

    Camera camera;
    
    DynamicMesh mesh1, mesh2;
    int disp;

public:

    TP10Exo1();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

};

/****** EXERCICE 2 ******/

class TP10Exo2 : public Exercice {

    Camera camera;
    
    DynamicMesh mesh1, mesh2;
    int disp;

public:

    TP10Exo2();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

};

#endif //PROG3D_TP10_HPP

#endif