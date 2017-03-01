#include "Exercice.hpp"

/****** EXERCICE 1 ******/

TP2Exo1::TP2Exo1() :
    p0(-1.0, 0.0, 0.0), p1(1.0, 0.0, 0.0),
    v0(1.0, 1.0, 0.0), v1(1.0, -1.0, 0.0)
{
    Fenetre::Actual().initOrtho();
    this->courbe = Curve::HermiteCubic(p0, p1, v0, v1, 20);
}

void TP2Exo1::OnDraw() {
    glColor3f(1.0, 0.0, 0.0);
    this->p0.Draw();
    this->p1.Draw();
    Segment(this->p0, Point(this->p0.x + this->v0.x, this->p0.y + this->v0.y, this->p0.z + this->v0.z)).Draw();
    Segment(this->p1, Point(this->p1.x + this->v1.x, this->p1.y + this->v1.y, this->p1.z + this->v1.z)).Draw();
    glColor3f(1.0, 1.0, 1.0);
    this->courbe.Draw();
}

void TP2Exo1::OnKeyboardEvent(unsigned char, int, int) {}

void TP2Exo1::OnMouseEvent(int, int, int, int) {}

void TP2Exo1::OnMotionPressedEvent(int, int) {}

void TP2Exo1::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 2 ******/

TP2Exo2::TP2Exo2() :
    p0(-1.0, 0.0, 0.0), p1(0.0, -1.0, 0.0), p2(0.0, 1.0, 0.0), p3(1.0, 0.0, 0.0)
{
    Fenetre::Actual().initOrtho();
    Point P[4] = { Point(p0), Point(p1), Point(p2), Point(p3) };
    this->courbe = Curve::BezierByBernstein(P, 4, 20);
}

void TP2Exo2::OnDraw() {
    glColor3f(1.0, 0.0, 0.0);
    this->p0.Draw();
    this->p1.Draw();
    this->p2.Draw();
    this->p3.Draw();
    Point P[4] = { Point(p0), Point(p1), Point(p2), Point(p3) };
    Curve line(P, 4);
    line.Draw();
    glColor3f(1.0, 1.0, 1.0);
    this->courbe.Draw();
}

void TP2Exo2::OnKeyboardEvent(unsigned char, int, int) {}

void TP2Exo2::OnMouseEvent(int, int, int, int) {}

void TP2Exo2::OnMotionPressedEvent(int, int) {}

void TP2Exo2::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 3 ******/

TP2Exo3::TP2Exo3() :
        p0(-1.0, 0.0, 0.0), p1(0.0, 1.0, 0.0), p2(0.0, -1.0, 0.0), p3(1.0, 0.0, 0.0)
{
    Fenetre::Actual().initOrtho();
    Point P[4] = { Point(p0), Point(p1), Point(p2), Point(p3) };
    this->courbe = Curve::BezierByCasteljau(P, 4, 20);
}

void TP2Exo3::OnDraw() {
    glColor3f(1.0, 0.0, 0.0);
    this->p0.Draw();
    this->p1.Draw();
    this->p2.Draw();
    this->p3.Draw();
    Point P[4] = { Point(p0), Point(p1), Point(p2), Point(p3) };
    Curve line(P, 4);
    line.Draw();
    glColor3f(1.0, 1.0, 1.0);
    this->courbe.Draw();
}

void TP2Exo3::OnKeyboardEvent(unsigned char, int, int) {}

void TP2Exo3::OnMouseEvent(int, int, int, int) {}

void TP2Exo3::OnMotionPressedEvent(int, int) {}

void TP2Exo3::OnMotionUnpressedEvent(int, int) {}