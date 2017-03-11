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

    uiLayout layout;
    uiBouton bt_prec, bt_suiv, bt_plus, bt_moins;

    int nb_segments, figure;

public:

    TP7Exo1();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

    static void action_bt_prec(void *);
    static void action_bt_suiv(void *);
    static void action_bt_plus(void *);
    static void action_bt_moins(void *);

};

#endif //PROG3D_TP7_HPP

#endif