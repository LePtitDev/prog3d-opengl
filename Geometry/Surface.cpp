#include "Surface.hpp"

/****** OBJET ******/

Surface::Surface() :
    n(0), m(0)
{

}

Surface::Surface(const Curve * c, unsigned int n, unsigned int m) :
    n(n), m(m)
{
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < m; j++) {
            this->surf.push_back(c[i]);
        }
    }
}

Surface::Surface(const Surface & s) :
    n(s.n), m(s.m)
{
    for (unsigned i = 0; i < n; i++) {
        this->surf.push_back(s.surf[i]);
    }
}

void Surface::Draw() {
    glBegin(GL_QUADS);
    double u, v;
    for (unsigned int i = 1; i < this->n; i++) {
        u = ((double)i / (double)(this->n - 1)) / 2.0;
        for (unsigned int j = 1; j < this->m; j++) {
            v = ((double)j / (double)(this->m - 1)) / 2.0;
            glColor3f(0.5, 0.5 + u, 0.5 + v);
            glVertex3f(this->surf[i-1][j-1].x, this->surf[i-1][j-1].y, this->surf[i-1][j-1].z);
            glVertex3f(this->surf[i-1][j].x, this->surf[i-1][j].y, this->surf[i-1][j].z);
            glVertex3f(this->surf[i][j].x, this->surf[i][j].y, this->surf[i][j].z);
            glVertex3f(this->surf[i][j-1].x, this->surf[i][j-1].y, this->surf[i][j-1].z);
        }
    }
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for (unsigned int i = 1; i < this->n; i++) {
        for (unsigned int j = 1; j < this->m; j++) {
            glVertex3f(this->surf[i-1][j].x, this->surf[i-1][j].y, this->surf[i-1][j].z);
            glVertex3f(this->surf[i][j].x, this->surf[i][j].y, this->surf[i][j].z);
            glVertex3f(this->surf[i][j-1].x, this->surf[i][j-1].y, this->surf[i][j-1].z);
            glVertex3f(this->surf[i][j].x, this->surf[i][j].y, this->surf[i][j].z);
        }
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (unsigned int i = 0; i < this->n; i++) {
        glVertex3f(this->surf[i][0].x, this->surf[i][0].y, this->surf[i][0].z);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (unsigned int j = 0; j < this->m; j++) {
        glVertex3f(this->surf[0][j].x, this->surf[0][j].y, this->surf[0][j].z);
    }
    glEnd();
}

void Surface::DrawWithLines() {
    glBegin(GL_LINES);
    for (unsigned int i = 1; i < this->n; i++) {
        for (unsigned int j = 1; j < this->m; j++) {
            glVertex3f(this->surf[i-1][j].x, this->surf[i-1][j].y, this->surf[i-1][j].z);
            glVertex3f(this->surf[i][j].x, this->surf[i][j].y, this->surf[i][j].z);
            glVertex3f(this->surf[i][j-1].x, this->surf[i][j-1].y, this->surf[i][j-1].z);
            glVertex3f(this->surf[i][j].x, this->surf[i][j].y, this->surf[i][j].z);
        }
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (unsigned int i = 0; i < this->n; i++) {
        glVertex3f(this->surf[i][0].x, this->surf[i][0].y, this->surf[i][0].z);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (unsigned int j = 0; j < this->m; j++) {
        glVertex3f(this->surf[0][j].x, this->surf[0][j].y, this->surf[0][j].z);
    }
    glEnd();
}

unsigned int Surface::GetN() const {
    return this->n;
}

unsigned int Surface::GetM(){
    if (this->n > 0)
        this->m = this->surf[0].Size();
    else
        return 0;
    return this->m;
}

Curve & Surface::operator[](unsigned int i) {
    while (i >= this->n) {
        this->surf.push_back(Curve());
        this->n++;
    }
    if (this->surf[i].Size() > this->m)
        this->m = this->surf[i].Size();
    return this->surf[i];
}

/****** STATIQUES ******/

Surface Surface::CylindricalSurface(const Point * c_bezier, long n_bezier, const Vecteur & v_droite, long nbU, long nbV) {
    Curve courbe = Curve::BezierByBernstein(c_bezier, n_bezier, nbV);
    Surface surface;
    double u;
    for (long i = 0; i < nbU; i++) {
        u = (double)i / (double)(nbU - 1);
        for (long j = 0; j < nbV; j++) {
            surface[i][j].x = courbe[j].x + u * v_droite.x;
            surface[i][j].y = courbe[j].y + u * v_droite.y;
            surface[i][j].z = courbe[j].z + u * v_droite.z;
        }
    }
    return surface;
}

Surface Surface::RuledSurface(const Point * c_bezier1, long n_bezier1, const Point * c_bezier2, long n_bezier2, long nbU, long nbV) {
    Curve courbe1 = Curve::BezierByBernstein(c_bezier1, n_bezier1, nbV);
    Curve courbe2 = Curve::BezierByBernstein(c_bezier2, n_bezier2, nbV);
    Surface surface;
    double u;
    for (long i = 0; i < nbU; i++) {
        u = (double)i / (double)(nbU - 1);
        for (long j = 0; j < nbV; j++) {
            surface[i][j].x = (1 - u) * courbe1[j].x + u * courbe2[j].x;
            surface[i][j].y = (1 - u) * courbe1[j].y + u * courbe2[j].y;
            surface[i][j].z = (1 - u) * courbe1[j].z + u * courbe2[j].z;
        }
    }
    return surface;
}

//Fonction récursive de l'algorithme de Casteljau
void curve_hpp_casteljau_recursive(const Point * p, long n, double u, Point& res);

//Fonction récursive de l'algorithme de Casteljau
void surface_hpp_surface_casteljau_recursive(Surface s, double u, double v, Point& res) {
    long nbU = s.GetN(), nbV = s.GetM();
    if (nbU == 1 && nbV == 1) {
        res.x = s[0][0].x;
        res.y = s[0][0].y;
        res.z = s[0][0].z;
        return;
    }
    if (nbU == 1) {
        curve_hpp_casteljau_recursive(s[0].GetArray(), nbV, v, res);
    }
    else if (nbV == 1) {
        Curve courbe;
        for (long i = 0; i < nbU; i++) {
            courbe[i].x = s[i][0].x;
            courbe[i].y = s[i][0].y;
            courbe[i].z = s[i][0].z;
        }
        curve_hpp_casteljau_recursive(courbe.GetArray(), nbU, u, res);
    }
    else {
        Surface ns;
        nbU--;
        nbV--;
        Point A, B;
        for (long i = 0; i < nbU; i++) {
            for (long j = 0; j < nbV; j++) {
                A.x = (1 - u) * s[i][j].x + u * s[i+1][j].x;
                A.y = (1 - u) * s[i][j].y + u * s[i+1][j].y;
                A.z = (1 - u) * s[i][j].z + u * s[i+1][j].z;
                B.x = (1 - u) * s[i][j+1].x + u * s[i+1][j+1].x;
                B.y = (1 - u) * s[i][j+1].y + u * s[i+1][j+1].y;
                B.z = (1 - u) * s[i][j+1].z + u * s[i+1][j+1].z;
                ns[i][j].x = (1 - v) * A.x + v * B.x;
                ns[i][j].y = (1 - v) * A.y + v * B.y;
                ns[i][j].z = (1 - v) * A.z + v * B.z;
            }
        }
        surface_hpp_surface_casteljau_recursive(ns, u, v, res);
    }
}

Surface Surface::BezierSurfaceByCasteljau(const Surface & s, long nbU, long nbV) {
    Surface surface;
    Surface S(s);
    double u, v;
    for (long i = 0; i < nbU; i++) {
        u = (double)i / (double)(nbU - 1);
        for (long j = 0; j < nbV; j++) {
            v = (double)j / (double)(nbV - 1);
            surface_hpp_surface_casteljau_recursive(S, u, v, surface[i][j]);
        }
    }
    return surface;
}