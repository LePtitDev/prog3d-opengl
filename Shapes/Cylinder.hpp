#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_CYLINDER_HPP
#define PROG3D_CYLINDER_HPP

class Cylinder {

    Point p;
    Vecteur v;
    double rayon;

    Surface surface;

public:

    Cylinder();
    Cylinder(const Point&, const Vecteur&, double, long);
    Cylinder(const Cylinder&);

    static Surface SurfaceByCylinder(const Cylinder&, long);

    bool Inside(double, double, double);

    void Draw();

    Mesh GetMesh(unsigned int, unsigned int) const;

};

#endif //PROG3D_CYLINDER_HPP

#endif