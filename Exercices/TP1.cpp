#include "Exercice.hpp"

TP1Exo::TP1Exo() :
    p1(-0.8, 1, 0), p2(0, 0.5, 0), v(0.4, 0.4, 0)
{
    Fenetre::Actual().initOrtho();
    p3 = p1.GetProjection(Droite(p2, v));
}

void TP1Exo::OnDraw3D() {
    p1.Draw();
    (Segment(p2, Point(p2.x + v.x, p2.y + v.y, p2.z + v.z))).Draw();
    p3.Draw();
}
void TP1Exo::OnDraw2D() {}

void TP1Exo::OnKeyboardEvent(unsigned char, int, int) {}

void TP1Exo::OnMouseEvent(int, int, int, int) {}

void TP1Exo::OnMotionPressedEvent(int, int) {}

void TP1Exo::OnMotionUnpressedEvent(int, int) {}