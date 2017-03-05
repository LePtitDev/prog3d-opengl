#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_SWITCH_HPP
#define PROG3D_SWITCH_HPP

class uiSwitch : public uiWidget {

    static const int dim_width, dim_height, dim_corner, dim_space;
    static const float color_enter_1[3];
    static const float color_exit_1[3];
    static const float color_clic_1[3];
    static const float color_enter_2[3];
    static const float color_exit_2[3];
    static const float color_clic_2[3];
    static const float color_enter_3[3];
    static const float color_exit_3[3];
    static const float color_clic_3[3];
    static const float color_checked[3];
    static const float color_unchecked[3];

    const int width, height;

    std::string text;
    bool clicked, enter, checked;

    void (*action)(bool, void*);
    void * args;

public:

    uiSwitch(const char *, bool, int, int, int, int, void(*)(bool, void*), void*);

    void SetWidth(int);
    int GetWidth() const;
    void SetHeight(int);
    int GetHeight() const;

    bool MouseInside(int, int) const;

    void Draw() const;

    void OnMouseUp(int, int, int);

    void OnMouseDown(int, int, int);

    void OnScrollUp(int, int);

    void OnScrollDown(int, int);

    void OnMouseMotion(int, bool, int, int);

    void OnKeyDown(unsigned char);

};

#endif //PROG3D_SWITCH_HPP

#endif