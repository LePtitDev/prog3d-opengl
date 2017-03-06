#ifndef PROG3D_MAIN_HPP
#include "main.hpp"

#else

#ifndef PROG3D_FENETRE_HPP
#define PROG3D_FENETRE_HPP

#include "main.hpp"

class Fenetre {

private:

    static Fenetre * actual;

    static void InitGL();

    bool ortho;

    Exercice * exo;

public:

    static Fenetre& Actual();

private:

    int win_width, win_height;

    int id;

    int menu_main;
    int tpNum, exoNum;

public:

    Fenetre(const char *, int, int, int, char *[]);

    ~Fenetre();

    int GetWidth() const;
    int GetHeight() const;

    void Execute();

    void initOrtho();

    void initPerspective();

private:

    static void OnDisplay();

    static void OnReshape(int, int);

    static void OnKeyboardEvent(unsigned char, int, int);

    static void OnMouseEvent(int, int, int, int);

    static void OnMotionPressedEvent(int, int);

    static void OnMotionUnpressedEvent(int, int);

    static void SelectExo(int);

};

#endif //PROG3D_FENETRE_HPP

#endif