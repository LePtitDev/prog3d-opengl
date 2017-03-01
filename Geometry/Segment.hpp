#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_SEGMENT_HPP
#define PROG3D_SEGMENT_HPP

class Segment {

public:

    Point p1, p2;

    Segment();
    Segment(const Point&, const Point&);
    Segment(const Segment&);

    double GetLength() const;

    void Draw() const;

};

#endif //PROG3D_SEGMENT_HPP

#endif