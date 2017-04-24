#include "TP11.hpp"

/****** EXERCICE 2 ******/

TP11Exo2::TP11Exo2() :
    camera(Point(0, 0, -8)), house(Point(), 4, 4, 5, 0.3)
{
    Fenetre::Actual().initPerspective();
    
    this->house.LoadTextures();
}

void TP11Exo2::OnDraw3D() {
    camera.Apply();
    
    house.Draw();
}
void TP11Exo2::OnDraw2D() {}

void TP11Exo2::OnKeyboardEvent(unsigned char key, int, int) {
    switch (key) {
        default:
            std::cout << "[KEY]: " << (int)key << std::endl;
            break;
    }
}

void TP11Exo2::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP11Exo2::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}