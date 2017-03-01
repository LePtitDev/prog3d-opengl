#include "Voxel.hpp"

Voxel::Voxel() :
    p(Point()), l(1)
{

}

Voxel::Voxel(const Point & p, double l) :
    p(p), l(l)
{

}

Voxel::Voxel(const Voxel & v) :
    p(v.p), l(v.l)
{

}

void Voxel::Draw() const {
    double h = l / 2.f;
    glBegin(GL_QUADS);
        glColor4f(0.5, 0.5, 1.0, 1.0);
        glVertex3f(p.x - h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y + h, p.z - h);
        glVertex3f(p.x + h, p.y + h, p.z - h);
        glVertex3f(p.x + h, p.y - h, p.z - h);

        glColor3f(0.5, 0.5, 0.9);
        glVertex3f(p.x - h, p.y - h, p.z + h);
        glVertex3f(p.x - h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y - h, p.z + h);

        glColor3f(0.5, 0.5, 0.8);
        glVertex3f(p.x - h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z + h);
        glVertex3f(p.x + h, p.y - h, p.z + h);
        glVertex3f(p.x + h, p.y - h, p.z - h);

        glColor3f(0.5, 0.5, 0.7);
        glVertex3f(p.x - h, p.y + h, p.z - h);
        glVertex3f(p.x - h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z - h);

        glColor3f(0.5, 0.5, 0.6);
        glVertex3f(p.x - h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z + h);
        glVertex3f(p.x - h, p.y + h, p.z + h);
        glVertex3f(p.x - h, p.y + h, p.z - h);

        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(p.x + h, p.y - h, p.z - h);
        glVertex3f(p.x + h, p.y - h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z - h);
    glEnd();
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y + h, p.z - h);
        glVertex3f(p.x + h, p.y + h, p.z - h);
        glVertex3f(p.x + h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z - h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y - h, p.z + h);
        glVertex3f(p.x - h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y - h, p.z + h);
        glVertex3f(p.x - h, p.y - h, p.z + h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z + h);
        glVertex3f(p.x + h, p.y - h, p.z + h);
        glVertex3f(p.x + h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z - h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y + h, p.z - h);
        glVertex3f(p.x - h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z - h);
        glVertex3f(p.x - h, p.y + h, p.z - h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z + h);
        glVertex3f(p.x - h, p.y + h, p.z + h);
        glVertex3f(p.x - h, p.y + h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z - h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x + h, p.y - h, p.z - h);
        glVertex3f(p.x + h, p.y - h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z - h);
        glVertex3f(p.x + h, p.y - h, p.z - h);
    glEnd();
}

void Voxel::DrawLines() const {
    double h = l / 2.f;
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y + h, p.z - h);
        glVertex3f(p.x + h, p.y + h, p.z - h);
        glVertex3f(p.x + h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z - h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y - h, p.z + h);
        glVertex3f(p.x - h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y - h, p.z + h);
        glVertex3f(p.x - h, p.y - h, p.z + h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z + h);
        glVertex3f(p.x + h, p.y - h, p.z + h);
        glVertex3f(p.x + h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z - h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y + h, p.z - h);
        glVertex3f(p.x - h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z - h);
        glVertex3f(p.x - h, p.y + h, p.z - h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x - h, p.y - h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z + h);
        glVertex3f(p.x - h, p.y + h, p.z + h);
        glVertex3f(p.x - h, p.y + h, p.z - h);
        glVertex3f(p.x - h, p.y - h, p.z - h);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(p.x + h, p.y - h, p.z - h);
        glVertex3f(p.x + h, p.y - h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z + h);
        glVertex3f(p.x + h, p.y + h, p.z - h);
        glVertex3f(p.x + h, p.y - h, p.z - h);
    glEnd();
}

bool Voxel::Inside(double x, double y, double z) const {
    double h = l / 2.0;
    return ((p.x - h <= x) && (x <= p.x + h) &&
            (p.y - h <= y) && (y <= p.y + h) &&
            (p.z - h <= z) && (z <= p.z + h));
}

void Voxel::operator=(const Voxel & v) {
    p = v.p;
    l = v.l;
}