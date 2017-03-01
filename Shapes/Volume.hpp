#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_VOLUME_HPP
#define PROG3D_VOLUME_HPP

class Volume {

    static Volume * _vox_op1, * _vox_op2;

    Voxel vox;

    bool has_child, exist, complete;
    std::array<Volume *, 8> child;

public:
    int depth_tree;

public:

    Volume();
    Volume(const Point&, double, int, bool(*)(void*, double, double, double), void*);
    Volume(const Volume&);
    ~Volume();

    bool Inside(double, double, double) const;

    Volume Intersection(Volume&);
    Volume Union(Volume&);
    Volume Soustraction(Volume&);

    void Draw() const;
    void DrawLines() const;

    void operator=(const Volume&);

private:

    Voxel GetChild(int) const;

};

#endif //PROG3D_VOLUME_HPP

#endif