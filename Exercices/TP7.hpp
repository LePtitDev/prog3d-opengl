#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_TP7_HPP
#define PROG3D_TP7_HPP

class TP7Exo1 : public Exercice {

    Camera camera;
    Lumiere lumiere;

    Cylinder cylinder;
    Ball ball;

    Mesh mesh;

public:

    TP7Exo1();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_TP7_HPP

#endif