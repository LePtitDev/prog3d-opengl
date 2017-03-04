#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_RECTANGLE_HPP
#define PROG3D_RECTANGLE_HPP

class RRectangle {

private:

    Point A, B, C, D;

public:

    RRectangle();
    RRectangle(const Point&, const Point&, const Point&);
    RRectangle(const RRectangle&);

    double GetWidth() const;
    double GetHeight() const;

    const Point& GetA() const;
    const Point& GetB() const;
    const Point& GetC() const;
    const Point& GetD() const;
    const Point * GetPoints() const;

    void Draw() const;

    Plan GetPlan() const;

};

#endif //PROG3D_RECTANGLE_HPP

#endif