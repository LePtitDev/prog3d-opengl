#include "TP7.hpp"

TP7Exo1::TP7Exo1() :
    camera(Point(0, 0, 50)), lumiere(Point(0, 0, 50)), cylinder(Point(0, 0, 0), Vecteur(0, 15, 0), 10, 1), ball(Point(0, 0, 0), 20, 1, 1)
{
    Fenetre::Actual().initPerspective();

    this->mesh = ball.GetMesh(20);//cylinder.GetMesh(20, 20);
    this->mesh.color = MeshColor(MeshColor::BRASS);
}

void TP7Exo1::OnDraw3D() {
    this->camera.Apply();
    this->lumiere.Apply();
    
    this->mesh.Draw();
    this->mesh.PolygonMode(GL_LINE);
    this->mesh.color = MeshColor(MeshColor::RUBY);
    this->mesh.Draw();
    //this->mesh.DrawNormals();
    this->mesh.PolygonMode(GL_FILL);
    this->mesh.color = MeshColor(MeshColor::BRASS);
}

void TP7Exo1::OnDraw2D() {
    
}

void TP7Exo1::OnKeyboardEvent(unsigned char keycode, int x, int y) {}

void TP7Exo1::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP7Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP7Exo1::OnMotionUnpressedEvent(int x, int y) {
    
}