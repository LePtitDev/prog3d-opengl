#include "Tab.hpp"

const int uiTab::dim_corner = 2;
const int uiTab::dim_padding = 10;

const uColor uiTab::color_1 = uColor(128, 128, 128);
const uColor uiTab::color_2 = uColor(235, 238, 238);
const uColor uiTab::color_3 = uColor(213, 217, 218);
const uColor uiTab::color_4 = uColor(64, 64, 64);

uColor uiTab::TAB_COLORS[7];
unsigned int uiTab::MAX_COLORS = 7;
bool uiTab::COLOR_INITIALIZED = false;

uiTab::uiTab(int x, int y, int w, int h, void (*action)(int, void*), void * args) :
    width(w), height(h), selected(0), hover(-1), action(action), args(args)
{
    if (!uiTab::COLOR_INITIALIZED) {
        uiTab::TAB_COLORS[0] = uColor(uColor::ROYAL_BLUE);
        uiTab::TAB_COLORS[1] = uColor(uColor::LIGHT_CORAL);
        uiTab::TAB_COLORS[2] = uColor(uColor::BEIGE);
        uiTab::TAB_COLORS[3] = uColor(uColor::PINK);
        uiTab::TAB_COLORS[4] = uColor(uColor::LIGHT_GREEN);
        uiTab::TAB_COLORS[5] = uColor(uColor::BLUE);
        uiTab::TAB_COLORS[6] = uColor(uColor::RED);
    }
    this->position = Point(x, y, 0);
}

void uiTab::AddTab(const char * name) {
    uColor color(uColor::WHITE);
    if (this->tabs.size() < uiTab::MAX_COLORS)
        color = uColor(uiTab::TAB_COLORS[this->tabs.size()]);
    this->AddTab(name, color);
}
void uiTab::AddTab(const char * name, const uColor & color) {
    this->tabs.push_back(std::pair<std::string, uColor>(std::string(name), color));
    this->lengths.push_back(glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char *)name));
}

void uiTab::SetWidth(int w) {
    this->width = w;
}

int uiTab::GetWidth() const {
    return this->width;
}

int uiTab::GetHeight() const {
    return this->height;
}

bool uiTab::MouseInside(int x, int y) const {
    return (this->position.x <= x && x <= this->position.x + this->width &&
            this->position.y <= y && y <= this->position.y + this->height);
}

void uiTab::Draw() const {
    if (this->tabs.size() == 0) return;
    int left = this->position.x, top = Fenetre::Actual().GetHeight() - this->position.y,
            right = left + this->width, bottom = top - this->height;
    glBegin(GL_QUADS);
    uiTab::color_4.Apply3f();
    glVertex2i(left, top);
    glVertex2i(right, top);
    glVertex2i(right, bottom);
    glVertex2i(left, bottom);

    for (unsigned int i = 0, j = 0, k = uiTab::dim_corner * 2 + uiTab::dim_padding * 2 + this->lengths[0], sz = this->tabs.size(); i < sz; j += k, k = uiTab::dim_corner * 2 + uiTab::dim_padding * 2 + this->lengths[++i]) {
        if (this->hover == i || this->selected == i) {
            this->tabs[i].second.Apply3f();
        } else {
            uiTab::color_1.Apply3f();
        }
        glVertex2i(left + j, top);
        glVertex2i(left + j + k, top);
        glVertex2i(left + j + k, bottom);
        glVertex2i(left + j, bottom);

        uiTab::color_2.Apply3f();
        glVertex2i(left + j + uiTab::dim_corner, top - uiTab::dim_corner);
        glVertex2i(left + j + k - uiTab::dim_corner, top - uiTab::dim_corner);
        glVertex2i(left + j + k - uiTab::dim_corner, bottom + uiTab::dim_corner);
        glVertex2i(left + j + uiTab::dim_corner, bottom + uiTab::dim_corner);

        uiTab::color_3.Apply3f();
        glVertex2i(left + j + uiTab::dim_corner, top - this->height / 2);
        glVertex2i(left + j + k - uiTab::dim_corner, top - this->height / 2);
        glVertex2i(left + j + k - uiTab::dim_corner, bottom + uiTab::dim_corner);
        glVertex2i(left + j + uiTab::dim_corner, bottom + uiTab::dim_corner);
    }

    this->tabs[this->selected].second.Apply3f();
    glVertex2i(left, bottom + uiTab::dim_corner);
    glVertex2i(right, bottom + uiTab::dim_corner);
    glVertex2i(right, bottom);
    glVertex2i(left, bottom);
    glEnd();

    glColor3f(0, 0, 0);
    for (unsigned int i = 0, j = 0, k = uiTab::dim_corner * 2 + uiTab::dim_padding * 2 + this->lengths[0], sz = this->tabs.size(); i < sz; j += k, k = uiTab::dim_corner * 2 + uiTab::dim_padding * 2 + this->lengths[++i]) {
        glRasterPos2i(left + j + uiTab::dim_padding, top - this->height / 2 - 4);
        for (int l = 0, sz2 = this->tabs[i].first.size(); l < sz2; l++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, this->tabs[i].first[l]);
        }
    }
}


void uiTab::OnMouseDown(int button, int x, int y) {
    if (this->tabs.size() == 0) return;
    if (button != 0 || !this->MouseInside(x, y)) return;
    for (unsigned int i = 0, j = 0, k = uiTab::dim_corner * 2 + uiTab::dim_padding * 2 + this->lengths[0], sz = this->tabs.size(); i < sz; j += k, k = uiTab::dim_corner * 2 + uiTab::dim_padding * 2 + this->lengths[++i]) {
        if (this->position.x + j <= x && x <= this->position.x + j + k &&
            this->position.y <= y && y <= this->position.y + this->height) {
            this->selected = i;
            if (this->action != nullptr)
                this->action(i, this->args);
            break;
        }
    }
}

void uiTab::OnMouseMotion(int button, bool state, int x, int y) {
    if (this->tabs.size() == 0) return;
    if (this->MouseInside(x, y)) {
        for (unsigned int i = 0, j = 0, k = uiTab::dim_corner * 2 + uiTab::dim_padding * 2 + this->lengths[0], sz = this->tabs.size(); i < sz; j += k, k = uiTab::dim_corner * 2 + uiTab::dim_padding * 2 + this->lengths[++i]) {
            if (this->position.x + j <= x && x <= this->position.x + j + k &&
                this->position.y <= y && y <= this->position.y + this->height) {
                this->hover = i;
                return;
            }
        }
        this->hover = -1;
    }
    else {
        this->hover = -1;
    }
}