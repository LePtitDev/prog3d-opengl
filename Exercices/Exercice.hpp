#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_EXERCICE_HPP
#define PROG3D_EXERCICE_HPP

class Exercice {

public:

    virtual void OnDraw3D();
    virtual void OnDraw2D();

    virtual void OnKeyboardEvent(unsigned char, int, int);

    virtual void OnMouseEvent(int, int, int, int);

    virtual void OnMotionPressedEvent(int, int);

    virtual void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_EXERCICE_HPP

#endif