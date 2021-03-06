#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_BOUTON_HPP
#define PROG3D_BOUTON_HPP

class uiBouton : public uiWidget {

    static const int dim_corner;
    static const float color_enter_1[3];
    static const float color_exit_1[3];
    static const float color_clic_1[3];
    static const float color_enter_2[3];
    static const float color_exit_2[3];
    static const float color_clic_2[3];
    static const float color_enter_3[3];
    static const float color_exit_3[3];
    static const float color_clic_3[3];

    std::string text;
    const int width, height;
    bool enter, clicked;
    void (*action)(void*);
    void * args;

public:

    uiBouton(const char *, int, int, int, int, void(*)(void*), void *);

    int GetWidth() const;
    int GetHeight() const;

    bool MouseInside(int, int) const;

    void Draw() const;

    void OnMouseUp(int, int, int);

    void OnMouseDown(int, int, int);

    void OnMouseMotion(int, bool, int, int);

};

#endif //PROG3D_BOUTON_HPP

#endif