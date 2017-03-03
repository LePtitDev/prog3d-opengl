#include "Vecteur.hpp"

Vecteur::Vecteur() :
    x(0.f), y(0.f), z(0.f)
{

}

Vecteur::Vecteur(double x, double y, double z) :
    x(x), y(y), z(z)
{

}

Vecteur::Vecteur(const Vecteur & v) :
    x(v.x), y(v.y), z(v.z)
{

}

Vecteur Vecteur::VectorByPoints(const Point & p1, const Point & p2) {
    return Vecteur(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
}

double Vecteur::GetScalar(const Vecteur & v) const {
    return (this->x * v.x + this->y * v.y + this->z * v.z);
}

double Vecteur::GetNorm() const {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

double Vecteur::GetAngle(const Vecteur & v) const {
    Vecteur v1(*this), v2(v);
    v1.Normalize();
    v2.Normalize();
    return acos(v1.GetScalar(v2));
}

Vecteur Vecteur::GetVectoriel(const Vecteur & v) const {
    return Vecteur(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

void Vecteur::Normalize() {
    double norm = this->GetNorm();
    this->x /= norm;
    this->y /= norm;
    this->z /= norm;
}

Vecteur Vecteur::operator+() const {
    return Vecteur(*this);
}

Vecteur Vecteur::operator-() const {
    return Vecteur(-this->x, -this->y, -this->z);
}

Vecteur Vecteur::operator+(const Vecteur & v) const {
    return Vecteur(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vecteur Vecteur::operator-(const Vecteur & v) const {
    return Vecteur(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vecteur Vecteur::operator*(double r) const {
    return Vecteur(this->x * r, this->y * r, this->z * r);
}