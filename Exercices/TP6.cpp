#include "TP6.hpp"

TP6Exo1::TP6Exo1() :
    camera(Point(0.0, 0.0, 15.0)), lumiere(Point(0, 0, 4)), mesh(0)
{
    Fenetre::Actual().initPerspective();

    FileOFF file("Ressources/TP 6/buddha.off");
    this->buddha = file.GetMesh();
    this->buddha.Normalize();
    this->buddha.Scale(50, 50, 50);
    this->buddha.Translate(0, -7.5, 0);
    file.Load("Ressources/TP 6/bunny.off");
    this->bunny = file.GetMesh();
    this->bunny.Scale(50, 50, 50);
    this->bunny.Translate(1.5, -5, 0);
    this->bunny.RotateY(M_PI / 2);
    this->bunny.Normalize();
    file.Load("Ressources/TP 6/max.off");
    this->max = file.GetMesh();
    this->max.Scale(0.03, 0.03, 0.03);
    this->max.Translate(-0.5, 0, -2);
    this->max.RotateY(M_PI);
    this->max.Normalize();
    file.Load("Ressources/TP 6/triceratops.off");
    this->triceratops = file.GetMesh();
    this->triceratops.RotateY(-M_PI / 2);
    this->triceratops.Normalize();

    Mesh::EnableSmooth();
}

void TP6Exo1::OnDraw() {
    this->camera.Apply();
    this->lumiere.Apply();

    switch (this->mesh) {
        case 0:
            this->buddha.Draw();
            break;
        case 1:
            this->bunny.Draw();
            break;
        case 2:
            this->max.Draw();
            break;
        case 3:
            this->triceratops.Draw();
    }
}

void TP6Exo1::OnKeyboardEvent(unsigned char keycode, int x, int y) {
    switch (keycode) {
        case 38:
            this->mesh = 0;
            break;
        case 233:
            this->mesh = 1;
            break;
        case 34:
            this->mesh = 2;
            break;
        case 39:
            this->mesh = 3;
            break;
        default:
        std::cout << "[KEY]: " << (int)keycode << std::endl;
    }
}

void TP6Exo1::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
    lumiere.pos = camera.pos;
}

void TP6Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
    lumiere.pos = camera.pos;
}

void TP6Exo1::OnMotionUnpressedEvent(int, int) {}