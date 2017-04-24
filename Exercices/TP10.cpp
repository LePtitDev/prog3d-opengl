#include "TP10.hpp"

/****** EXERCICE 1 ******/

TP10Exo1::TP10Exo1() :
    camera(Point(0, 0, -8)), disp(1)
{
    Fenetre::Actual().initPerspective();

    this->mesh1 = FileOFF("Ressources/TP 6/max.off").GetDynamicMesh();
    this->mesh1.Reposition(Box(Point(-3, -3, -3), Vecteur(6, 6, 6), Vecteur(6, 6, 6), Vecteur(6, 6, 6)));

    this->mesh2 = this->mesh1;
    Grille3D grille(Point(-3, -3, -3), Vecteur(1, 1, 1), 6);
    this->mesh2.Merge(grille);
    //this->mesh2.SubdivideByButterfly();
    //this->mesh2.SubdivideByButterfly();
    this->mesh1.Normalize();
    this->mesh2.Normalize();

    this->mesh1.CalculateDistance(this->mesh2);
    this->mesh2.CalculateDistance(this->mesh1);
}

void TP10Exo1::OnDraw3D() {
    camera.Apply();

    if (this->disp == 0) {
        glColor3f(0.5, 0.3, 0.8);
        this->mesh1.DrawDistances();
        glColor3f(1, 1, 1);
        this->mesh1.DrawLines();
        //glColor3f(1, 0, 0);
        //this->mesh1.DrawNormals();
    }
    else {
        glColor3f(0.8, 0.3, 0.5);
        this->mesh2.DrawDistances();
        glColor3f(1, 1, 1);
        this->mesh2.DrawLines();
        //glColor3f(1, 0, 0);
        //this->mesh2.DrawNormals();
    }
}
void TP10Exo1::OnDraw2D() {}

void TP10Exo1::OnKeyboardEvent(unsigned char key, int, int) {
    switch (key) {
        case 38: //&
            this->disp = (this->disp + 1) % 2;
            break;
        default:
            std::cout << "[KEY]: " << (int)key << std::endl;
            break;
    }
}

void TP10Exo1::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP10Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

/****** EXERCICE 2 ******/

TP10Exo2::TP10Exo2() :
    camera(Point(0, 0, -8)), disp(1)
{
    Fenetre::Actual().initPerspective();

    this->mesh1 = FileOFF("Ressources/TP 6/max.off").GetDynamicMesh();
    this->mesh1.Reposition(Box(Point(-3, -3, -3), Vecteur(6, 6, 6), Vecteur(6, 6, 6), Vecteur(6, 6, 6)));

    this->mesh2 = this->mesh1;
    this->mesh2.SubdivideByButterfly();
    this->mesh2.SubdivideByButterfly();
    this->mesh1.Normalize();
    this->mesh2.Normalize();

    uTimer timer;
    timer.Start();
    this->mesh2.CalculateDistance(this->mesh1);
    std::cout << "Temps de calcul du premier : " << timer.GetTime() << std::endl;
    //timer.Stop();
    //timer.Start();
    this->mesh2.CalculateDistanceByOctree(this->mesh1);
    //std::cout << "Temps de calcul du second : " << timer.GetTime() << std::endl;
    //timer.Stop();
}

void TP10Exo2::OnDraw3D() {
    camera.Apply();

    if (this->disp == 0) {
        glColor3f(0.5, 0.3, 0.8);
        this->mesh1.Draw();
        glColor3f(1, 1, 1);
        this->mesh1.DrawLines();
        //glColor3f(1, 0, 0);
        //this->mesh1.DrawNormals();
    }
    else {
        glColor3f(0.8, 0.3, 0.5);
        this->mesh2.DrawDistances();
        glColor3f(1, 1, 1);
        this->mesh2.DrawLines();
        //glColor3f(1, 0, 0);
        //this->mesh2.DrawNormals();
    }
}
void TP10Exo2::OnDraw2D() {}

void TP10Exo2::OnKeyboardEvent(unsigned char key, int, int) {
    switch (key) {
        case 38: //&
            this->disp = (this->disp + 1) % 2;
            break;
        default:
            std::cout << "[KEY]: " << (int)key << std::endl;
            break;
    }
}

void TP10Exo2::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP10Exo2::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}