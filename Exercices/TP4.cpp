#include "TP4.hpp"

/****** EXERCICE 1 ******/

TP4Exo1::TP4Exo1() :
        camera(Point(0.0, 0.0, 5.0)), c(Point(0, 0, 0), Vecteur(0, 2, 0), 1, 20)
{
    Fenetre::Actual().initPerspective();
}

void TP4Exo1::OnDraw3D() {
    this->camera.Apply();

    this->c.Draw();
}
void TP4Exo1::OnDraw2D() {}

void TP4Exo1::OnKeyboardEvent(unsigned char, int, int) {}

void TP4Exo1::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP4Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP4Exo1::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 2 ******/

TP4Exo2::TP4Exo2() :
        camera(Point(0.0, 0.0, 5.0)), c(Point(0, 0, 0), Vecteur(0, 2, 0), 1, 20)
{
    Fenetre::Actual().initPerspective();
}

void TP4Exo2::OnDraw3D() {
    this->camera.Apply();

    this->c.Draw();
}
void TP4Exo2::OnDraw2D() {}

void TP4Exo2::OnKeyboardEvent(unsigned char, int, int) {}

void TP4Exo2::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP4Exo2::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP4Exo2::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 3 ******/

TP4Exo3::TP4Exo3() :
        camera(Point(0.0, 0.0, 3.0)), b(Point(0, 0, 0), 1, 20, 10)
{
    Fenetre::Actual().initPerspective();
}

void TP4Exo3::OnDraw3D() {
    this->camera.Apply();

    this->b.Draw();
}
void TP4Exo3::OnDraw2D() {}

void TP4Exo3::OnKeyboardEvent(unsigned char, int, int) {}

void TP4Exo3::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP4Exo3::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP4Exo3::OnMotionUnpressedEvent(int, int) {}