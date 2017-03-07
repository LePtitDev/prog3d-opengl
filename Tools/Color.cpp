#include "Color.hpp"

uColor uColor::WHITE(255, 255, 255);
uColor uColor::GREY(128, 128, 128);
uColor uColor::BLACK(0, 0, 0);
uColor uColor::RED(255, 0, 0);
uColor uColor::GREEN(0, 255, 0);
uColor uColor::BLUE(0, 0, 255);
uColor uColor::CYAN(0, 255, 255);
uColor uColor::MAGENTA(255, 0, 255);
uColor uColor::YELLOW(255, 255, 0);
uColor uColor::PINK(255, 102, 204);
uColor uColor::ORANGE(255, 128, 0);
uColor uColor::LIGHT_CORAL(255, 128, 128);
uColor uColor::LIGHT_GREEN(128, 255, 128);
uColor uColor::ROYAL_BLUE(0, 128, 255);
uColor uColor::BROWN(128, 64, 0);
uColor uColor::BEIGE(255, 191, 128);

uColor::uColor() :
    r(0), g(0), b(0), a(255)
{

}

uColor::uColor(unsigned char r, unsigned char g, unsigned char b) :
    r(r), g(g), b(b), a(255)
{

}

uColor::uColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) :
        r(r), g(g), b(b), a(a)
{

}

uColor::uColor(const uColor & c) :
    r(c.r), g(c.g), b(c.b), a(c.a)
{

}

float uColor::GetRf() const {
    return (float)this->r / 255.f;
}
float uColor::GetGf() const {
    return (float)this->g / 255.f;
}
float uColor::GetBf() const {
    return (float)this->b / 255.f;
}
float uColor::GetAf() const {
    return (float)this->a / 255.f;
}

void uColor::Apply3f() const {
    glColor3f((float)this->r / 255.f, (float)this->g / 255.f, (float)this->b / 255.f);
}
void uColor::Apply4f() const {
    glColor4f((float)this->r / 255.f, (float)this->g / 255.f, (float)this->b / 255.f, (float)this->a / 255.f);
}