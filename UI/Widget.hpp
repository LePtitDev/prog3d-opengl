#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_WIDGET_HPP
#define PROG3D_WIDGET_HPP

class uiWidget {

public:

    Point position;

    virtual void SetWidth(int);
    virtual int GetWidth() const;
    virtual void SetHeight(int);
    virtual int GetHeight() const;

    virtual bool MouseInside(int, int) const;

    virtual void Update();

    virtual void Draw() const = 0;

    virtual void OnMouseUp(int, int, int);

    virtual void OnMouseDown(int, int, int);

    virtual void OnScrollUp(int, int);

    virtual void OnScrollDown(int, int);

    virtual void OnMouseMotion(int, bool, int, int);

    virtual void OnKeyDown(unsigned char);

};

#endif //PROG3D_WIDGET_HPP

#endif