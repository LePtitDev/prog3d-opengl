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
}

void Mesh::PushTriangle(unsigned int a, unsigned int b, unsigned int c) {
    basic_meshtriangle t;
    t.A = a; t.B = b; t.C = c;
    this->T.push_back(t);
}

void Mesh::Draw() const {
    glBegin(GL_TRIANGLES);
    double u;
    for (unsigned int i = 0, sz = this->T.size(); i < sz; i++) {
        u = ((double)i / (double)(sz - 1)) / 2.0;
        glColor3f(0.5, 0.5 + u, 0.5 + u);
        Point p1 = this->P[this->T[i].A];
        Point p2 = this->P[this->T[i].B];
        Point p3 = this->P[this->T[i].C];
        glVertex3f(p1.x, p1.y, p1.z);
        glVertex3f(p2.x, p2.y, p2.z);
        glVertex3f(p3.x, p3.y, p3.z);
    }
    glEnd();
}