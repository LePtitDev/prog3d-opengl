#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_TAB_HPP
#define PROG3D_TAB_HPP

class uiTab : public uiWidget {

    static const int dim_corner, dim_padding;
    static const uColor color_1, color_2, color_3, color_4;

    static uColor TAB_COLORS[];
    static unsigned int MAX_COLORS;
    static bool COLOR_INITIALIZED;

    int width, height;

    std::vector<std::pair<std::string, uColor>> tabs;
    std::vector<int> lengths;
    int selected, hover;

    void (*action)(int, void*);
    void * args;

public:

    uiTab(int, int, int, int, void(*)(int, void*), void*);

    void AddTab(const char *);
    void AddTab(const char *, const uColor&);

    void SetWidth(int);
    int GetWidth() const;
    int GetHeight() const;

    bool MouseInside(int, int) const;

    void Draw() const;

    void OnMouseDown(int, int, int);

    void OnMouseMotion(int, bool, int, int);

};

#endif //PROG3D_UITAB_HPP

#endif
