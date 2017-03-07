#ifndef PROG3D_MAIN_HPP
#include "main.hpp"

#else

#ifndef PROG3D_RAYCASTER_HPP
#define PROG3D_RAYCASTER_HPP

class Raycaster {

    std::vector<const Mesh *> mesh;

public:

    Raycaster();
    Raycaster(const Raycaster&);

    void Add(const Mesh&);
    unsigned int MeshNumber() const;

    const Mesh& operator[](unsigned int) const;

    std::vector<Point> Ray(const Droite&) const;

    std::vector<Point> RayOnScreen(const Camera&, int, int) const;

    static std::vector<Point> Ray(const Droite&, const Mesh&);

    static std::vector<Point> RayOnScreen(const Camera&, int, int, const Mesh&);

private:

    static bool Ray(const Droite&, const Triangle&, Point&);

};

#endif //PROG3D_RAYCASTER_HPP

#endif