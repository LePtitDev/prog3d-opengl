#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_TP8_HPP
#define PROG3D_TP8_HPP

class TP8Exo1 : public Exercice {

    Camera camera;
    
    Mesh mesh;
    std::vector<Mesh> segms;

public:

    TP8Exo1();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_TP8_HPP

#endif