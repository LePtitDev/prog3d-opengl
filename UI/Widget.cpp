#include "Widget.hpp"

void uiWidget::SetWidth(int) {}
int uiWidget::GetWidth() const {
    return 0;
}

void uiWidget::SetHeight(int) {}
int uiWidget::GetHeight() const {
    return 0;
}

bool uiWidget::MouseInside(int, int) const {
    return false;
}

void uiWidget::Update() {}

void uiWidget::OnMouseUp(int, int, int) {}
void uiWidget::OnMouseDown(int, int, int) {}
void uiWidget::OnScrollUp(int, int) {}
void uiWidget::OnScrollDown(int, int) {}
void uiWidget::OnMouseMotion(int, bool, int, int) {}
void uiWidget::OnKeyDown(unsigned char) {}