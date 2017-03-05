#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_EXERCICE_HPP
#define PROG3D_EXERCICE_HPP

class Exercice {

public:

    virtual void OnDraw3D() = 0;
    virtual void OnDraw2D() = 0;

    virtual void OnKeyboardEvent(unsigned char, int, int) = 0;

    virtual void OnMouseEvent(int, int, int, int) = 0;

    virtual void OnMotionPressedEvent(int, int) = 0;

    virtual void OnMotionUnpressedEvent(int, int) = 0;

};

#endif //PROG3D_EXERCICE_HPP

#endif