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

    void Draw() const;

    Point operator+(const Vecteur&) const;

};

#endif //PROG3D_POINT_HPP

#endif