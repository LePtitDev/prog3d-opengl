#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_TP11_HPP
#define PROG3D_TP11_HPP

/****** EXERCICE 2 ******/

class TP11Exo2 : public Exercice {

    Camera camera;
    
    House house;

public:

    TP11Exo2();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

};

#endif //PROG3D_TP10_HPP

#endif