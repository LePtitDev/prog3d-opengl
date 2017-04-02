#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_POINT_HPP
#define PROG3D_POINT_HPP

class Point {

public:

    double x, y, z;

    Point();
    Point(double, double, double);
    Point(const Point&);

    Point GetProjection(const Droite&) const;
    Point GetProjection(const Plan&) const;

    Point GetMiddle(const Point&) const;

    void Draw() const;

    void Apply() const;

    bool IsNull() const;
    void Nullify();

    Point operator+(const Vecteur&) const;
    Point operator-(const Vecteur&) const;
    Point operator+(const Point&) const;
    Point operator-(const Point&) const;
    Point operator*(double) const;
    Point operator/(double) const;

};

#endif //PROG3D_POINT_HPP

#endif