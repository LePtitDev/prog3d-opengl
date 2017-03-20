#include "TP9.hpp"

/****** EXERCICE 1 ******/

TP9Exo1::TP9Exo1() :
    camera(Point(0, 0, 7))
{
    Fenetre::Actual().initPerspective();

    this->mesh = FileOFF("Ressources/TP 9/cube.off").GetMesh();
    this->mesh.CalculateAretes();
    this->mesh.Fusion2Points(0, 1);
}

void TP9Exo1::OnDraw3D() {
    camera.Apply();

    glColor3f(0.5, 0.3, 0.8);
    this->mesh.PolygonMode(GL_FILL);
    this->mesh.Draw();
    glColor3f(1, 1, 1);
    this->mesh.PolygonMode(GL_LINE);
    this->mesh.Draw();

}
void TP9Exo1::OnDraw2D() {}

void TP9Exo1::OnKeyboardEvent(unsigned char, int, int) {}

void TP9Exo1::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP9Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP9Exo1::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 2 ******/

TP9Exo2::TP9Exo2() :
    camera(Point(0, 0, 7)), grille(Point(-3, -3, -3), Vecteur(1, 1, 1), 6)
{
    Fenetre::Actual().initPerspective();

    this->mesh = FileOFF("Ressources/TP 6/bunny.off").GetMesh();
    this->mesh.CalculateAretes();
    this->mesh.Reposition(Box(Point(-3, -3, -3), Vecteur(6, 6, 6), Vecteur(6, 6, 6), Vecteur(6, 6, 6)));
    this->mesh.Fusion(this->grille);
}

void TP9Exo2::OnDraw3D() {
    camera.Apply();

    glColor3f(0.5, 0.3, 0.8);
    this->mesh.PolygonMode(GL_FILL);
    this->mesh.Draw();
    glColor3f(1, 1, 1);
    this->mesh.PolygonMode(GL_LINE);
    this->mesh.Draw();
    glColor3f(1, 0, 0);
    for (unsigned int i = 0, sz = this->mesh.PointNumber(); i < sz; i++) {
        this->mesh[i].Draw();
    }

    this->grille.Draw();

}
void TP9Exo2::OnDraw2D() {}

void TP9Exo2::OnKeyboardEvent(unsigned char, int, int) {}

void TP9Exo2::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP9Exo2::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP9Exo2::OnMotionUnpressedEvent(int, int) {}