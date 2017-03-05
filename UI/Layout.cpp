#include "Layout.hpp"

uiLayout::uiLayout() :
        width(Fenetre::Actual().GetWidth()), height(Fenetre::Actual().GetHeight()), mouse_button_down(0)
{

}

uiLayout::~uiLayout() {
    for (unsigned int i = 0, sz = this->widget.size(); i < sz; i++) {
        delete this->widget[i];
    }
}

void uiLayout::AddWidget(uiWidget& w) {
    this->widget.push_back(&w);
}

void uiLayout::RemoveWidget(uiWidget& w) {
    for (unsigned int i = 0, sz = this->widget.size(); i < sz; i++) {
        if (this->widget[i] == &w) {
            delete this->widget[i];
            this->widget.erase(this->widget.begin() + i);
        }
    }
}

bool uiLayout::MouseInside(int x, int y) const {
    for (unsigned int i = 0, sz = this->widget.size(); i < sz; i++) {
        if (this->widget[i]->MouseInside(x, y))
            return true;
    }
    return false;
}

void uiLayout::OnDisplay() {
    for (unsigned int i = 0, sz = this->widget.size(); i < sz; i++) {
        this->widget[i]->Draw();
    }
}

void uiLayout::OnReshape(int w, int h) {
    double dw = (double)w / (double)this->width, dh = (double)h / (double)this->height;
    Point after_middle = Point(this->width / 2, this->height / 2, 0);
    for (unsigned int i = 0, sz = this->widget.size(); i < sz; i++) {
        if (this->widget[i]->position.x < after_middle.x) {
            this->widget[i]->position.x *= dw;
            this->widget[i]->SetWidth(this->widget[i]->GetWidth() * dw);
        }
        else {
            int right = (this->widget[i]->position.x + this->widget[i]->GetWidth()) * dw;
            this->widget[i]->SetWidth(this->widget[i]->GetWidth() * dw);
            this->widget[i]->position.x = right - this->widget[i]->GetWidth();
        }
        if (this->widget[i]->position.y < after_middle.y) {
            this->widget[i]->position.y *= dh;
            this->widget[i]->SetHeight(this->widget[i]->GetHeight() * dh);
        }
        else {
            int bottom = (this->widget[i]->position.y + this->widget[i]->GetHeight()) * dh;
            this->widget[i]->SetHeight(this->widget[i]->GetHeight() * dh);
            this->widget[i]->position.y = bottom - this->widget[i]->GetHeight();
        }
    }
    this->width = w;
    this->height = h;
}

void uiLayout::OnKeyboardEvent(unsigned char key, int x, int y) {
    for (unsigned int i = 0, sz = this->widget.size(); i < sz; i++) {
        this->widget[i]->OnKeyDown(key);
    }
}

void uiLayout::OnMouseEvent(int button, int state, int x, int y) {
    unsigned int i = 0, sz = this->widget.size();
    this->mouse_button_down = button;
    if (state == 0) {
        switch (button) {
            case 3:
                for (; i < sz; i++) {
                    this->widget[i]->OnScrollUp(x, y);
                }
                break;
            case 4:
                for (; i < sz; i++) {
                    this->widget[i]->OnScrollDown(x, y);
                }
                break;
            default:
                for (; i < sz; i++) {
                    this->widget[i]->OnMouseDown(button, x, y);
                }
        }
    }
    else {
        if (button != 3 && button != 4) {
            for (; i < sz; i++) {
                this->widget[i]->OnMouseUp(button, x, y);
            }
        }
    }
}

void uiLayout::OnMotionPressedEvent(int x, int y) {
    for (unsigned int i = 0, sz = this->widget.size(); i < sz; i++) {
        this->widget[i]->OnMouseMotion(this->mouse_button_down, true, x, y);
    }
}

void uiLayout::OnMotionUnpressedEvent(int x, int y) {
    for (unsigned int i = 0, sz = this->widget.size(); i < sz; i++) {
        this->widget[i]->OnMouseMotion(this->mouse_button_down, false, x, y);
    }
}