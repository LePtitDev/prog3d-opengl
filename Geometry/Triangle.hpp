#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_TRIANGLE_HPP
#define PROG3D_TRIANGLE_HPP

class Triangle {

public:

    Point A, B, C;

    Triangle();
    Triangle(const Point&, const Point&, const Point&);
    Triangle(const Triangle&);

    void Draw() const;

    Plan GetPlan() const;

};

#endif //PROG3D_TRIANGLE_HPP

#endif