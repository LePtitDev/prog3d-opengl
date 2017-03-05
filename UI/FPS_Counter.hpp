#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_FPS_COUNTER_HPP
#define PROG3D_FPS_COUNTER_HPP

class uiFPS_Counter : public uiWidget {

    static const int dim_text_height;

    uTimer timer;
    uiGraphFIFO graph;
    double fps;
    int frame, count;

    const int width, height;

public:

    uiFPS_Counter(int, int, int, int, const uColor&);

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

#endif //PROG3D_FPS_COUNTER_HPP

#endif