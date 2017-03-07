#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_GRAPHFIFO_HPP
#define PROG3D_GRAPHFIFO_HPP

class uiGraphFIFO : public uiWidget {

    const int width, height, max_values;

    int index;
    std::vector<double> table;

    uColor color;

public:

    uiGraphFIFO(int, int, int, int, int, const uColor&);

    void PushValue(double);

    int GetWidth() const;
    int GetHeight() const;

    bool MouseInside(int, int) const;

    void Draw() const;

};

#endif //PROG3D_GRAPHFIFO_HPP

#endif