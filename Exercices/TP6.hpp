#ifndef PROG3D_EXERCICE_HPP
#include "Exercice.hpp"

#else

#ifndef PROG3D_TP6_HPP
#define PROG3D_TP6_HPP

/****** EXERCICE 2 ******/

class TP6Exo2 : public Exercice {

    Lumiere lumiere;
    Camera camera;
    RRectangle nearR;
    Point CPos;

    int mesh;
    Mesh buddha, bunny, max, triceratops;

    uiLayout layout;
    uiBouton bt_buddha, bt_bunny, bt_max, bt_triceratops;
    uiSwitch sw_poly, sw_shade, sw_projection;

    bool display_projection;

public:

    TP6Exo2();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

    static void action_bt_buddha(void *);
    static void action_bt_bunny(void *);
    static void action_bt_max(void *);
    static void action_bt_triceratops(void *);
    static void action_sw_poly(bool, void *);
    static void action_sw_shade(bool, void *);
    static void action_sw_projection(bool, void*);

};

/****** EXERCICE 3 ******/

class TP6Exo3 : public Exercice {

    Lumiere lumiere;
    Camera camera;

    int mesh;
    Mesh buddha, bunny, max, triceratops;

    uiLayout layout;
    uiBouton bt_buddha, bt_bunny, bt_max, bt_triceratops;
    uiSwitch sw_poly, sw_shade;

public:

    TP6Exo3();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

    static void action_bt_buddha(void *);
    static void action_bt_bunny(void *);
    static void action_bt_max(void *);
    static void action_bt_triceratops(void *);
    static void action_sw_poly(bool, void *);
    static void action_sw_shade(bool, void *);

};

#endif //PROG3D_TP6_HPP

#endif