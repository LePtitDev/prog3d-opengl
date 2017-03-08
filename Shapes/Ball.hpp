#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_BALL_HPP
#define PROG3D_BALL_HPP

class Ball {

    Point p;
    double r;

    Surface surface;

public:

    Ball();
    Ball(const Point&, double, long, long);
    Ball(const Ball&);

    static Surface SurfaceByBall(const Ball&, long, long);

    bool Inside(double, double, double);

    void Draw();

    Mesh GetMesh(unsigned int);

};

#endif //PROG3D_BALL_HPP

#endif