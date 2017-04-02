#include "TP9.hpp"

/****** EXERCICE 1 ******/

TP9Exo1::TP9Exo1() :
    camera(Point(0, 0, 7))
{
    Fenetre::Actual().initPerspective();

    this->mesh = FileOFF("Ressources/TP 9/cube.off").GetMesh().ToDynamicMesh();
    this->mesh.Merge(0, 1);
}

void TP9Exo1::OnDraw3D() {
    camera.Apply();

    glColor3f(0.5, 0.3, 0.8);
    this->mesh.Draw();
    glColor3f(1, 1, 1);
    this->mesh.DrawLines();
    glColor3f(1, 0, 0);
    this->mesh.DrawPoints();

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
    camera(Point(5, 5, 10)), grille(Point(-3, -3, -3), Vecteur(1, 1, 1), 6), reduced(false), display_reduced(false), display_grid(true)
{
    Fenetre::Actual().initPerspective();

    Mesh m = FileOFF("Ressources/TP 9/triceratops(12).off").GetMesh();
    m.Reposition(Box(Point(-3, -3, -3), Vecteur(6, 6, 6), Vecteur(6, 6, 6), Vecteur(6, 6, 6)));

    this->mesh = m.ToDynamicMesh();
    this->mesh_cpy = this->mesh;
}

void TP9Exo2::OnDraw3D() {
    if (!this->reduced && this->display_reduced) {
        this->timer.Start();
        this->mesh.Merge(this->grille);
        this->timer.Stop();
        this->reduced = true;
    }

    camera.Apply();

    if (!reduced || !display_reduced) {
        glColor3f(0.5, 0.3, 0.8);
        this->mesh_cpy.Draw();
        //glColor3f(0.8, 0.6, 0.4);
        //this->mesh_cpy.DrawLines();
        //glColor3f(1, 0, 0);
        //this->mesh_cpy.DrawPoints();
        glColor3f(1, 0, 0);
        this->mesh_cpy.DrawLines();
    }
    else {
        glColor3f(0.5, 0.3, 0.8);
        this->mesh.Draw();
        //glColor3f(0.8, 0.6, 0.4);
        //this->mesh.DrawLines();
        //glColor3f(1, 0, 0);
        //this->mesh.DrawPoints();
        glColor3f(1, 0, 0);
        this->mesh.DrawLines();
    }

    if (this->display_grid) {
        glColor3f(1, 1, 1);
        this->grille.Draw();
    }
}
void TP9Exo2::OnDraw2D() {
    glColor3f(1, 1, 1);
    if (reduced) {
        glRasterPos2i(10, 10);
        std::stringstream stext;
        stext << "TEMPS DE CALCUL : ";
        stext << timer.GetTime();
        stext << " sec";
        std::string text = stext.str();
        for (int i = 0, sz = text.size(); i < sz; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
        }
    }
    else {
        glRasterPos2i(10, 10);
        std::string text = "CALCUL EN COURS";
        for (int i = 0, sz = text.size(); i < sz; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
        }
        this->display_reduced = true;
    }
}

void TP9Exo2::OnKeyboardEvent(unsigned char key, int, int) {
    switch (key) {
        case 38: //&
            this->display_reduced = !this->display_reduced;
            break;
        case 233: //é
            this->display_grid = !this->display_grid;
            break;
        default:
            std::cout << "[KEY]: " << (int)key << std::endl;
            break;
    }
}

void TP9Exo2::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP9Exo2::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP9Exo2::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 3 ******/

TP9Exo3::TP9Exo3() :
        camera(Point(0, 0, 7))
{
    Fenetre::Actual().initPerspective();

    this->mesh = FileOFF("Ressources/TP 9/cube.off").GetMesh().ToDynamicMesh();
    this->mesh.Subdivide();
}

void TP9Exo3::OnDraw3D() {
    camera.Apply();

    glColor3f(0.5, 0.3, 0.8);
    this->mesh.Draw();
    glColor3f(1, 1, 1);
    this->mesh.DrawLines();
    glColor3f(1, 0, 0);
    this->mesh.DrawPoints();

}
void TP9Exo3::OnDraw2D() {}

void TP9Exo3::OnKeyboardEvent(unsigned char, int, int) {}

void TP9Exo3::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP9Exo3::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

/****** EXERCICE 4 ******/

TP9Exo4::TP9Exo4() :
        camera(Point(5, 5, 10)), reduced(false), figure(0)
{
    Fenetre::Actual().initPerspective();

    Mesh m = FileOFF("Ressources/TP 6/max.off").GetMesh();
    m.Reposition(Box(Point(-3, -3, -3), Vecteur(6, 6, 6), Vecteur(6, 6, 6), Vecteur(6, 6, 6)));

    this->mesh = m.ToDynamicMesh();
    this->mesh_ssub = this->mesh;
    this->mesh_cpy = this->mesh;
}

void TP9Exo4::OnDraw3D() {
    if (!this->reduced && this->figure != 0) {
        this->timer.Start();
        this->mesh_ssub.Subdivide();
        this->mesh.SubdivideByButterfly();
        this->timer.Stop();
        this->reduced = true;
    }

    camera.Apply();

    if (!reduced || this->figure == 0) {
        glColor3f(0.5, 0.3, 0.8);
        this->mesh_cpy.Draw();
        glColor3f(1, 1, 1);
        this->mesh_cpy.DrawLines();
        //glColor3f(1, 0, 0);
        //this->mesh_cpy.DrawPoints();
    }
    else if (this->figure == 1) {
        glColor3f(0.5, 0.3, 0.8);
        this->mesh_ssub.Draw();
        glColor3f(1, 1, 1);
        this->mesh_ssub.DrawLines();
        //glColor3f(1, 0, 0);
        //this->mesh_ssub.DrawPoints();
    }
    else {
        glColor3f(0.5, 0.3, 0.8);
        this->mesh.Draw();
        glColor3f(1, 1, 1);
        this->mesh.DrawLines();
        //glColor3f(1, 0, 0);
        //this->mesh.DrawPoints();
    }
}
void TP9Exo4::OnDraw2D() {
    glColor3f(1, 1, 1);
    if (reduced) {
        glRasterPos2i(10, 10);
        std::stringstream stext;
        stext << "TEMPS DE CALCUL : ";
        stext << timer.GetTime();
        stext << " sec";
        std::string text = stext.str();
        for (int i = 0, sz = text.size(); i < sz; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
        }
    }
    else {
        glRasterPos2i(10, 10);
        std::string text = "CALCUL EN COURS";
        for (int i = 0, sz = text.size(); i < sz; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
        }
        this->figure = 2;
    }
}

void TP9Exo4::OnKeyboardEvent(unsigned char key, int, int) {
    switch (key) {
        case 38: //&
            this->figure = 0;
            break;
        case 233: //é
            this->figure = 1;
            break;
        case 34: //"
            this->figure = 2;
            break;
        default:
            std::cout << "[KEY]: " << (int)key << std::endl;
            break;
    }
}

void TP9Exo4::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP9Exo4::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}