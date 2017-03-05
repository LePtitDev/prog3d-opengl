#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_LAYOUT_HPP
#define PROG3D_LAYOUT_HPP

class uiLayout {

    int width, height;

    std::vector<uiWidget *> widget;

    int mouse_button_down;

public:

    uiLayout();
    ~uiLayout();

    void AddWidget(uiWidget *);
    void RemoveWidget(uiWidget *);

    bool MouseInside(int, int) const;

    void OnDisplay();

    void OnReshape(int, int);

    void OnKeyboardEvent(unsigned char, int, int);

    void OnMouseEvent(int, int, int, int);

    void OnMotionPressedEvent(int, int);

    void OnMotionUnpressedEvent(int, int);

};

#endif //PROG3D_LAYOUT_HPP

#endif