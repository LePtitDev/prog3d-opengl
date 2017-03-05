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

    void SetWidth(int);
    int GetWidth() const;
    void SetHeight(int);
    int GetHeight() const;

    bool MouseInside(int, int) const;

    void Update();

    void Draw() const;

    void OnMouseUp(int, int, int);

    void OnMouseDown(int, int, int);

    void OnScrollUp(int, int);

    void OnScrollDown(int, int);

    void OnMouseMotion(int, bool, int, int);

    void OnKeyDown(unsigned char);

};

#endif //PROG3D_GRAPHFIFO_HPP

#endif