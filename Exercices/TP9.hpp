#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_TP9_HPP
#define PROG3D_TP9_HPP

/****** EXERCICE 1 ******/

class TP9Exo1 : public Exercice {

    Camera camera;
    
    DynamicMesh mesh;

public:

    TP9Exo1();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

/****** EXERCICE 2 ******/

class TP9Exo2 : public Exercice {

    Camera camera;
    
    DynamicMesh mesh;
    Grille3D grille;

public:

    TP9Exo2();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_TP8_HPP

#endif