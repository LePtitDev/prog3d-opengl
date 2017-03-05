#include "GraphFIFO.hpp"

uiGraphFIFO::uiGraphFIFO(int x, int y, int w, int h, int max_values, const uColor & color) :
    width(w), height(h), max_values(max_values), color(color), index(0)
{
    this->position = Point(x, y, 0);
    this->table.reserve(max_values);
    for (unsigned int i = 0; i < max_values; i++) this->table.push_back(0);
}

void uiGraphFIFO::PushValue(double v) {
    this->table[this->index] = v;
    this->index = (this->index + 1) % this->max_values;
}

void uiGraphFIFO::SetWidth(int) {}
int uiGraphFIFO::GetWidth() const {
    return this->width;
}

void uiGraphFIFO::SetHeight(int) {}
int uiGraphFIFO::GetHeight() const {
    return this->height;
}

bool uiGraphFIFO::MouseInside(int x, int y) const {
    return (this->position.x <= x && x <= this->position.x + this->width &&
            this->position.y <= y && y <= this->position.y + this->height);
}

void uiGraphFIFO::Update() {}

void uiGraphFIFO::Draw() const {
    int left = this->position.x, top = Fenetre::Actual().GetHeight() - this->position.y,
            right = left + this->width, bottom = top - this->height;
    uColor bkgrd(this->color);
    bkgrd.a /= 2;

    double min_value = 0, max_value = 0;
    for (unsigned int i = 0; i < this->max_values; i++) {
        if (min_value > this->table[i]) min_value = this->table[i];
        if (max_value < this->table[i]) max_value = this->table[i];
    }
    if (min_value > 0) min_value = 0;
    if (max_value < 0) max_value = 0;

    //GRAPH
    double delta = max_value - min_value, previous, u_1, v_1, u, v;
    if (delta != 0) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        previous = table[this->index];
        u_1 = 0;
        v_1 = (previous - min_value) / delta;
        for (unsigned int i = (this->index + 1) % this->max_values, j = 1; j < this->max_values; i = (i + 1) % this->max_values, j++) {
            u = (double)j / (double)(this->max_values - 1);
            v = (this->table[i] - min_value) / delta;
            glBegin(GL_QUADS);
                bkgrd.Apply4f();
                glVertex2i(left + this->width * u_1, bottom);
                glVertex2i(left + this->width * u_1, bottom + this->height * v_1);
                glVertex2i(left + this->width * u, bottom + this->height * v);
                glVertex2i(left + this->width * u, bottom);
            glEnd();
            glBegin(GL_LINES);
                this->color.Apply4f();
                glVertex2i(left + this->width * u_1, bottom + this->height * v_1);
                glVertex2i(left + this->width * u, bottom + this->height * v);
            glEnd();
            u_1 = u;
            v_1 = v;
        }
        glDisable(GL_BLEND);
    }

    this->color.Apply4f();

    //BARRE A ZERO
    if (min_value < 0 && max_value > 0) {
        double v_0 = -min_value * this->height / delta;
        glLineStipple(1, 0xAAAA);
        glEnable(GL_LINE_STIPPLE);
            glVertex2i(left, bottom + v_0);
            glVertex2i(right, bottom + v_0);
        glDisable(GL_LINE_STIPPLE);
    }

    //CADRE
    glBegin(GL_LINE_STRIP);
        glVertex2i(left, top);
        glVertex2i(right, top);
        glVertex2i(right, bottom);
        glVertex2i(left, bottom);
        glVertex2i(left, top);
    glEnd();
}

void uiGraphFIFO::OnMouseUp(int, int, int) {}

void uiGraphFIFO::OnMouseDown(int, int, int) {}

void uiGraphFIFO::OnScrollUp(int, int) {}

void uiGraphFIFO::OnScrollDown(int, int) {}

void uiGraphFIFO::OnMouseMotion(int, bool, int, int) {}

void uiGraphFIFO::OnKeyDown(unsigned char) {}