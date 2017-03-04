#include "Rectangle.hpp"

RRectangle::RRectangle() :
    A(), B(), C(), D()
{

}

RRectangle::RRectangle(const Point & a, const Point& b, const Point & c) :
    A(a), B(b), C(c), D(c + Vecteur::VectorByPoints(b, a))
{

}

RRectangle::RRectangle(const RRectangle & r) :
    A(r.A), B(r.B), C(r.C), D(r.D)
{

}

double RRectangle::GetWidth() const {
    return Segment(this->A, this->B).GetLength();
}

double RRectangle::GetHeight() const {
    return Segment(this->B, this->C).GetLength();
}

const Point & RRectangle::GetA() const {
    return this->A;
}

const Point & RRectangle::GetB() const {
    return this->B;
}

const Point & RRectangle::GetC() const {
    return this->C;
}

const Point & RRectangle::GetD() const {
    return this->D;
}

const Point * RRectangle::GetPoints() const {
    return &(this->A);
}

void RRectangle::Draw() const {
    glBegin(GL_LINE_STRIP);
        glVertex3f(this->A.x, this->A.y, this->A.z);
        glVertex3f(this->B.x, this->B.y, this->B.z);
        glVertex3f(this->C.x, this->C.y, this->C.z);
        glVertex3f(this->D.x, this->D.y, this->D.z);
        glVertex3f(this->A.x, this->A.y, this->A.z);
    glEnd();
}

Plan RRectangle::GetPlan() const {
    return Plan(this->A, Vecteur::VectorByPoints(this->A, this->B), Vecteur::VectorByPoints(this->A, this->D));
}