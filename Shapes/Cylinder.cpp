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

Mesh Cylinder::GetMesh(unsigned int nbU, unsigned int nbV) const {
    Mesh mesh;
    Vecteur vt(this->v); vt.Normalize();
    Vecteur v1(cos(vt.x), cos(vt.y), cos(vt.z)), v2; v1 = vt.GetVectoriel(v1);
    v2 = vt.GetVectoriel(v1);
    v1.Normalize(); v1 = v1 * this->rayon;
    v2.Normalize(); v2 = v2 * this->rayon;
    Point center = this->p + this->v, tmp_center, center2 = this->p + (-this->v);
    double u, v;
    for (unsigned int j = 0; j < nbV; j++) {
        v = ((double)j / (double)(nbV - 1)) * 2;
        tmp_center = center - this->v * v;
        for (unsigned int i = 0; i < nbU - 1; i++) {
            u = ((double)i / (double)(nbU - 1)) * M_PI * 2.0;
            mesh.PushPoint(tmp_center + (v1 * cos(u) + v2 * sin(u)));
        }
    }
    mesh.PushPoint(center);
    mesh.PushPoint(center2);
    for (unsigned int j = 1; j < nbV; j++) {
        for (unsigned int i = 0; i < nbU - 2; i++) {
            unsigned int vertex[4] = {
                (j - 1) * (nbU - 1) + i,
                (j - 1) * (nbU - 1) + i + 1,
                j * (nbU - 1) + i,
                j * (nbU - 1) + i + 1
            };
            mesh.PushTriangle(vertex[0], vertex[2], vertex[1]);
            mesh.PushTriangle(vertex[1], vertex[2], vertex[3]);
        }
        mesh.PushTriangle((j - 1) * (nbU - 1), j * (nbU - 1) - 1, (j + 1) * (nbU - 1) - 1);
        mesh.PushTriangle((j - 1) * (nbU - 1), (j + 1) * (nbU - 1) - 1, j * (nbU - 1));
    }
    unsigned int pos_center_1 = mesh.PointNumber() - 2, pos_last_circle = pos_center_1 - nbU + 1;
    for (unsigned int i = 1; i < nbU - 1; i++) {
        mesh.PushTriangle(pos_center_1, i - 1, i);
        mesh.PushTriangle(pos_center_1 + 1, pos_last_circle + i, pos_last_circle + i - 1);
    }
    mesh.PushTriangle(pos_center_1, nbU - 2, 0);
    mesh.PushTriangle(pos_center_1 + 1, pos_last_circle, pos_center_1 - 1);
    return mesh;
}