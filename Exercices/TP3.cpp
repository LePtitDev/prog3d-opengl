#include "TP3.hpp"

/****** EXERCICE 1 ******/

TP3Exo1::TP3Exo1() :
        camera(Point(0.0, 0.0, 3.0))
{
    Fenetre::Actual().initPerspective();
    Point P[4] = {
            Point(0, 0, 0),
            Point(-1, 1, -0.5),
            Point(0.5, -1, -2.0),
            Point(0, -1, 0)
    };
    this->courbe = Curve(P, 4);
    this->droite = Vecteur(2, 2, 1);

    this->surface = Surface::CylindricalSurface(this->courbe.GetArray(), 4, this->droite, 10, 20);
}

void TP3Exo1::OnDraw() {
    this->camera.Apply();

    this->surface.Draw();
    glColor3f(1.0, 0.0, 0.0);
    this->courbe.Draw();
    glColor3f(0.0, 0.0, 1.0);
    this->courbe[0].Draw();
    glColor3f(1.0, 0.0, 0.0);
    this->courbe[1].Draw();
    this->courbe[2].Draw();
    this->courbe[3].Draw();
    Point P2[4] = {
            this->courbe[0] + this->droite,
            this->courbe[1] + this->droite,
            this->courbe[2] + this->droite,
            this->courbe[3] + this->droite
    };
    Curve(P2, 4).Draw();
    Segment(this->courbe[0], P2[0]).Draw();
    Segment(this->courbe[1], P2[1]).Draw();
    Segment(this->courbe[2], P2[2]).Draw();
    Segment(this->courbe[3], P2[3]).Draw();
}

void TP3Exo1::OnKeyboardEvent(unsigned char, int, int) {}

void TP3Exo1::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP3Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP3Exo1::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 2 ******/

TP3Exo2::TP3Exo2() :
        camera(Point(0.0, 0.0, 5.0))
{
    Fenetre::Actual().initPerspective();
    Point P1[4] = {
            Point(1, -2, 4),
            Point(-2, -1, 3),
            Point(-1, -1, 2),
            Point(1, -2, 2)
    };
    Point P2[4] = {
            Point(1, 1, 0),
            Point(1, 2, -2),
            Point(2, 1, -4),
            Point(1, 0, 0)
    };
    this->courbe1 = Curve(P1, 4);
    this->courbe2 = Curve(P2, 4);

    this->surface = Surface::RuledSurface(this->courbe1.GetArray(), 4, this->courbe2.GetArray(), 4, 10, 20);
}

void TP3Exo2::OnDraw() {
    this->camera.Apply();

    this->surface.Draw();
    glColor3f(1.0, 0.0, 0.0);
    this->courbe1.Draw();
    this->courbe2.Draw();
    this->courbe1[0].Draw();
    this->courbe1[1].Draw();
    this->courbe1[2].Draw();
    this->courbe1[3].Draw();
    this->courbe2[0].Draw();
    this->courbe2[1].Draw();
    this->courbe2[2].Draw();
    this->courbe2[3].Draw();
    Segment(this->courbe1[0], this->courbe2[0]).Draw();
    Segment(this->courbe1[1], this->courbe2[1]).Draw();
    Segment(this->courbe1[2], this->courbe2[2]).Draw();
    Segment(this->courbe1[3], this->courbe2[3]).Draw();
}

void TP3Exo2::OnKeyboardEvent(unsigned char, int, int) {}

void TP3Exo2::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP3Exo2::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP3Exo2::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 3 ******/

TP3Exo3::TP3Exo3() :
        camera(Point(0.0, 0.0, 6.0))
{
    Fenetre::Actual().initPerspective();

    P[0][0] = Point(-2, -2, 2); P[0][1] = Point(-2, -2, 1); P[0][2] = Point(-2, 2, -1); P[0][3] = Point(-2, 2, -2);
    P[1][0] = Point(-1, -1, 2); P[1][1] = Point(-1, 0, 1); P[1][2] = Point(-1, 0, -1); P[1][3] = Point(-1, 1, -2);
    P[2][0] = Point(1, -1, 2); P[2][1] = Point(1, 0, 1); P[2][2] = Point(1, 0, -1); P[2][3] = Point(1, 1, -2);
    P[3][0] = Point(2, -2, 2); P[3][1] = Point(2, -2, 1); P[3][2] = Point(2, 2, -1); P[3][3] = Point(2, 2, -2);

    this->surface = Surface::BezierSurfaceByCasteljau(P, 20, 20);
}

void TP3Exo3::OnDraw() {
    this->camera.Apply();

    this->surface.Draw();
    glColor3f(1.0, 0.0, 0.0);
    this->P.DrawWithLines();
    glColor3f(0.0, 0.0, 1.0);
    this->P[0][0].Draw();
}

void TP3Exo3::OnKeyboardEvent(unsigned char, int, int) {}

void TP3Exo3::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP3Exo3::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP3Exo3::OnMotionUnpressedEvent(int, int) {}