#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_COLOR_HPP
#define PROG3D_COLOR_HPP

class uColor {

public:

    static uColor WHITE, GREY, BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW;

    unsigned char r, g, b, a;

    uColor();
    uColor(unsigned char, unsigned char, unsigned char);
    uColor(unsigned char, unsigned char, unsigned char, unsigned char);
    uColor(const uColor&);

    float GetRf() const;
    float GetGf() const;
    float GetBf() const;
    float GetAf() const;

    void Apply3f() const;
    void Apply4f() const;

};

#endif //PROG3D_COLOR_HPP

#endif