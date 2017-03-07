#include "FPS_Counter.hpp"

const int uiFPS_Counter::dim_text_height = 20;

uiFPS_Counter::uiFPS_Counter(int x, int y, int w, int h, const uColor & color) :
    width(w), height(h), graph(x, y + uiFPS_Counter::dim_text_height, w, h - uiFPS_Counter::dim_text_height, w / 3, color), fps(0), frame(0), count(0)
{
    this->position = Point(x, y, 0);
    timer.Start();
}

int uiFPS_Counter::GetWidth() const {
    return this->width;
}

int uiFPS_Counter::GetHeight() const {
    return this->height;
}

bool uiFPS_Counter::MouseInside(int x, int y) const {
    return (this->position.x <= x && x <= this->position.x + this->width &&
            this->position.y <= y && y <= this->position.y + this->height);
}

void uiFPS_Counter::Update() {
    this->count++;
    if (this->frame < (int)(this->timer.GetTime())) {
        this->frame = (int)(this->timer.GetTime());
        this->fps = this->count;
        this->graph.PushValue(this->fps);
        this->count = 0;
    }
}

void uiFPS_Counter::Draw() const {
    this->graph.Draw();
    uColor::WHITE.Apply3f();
    glRasterPos2i(this->position.x, Fenetre::Actual().GetHeight() - this->position.y - uiFPS_Counter::dim_text_height / 2);
    std::string text = "FPS";
    for (int i = 0, sz = text.size(); i < sz; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
    }
    std::stringstream stream;
    stream << fps;
    text = stream.str();
    uColor::GREY.Apply3f();
    glRasterPos2i(this->position.x + 40, Fenetre::Actual().GetHeight() - this->position.y - uiFPS_Counter::dim_text_height / 2);
    for (int i = 0, sz = text.size(); i < sz; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
    }
}