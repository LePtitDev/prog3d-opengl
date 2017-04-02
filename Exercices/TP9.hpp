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
    
    DynamicMesh mesh, mesh_cpy;
    Grille3D grille;

    uTimer timer;
    bool reduced, display_reduced, display_grid;

public:

    TP9Exo2();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

/****** EXERCICE 3 ******/

class TP9Exo3 : public Exercice {

    Camera camera;

    DynamicMesh mesh;

public:

    TP9Exo3();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

};

/****** EXERCICE 4 ******/

class TP9Exo4 : public Exercice {

    Camera camera;

    DynamicMesh mesh, mesh_ssub, mesh_cpy;

    uTimer timer;
    bool reduced;
    int figure;

public:

    TP9Exo4();

    void OnDraw3D();
    void OnDraw2D();

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

};

#endif //PROG3D_TP8_HPP

#endif