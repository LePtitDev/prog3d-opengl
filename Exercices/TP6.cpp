#include "TP6.hpp"

TP6Exo1::TP6Exo1() :
    camera(Point(0.0, 0.0, 3.0))
{
    Fenetre::Actual().initPerspective();

    FileOFF file("Ressources/TP 6/triceratops.off");
    this->mesh = file.GetMesh();
}

void TP6Exo1::OnDraw() {
    this->camera.Apply();

    this->mesh.Draw();
}

void TP6Exo1::OnKeyboardEvent(unsigned char, int, int) {}

void TP6Exo1::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP6Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP6Exo1::OnMotionUnpressedEvent(int, int) {}