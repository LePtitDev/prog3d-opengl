#include "Cone.hpp"

Cone::Cone() :
    p(Point()), v(0, 1, 0), r(1)
{
    this->courbe = Cone::CurveByCone(*this, 20);
}

Cone::Cone(const Point & p, const Vecteur & v, double r, long nb) :
    p(p), v(v), r(r)
{
    this->courbe = Cone::CurveByCone(*this, nb);
}

Cone::Cone(const Cone & c) :
    p(c.p), v(c.v), r(c.r), courbe(c.courbe)
{

}

Curve Cone::CurveByCone(const Cone & c, long nb){
    Vecteur v(c.v); v.Normalize();
    Vecteur v1(cos(v.x), cos(v.y), cos(v.z)), v2; v1 = v.GetVectoriel(v1);
    v2 = v.GetVectoriel(v1);
    v1.Normalize(); v1 = v1 * c.r;
    v2.Normalize(); v2 = v2 * c.r;
    Curve courbe;
    double u;
    for (unsigned int i = 0; i < nb; i++) {
        u = ((double)i / (double)(nb - 2)) * M_PI * 2.0;
        courbe[i] = c.p + (v1 * cos(u) + v2 * sin(u));
    }
    return courbe;
}

void Cone::Draw() {
    unsigned int N = this->courbe.Size(), u;
    Point P = this->p + this->v;
    glColor3f(0.5, 0.8, 0.8);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(P.x, P.y, P.z);
    for (unsigned int i = 0; i < N; i++) {
        glVertex3f(this->courbe[i].x, this->courbe[i].y, this->courbe[i].z);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (unsigned int i = 0; i < N; i++) {
        glVertex3f(this->courbe[i].x, this->courbe[i].y, this->courbe[i].z);
    }
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    this->courbe.Draw();
    glBegin(GL_LINES);
    for (unsigned int i = 0; i < N; i++) {
        glVertex3f(P.x, P.y, P.z);
        glVertex3f(this->courbe[i].x, this->courbe[i].y, this->courbe[i].z);
    }
    glEnd();
}