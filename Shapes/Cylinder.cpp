#include "Cylinder.hpp"

Cylinder::Cylinder() :
    p(Point()), v(0, 1, 0), rayon(1)
{
    this->surface = Cylinder::SurfaceByCylinder(*this, 20);
}

Cylinder::Cylinder(const Point & p, const Vecteur & v, double r, long nbU) :
    p(p), v(v), rayon(r)
{
    this->surface = Cylinder::SurfaceByCylinder(*this, nbU);
}

Cylinder::Cylinder(const Cylinder & c) :
    p(c.p), v(c.v), rayon(c.rayon), surface(c.surface)
{

}

Surface Cylinder::SurfaceByCylinder(const Cylinder & c, long nbU) {
    Vecteur v(c.v); v.Normalize();
    Vecteur v1(cos(v.x), cos(v.y), cos(v.z)), v2; v1 = v.GetVectoriel(v1);
    v2 = v.GetVectoriel(v1);
    v1.Normalize(); v1 = v1 * c.rayon;
    v2.Normalize(); v2 = v2 * c.rayon;
    Point center1 = c.p + c.v, center2 = c.p + (-c.v);
    Surface surface;
    double u;
    for (unsigned int i = 0; i < nbU; i++) {
        u = ((double)i / (double)(nbU - 2)) * M_PI * 2.0;
        surface[0][i] = center1 + (v1 * cos(u) + v2 * sin(u));
        surface[1][i] = center2 + (v1 * cos(u) + v2 * sin(u));
    }
    return surface;
}

bool Cylinder::Inside(double x, double y, double z) {
    Point point(x, y, z);
    Point projection(point.GetProjection(Droite(this->p, this->v)));
    return (Segment(projection, this->p).GetLength() <= this->v.GetNorm() && Segment(point, projection).GetLength() <= this->rayon);
}

void Cylinder::Draw() {
    this->surface.Draw();
    unsigned int N = this->surface.GetM();
    glColor3f(0.5, 0.8, 0.8);
    glBegin(GL_POLYGON);
    for (unsigned i = 0; i < N; i++) {
        glVertex3f(this->surface[0][i].x, this->surface[0][i].y, this->surface[0][i].z);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (unsigned i = 0; i < N; i++) {
        glVertex3f(this->surface[1][i].x, this->surface[1][i].y, this->surface[1][i].z);
    }
    glEnd();
}