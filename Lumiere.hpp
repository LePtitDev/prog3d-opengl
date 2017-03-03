#ifndef PROG3D_MAIN_HPP
#include "main.hpp"

#else

#ifndef PROG3D_LUMIERE_HPP
#define PROG3D_LUMIERE_HPP

class Lumiere {

private:

    int light;

public:

    Point pos;
    float intensity;

    Lumiere(const Point& = Point(0, 0, 0));
    ~Lumiere();

    void Apply() const;

private:

    static int nb_lights;

public:

    static void EnableLights();
    static void DisableLights();

};

#endif //PROG3D_LUMIERE_HPP

#endif