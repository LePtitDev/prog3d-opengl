#include "Bouton.hpp"

const int uiBouton::dim_corner = 2;
const float uiBouton::color_enter_1[3] = { 60.f / 255.f, 127.f / 255.f, 177.f / 255.f };
const float uiBouton::color_exit_1[3] = { 128.f / 255.f, 128.f / 255.f, 128.f / 255.f };
const float uiBouton::color_clic_1[3] = { 60.f / 255.f, 127.f / 255.f, 177.f / 255.f };
const float uiBouton::color_enter_2[3] = { 63.f / 255.f, 208.f / 255.f, 245.f / 255.f };
const float uiBouton::color_exit_2[3] = { 255.f / 255.f, 255.f / 255.f, 255.f / 255.f };
const float uiBouton::color_clic_2[3] = { 140.f / 255.f, 161.f / 255.f, 172.f / 255.f };
const float uiBouton::color_enter_3[3] = { 235.f / 255.f, 238.f / 255.f, 238.f / 255.f };
const float uiBouton::color_exit_3[3] = { 235.f / 255.f, 238.f / 255.f, 238.f / 255.f };
const float uiBouton::color_clic_3[3] = { 194.f / 255.f, 228.f / 255.f, 246.f / 255.f };
const float uiBouton::color_enter_4[3] = { 213.f / 255.f, 217.f / 255.f, 218.f / 255.f };
const float uiBouton::color_exit_4[3] = { 213.f / 255.f, 217.f / 255.f, 218.f / 255.f };
const float uiBouton::color_clic_4[3] = { 156.f / 255.f, 210.f / 255.f, 238.f / 255.f };

uiBouton::uiBouton(const char * text, int x, int y, int width, int height, void (*action)(void*), void * args) :
    text(text), width(width), height(height), action(action), args(args)
{
    this->position = Point(x, y, 0);
}

void uiBouton::SetWidth(int) {}
int uiBouton::GetWidth() const {
    return this->width;
}

void uiBouton::SetHeight(int) {}
int uiBouton::GetHeight() const {
    return this->height;
}

bool uiBouton::MouseInside(int x, int y) const {
    return (this->position.x <= x && x <= this->position.x + this->width &&
            this->position.y <= y && y <= this->position.y + this->height);
}

void uiBouton::Draw() const {
    int left = this->position.x, top = Fenetre::Actual().GetHeight() - this->position.y,
        right = left + this->width, bottom = top - this->height;
    glBegin(GL_LINE_STRIP);
    glColor3fv((this->clicked) ? (const float *)uiBouton::color_clic_1 : (this->enter) ? (const float *)uiBouton::color_enter_1 : (const float *)uiBouton::color_exit_1);
    glVertex2i(left + 1, top - uiBouton::dim_corner);
    glVertex2i(left + uiBouton::dim_corner, top);
    glVertex2i(left + uiBouton::dim_corner, top);
    glVertex2i(right - uiBouton::dim_corner, top);
    glVertex2i(right, top - uiBouton::dim_corner);
    glVertex2i(right, bottom + uiBouton::dim_corner + 1);
    glVertex2i(right - uiBouton::dim_corner, bottom + 1);
    glVertex2i(left + uiBouton::dim_corner, bottom + 1);
    glVertex2i(left + 1, bottom + uiBouton::dim_corner);
    glVertex2i(left + 1, top - uiBouton::dim_corner);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3fv((this->clicked) ? (const float *)uiBouton::color_clic_2 : (this->enter) ? (const float *)uiBouton::color_enter_2 : (const float *)uiBouton::color_exit_2);
    glVertex2i(left + 2, top - uiBouton::dim_corner);
    glVertex2i(left + uiBouton::dim_corner, top - 1);
    glVertex2i(left + uiBouton::dim_corner, top - 1);
    glVertex2i(right - uiBouton::dim_corner, top - 1);
    glVertex2i(right - 1, top - uiBouton::dim_corner);
    glVertex2i(right - 1, bottom + uiBouton::dim_corner + 1);
    glVertex2i(right - uiBouton::dim_corner, bottom + 2);
    glVertex2i(left + uiBouton::dim_corner, bottom + 2);
    glVertex2i(left + 2, bottom + uiBouton::dim_corner + 1);
    glVertex2i(left + 2, top - uiBouton::dim_corner);
    glEnd();
    glBegin(GL_QUADS);
    glColor3fv((this->clicked) ? (const float *)uiBouton::color_clic_3 : (this->enter) ? (const float *)uiBouton::color_enter_3 : (const float *)uiBouton::color_exit_3);
    glVertex2i(left + uiBouton::dim_corner, top - uiBouton::dim_corner);
    glVertex2i(right - uiBouton::dim_corner, top - uiBouton::dim_corner);
    glVertex2i(right - uiBouton::dim_corner, bottom + uiBouton::dim_corner);
    glVertex2i(left + uiBouton::dim_corner, bottom + uiBouton::dim_corner);
    glEnd();
    glBegin(GL_QUADS);
    glColor3fv((this->clicked) ? (const float *)uiBouton::color_clic_4 : (this->enter) ? (const float *)uiBouton::color_enter_4 : (const float *)uiBouton::color_exit_4);
    glVertex2i(left + uiBouton::dim_corner, top - this->height / 2);
    glVertex2i(right - uiBouton::dim_corner, top - this->height / 2);
    glVertex2i(right - uiBouton::dim_corner, bottom + uiBouton::dim_corner);
    glVertex2i(left + uiBouton::dim_corner, bottom + uiBouton::dim_corner);
    glEnd();

    int length = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char *)this->text.c_str());
    glColor3f(0, 0, 0);
    glRasterPos2i(left + this->width / 2 - length / 2, top - this->height / 2 - 4);
    for (int i = 0, sz = this->text.size(); i < sz; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, this->text[i]);
    }
}

void uiBouton::OnMouseUp(int button, int x, int y) {
    if (button == 0)
        this->clicked = false;
    if (this->action != nullptr && this->MouseInside(x, y)) this->action(this->args);
}

void uiBouton::OnMouseDown(int button, int x, int y) {
    if (button == 0 && this->MouseInside(x, y))
        this->clicked = true;
}

void uiBouton::OnScrollUp(int, int) {}

void uiBouton::OnScrollDown(int, int) {}

void uiBouton::OnMouseMotion(int button, bool click, int x, int y) {
    if (this->MouseInside(x, y))
        this->enter = true;
    else
        this->enter = false;
}

void uiBouton::OnKeyDown(unsigned char) {}