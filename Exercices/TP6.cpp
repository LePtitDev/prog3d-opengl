#include "TP6.hpp"

/****** EXERCICE 2 ******/

TP6Exo2::TP6Exo2() :
        camera(Point(0.0, 0.0, 15.0)), lumiere(Point(0, 0, 4)), mesh(0)
{
    Fenetre::Actual().initPerspective();

    this->nearR = camera.GetNearViewport();

    FileOFF file("Ressources/TP 6/buddha.off");
    this->buddha = file.GetMesh();
    this->buddha.Normalize();
    this->buddha.Scale(50, 50, 50);
    this->buddha.Translate(0, -7.5, 0);
    this->buddha.color = MeshColor(MeshColor::BRONZE);
    file.Load("Ressources/TP 6/bunny.off");
    this->bunny = file.GetMesh();
    this->bunny.Scale(50, 50, 50);
    this->bunny.Translate(1.5, -5, 0);
    this->bunny.RotateY(M_PI / 2);
    this->bunny.Normalize();
    this->bunny.color = MeshColor(MeshColor::BRASS);
    file.Load("Ressources/TP 6/max.off");
    this->max = file.GetMesh();
    this->max.Scale(0.03, 0.03, 0.03);
    this->max.Translate(-0.5, 0, -2);
    this->max.RotateY(M_PI);
    this->max.Normalize();
    this->max.color = MeshColor(MeshColor::SILVER);
    file.Load("Ressources/TP 6/triceratops.off");
    this->triceratops = file.GetMesh();
    this->triceratops.RotateY(-M_PI / 2);
    this->triceratops.Normalize();
    this->triceratops.color = MeshColor(MeshColor::PEARL);

    this->CPos = camera.GetPosition();

    Mesh::EnableSmooth();
}

void TP6Exo2::OnDraw() {
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

    Lumiere::DisableLights();
    glColor3f(1, 0, 0);
    this->nearR.Draw();
    glColor3f(0, 1, 0);
    Point tmp;
    switch (this->mesh) {
        case 0:
            for (unsigned int i = 0, sz = this->buddha.PointNumber(); i < sz; i++) {
                if (Droite(this->buddha[i], Vecteur::VectorByPoints(this->buddha[i], CPos)).GetIntersection(this->nearR.GetPlan(), tmp))
                    tmp.Draw();
            }
            break;
        case 1:
            for (unsigned int i = 0, sz = this->bunny.PointNumber(); i < sz; i++) {
                if (Droite(this->bunny[i], Vecteur::VectorByPoints(this->bunny[i], CPos)).GetIntersection(this->nearR.GetPlan(), tmp))
                    tmp.Draw();
            }
            break;
        case 2:
            for (unsigned int i = 0, sz = this->max.PointNumber(); i < sz; i++) {
                if (Droite(this->max[i], Vecteur::VectorByPoints(this->max[i], CPos)).GetIntersection(this->nearR.GetPlan(), tmp))
                    tmp.Draw();
            }
            break;
        case 3:
            for (unsigned int i = 0, sz = this->triceratops.PointNumber(); i < sz; i++) {
                if (Droite(this->triceratops[i], Vecteur::VectorByPoints(this->triceratops[i], CPos)).GetIntersection(this->nearR.GetPlan(), tmp))
                    tmp.Draw();
            }
    }
    Lumiere::EnableLights();
}

void TP6Exo2::OnKeyboardEvent(unsigned char keycode, int x, int y) {
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

        case 97: //a
            this->buddha.PolygonMode(GL_FILL);
            this->bunny.PolygonMode(GL_FILL);
            this->max.PolygonMode(GL_FILL);
            this->triceratops.PolygonMode(GL_FILL);
            break;
        case 122: //z
            this->buddha.PolygonMode(GL_LINE);
            this->bunny.PolygonMode(GL_LINE);
            this->max.PolygonMode(GL_LINE);
            this->triceratops.PolygonMode(GL_LINE);
            break;
        case 101: //e
            this->buddha.ShadeMode(GL_SMOOTH);
            this->bunny.ShadeMode(GL_SMOOTH);
            this->max.ShadeMode(GL_SMOOTH);
            this->triceratops.ShadeMode(GL_SMOOTH);
            break;
        case 114: //r
            this->buddha.ShadeMode(GL_FLAT);
            this->bunny.ShadeMode(GL_FLAT);
            this->max.ShadeMode(GL_FLAT);
            this->triceratops.ShadeMode(GL_FLAT);
            break;
        default:
            std::cout << "[KEY]: " << (int)keycode << std::endl;
    }
}

void TP6Exo2::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
    lumiere.pos = camera.pos;
}

void TP6Exo2::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
    lumiere.pos = camera.pos;
}

void TP6Exo2::OnMotionUnpressedEvent(int, int) {}

/****** EXERCICE 3 ******/

TP6Exo3::TP6Exo3() :
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

void TP6Exo3::OnDraw() {
    this->camera.Apply();
    this->lumiere.Apply();

    switch (this->mesh) {
        case 0:
            this->buddha.color = MeshColor(MeshColor::OBSIDIAN);
            this->buddha.DrawFront();
            this->buddha.color = MeshColor(MeshColor::RED_PLASTIC);
            this->buddha.DrawBack();
            break;
        case 1:
            this->bunny.color = MeshColor(MeshColor::BRASS);
            this->bunny.DrawFront();
            this->bunny.color = MeshColor(MeshColor::CYAN_RUBBER);
            this->bunny.DrawBack();
            break;
        case 2:
            this->max.color = MeshColor(MeshColor::EMERALD);
            this->max.DrawFront();
            this->max.color = MeshColor(MeshColor::CHROME);
            this->max.DrawBack();
            break;
        case 3:
            this->triceratops.color = MeshColor(MeshColor::BRONZE);
            this->triceratops.DrawFront();
            this->triceratops.color = MeshColor(MeshColor::JADE);
            this->triceratops.DrawBack();
    }
}

void TP6Exo3::OnKeyboardEvent(unsigned char keycode, int x, int y) {
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

        case 97: //a
            this->buddha.PolygonMode(GL_FILL);
            this->bunny.PolygonMode(GL_FILL);
            this->max.PolygonMode(GL_FILL);
            this->triceratops.PolygonMode(GL_FILL);
            break;
        case 122: //z
            this->buddha.PolygonMode(GL_LINE);
            this->bunny.PolygonMode(GL_LINE);
            this->max.PolygonMode(GL_LINE);
            this->triceratops.PolygonMode(GL_LINE);
            break;
        case 101: //e
            this->buddha.ShadeMode(GL_SMOOTH);
            this->bunny.ShadeMode(GL_SMOOTH);
            this->max.ShadeMode(GL_SMOOTH);
            this->triceratops.ShadeMode(GL_SMOOTH);
            break;
        case 114: //r
            this->buddha.ShadeMode(GL_FLAT);
            this->bunny.ShadeMode(GL_FLAT);
            this->max.ShadeMode(GL_FLAT);
            this->triceratops.ShadeMode(GL_FLAT);
            break;
        default:
            std::cout << "[KEY]: " << (int)keycode << std::endl;
    }
}

void TP6Exo3::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
    lumiere.pos = camera.pos;
}

void TP6Exo3::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
    lumiere.pos = camera.pos;
}

void TP6Exo3::OnMotionUnpressedEvent(int, int) {}