#include "Curve.hpp"

/****** OBJET ******/

Curve::Curve() {

}

Curve::Curve(const Point p[], unsigned int nb) {
    for (unsigned int i = 0; i < nb; i++) {
        this->P.push_back(p[i]);
    }
}

Curve::Curve(const Curve & c) {
    for (unsigned int i = 0, nb = c.P.size(); i < nb; i++) {
        this->P.push_back(c.P[i]);
    }
}

void Curve::Draw() const {
    glBegin(GL_LINE_STRIP);
    for (unsigned int i = 0, nb = this->P.size(); i < nb; i++) {
        glVertex3f(this->P[i].x, this->P[i].y, this->P[i].z);
    }
    glEnd();
}

unsigned int Curve::Size() const {
    return this->P.size();
}

Point& Curve::operator[](unsigned int i) {
    while (i >= this->P.size())
        this->P.push_back(Point());
    return this->P[i];
}

const Point * Curve::GetArray() const {
    return this->P.data();
}

/****** STATIQUES ******/

Curve Curve::HermiteCubic(const Point & p0, const Point & p1, const Vecteur & v0, const Vecteur & v1, long n) {
    Point a(2 * p0.x - 2 * p1.x + v0.x + v1.x, 2 * p0.y - 2 * p1.y + v0.y + v1.y, 2 * p0.z - 2 * p1.z + v0.z + v1.z);
    Point b(-3 * p0.x + 3 * p1.x - 2 * v0.x - v1.x, -3 * p0.y + 3 * p1.y - 2 * v0.y - v1.y, -3 * p0.z + 3 * p1.z - 2 * v0.z - v1.z);
    Point c(v0.x, v0.y, v0.z);
    Point d(p0);

    Curve curve;
    double u;
    for (long i = 0; i < n; i++) {
        u = (double)i / (double)(n - 1);
        curve[i].x = a.x * u * u * u + b.x * u * u + c.x * u + d.x;
        curve[i].y = a.y * u * u * u + b.y * u * u + c.y * u + d.y;
        curve[i].z = a.z * u * u * u + b.z * u * u + c.z * u + d.z;
    }

    return curve;
}

long curve_hpp_factorial(long n) {
    return (n == 0) ? 1 : n * curve_hpp_factorial(n - 1);
}

Curve Curve::BezierByBernstein(const Point * p, long nbP, long n) {
    nbP--;
    double * B = new double[nbP + 1], u;
    for (long i = 0; i <= nbP; i++) {
        B[i] = (curve_hpp_factorial(nbP) / (curve_hpp_factorial(i) * curve_hpp_factorial(nbP - i)));
    }

    Curve curve;
    double x, y, z, tmp;
    for (long i = 0; i < n; i++) {
        x = 0.0;
        y = 0.0;
        z = 0.0;
        u = (double)i / (double)(n - 1);
        for (long j = 0; j <= nbP; j++) {
            tmp = B[j] * pow(u, j) * pow(1.0 - u, nbP - j);
            x += tmp * p[j].x;
            y += tmp * p[j].y;
            z += tmp * p[j].z;
        }
        curve[i].x = x;
        curve[i].y = y;
        curve[i].z = z;
    }

    return curve;
}

//Fonction récursive de l'algorithme de Casteljau
void curve_hpp_casteljau_recursive(const Point * p, long n, double u, Point& res) {
    if (n == 1) {
        res.x = p->x;
        res.y = p->y;
        res.z = p->z;
    }
    else {
        Point * np = new Point[--n];
        for (long i = 0; i < n; i++) {
            np[i].x = (1.0 - u) * p[i].x + u * p[i + 1].x;
            np[i].y = (1.0 - u) * p[i].y + u * p[i + 1].y;
            np[i].z = (1.0 - u) * p[i].z + u * p[i + 1].z;
        }
        curve_hpp_casteljau_recursive(np, n, u, res);
        delete[] np;
    }
}

Curve Curve::BezierByCasteljau(const Point * p, long nbP, long n) {
    Curve curve;
    double u;
    for (long i = 0; i < n; i++) {
        u = (double)i / (double)(n - 1);
        curve_hpp_casteljau_recursive(p, nbP, u, curve[i]);
    }
    return curve;
}