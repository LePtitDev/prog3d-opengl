#include "TP8.hpp"

TP8Exo1::TP8Exo1() :
    camera(Point(0, 0, 40))
{
    Fenetre::Actual().initPerspective();

    this->mesh = FileOFF("Ressources/TP 8/MeshSegmentation.off").GetMesh();
    this->mesh.CalculateAretes();
    this->segms = this->mesh.Segmenter(M_PI - M_PI / 6);
    std::cout << this->segms.size() << std::endl;
}

void TP8Exo1::OnDraw3D() {
    camera.Apply();

    for (unsigned int i = 0, sz = this->segms.size(); i < sz; i++) {
        glColor3f((float)((double)i / (double)(sz - 1)), 0.3, 0.7);
        this->segms[i].Draw();
        this->segms[i].PolygonMode(GL_LINE);
        glColor3f(0, 0, 0);
        this->segms[i].Draw();
        this->segms[i].PolygonMode(GL_FILL);
    }

/*
    glColor3f(0.5, 0.3, 0.7);
    this->mesh.Draw();
    this->mesh.PolygonMode(GL_LINE);
    glColor3f(0, 0, 0);
    this->mesh.Draw();
    this->mesh.PolygonMode(GL_FILL);
*/
}
void TP8Exo1::OnDraw2D() {}

void TP8Exo1::OnKeyboardEvent(unsigned char, int, int) {}

void TP8Exo1::OnMouseEvent(int button, int state, int x, int y) {
    camera.OnMouseEvent(button, state, x, y);
}

void TP8Exo1::OnMotionPressedEvent(int x, int y) {
    camera.OnMotionPressedEvent(x, y);
}

void TP8Exo1::OnMotionUnpressedEvent(int, int) {}