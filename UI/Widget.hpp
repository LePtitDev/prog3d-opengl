#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_WIDGET_HPP
#define PROG3D_WIDGET_HPP

class uiWidget {

public:

    Point position;

    virtual void SetWidth(int) = 0;
    virtual int GetWidth() const = 0;
    virtual void SetHeight(int) = 0;
    virtual int GetHeight() const = 0;

    virtual bool MouseInside(int, int) const = 0;

    virtual void Draw() const = 0;

    virtual void OnMouseUp(int, int, int) = 0;

    virtual void OnMouseDown(int, int, int) = 0;

    virtual void OnScrollUp(int, int) = 0;

    virtual void OnScrollDown(int, int) = 0;

    virtual void OnMouseMotion(int, bool, int, int) = 0;

    virtual void OnKeyDown(unsigned char) = 0;

};

#endif //PROG3D_WIDGET_HPP

#endif