#include "Triangle.hpp"

Triangle::Triangle() :
    A(), B(), C()
{

}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
    A(a), B(b), C(c)
{

}

Triangle::Triangle(const Triangle& t) :
    A(t.A), B(t.B), C(t.C)
{

}

Plan Triangle::GetPlan() const {
    return Plan(this->A, Vecteur::VectorByPoints(this->A, this->B).GetVectoriel(Vecteur::VectorByPoints(this->A, this->C)));
}

void Triangle::Draw() const {
    glBegin(GL_TRIANGLES);
        glVertex3f(A.x, A.y, A.z);
        glVertex3f(B.x, B.y, B.z);
        glVertex3f(C.x, C.y, C.z);
    glEnd();
}