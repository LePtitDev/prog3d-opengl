#include "TP5.hpp"

/****** EXERCICE 1 ******/

TP5Exo1::TP5Exo1() :
        camera(Point(0.0, 0.0, 3.0)), v(Point(), 2)
{
    Fenetre::Actual().initPerspective();
}

void TP5Exo1::OnDraw() {
    this->camera.Apply();

    this->v.Draw();
}

void TP5Exo1::OnKeyboardEvent(unsigned char, int, int) {}

void TP5Exo1::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP5Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP5Exo1::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 2 ******/

Cylinder TP5Exo2::cy(Point(0, 0, 0), Vecteur(1, 1, 1), 1, 3);
Ball TP5Exo2::ba(Point(0, 0, 0), 1, 3, 3);

TP5Exo2::TP5Exo2() :
        camera(Point(0.0, 0.0, 3.0))
{
    Fenetre::Actual().initPerspective();
    v = Volume(Point(0, 0, 0), 4.0, 6, TP5Exo2::InsideBall, nullptr);
}

void TP5Exo2::OnDraw() {
    this->camera.Apply();
    this->v.Draw();
}

void TP5Exo2::OnKeyboardEvent(unsigned char key, int x, int y) {
    switch (key) {
        case 38: //&
            v = Volume(Point(0, 0, 0), 4.0, 6, TP5Exo2::InsideBall, nullptr);
            break;
        case 233: //é
            v = Volume(Point(0, 0, 0), 4.0, 6, TP5Exo2::InsideCylinder, nullptr);
            break;

        default:
        std::cout << "[KEY]: " << (int)key << std::endl;
    }
}

void TP5Exo2::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP5Exo2::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP5Exo2::OnMotionUnpressedEvent(int, int) {}

bool TP5Exo2::InsideBall(void* args, double x, double y, double z) {
    return TP5Exo2::ba.Inside(x, y, z);
}

bool TP5Exo2::InsideCylinder(void* args, double x, double y, double z) {
    return TP5Exo2::cy.Inside(x, y, z);
}

/****** EXERCICE 3 ******/

Cylinder TP5Exo3::cy(Point(0, 0, 0), Vecteur(1, 0, 1), 0.5, 3);
Ball TP5Exo3::ba(Point(0, 0, 0), 1, 3, 3);

TP5Exo3::TP5Exo3() :
        camera(Point(0.0, 0.0, 3.0)), v1_show(1), v2_show(1)
{
    Fenetre::Actual().initPerspective();
    v1 = Volume(Point(0, 0, 0), 4.0, 6, TP5Exo3::InsideBall, nullptr);
    v2 = Volume(Point(0, 0, 0), 4.0, 6, TP5Exo3::InsideCylinder, nullptr);
    v3 = v1.Intersection(v2);
}

void TP5Exo3::OnDraw() {
    this->camera.Apply();

    if (v1_show == 0)
        this->v1.Draw();
    else if (v1_show == 1)
        this->v1.DrawLines();
    if (v2_show == 0)
        this->v2.Draw();
    else if (v2_show == 1)
        this->v2.DrawLines();

    this->v3.Draw();
}

void TP5Exo3::OnKeyboardEvent(unsigned char key, int x, int y) {
    switch (key) {
        case 38: //&
            v3 = v1.Intersection(v2);
            break;
        case 233: //é
            v3 = v1.Union(v2);
            break;
        case 34: //é
            v3 = v1.Soustraction(v2);
            break;

        case 97: //a
            v1_show = 0;
            break;
        case 122: //z
            v1_show = 1;
            break;
        case 101: //e
            v1_show = 2;
            break;
        case 113: //q
            v2_show = 0;
            break;
        case 115: //s
            v2_show = 1;
            break;
        case 100: //d
            v2_show = 2;
            break;

        default:
            std::cout << "[KEY]: " << (int)key << std::endl;
    }
}

void TP5Exo3::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP5Exo3::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP5Exo3::OnMotionUnpressedEvent(int, int) {}

bool TP5Exo3::InsideBall(void* args, double x, double y, double z) {
    return TP5Exo3::ba.Inside(x, y, z);
}

bool TP5Exo3::InsideCylinder(void* args, double x, double y, double z) {
    return TP5Exo3::cy.Inside(x, y, z);
}