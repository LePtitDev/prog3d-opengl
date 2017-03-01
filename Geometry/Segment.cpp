#include "Segment.hpp"

Segment::Segment() :
    p1(), p2()
{

}

Segment::Segment(const Point & p1, const Point & p2) :
    p1(p1), p2(p2)
{

}

Segment::Segment(const Segment & s) :
    p1(s.p1), p2(s.p2)
{

}

double Segment::GetLength() const {
    double dx = this->p2.x - this->p1.x;
    double dy = this->p2.y - this->p1.y;
    double dz = this->p2.z - this->p1.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void Segment::Draw() const {
    glBegin(GL_LINES);
    glVertex3f(this->p1.x, this->p1.y, this->p1.z);
    glVertex3f(this->p2.x, this->p2.y, this->p2.z);
    glEnd();
}