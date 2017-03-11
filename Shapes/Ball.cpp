#include "Ball.hpp"

Ball::Ball() :
    p(Point()), r(1)
{
    this->surface = Ball::SurfaceByBall(*this, 20, 20);
}

Ball::Ball(const Point & p, double r, long n, long m) :
    p(p), r(r)
{
    this->surface = Ball::SurfaceByBall(*this, n, m);
}

Ball::Ball(const Ball & b) :
    p(b.p), r(b.r), surface(b.surface)
{

}

Surface Ball::SurfaceByBall(const Ball & b, long n, long m) {
    Surface surface;
    double teta, phi;
    for (int i = 0; i < m; i++) {
        phi = ((double)i / (double)(m - 1)) * M_PI;
        for (int j = 0; j < n; j++) {
            teta = ((double)j / (double)(n - 2)) * 2.0 * M_PI;
            surface[i][j] = Point(b.r * sin(phi) * cos(teta) + b.p.x, b.r * cos(phi) + b.p.y, b.r * sin(phi) * sin(teta) + b.p.z);
        }
    }
    return surface;
}

bool Ball::Inside(double x, double y, double z) {
    return (Segment(Point(x, y, z), this->p).GetLength() <= r);
}

void Ball::Draw() {
    this->surface.Draw();
}

Mesh Ball::GetMesh(unsigned int n) {
    Mesh mesh;
    double teta, phi;
    for (unsigned int i = 1; i < n - 1; i++) {
        phi = ((double)i / (double)(n - 1)) * M_PI;
        for (unsigned int j = 0; j < n - 1; j++) {
            teta = ((double)j / (double)(n - 1)) * 2.0 * M_PI;
            mesh.PushPoint(Point(this->r * sin(phi) * cos(teta) + this->p.x, this->r * cos(phi) + this->p.y, this->r * sin(phi) * sin(teta) + this->p.z));
        }
    }
    mesh.PushPoint(this->p + Vecteur(0, 1, 0) * this->r);
    mesh.PushPoint(this->p + Vecteur(0, -1, 0) * this->r);
    for (unsigned int i = 1; i < n - 2; i++) {
        for (unsigned int j = 0; j < n - 2; j++) {
            unsigned int vertex[4] = {
                (i - 1) * (n - 1) + j,
                (i - 1) * (n - 1) + j + 1,
                i * (n - 1) + j,
                i * (n - 1) + j + 1
            };
            mesh.PushTriangle(vertex[0], vertex[1], vertex[2]);
            mesh.PushTriangle(vertex[1], vertex[3], vertex[2]);
        }
        mesh.PushTriangle(i * (n - 1) - 1, (i - 1) * (n - 1), (i + 1) * (n - 1) - 1);
        mesh.PushTriangle((i - 1) * (n - 1), i * (n - 1), (i + 1) * (n - 1) - 1);
    }
    unsigned int pos_center_1 = mesh.PointNumber() - 2, pos_last_circle = pos_center_1 - n + 1;
    for (unsigned int i = 1; i < n - 1; i++) {
        mesh.PushTriangle(pos_center_1, i, i - 1);
        mesh.PushTriangle(pos_center_1 + 1, pos_last_circle + i - 1, pos_last_circle + i);
    }
    mesh.PushTriangle(pos_center_1, 0, n - 2);
    mesh.PushTriangle(pos_center_1 + 1, pos_center_1 - 1, pos_last_circle);
    return mesh;
}