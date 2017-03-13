#include "Mesh.hpp"

MeshColor::MeshColor(MeshColor::MESH_COLOR color) {
    switch (color) {
        case MeshColor::WHITE:
            this->ambiant[0] = 1.0;
            this->ambiant[1] = 1.0;
            this->ambiant[2] = 1.0;
            this->diffuse[0] = 1.0;
            this->diffuse[1] = 1.0;
            this->diffuse[2] = 1.0;
            this->specular[0] = 1.0;
            this->specular[1] = 1.0;
            this->specular[2] = 1.0;
            this->shininess = 1.0;
            break;
        case MeshColor::EMERALD:
            this->ambiant[0] = 0.0215;
            this->ambiant[1] = 0.1745;
            this->ambiant[2] = 0.0215;
            this->diffuse[0] = 0.07568;
            this->diffuse[1] = 0.61424;
            this->diffuse[2] = 0.07568;
            this->specular[0] = 0.633;
            this->specular[1] = 0.727811;
            this->specular[2] = 0.633;
            this->shininess = 0.6;
            break;
        case MeshColor::JADE:
            this->ambiant[0] = 0.135;
            this->ambiant[1] = 0.2225;
            this->ambiant[2] = 0.1575;
            this->diffuse[0] = 0.54;
            this->diffuse[1] = 0.89;
            this->diffuse[2] = 0.63;
            this->specular[0] = 0.316228;
            this->specular[1] = 0.316228;
            this->specular[2] = 0.316228;
            this->shininess = 0.1;
            break;
        case MeshColor::OBSIDIAN:
            this->ambiant[0] = 0.05375;
            this->ambiant[1] = 0.05;
            this->ambiant[2] = 0.06625;
            this->diffuse[0] = 0.18275;
            this->diffuse[1] = 0.17;
            this->diffuse[2] = 0.22525;
            this->specular[0] = 0.332741;
            this->specular[1] = 0.328634;
            this->specular[2] = 0.346435;
            this->shininess = 0.3;
            break;
        case MeshColor::PEARL:
            this->ambiant[0] = 0.25;
            this->ambiant[1] = 0.20725;
            this->ambiant[2] = 0.20725;
            this->diffuse[0] = 1.0;
            this->diffuse[1] = 0.829;
            this->diffuse[2] = 0.829;
            this->specular[0] = 0.296648;
            this->specular[1] = 0.296648;
            this->specular[2] = 0.296648;
            this->shininess = 0.088;
            break;
        case MeshColor::RUBY:
            this->ambiant[0] = 0.1745;
            this->ambiant[1] = 0.01175;
            this->ambiant[2] = 0.01175;
            this->diffuse[0] = 0.61424;
            this->diffuse[1] = 0.04136;
            this->diffuse[2] = 0.04136;
            this->specular[0] = 0.727811;
            this->specular[1] = 0.626959;
            this->specular[2] = 0.626959;
            this->shininess = 0.6;
            break;
        case MeshColor::TURQUOISE:
            this->ambiant[0] = 0.1;
            this->ambiant[1] = 0.18725;
            this->ambiant[2] = 0.1745;
            this->diffuse[0] = 0.396;
            this->diffuse[1] = 0.74151;
            this->diffuse[2] = 0.69102;
            this->specular[0] = 0.297254;
            this->specular[1] = 0.30829;
            this->specular[2] = 0.306678;
            this->shininess = 0.1;
            break;
        case MeshColor::BRASS:
            this->ambiant[0] = 0.329412;
            this->ambiant[1] = 0.223529;
            this->ambiant[2] = 0.027451;
            this->diffuse[0] = 0.780392;
            this->diffuse[1] = 0.568627;
            this->diffuse[2] = 0.113725;
            this->specular[0] = 0.992157;
            this->specular[1] = 0.941176;
            this->specular[2] = 0.807843;
            this->shininess = 0.21794872;
            break;
        case MeshColor::BRONZE:
            this->ambiant[0] = 0.2125;
            this->ambiant[1] = 0.1275;
            this->ambiant[2] = 0.054;
            this->diffuse[0] = 0.714;
            this->diffuse[1] = 0.4284;
            this->diffuse[2] = 0.18144;
            this->specular[0] = 0.393548;
            this->specular[1] = 0.271906;
            this->specular[2] = 0.166721;
            this->shininess = 0.2;
            break;
        case MeshColor::CHROME:
            this->ambiant[0] = 0.25;
            this->ambiant[1] = 0.25;
            this->ambiant[2] = 0.25;
            this->diffuse[0] = 0.4;
            this->diffuse[1] = 0.4;
            this->diffuse[2] = 0.4;
            this->specular[0] = 0.774597;
            this->specular[1] = 0.774597;
            this->specular[2] = 0.774597;
            this->shininess = 0.6;
            break;
        case MeshColor::COPPER:
            this->ambiant[0] = 0.19125;
            this->ambiant[1] = 0.0735;
            this->ambiant[2] = 0.0225;
            this->diffuse[0] = 0.7038;
            this->diffuse[1] = 0.27048;
            this->diffuse[2] = 0.0828;
            this->specular[0] = 0.256777;
            this->specular[1] = 0.137622;
            this->specular[2] = 0.086014;
            this->shininess = 0.1;
            break;
        case MeshColor::GOLD:
            this->ambiant[0] = 0.24725;
            this->ambiant[1] = 0.1995;
            this->ambiant[2] = 0.0745;
            this->diffuse[0] = 0.75164;
            this->diffuse[1] = 0.60648;
            this->diffuse[2] = 0.22648;
            this->specular[0] = 0.628281;
            this->specular[1] = 0.555802;
            this->specular[2] = 0.366065;
            this->shininess = 0.4;
            break;
        case MeshColor::SILVER:
            this->ambiant[0] = 0.19225;
            this->ambiant[1] = 0.19225;
            this->ambiant[2] = 0.19225;
            this->diffuse[0] = 0.50754;
            this->diffuse[1] = 0.50754;
            this->diffuse[2] = 0.50754;
            this->specular[0] = 0.508273;
            this->specular[1] = 0.508273;
            this->specular[2] = 0.508273;
            this->shininess = 0.4;
            break;
        case MeshColor::BLACK_PLASTIC:
            this->ambiant[0] = 0.0;
            this->ambiant[1] = 0.0;
            this->ambiant[2] = 0.0;
            this->diffuse[0] = 0.01;
            this->diffuse[1] = 0.01;
            this->diffuse[2] = 0.01;
            this->specular[0] = 0.50;
            this->specular[1] = 0.50;
            this->specular[2] = 0.50;
            this->shininess = 0.25;
            break;
        case MeshColor::CYAN_PLASTIC:
            this->ambiant[0] = 0.0;
            this->ambiant[1] = 0.1;
            this->ambiant[2] = 0.06;
            this->diffuse[0] = 0.0;
            this->diffuse[1] = 0.50980392;
            this->diffuse[2] = 0.50980392;
            this->specular[0] = 0.50196078;
            this->specular[1] = 0.50196078;
            this->specular[2] = 0.50196078;
            this->shininess = 0.25;
            break;
        case MeshColor::GREEN_PLASTIC:
            this->ambiant[0] = 0.0;
            this->ambiant[1] = 0.0;
            this->ambiant[2] = 0.0;
            this->diffuse[0] = 0.1;
            this->diffuse[1] = 0.35;
            this->diffuse[2] = 0.1;
            this->specular[0] = 0.45 ;
            this->specular[1] = 0.55;
            this->specular[2] = 0.45;
            this->shininess = 0.25;
            break;
        case MeshColor::RED_PLASTIC:
            this->ambiant[0] = 0.0;
            this->ambiant[1] = 0.0;
            this->ambiant[2] = 0.0;
            this->diffuse[0] = 0.5;
            this->diffuse[1] = 0.0;
            this->diffuse[2] = 0.0;
            this->specular[0] = 0.7;
            this->specular[1] = 0.6;
            this->specular[2] = 0.6;
            this->shininess = 0.25;
            break;
        case MeshColor::WHITE_PLASTIC:
            this->ambiant[0] = 0.0;
            this->ambiant[1] = 0.0;
            this->ambiant[2] = 0.0;
            this->diffuse[0] = 0.55;
            this->diffuse[1] = 0.55;
            this->diffuse[2] = 0.55;
            this->specular[0] = 0.70;
            this->specular[1] = 0.70;
            this->specular[2] = 0.70;
            this->shininess = 0.25;
            break;
        case MeshColor::YELLOW_PLASTIC:
            this->ambiant[0] = 0.0;
            this->ambiant[1] = 0.0;
            this->ambiant[2] = 0.0;
            this->diffuse[0] = 0.5;
            this->diffuse[1] = 0.5;
            this->diffuse[2] = 0.0;
            this->specular[0] = 0.60;
            this->specular[1] = 0.60;
            this->specular[2] = 0.50;
            this->shininess = 0.25;
            break;
        case MeshColor::BLACK_RUBBER:
            this->ambiant[0] = 0.02;
            this->ambiant[1] = 0.02;
            this->ambiant[2] = 0.02;
            this->diffuse[0] = 0.01;
            this->diffuse[1] = 0.01;
            this->diffuse[2] = 0.01;
            this->specular[0] = 0.4;
            this->specular[1] = 0.4;
            this->specular[2] = 0.4;
            this->shininess = 0.078125;
            break;
        case MeshColor::CYAN_RUBBER:
            this->ambiant[0] = 0.0;
            this->ambiant[1] = 0.05;
            this->ambiant[2] = 0.05;
            this->diffuse[0] = 0.4;
            this->diffuse[1] = 0.5;
            this->diffuse[2] = 0.5;
            this->specular[0] = 0.04;
            this->specular[1] = 0.7;
            this->specular[2] = 0.7;
            this->shininess = 0.078125;
            break;
        case MeshColor::GREEN_RUBBER:
            this->ambiant[0] = 0.0;
            this->ambiant[1] = 0.05;
            this->ambiant[2] = 0.0;
            this->diffuse[0] = 0.4;
            this->diffuse[1] = 0.5;
            this->diffuse[2] = 0.4;
            this->specular[0] = 0.04;
            this->specular[1] = 0.7;
            this->specular[2] = 0.04;
            this->shininess = 0.078125;
            break;
        case MeshColor::RED_RUBBER:
            this->ambiant[0] = 0.05;
            this->ambiant[1] = 0.0;
            this->ambiant[2] = 0.0;
            this->diffuse[0] = 0.5;
            this->diffuse[1] = 0.4;
            this->diffuse[2] = 0.4;
            this->specular[0] = 0.7;
            this->specular[1] = 0.04;
            this->specular[2] = 0.04;
            this->shininess = 0.078125;
            break;
        case MeshColor::WHITE_RUBBER:
            this->ambiant[0] = 0.05;
            this->ambiant[1] = 0.05;
            this->ambiant[2] = 0.05;
            this->diffuse[0] = 0.5;
            this->diffuse[1] = 0.5;
            this->diffuse[2] = 0.5;
            this->specular[0] = 0.7;
            this->specular[1] = 0.7;
            this->specular[2] = 0.7;
            this->shininess = 0.078125;
            break;
        case MeshColor::YELLOW_RUBBER:
            this->ambiant[0] = 0.05;
            this->ambiant[1] = 0.05;
            this->ambiant[2] = 0.0;
            this->diffuse[0] = 0.5;
            this->diffuse[1] = 0.5;
            this->diffuse[2] = 0.4;
            this->specular[0] = 0.7;
            this->specular[1] = 0.7;
            this->specular[2] = 0.04;
            this->shininess = 0.078125;
            break;
    }
}

MeshColor::MeshColor(const MeshColor & m) {
    this->ambiant[0] = m.ambiant[0];
    this->ambiant[1] = m.ambiant[1];
    this->ambiant[2] = m.ambiant[2];
    this->diffuse[0] = m.diffuse[0];
    this->diffuse[1] = m.diffuse[1];
    this->diffuse[2] = m.diffuse[2];
    this->specular[0] = m.specular[0];
    this->specular[1] = m.specular[1];
    this->specular[2] = m.specular[2];
    this->shininess = m.shininess;
}

void MeshColor::Apply() const {
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, this->ambiant);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, this->diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, this->specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, this->shininess * 128.0);
}

Mesh::Mesh() :
    polygon_mode(GL_FILL), shade_mode(GL_SMOOTH), color(MeshColor::WHITE)
{

}

Mesh::Mesh(const Mesh& m) :
    polygon_mode(m.polygon_mode), shade_mode(m.shade_mode), color(m.color)
{
    for (unsigned int i = 0, sz = m.P.size(); i < sz; i++) {
        this->P.push_back(m.P[i]);
    }
    for (unsigned int i = 0, sz = m.T.size(); i < sz; i++) {
        this->T.push_back(m.T[i]);
    }
    for (unsigned int i = 0, sz = m.A.size(); i < sz; i++) {
        this->A.push_back(m.A[i]);
    }
}

unsigned int Mesh::PointNumber() const {
    return this->P.size();
}

unsigned int Mesh::TriangleNumber() const {
    return this->T.size();
}

unsigned int Mesh::AreteNumber() const {
    return this->A.size();
}

void Mesh::PushPoint(const Point& p) {
    this->P.push_back(p);
    this->N.push_back(Vecteur(0, 0, 0));
}

void Mesh::PushTriangle(unsigned int a, unsigned int b, unsigned int c) {
    basic_meshtriangle t;
    t.A = a; t.B = b; t.C = c; t.T1 = -1; t.T2 = -1; t.T3 = -1;
    this->T.push_back(t);
    Vecteur normal = Vecteur::VectorByPoints(this->P[a], this->P[b]).GetVectoriel(Vecteur::VectorByPoints(this->P[a], this->P[c]));
    this->N[a] = this->N[a] + normal;
    this->N[b] = this->N[b] + normal;
    this->N[c] = this->N[c] + normal;
}

void Mesh::Normalize() {
    for (unsigned int i = 0, sz = this->N.size(); i < sz; i++) {
        this->N[i].Normalize();
    }
}

void Mesh::Translate(double x, double y, double z) {
    Vecteur t(x, y, z);
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        this->P[i] = this->P[i] + t;
    }
}

void Mesh::RotateX(double a) {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        Point pnorm = this->P[i] + this->N[i];
        double y = this->P[i].y, z = this->P[i].z;
        this->P[i].y = y * cos(a) - z * sin(a);
        this->P[i].z = y * sin(a) + z * cos(a);
        y = pnorm.y; z = pnorm.z;
        pnorm.y = y * cos(a) - z * sin(a);
        pnorm.z = y * sin(a) + z * cos(a);
        this->N[i] = Vecteur::VectorByPoints(this->P[i], pnorm);
    }
}

void Mesh::RotateY(double a) {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        Point pnorm = this->P[i] + this->N[i];
        double x = this->P[i].x, z = this->P[i].z;
        this->P[i].x = x * cos(a) + z * sin(a);
        this->P[i].z = -x * sin(a) + z * cos(a);
        x = pnorm.x; z = pnorm.z;
        pnorm.x = x * cos(a) + z * sin(a);
        pnorm.z = -x * sin(a) + z * cos(a);
        this->N[i] = Vecteur::VectorByPoints(this->P[i], pnorm);
    }
}

void Mesh::RotateZ(double a) {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        Point pnorm = this->P[i] + this->N[i];
        double x = this->P[i].x, y = this->P[i].y;
        this->P[i].x = x * cos(a) - y * sin(a);
        this->P[i].y = x * sin(a) + y * cos(a);
        x = pnorm.x; y = pnorm.y;
        pnorm.x = x * cos(a) - y * sin(a);
        pnorm.y = x * sin(a) + y * cos(a);
        this->N[i] = Vecteur::VectorByPoints(this->P[i], pnorm);
    }
}

void Mesh::Scale(double x, double y, double z) {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        this->P[i].x *= x;
        this->P[i].y *= y;
        this->P[i].z *= z;
    }
}

Box Mesh::GetBox() const {
    double x_min = this->P[0].x, x_max = this->P[0].x, y_min = this->P[0].y, y_max = this->P[0].y, z_min = this->P[0].z, z_max = this->P[0].z;
    for (unsigned int i = 1, sz = this->P.size(); i < sz; i++) {
        if (this->P[i].x < x_min) x_min = this->P[i].x;
        if (this->P[i].x > x_max) x_max = this->P[i].x;
        if (this->P[i].y < y_min) y_min = this->P[i].y;
        if (this->P[i].y > y_max) y_max = this->P[i].y;
        if (this->P[i].z < z_min) z_min = this->P[i].z;
        if (this->P[i].z > z_max) z_max = this->P[i].z;
    }
    Point point(x_min, y_min, z_min);
    return Box(point, Vecteur(x_max - x_min, 0, 0), Vecteur(0, y_max - y_min, 0), Vecteur(0, 0, z_max - z_min));
}

void Mesh::Reposition(const Box& b) {
    Box actual = this->GetBox();
    double dx = b.GetVector(0).x / actual.GetVector(0).x;
    double dy = b.GetVector(1).y / actual.GetVector(1).y;
    double dz = b.GetVector(2).z / actual.GetVector(2).z;
    double min_value = (dx < dy) ? dx : dy; min_value = (min_value < dz) ? min_value : dz;
    this->Scale(min_value, min_value, min_value);
    actual = this->GetBox();
    dx = b.GetPoint(0).x - actual.GetPoint(0).x;
    dy = b.GetPoint(0).y - actual.GetPoint(0).y;
    dz = b.GetPoint(0).z - actual.GetPoint(0).z;
    double diff_x = b.GetVector(0).x - actual.GetVector(0).x;
    double diff_y = b.GetVector(1).y - actual.GetVector(1).y;
    double diff_z = b.GetVector(2).z - actual.GetVector(2).z;
    this->Translate(dx + diff_x / 2, dy + diff_y / 2, dz + diff_z / 2);
    actual = this->GetBox();
}

void Mesh::Draw() const {
    glPolygonMode(GL_FRONT_AND_BACK, this->polygon_mode);
    glShadeModel(this->shade_mode);
    this->color.Apply();
    this->_draw_();
}

void Mesh::DrawFront() const {
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT, this->polygon_mode);
    glShadeModel(this->shade_mode);
    this->color.Apply();
    this->_draw_();
    glDisable(GL_CULL_FACE);
}

void Mesh::DrawBack() const {
    glCullFace(GL_FRONT);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_BACK, this->polygon_mode);
    glShadeModel(this->shade_mode);
    this->color.Apply();
    this->_draw_invert_();
    glDisable(GL_CULL_FACE);
}

void Mesh::DrawNormals() const {
    for (unsigned int i = 0, sz = this->N.size(); i < sz; i++) {
        Segment(this->P[i], this->P[i] + this->N[i]).Draw();
    }
}

void Mesh::DrawAretes() const {
    for (unsigned int i = 0, sz = this->A.size(); i < sz; i++) {
        Segment(this->P[this->A[i].P1], this->P[this->A[i].P2]).Draw();
    }
}

void Mesh::DrawAretesByAngle() const {
    basic_meshtriangle t1, t2;
    Vecteur n1, n2;
    for (unsigned int i = 0, sz = this->A.size(); i < sz; i++) {
        if (this->A[i].T1 == 0xffffffff || this->A[i].T2 == 0xffffffff) {
            uColor::RED.Apply3f();
        }
        else {
            t1 = this->T[this->A[i].T1];
            t2 = this->T[this->A[i].T2];
            n1 = Vecteur::VectorByPoints(this->P[t1.A], this->P[t1.B]).GetVectoriel(Vecteur::VectorByPoints(this->P[t1.A], this->P[t1.C]));
            n2 = Vecteur::VectorByPoints(this->P[t2.A], this->P[t2.B]).GetVectoriel(Vecteur::VectorByPoints(this->P[t2.A], this->P[t2.C]));
            double angle = n1.GetAngle(n2);
            if (angle < 0.1) {
                uColor::GREEN.Apply3f();
            }
            else if (angle < M_PI / 2.0) {
                uColor::ORANGE.Apply3f();
            }
            else if (angle < M_PI) {
                uColor::ROYAL_BLUE.Apply3f();
                if (angle > M_PI)
                    std::cout << angle << std::endl;
            }
            else {
                uColor::GREEN.Apply3f();

                /*
                glColor3f(1, 0, 0);
                Point segm_p = this->P[this->A[i].P1] + Vecteur::VectorByPoints(this->P[this->A[i].P1], this->P[this->A[i].P2]) * 0.5;
                Segment(segm_p, segm_p + n1).Draw();
                Segment(segm_p, segm_p + n2).Draw();

                std::cout << angle << std::endl;
                */
            }
        }
        Segment(this->P[this->A[i].P1], this->P[this->A[i].P2]).Draw();
    }
}

void Mesh::PolygonMode(int m) {
    this->polygon_mode = m;
}

void Mesh::ShadeMode(int m) {
    this->shade_mode = m;
}

Point & Mesh::operator[](unsigned int i) {
    return this->P[i];
}

Vecteur Mesh::GetNormal(unsigned int i) const {
    return this->N[i];
}

Triangle Mesh::GetTriangle(unsigned int i) const {
    return Triangle(this->P[this->T[i].A], this->P[this->T[i].B], this->P[this->T[i].C]);
}

void Mesh::CalculateAretes() {
    if (this->T.size() == 0) return;

    std::vector<struct _mesh_litesort_GraphElement> graph;
    basic_mesharete arete;
    arete.T2 = 0xffffffff;

    // AJOUTER LE PREMIER
    arete.T1 = 0;
    if (this->T[0].A < this->T[0].B) {
        arete.P1 = this->T[0].A;
        arete.P2 = this->T[0].B;
    }
    else {
        arete.P1 = this->T[0].B;
        arete.P2 = this->T[0].A;
    }
    graph.push_back({arete, 0, 0});
    if (this->T[0].B < this->T[0].C) {
        arete.P1 = this->T[0].B;
        arete.P2 = this->T[0].C;
    }
    else {
        arete.P1 = this->T[0].C;
        arete.P2 = this->T[0].B;
    }
    _mesh_litesort_insert(graph, 0, arete);
    if (this->T[0].A < this->T[0].C) {
        arete.P1 = this->T[0].A;
        arete.P2 = this->T[0].C;
    }
    else {
        arete.P1 = this->T[0].C;
        arete.P2 = this->T[0].A;
    }
    _mesh_litesort_insert(graph, 0, arete);
    for (unsigned int i = 1, sz = this->T.size(); i < sz; i++) {
        arete.T1 = i;
        if (this->T[i].A < this->T[i].B) {
            arete.P1 = this->T[i].A;
            arete.P2 = this->T[i].B;
        }
        else {
            arete.P1 = this->T[i].B;
            arete.P2 = this->T[i].A;
        }
        _mesh_litesort_insert(graph, 0, arete);
        if (this->T[i].B < this->T[i].C) {
            arete.P1 = this->T[i].B;
            arete.P2 = this->T[i].C;
        }
        else {
            arete.P1 = this->T[i].C;
            arete.P2 = this->T[i].B;
        }
        _mesh_litesort_insert(graph, 0, arete);
        if (this->T[i].A < this->T[i].C) {
            arete.P1 = this->T[i].A;
            arete.P2 = this->T[i].C;
        }
        else {
            arete.P1 = this->T[i].C;
            arete.P2 = this->T[i].A;
        }
        _mesh_litesort_insert(graph, 0, arete);
    }
    _mesh_litesort_paste(graph, 0, this->A);

    for (unsigned int i = 0, sz = this->A.size(); i < sz; i++) {
        unsigned int t1 = this->A[i].T1, t2 = this->A[i].T2;
        if (t2 == 0xffffffff) continue;

        if (this->T[t1].T1 == -1) this->T[t1].T1 = t2;
        else if (this->T[t1].T2 == -1) this->T[t1].T2 = t2;
        else this->T[t1].T3 = t2;

        if (this->T[t2].T1 == -1) this->T[t2].T1 = t1;
        else if (this->T[t2].T2 == -1) this->T[t2].T2 = t1;
        else this->T[t2].T3 = t1;

        Vecteur n1 = Vecteur::VectorByPoints(this->P[this->T[t1].A], this->P[this->T[t1].B]).GetVectoriel(Vecteur::VectorByPoints(this->P[this->T[t1].A], this->P[this->T[t1].C]));
        Vecteur n2 = Vecteur::VectorByPoints(this->P[this->T[t2].A], this->P[this->T[t2].B]).GetVectoriel(Vecteur::VectorByPoints(this->P[this->T[t2].A], this->P[this->T[t2].C]));
        this->A[i].angle = n1.GetAngle(n2);
        if (this->A[i].angle < 0 || this->A[i].angle > M_PI) this->A[i].angle = 0;
        this->A[i].angle = M_PI - this->A[i].angle;
    }
}

double Mesh::GetAngle(unsigned int t1, unsigned int t2) const {
    Vecteur n1 = Vecteur::VectorByPoints(this->P[this->T[t1].A], this->P[this->T[t1].B]).GetVectoriel(Vecteur::VectorByPoints(this->P[this->T[t1].A], this->P[this->T[t1].C]));
    Vecteur n2 = Vecteur::VectorByPoints(this->P[this->T[t2].A], this->P[this->T[t2].B]).GetVectoriel(Vecteur::VectorByPoints(this->P[this->T[t2].A], this->P[this->T[t2].C]));
    double angle = n1.GetAngle(n2);
    if (angle < 0 || angle > M_PI) angle = 0;
    return M_PI - angle;
}

bool Mesh::IsVoisin(unsigned int t1, unsigned int t2) const {
    return (this->T[t1].T1 == t2 || this->T[t1].T2 == t2 || this->T[t1].T3 == t2);
}

bool Mesh::IsInsideList(unsigned int t, std::vector<unsigned int>& v) const {
    for (unsigned int i = 0, sz = v.size(); i < sz; i++) {
        if (t == v[i]) return true;
    }
    return false;
}

int Mesh::IndexInsideList(unsigned int t, std::vector<unsigned int>& v) const {
    for (int i = 0, sz = v.size(); i < sz; i++) {
        if (t == v[i]) return i;
    }
    return -1;
}

void Mesh::RemoveInsideList(unsigned int t, std::vector<unsigned int>& v) const {
    for (unsigned int i = 0, sz = v.size(); i < sz; i++) {
        if (t == v[i]) {
            v.erase(v.begin() + i);
            break;
        }
    }
}

void Mesh::AddVoisin(unsigned int t, std::vector<unsigned int>& v_src, std::vector<unsigned int>& v_dest) const {
    if (this->T[t].T1 != -1 && this->IsInsideList(this->T[t].T1, v_src) && !this->IsInsideList(this->T[t].T1, v_dest)) v_dest.push_back(this->T[t].T1);
    if (this->T[t].T2 != -1 && this->IsInsideList(this->T[t].T2, v_src) && !this->IsInsideList(this->T[t].T2, v_dest)) v_dest.push_back(this->T[t].T2);
    if (this->T[t].T3 != -1 && this->IsInsideList(this->T[t].T3, v_src) && !this->IsInsideList(this->T[t].T3, v_dest)) v_dest.push_back(this->T[t].T3);
}

void Mesh::AddTrianglePoints(unsigned int t, std::vector<unsigned int>& v) const {
    if (!this->IsInsideList(this->T[t].A, v)) v.push_back(this->T[t].A);
    if (!this->IsInsideList(this->T[t].B, v)) v.push_back(this->T[t].B);
    if (!this->IsInsideList(this->T[t].C, v)) v.push_back(this->T[t].C);
}

std::vector<Mesh> Mesh::Segmenter(double a) const {
    std::vector<std::vector<unsigned int>> segms;
    std::vector<unsigned int> unexp, exp;
    int idx = 0;
    for (int i = 0, sz = this->T.size(); i < sz; i++) {
        unexp.push_back(i);
    }
    while (unexp.size() > 0) {
        segms.push_back(std::vector<unsigned int>());
        segms[idx].push_back(unexp[0]);
        this->AddVoisin(unexp[0], unexp, exp);
        unexp.erase(unexp.begin());
        while (exp.size() > 0) {
            for (unsigned int i = 0, sz = segms[idx].size(); i < sz; i++) {
                if (this->GetAngle(exp[0], segms[idx][i]) > a) {
                    this->AddVoisin(exp[0], unexp, exp);
                    segms[idx].push_back(exp[0]);
                    this->RemoveInsideList(exp[0], unexp);
                    break;
                }
            }
            exp.erase(exp.begin());
        }
        //std::cout << ((this->T.size() - unexp.size()) * 100 / this->T.size()) << "%" << std::endl;
        idx++;
    }

    std::vector<Mesh> res;
    Mesh mesh;
    std::vector<unsigned int> p;
    for (unsigned int i = 0, sz = segms.size(); i < sz; i++) {
        mesh = Mesh();
        for (unsigned int j = 0, sz2 = segms[i].size(); j < sz2; j++) {
            this->AddTrianglePoints(segms[i][j], p);
        }
        for (unsigned int j = 0, sz2 = p.size(); j < sz2; j++) {
            mesh.PushPoint(this->P[p[j]]);
        }
        for (unsigned int j = 0, sz2 = segms[i].size(); j < sz2; j++) {
            mesh.PushTriangle(this->IndexInsideList(this->T[segms[i][j]].A, p), this->IndexInsideList(this->T[segms[i][j]].B, p), this->IndexInsideList(this->T[segms[i][j]].C, p));
        }
        res.push_back(mesh);
        p.clear();
    }
    return res;
}

void Mesh::_draw_() const {
    glBegin(GL_TRIANGLES);
    if (Mesh::is_smooth) {
        for (unsigned int i = 0, sz = this->T.size(); i < sz; i++) {
            Point p1 = this->P[this->T[i].A];
            Point p2 = this->P[this->T[i].B];
            Point p3 = this->P[this->T[i].C];
            Vecteur n1 = this->N[this->T[i].A];
            Vecteur n2 = this->N[this->T[i].B];
            Vecteur n3 = this->N[this->T[i].C];
            glNormal3f(n1.x, n1.y, n1.z);
            glVertex3f(p1.x, p1.y, p1.z);
            glNormal3f(n2.x, n2.y, n2.z);
            glVertex3f(p2.x, p2.y, p2.z);
            glNormal3f(n3.x, n3.y, n3.z);
            glVertex3f(p3.x, p3.y, p3.z);
        }
    }
    else {
        for (unsigned int i = 0, sz = this->T.size(); i < sz; i++) {
            Point p1 = this->P[this->T[i].A];
            Point p2 = this->P[this->T[i].B];
            Point p3 = this->P[this->T[i].C];
            glVertex3f(p1.x, p1.y, p1.z);
            glVertex3f(p2.x, p2.y, p2.z);
            glVertex3f(p3.x, p3.y, p3.z);
        }
    }
    glEnd();
}

void Mesh::_draw_invert_() const {
    glBegin(GL_TRIANGLES);
    if (Mesh::is_smooth) {
        for (unsigned int i = 0, sz = this->T.size(); i < sz; i++) {
            Point p1 = this->P[this->T[i].A];
            Point p2 = this->P[this->T[i].B];
            Point p3 = this->P[this->T[i].C];
            Vecteur n1 = this->N[this->T[i].A];
            Vecteur n2 = this->N[this->T[i].B];
            Vecteur n3 = this->N[this->T[i].C];
            glNormal3f(-n1.x, -n1.y, -n1.z);
            glVertex3f(p1.x, p1.y, p1.z);
            glNormal3f(-n2.x, -n2.y, -n2.z);
            glVertex3f(p2.x, p2.y, p2.z);
            glNormal3f(-n3.x, -n3.y, -n3.z);
            glVertex3f(p3.x, p3.y, p3.z);
        }
    }
    else {
        for (unsigned int i = 0, sz = this->T.size(); i < sz; i++) {
            Point p1 = this->P[this->T[i].A];
            Point p2 = this->P[this->T[i].B];
            Point p3 = this->P[this->T[i].C];
            glVertex3f(p1.x, p1.y, p1.z);
            glVertex3f(p2.x, p2.y, p2.z);
            glVertex3f(p3.x, p3.y, p3.z);
        }
    }
    glEnd();
}

bool Mesh::is_smooth = false;

void Mesh::EnableSmooth() {
    Mesh::is_smooth = true;
    glEnable(GL_SMOOTH);
}

void Mesh::DisableSmooth() {
    Mesh::is_smooth = false;
    glDisable(GL_SMOOTH);
}

/**
 * Insère un élément dans le graphe
 * Paramètres:
 * - graphe
 * - position dans le graphe
 * - élément à insérer
*/
void _mesh_litesort_insert(std::vector<struct _mesh_litesort_GraphElement>& Graph, unsigned int GraphPos, basic_mesharete& Elem) {
    if (Elem.P1 == Graph[GraphPos].elem.P1) {
        if (Elem.P2 == Graph[GraphPos].elem.P2) {
            if (Graph[GraphPos].elem.T2 == 0xffffffff)
                Graph[GraphPos].elem.T2 = Elem.T1;
            else
                goto goto_insert_next;
        }
        else if (Elem.P2 < Graph[GraphPos].elem.P2) {
            goto goto_insert_prev;
        }
        else {
            goto goto_insert_next;
        }
    }
    else if (Elem.P1 < Graph[GraphPos].elem.P1) {
        goto goto_insert_prev;
    }
    else {
        goto goto_insert_next;
    }
    return;

goto_insert_prev:
    if (Graph[GraphPos].prev == 0) {
        Graph[GraphPos].prev = Graph.size();
        Graph.push_back({ Elem, 0, 0 });
    }
    else {
        _mesh_litesort_insert(Graph, Graph[GraphPos].prev, Elem);
    }
    return;

goto_insert_next:
    if (Graph[GraphPos].next == 0) {
        Graph[GraphPos].next = Graph.size();
        Graph.push_back({ Elem, 0, 0 });
    }
    else {
        _mesh_litesort_insert(Graph, Graph[GraphPos].next, Elem);
    }
}

void _mesh_litesort_paste(std::vector<struct _mesh_litesort_GraphElement>& Graph, unsigned int GraphPos, std::vector<basic_mesharete>& Arr) {
    if (Graph[GraphPos].prev != 0)
        _mesh_litesort_paste(Graph, Graph[GraphPos].prev, Arr);
    Arr.push_back(Graph[GraphPos].elem);
    if (Graph[GraphPos].next != 0)
        _mesh_litesort_paste(Graph, Graph[GraphPos].next, Arr);
}