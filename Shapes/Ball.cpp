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