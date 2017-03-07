#include "TP6.hpp"

/****** EXERCICE 2 ******/

TP6Exo2::TP6Exo2() :
        camera(Point(0.0, 0.0, 15.0)), lumiere(Point(0, 0, 4)), mesh(0), display_projection(false), area_box(Point(-5, -5, -5), Vecteur(10, 0, 0), Vecteur(0, 10, 0), Vecteur(0, 0, 10)),
        bt_buddha("Buddha", 10, 10, 80, 30, TP6Exo2::action_bt_buddha, (void*)this),
        bt_bunny("Bunny", 100, 10, 80, 30, TP6Exo2::action_bt_bunny, (void*)this),
        bt_max("Max", 190, 10, 80, 30, TP6Exo2::action_bt_max, (void*)this),
        bt_triceratops("Triceratops", 280, 10, 80, 30, TP6Exo2::action_bt_triceratops, (void*)this),
        sw_poly("Polygones pleins", true, 10, 50, 100, 30, TP6Exo2::action_sw_poly, (void*)this),
        sw_shade("Smooth", true, 10, 90, 100, 30, TP6Exo2::action_sw_shade, (void*)this),
        sw_projection("Afficher la projection", false, 10, 200, 100, 30, TP6Exo2::action_sw_projection, (void*)this),
        fps_count(800, 10, 200, 150, uColor::CYAN)
{
    Fenetre::Actual().initPerspective();

    layout.AddWidget(bt_buddha);
    layout.AddWidget(bt_bunny);
    layout.AddWidget(bt_max);
    layout.AddWidget(bt_triceratops);
    layout.AddWidget(sw_poly);
    layout.AddWidget(sw_shade);
    layout.AddWidget(sw_projection);
    layout.AddWidget(fps_count);

    FileOFF file("Ressources/TP 6/buddha.off");
    this->buddha = file.GetMesh();
    this->buddha.color = MeshColor(MeshColor::BRONZE);
    file.Load("Ressources/TP 6/bunny.off");
    this->bunny = file.GetMesh();
    this->bunny.color = MeshColor(MeshColor::BRASS);
    file.Load("Ressources/TP 6/max.off");
    this->max = file.GetMesh();
    this->max.color = MeshColor(MeshColor::SILVER);
    file.Load("Ressources/TP 6/triceratops.off");
    this->triceratops = file.GetMesh();
    this->triceratops.color = MeshColor(MeshColor::PEARL);

    this->camera.Reposition(this->buddha.GetBox());
    this->lumiere.pos = this->camera.pos;

    this->CPos = this->camera.GetPosition();
    this->nearR = this->camera.GetNearViewport();

    Mesh::EnableSmooth();
}

void TP6Exo2::OnDraw3D() {
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

    if (this->display_projection) {
        Lumiere::DisableLights();
        glColor3f(1, 0, 0);
        this->nearR.Draw();
        glColor3f(0, 1, 0);
        Point tmp;
        switch (this->mesh) {
            case 0:
                for (unsigned int i = 0, sz = this->buddha.PointNumber(); i < sz; i++) {
                    if (Droite(this->buddha[i], Vecteur::VectorByPoints(this->buddha[i], CPos)).GetIntersection(
                            this->nearR.GetPlan(), tmp))
                        tmp.Draw();
                }
                break;
            case 1:
                for (unsigned int i = 0, sz = this->bunny.PointNumber(); i < sz; i++) {
                    if (Droite(this->bunny[i], Vecteur::VectorByPoints(this->bunny[i], CPos)).GetIntersection(
                            this->nearR.GetPlan(), tmp))
                        tmp.Draw();
                }
                break;
            case 2:
                for (unsigned int i = 0, sz = this->max.PointNumber(); i < sz; i++) {
                    if (Droite(this->max[i], Vecteur::VectorByPoints(this->max[i], CPos)).GetIntersection(
                            this->nearR.GetPlan(), tmp))
                        tmp.Draw();
                }
                break;
            case 3:
                for (unsigned int i = 0, sz = this->triceratops.PointNumber(); i < sz; i++) {
                    if (Droite(this->triceratops[i],
                               Vecteur::VectorByPoints(this->triceratops[i], CPos)).GetIntersection(
                            this->nearR.GetPlan(), tmp))
                        tmp.Draw();
                }
        }
        Lumiere::EnableLights();
    }

    if (this->inters.size() > 0) {
        Lumiere::DisableLights();
        glBegin(GL_POINTS);
        glColor3f(1, 0, 0);
        for (unsigned i = 0, sz = this->inters.size(); i < sz; i++) {
            this->inters[i].Apply();
        }
        glEnd();
        Lumiere::EnableLights();
    }
}
void TP6Exo2::OnDraw2D() {
    this->layout.OnDisplay();
}

void TP6Exo2::OnKeyboardEvent(unsigned char keycode, int x, int y) {}

void TP6Exo2::OnMouseEvent(int button, int state, int x, int y) {
    if (!this->layout.MouseInside(x, y))
        camera.OnMouseEvent(button, state, x, y);
    lumiere.pos = camera.pos;
    this->layout.OnMouseEvent(button, state, x, y);
    if (button == 1 && state == 0) {
        switch (this->mesh) {
            case 0:
                this->inters = Raycaster::RayOnScreen(this->camera, x, y, this->buddha);
                break;
            case 1:
                this->inters = Raycaster::RayOnScreen(this->camera, x, y, this->bunny);
                break;
            case 2:
                this->inters = Raycaster::RayOnScreen(this->camera, x, y, this->max);
                break;
            case 3:
                this->inters = Raycaster::RayOnScreen(this->camera, x, y, this->triceratops);
                break;
        }
    }
}

void TP6Exo2::OnMotionPressedEvent(int x, int y) {
    if (!this->layout.MouseInside(x, y))
        camera.OnMotionPressedEvent(x, y);
    lumiere.pos = camera.pos;
    this->layout.OnMotionPressedEvent(x, y);
}

void TP6Exo2::OnMotionUnpressedEvent(int x, int y) {
    this->layout.OnMotionPressedEvent(x, y);
}

void TP6Exo2::action_bt_buddha(void * args) {
    TP6Exo2 * exo = (TP6Exo2 *)args;
    exo->camera.Reposition(exo->buddha.GetBox());
    exo->lumiere.pos = exo->camera.pos;
    exo->mesh = 0;
    exo->CPos = exo->camera.GetPosition();
    exo->nearR = exo->camera.GetNearViewport();
    exo->inters.clear();
}
void TP6Exo2::action_bt_bunny(void * args) {
    TP6Exo2 * exo = (TP6Exo2 *)args;
    exo->camera.Reposition(exo->bunny.GetBox());
    exo->lumiere.pos = exo->camera.pos;
    exo->mesh = 1;
    exo->CPos = exo->camera.GetPosition();
    exo->nearR = exo->camera.GetNearViewport();
    exo->inters.clear();
}
void TP6Exo2::action_bt_max(void * args) {
    TP6Exo2 * exo = (TP6Exo2 *)args;
    exo->camera.Reposition(exo->max.GetBox());
    exo->lumiere.pos = exo->camera.pos;
    exo->mesh = 2;
    exo->CPos = exo->camera.GetPosition();
    exo->nearR = exo->camera.GetNearViewport();
    exo->inters.clear();
}
void TP6Exo2::action_bt_triceratops(void * args) {
    TP6Exo2 * exo = (TP6Exo2 *)args;
    exo->camera.Reposition(exo->triceratops.GetBox());
    exo->lumiere.pos = exo->camera.pos;
    exo->mesh = 3;
    exo->CPos = exo->camera.GetPosition();
    exo->nearR = exo->camera.GetNearViewport();
    exo->inters.clear();
}
void TP6Exo2::action_sw_poly(bool state, void * args) {
    TP6Exo2 * exo = (TP6Exo2 *)args;
    if (state) {
        exo->buddha.PolygonMode(GL_FILL);
        exo->bunny.PolygonMode(GL_FILL);
        exo->max.PolygonMode(GL_FILL);
        exo->triceratops.PolygonMode(GL_FILL);
    }
    else {
        exo->buddha.PolygonMode(GL_LINE);
        exo->bunny.PolygonMode(GL_LINE);
        exo->max.PolygonMode(GL_LINE);
        exo->triceratops.PolygonMode(GL_LINE);
    }
}
void TP6Exo2::action_sw_shade(bool state, void * args) {
    TP6Exo2 * exo = (TP6Exo2 *)args;
    if (state) {
        exo->buddha.ShadeMode(GL_SMOOTH);
        exo->bunny.ShadeMode(GL_SMOOTH);
        exo->max.ShadeMode(GL_SMOOTH);
        exo->triceratops.ShadeMode(GL_SMOOTH);
    }
    else {
        exo->buddha.ShadeMode(GL_FLAT);
        exo->bunny.ShadeMode(GL_FLAT);
        exo->max.ShadeMode(GL_FLAT);
        exo->triceratops.ShadeMode(GL_FLAT);
    }
}
void TP6Exo2::action_sw_projection(bool state, void * args) {
    TP6Exo2 * exo = (TP6Exo2 *)args;
    exo->display_projection = state;
}

/****** EXERCICE 3 ******/

TP6Exo3::TP6Exo3() :
        camera(Point(0.0, 0.0, 15.0)), lumiere(Point(0, 0, 4)), mesh(0),
        bt_buddha("Buddha", 10, 10, 80, 30, TP6Exo3::action_bt_buddha, (void*)this),
        bt_bunny("Bunny", 100, 10, 80, 30, TP6Exo3::action_bt_bunny, (void*)this),
        bt_max("Max", 190, 10, 80, 30, TP6Exo3::action_bt_max, (void*)this),
        bt_triceratops("Triceratops", 280, 10, 80, 30, TP6Exo3::action_bt_triceratops, (void*)this),
        sw_poly("Polygones pleins", true, 10, 50, 100, 30, TP6Exo3::action_sw_poly, (void*)this),
        sw_shade("Smooth", true, 10, 90, 100, 30, TP6Exo3::action_sw_shade, (void*)this),
        fps_count(800, 10, 200, 150, uColor::CYAN)
{
    Fenetre::Actual().initPerspective();

    layout.AddWidget(bt_buddha);
    layout.AddWidget(bt_bunny);
    layout.AddWidget(bt_max);
    layout.AddWidget(bt_triceratops);
    layout.AddWidget(sw_poly);
    layout.AddWidget(sw_shade);
    layout.AddWidget(fps_count);

    FileOFF file("Ressources/TP 6/buddha.off");
    this->buddha = file.GetMesh();
    file.Load("Ressources/TP 6/bunny.off");
    this->bunny = file.GetMesh();
    file.Load("Ressources/TP 6/max.off");
    this->max = file.GetMesh();
    file.Load("Ressources/TP 6/triceratops.off");
    this->triceratops = file.GetMesh();
    
    camera.Reposition(this->buddha.GetBox());

    Mesh::EnableSmooth();
}

void TP6Exo3::OnDraw3D() {
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
void TP6Exo3::OnDraw2D() {
    layout.OnDisplay();
}

void TP6Exo3::OnKeyboardEvent(unsigned char keycode, int x, int y) {}

void TP6Exo3::OnMouseEvent(int button, int state, int x, int y) {
    if (!this->layout.MouseInside(x, y))
        camera.OnMouseEvent(button, state, x, y);
    lumiere.pos = camera.pos;
    this->layout.OnMouseEvent(button, state, x, y);
}

void TP6Exo3::OnMotionPressedEvent(int x, int y) {
    if (!this->layout.MouseInside(x, y))
        camera.OnMotionPressedEvent(x, y);
    lumiere.pos = camera.pos;
    this->layout.OnMotionPressedEvent(x, y);
}

void TP6Exo3::OnMotionUnpressedEvent(int x, int y) {
    this->layout.OnMotionUnpressedEvent(x, y);
}

void TP6Exo3::action_bt_buddha(void * args) {
    TP6Exo3 * exo = (TP6Exo3 *)args;
    exo->camera.Reposition(exo->buddha.GetBox());
    exo->lumiere.pos = exo->camera.pos;
    exo->mesh = 0;
}
void TP6Exo3::action_bt_bunny(void * args) {
    TP6Exo3 * exo = (TP6Exo3 *)args;
    exo->camera.Reposition(exo->bunny.GetBox());
    exo->lumiere.pos = exo->camera.pos;
    exo->mesh = 1;
}
void TP6Exo3::action_bt_max(void * args) {
    TP6Exo3 * exo = (TP6Exo3 *)args;
    exo->camera.Reposition(exo->max.GetBox());
    exo->lumiere.pos = exo->camera.pos;
    exo->mesh = 2;
}
void TP6Exo3::action_bt_triceratops(void * args) {
    TP6Exo3 * exo = (TP6Exo3 *)args;
    exo->camera.Reposition(exo->triceratops.GetBox());
    exo->lumiere.pos = exo->camera.pos;
    exo->mesh = 3;
}
void TP6Exo3::action_sw_poly(bool state, void * args) {
    TP6Exo3 * exo = (TP6Exo3 *)args;
    if (state) {
        exo->buddha.PolygonMode(GL_FILL);
        exo->bunny.PolygonMode(GL_FILL);
        exo->max.PolygonMode(GL_FILL);
        exo->triceratops.PolygonMode(GL_FILL);
    }
    else {
        exo->buddha.PolygonMode(GL_LINE);
        exo->bunny.PolygonMode(GL_LINE);
        exo->max.PolygonMode(GL_LINE);
        exo->triceratops.PolygonMode(GL_LINE);
    }
}
void TP6Exo3::action_sw_shade(bool state, void * args) {
    TP6Exo3 * exo = (TP6Exo3 *)args;
    if (state) {
        exo->buddha.ShadeMode(GL_SMOOTH);
        exo->bunny.ShadeMode(GL_SMOOTH);
        exo->max.ShadeMode(GL_SMOOTH);
        exo->triceratops.ShadeMode(GL_SMOOTH);
    }
    else {
        exo->buddha.ShadeMode(GL_FLAT);
        exo->bunny.ShadeMode(GL_FLAT);
        exo->max.ShadeMode(GL_FLAT);
        exo->triceratops.ShadeMode(GL_FLAT);
    }
}