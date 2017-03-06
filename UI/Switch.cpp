#include "Switch.hpp"

const int uiSwitch::dim_width = 35;
const int uiSwitch::dim_height = 20;
const int uiSwitch::dim_corner = 2;
const int uiSwitch::dim_space = 5;
const float uiSwitch::color_enter_1[3] = { 60.f / 255.f, 127.f / 255.f, 177.f / 255.f };
const float uiSwitch::color_exit_1[3] = { 128.f / 255.f, 128.f / 255.f, 128.f / 255.f };
const float uiSwitch::color_clic_1[3] = { 60.f / 255.f, 127.f / 255.f, 177.f / 255.f };
const float uiSwitch::color_enter_2[3] = { 235.f / 255.f, 238.f / 255.f, 238.f / 255.f };
const float uiSwitch::color_exit_2[3] = { 235.f / 255.f, 238.f / 255.f, 238.f / 255.f };
const float uiSwitch::color_clic_2[3] = { 194.f / 255.f, 228.f / 255.f, 246.f / 255.f };
const float uiSwitch::color_enter_3[3] = { 213.f / 255.f, 217.f / 255.f, 218.f / 255.f };
const float uiSwitch::color_exit_3[3] = { 213.f / 255.f, 217.f / 255.f, 218.f / 255.f };
const float uiSwitch::color_clic_3[3] = { 156.f / 255.f, 210.f / 255.f, 238.f / 255.f };
const float uiSwitch::color_checked[3] = { 120.f / 255.f, 210.f / 255.f, 65.f / 255.f };
const float uiSwitch::color_unchecked[3] = { 225.f / 255.f, 65.f / 255.f, 65.f / 255.f };

uiSwitch::uiSwitch(const char * text, bool init_state, int x, int y, int w, int h, void (*action)(bool, void *), void * args) :
    text(text), clicked(false), enter(false), checked(init_state), width(w), height(h), action(action), args(args)
{
    this->position = Point(x, y, 0);
}

void uiSwitch::SetWidth(int) {}
int uiSwitch::GetWidth() const {
    return this->width;
}

void uiSwitch::SetHeight(int) {}
int uiSwitch::GetHeight() const {
    return this->height;
}

bool uiSwitch::MouseInside(int x, int y) const {
    return (this->position.x <= x && x <= this->position.x + this->width &&
            this->position.y <= y && y <= this->position.y + this->height);
}

void uiSwitch::Update() {}

void uiSwitch::Draw() const {
    int left = this->position.x, top = Fenetre::Actual().GetHeight() - this->position.y - this->height / 2 + uiSwitch::dim_height / 2,
        right = left + uiSwitch::dim_width, bottom = top - uiSwitch::dim_height;
    glBegin(GL_QUADS);
        glColor3fv((this->clicked) ? (const float *)uiSwitch::color_clic_1 : (this->enter) ? (const float *)uiSwitch::color_enter_1 : (const float *)uiSwitch::color_exit_1);
        glVertex2i(left, top);
        glVertex2i(right, top);
        glVertex2i(right, bottom);
        glVertex2i(left, bottom);

        glColor3f(1, 1, 1);
        glVertex2i(left + uiSwitch::dim_corner, top - uiSwitch::dim_corner);
        glVertex2i(right - uiSwitch::dim_corner, top - uiSwitch::dim_corner);
        glVertex2i(right - uiSwitch::dim_corner, bottom + uiSwitch::dim_corner);
        glVertex2i(left + uiSwitch::dim_corner, bottom + uiSwitch::dim_corner);

        glColor3fv((this->checked) ? (const float *)uiSwitch::color_checked : (const float *)uiSwitch::color_unchecked);
        glVertex2i(left + uiSwitch::dim_corner * 2, top - uiSwitch::dim_corner * 2);
        glVertex2i(right - uiSwitch::dim_corner * 2, top - uiSwitch::dim_corner * 2);
        glVertex2i(right - uiSwitch::dim_corner * 2, bottom + uiSwitch::dim_corner * 2);
        glVertex2i(left + uiSwitch::dim_corner * 2, bottom + uiSwitch::dim_corner * 2);

    if (checked) {
        left += uiSwitch::dim_width * 0.7;
        right -= uiSwitch::dim_corner;
    }
    else {
        left += uiSwitch::dim_corner;
        right -= uiSwitch::dim_width * 0.7;
    }

        glColor3fv((this->clicked) ? (const float *)uiSwitch::color_clic_2 : (this->enter) ? (const float *)uiSwitch::color_enter_2 : (const float *)uiSwitch::color_exit_2);
        glVertex2i(left, top);
        glVertex2i(right, top);
        glVertex2i(right, bottom);
        glVertex2i(left, bottom);

        glColor3fv((this->clicked) ? (const float *)uiSwitch::color_clic_3 : (this->enter) ? (const float *)uiSwitch::color_enter_3 : (const float *)uiSwitch::color_exit_3);
        glVertex2i(left, top - uiSwitch::dim_height / 2);
        glVertex2i(right, top - uiSwitch::dim_height / 2);
        glVertex2i(right, bottom);
        glVertex2i(left, bottom);
    glEnd();

    glColor3f(1, 1, 1);
    glRasterPos2i(this->position.x + uiSwitch::dim_width + uiSwitch::dim_space, top - uiSwitch::dim_height / 2 - 4);
    for (int i = 0, sz = this->text.size(); i < sz; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, this->text[i]);
    }
}

void uiSwitch::OnMouseUp(int button, int x, int y) {
    if (!this->clicked || button != 0) return;
    int left = this->position.x, top = this->position.y + this->height / 2 - uiSwitch::dim_height / 2,
            right = left + uiSwitch::dim_width, bottom = top + uiSwitch::dim_height;
    this->clicked = false;
    if (left <= x && x <= right && top <= y && y <= bottom) {
        this->checked = !this->checked;
        if (this->action != nullptr)
            this->action(this->checked, this->args);
    }
}

void uiSwitch::OnMouseDown(int button, int x, int y) {
    if (button != 0) return;
    int left = this->position.x, top = this->position.y + this->height / 2 - uiSwitch::dim_height / 2,
            right = left + uiSwitch::dim_width, bottom = top + uiSwitch::dim_height;
    if (left <= x && x <= right && top <= y && y <= bottom) {
        this->clicked = true;
    }
}

void uiSwitch::OnScrollUp(int, int) {}

void uiSwitch::OnScrollDown(int, int) {}

void uiSwitch::OnMouseMotion(int button, bool click, int x, int y) {
    int left = this->position.x, top = this->position.y + this->height / 2 - uiSwitch::dim_height / 2,
            right = left + uiSwitch::dim_width, bottom = top + uiSwitch::dim_height;
    if (left <= x && x <= right && top <= y && y <= bottom) {
        this->enter = true;
    }
    else {
        this->enter = false;
    }
}

void uiSwitch::OnKeyDown(unsigned char) {}