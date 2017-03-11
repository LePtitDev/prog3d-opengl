#include "TP7.hpp"

TP7Exo1::TP7Exo1() :
    camera(Point(0, 0, 50)), lumiere(Point(0, 0, 100)), cylinder(Point(0, 0, 0), Vecteur(0, 15, 0), 10, 1), ball(Point(0, 0, 0), 20, 1, 1), nb_segments(10), figure(0),
    layout(),
    bt_prec("<", 50, 370, 30, 30, TP7Exo1::action_bt_prec, this),
    bt_suiv(">", 950, 370, 30, 30, TP7Exo1::action_bt_suiv, this),
    bt_plus("+", 550, 50, 30, 30, TP7Exo1::action_bt_plus, this),
    bt_moins("-", 450, 50, 30, 30, TP7Exo1::action_bt_moins, this)
{
    Fenetre::Actual().initPerspective();

    layout.AddWidget(bt_prec);
    layout.AddWidget(bt_suiv);
    layout.AddWidget(bt_plus);
    layout.AddWidget(bt_moins);

    this->mesh = cylinder.GetMesh(nb_segments, nb_segments);
    this->mesh.color = MeshColor(MeshColor::BRASS);
    this->mesh.Normalize();
}

void TP7Exo1::OnDraw3D() {
    this->camera.Apply();
    this->lumiere.Apply();
    
    this->mesh.Draw();
    this->mesh.PolygonMode(GL_LINE);
    this->mesh.color = MeshColor(MeshColor::RUBY);
    this->mesh.Draw();
    this->mesh.PolygonMode(GL_FILL);
    this->mesh.color = MeshColor(MeshColor::BRASS);
}

void TP7Exo1::OnDraw2D() {
    layout.OnDisplay();
    glViewport(100, 100, 100, 100);
    uColor::RED.Apply3f();
    glPointSize(2);
    gluPerspective(45, 1, 1, 100);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    Vecteur v = Vecteur::VectorByPoints(Point(), this->camera.pos); v.Normalize();
    Camera(Point() + v).Apply();
    for (unsigned int i = 0, sz = this->mesh.PointNumber(); i < sz; i++) {
        (Point() + this->mesh.GetNormal(i)).Draw();
    }
    glViewport(0, 0, Fenetre::Actual().GetWidth(), Fenetre::Actual().GetHeight());
}

void TP7Exo1::OnKeyboardEvent(unsigned char keycode, int x, int y) {}

void TP7Exo1::OnMouseEvent(int button, int state, int x, int y) {
    if (!layout.MouseInside(x, y))
        camera.OnMouseEvent(button, state, x, y);
    layout.OnMouseEvent(button, state, x, y);
}

void TP7Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
    layout.OnMotionPressedEvent(x, y);
}

void TP7Exo1::OnMotionUnpressedEvent(int x, int y) {
    layout.OnMotionUnpressedEvent(x, y);
}

void TP7Exo1::action_bt_prec(void * args) {
    TP7Exo1 * exo = (TP7Exo1 *)args;
    if (exo->figure = (exo->figure + 1) % 2) {
        exo->mesh = exo->ball.GetMesh(exo->nb_segments);
        exo->mesh.Normalize();
    }
    else {
        exo->mesh = exo->cylinder.GetMesh(exo->nb_segments, exo->nb_segments);
        exo->mesh.Normalize();
    }
}

void TP7Exo1::action_bt_suiv(void * args) {
    TP7Exo1::action_bt_prec(args);
}

void TP7Exo1::action_bt_plus(void * args) {
    TP7Exo1 * exo = (TP7Exo1 *)args;
    exo->nb_segments++;
    if (exo->figure) {
        exo->mesh = exo->ball.GetMesh(exo->nb_segments);
        exo->mesh.Normalize();
    }
    else {
        exo->mesh = exo->cylinder.GetMesh(exo->nb_segments, exo->nb_segments);
        exo->mesh.Normalize();
    }
}

void TP7Exo1::action_bt_moins(void * args) {
    TP7Exo1 * exo = (TP7Exo1 *)args;
    exo->nb_segments--;
    if (exo->figure) {
        exo->mesh = exo->ball.GetMesh(exo->nb_segments);
        exo->mesh.Normalize();
    }
    else {
        exo->mesh = exo->cylinder.GetMesh(exo->nb_segments, exo->nb_segments);
        exo->mesh.Normalize();
    }
}