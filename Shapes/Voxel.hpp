#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_VOXEL_HPP
#define PROG3D_VOXEL_HPP

class Voxel {

public:

    Point p;
    double l;

    Voxel();
    Voxel(const Point&, double);
    Voxel(const Voxel&);

    void Draw() const;
    void DrawLines() const;

    bool Inside(const Point&) const;
    bool Inside(double, double, double) const;

    void operator=(const Voxel&);

};

#endif //PROG3D_VOXEL_HPP

#endif