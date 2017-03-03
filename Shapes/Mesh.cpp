#include "Mesh.hpp"

Mesh::Mesh() {

}

Mesh::Mesh(const Mesh& m) {
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
    t.A = a; t.B = b; t.C = c;
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

void Mesh::Draw() const {
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

void Mesh::DrawNormals() const {
    for (unsigned int i = 0, sz = this->N.size(); i < sz; i++) {
        Segment(this->P[i], this->P[i] + this->N[i]).Draw();
    }
}

Point & Mesh::operator[](unsigned int i) {
    return this->P[i];
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