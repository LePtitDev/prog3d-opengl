#include "Point.hpp"

Point::Point() :
    x(0.f), y(0.f), z(0.f)
{

}

Point::Point(double x, double y, double z) :
    x(x), y(y), z(z)
{

}

Point::Point(const Point & p) :
    x(p.x), y(p.y), z(p.z)
{

}

Point Point::GetProjection(const Droite & d) const {
    Vecteur vp1(this->x - d.p.x, this->y - d.p.y, this->z - d.p.z), vp2(d.v);
    double norm = vp1.GetScalar(vp2) / vp2.GetNorm();

    vp2.Normalize();
    return Point(d.p.x + vp2.x * norm, d.p.y + vp2.y * norm, d.p.z + vp2.z * norm);
}

Point Point::GetProjection(const Plan & P) const {
    Vecteur vp1(P.p.x - this->x, P.p.y - this->y, P.p.z - this->z), vp2(P.GetNormal());
    double norm = vp1.GetScalar(vp2) / vp2.GetNorm();

    vp2.Normalize();
    return Point(this->x - vp2.x * norm, this->y - vp2.y * norm, this->z - vp2.z * norm);
}

double Point::GetDistance(const Point& p) const {
    double dx = this->x - p.x, dy = this->y - p.y, dz = this->z - p.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

Point Point::GetMiddle(const Point & p) const {
    return Point((this->x + p.x) / 2, (this->y + p.y) / 2, (this->z + p.z) / 2);
}

void Point::Draw() const {
    glBegin(GL_POINTS);
    glVertex3f(this->x, this->y, this->z);
    glEnd();
}

void Point::Apply() const {
    glVertex3f(this->x, this->y, this->z);
}

bool Point::IsNull() const {
    return (
        this->x == NAN ||
        this->y == NAN ||
        this->z == NAN
    );
}

void Point::Nullify() {
    this->x = NAN;
    this->y = NAN;
    this->z = NAN;
}

Point Point::operator+(const Vecteur & v) const {
    return Point(this->x + v.x, this->y + v.y, this->z + v.z);
}

Point Point::operator-(const Vecteur & v) const {
    return Point(this->x - v.x, this->y - v.y, this->z - v.z);
}

Point Point::operator+(const Point & p) const {
    return Point(this->x + p.x, this->y + p.y, this->z + p.z);
}

Point Point::operator-(const Point & p) const {
    return Point(this->x - p.x, this->y - p.y, this->z - p.z);
}

Point Point::operator*(double k) const {
    return Point(this->x * k, this->y * k, this->z * k);
}

Point Point::operator/(double k) const {
    return Point(this->x / k, this->y / k, this->z / k);
}

std::ostream& operator<<(std::ostream& s, const Point& p) {
    s << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
}