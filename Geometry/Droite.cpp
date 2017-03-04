#include "Droite.hpp"

Droite::Droite() :
    p(), v(1.f, 0.f, 0.f)
{

}

Droite::Droite(const Point & p, const Vecteur & v) :
    p(p), v(v)
{

}

Droite::Droite(const Droite & d) :
    p(d.p), v(d.v)
{

}

bool Droite::GetIntersection(const Plan & plan, Point& res) const {
    Vecteur u(plan.GetU()), v(plan.GetV()), w(-this->v);
    Matrice<double, 3, 3> M;
    M[0][0] = u.x;
    M[0][1] = v.x;
    M[0][2] = w.x;
    M[1][0] = u.y;
    M[1][1] = v.y;
    M[1][2] = w.y;
    M[2][0] = u.z;
    M[2][1] = v.z;
    M[2][2] = w.z;
    double detM = M.GetDeterminant();
    if (detM == 0) return false;

    double b1 = this->p.x - plan.p.x, b2 = this->p.y - plan.p.y, b3 = this->p.z - plan.p.z;
    /*Matrice<double, 3, 3> M1;
    M1[0][0] = b1;
    M1[0][1] = v.x;
    M1[0][2] = w.x;
    M1[1][0] = b2;
    M1[1][1] = v.y;
    M1[1][2] = w.y;
    M1[2][0] = b3;
    M1[2][1] = v.z;
    M1[2][2] = w.z;
    Matrice<double, 3, 3> M2;
    M2[0][0] = u.x;
    M2[0][1] = b1;
    M2[0][2] = w.x;
    M2[1][0] = u.y;
    M2[1][1] = b2;
    M2[1][2] = w.y;
    M2[2][0] = u.z;
    M2[2][1] = b3;
    M2[2][2] = w.z;*/
    Matrice<double, 3, 3> M3;
    M3[0][0] = u.x;
    M3[0][1] = v.x;
    M3[0][2] = b1;
    M3[1][0] = u.y;
    M3[1][1] = v.y;
    M3[1][2] = b2;
    M3[2][0] = u.z;
    M3[2][1] = v.z;
    M3[2][2] = b3;

    res = this->p + this->v * (M3.GetDeterminant() / detM);
    return true;
}