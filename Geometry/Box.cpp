#include "Box.hpp"

Box::Box() {

}

Box::Box(const Point& p, const Vecteur& v1, const Vecteur& v2, const Vecteur& v3) {
    this->P[0] = p;
    this->V[0] = v1;
    this->V[1] = v2;
    this->V[2] = v3;

    this->P[1] = p + v3;
    this->P[2] = p + v2;
    this->P[3] = p + v2 + v3;
    this->P[4] = p + v1;
    this->P[5] = p + v1 + v3;
    this->P[6] = p + v1 + v2;
    this->P[7] = p + v1 + v2 + v3;
}

Box::Box(const Box& b) {
    for (unsigned int i = 0; i < 8; i++) {
        this->P[i] = b.P[i];
    }
    for (unsigned int i = 0; i < 3; i++) {
        this->V[i] = b.V[i];
    }
}

const Point& Box::GetPoint(int i) const {
    return this->P[i];
}

const Vecteur& Box::GetVector(int i) const {
    return this->V[i];
}

void Box::Draw() const {
    glBegin(GL_LINES);
    this->P[0].Apply();
    this->P[1].Apply();
    this->P[0].Apply();
    this->P[2].Apply();
    this->P[1].Apply();
    this->P[3].Apply();
    this->P[2].Apply();
    this->P[3].Apply();

    this->P[4].Apply();
    this->P[5].Apply();
    this->P[4].Apply();
    this->P[6].Apply();
    this->P[5].Apply();
    this->P[7].Apply();
    this->P[6].Apply();
    this->P[7].Apply();

    this->P[0].Apply();
    this->P[4].Apply();
    this->P[1].Apply();
    this->P[5].Apply();
    this->P[2].Apply();
    this->P[6].Apply();
    this->P[3].Apply();
    this->P[7].Apply();
    glEnd();
}

bool Box::Inside(const Point& p) const {
    Point mid = this->P[0] + this->V[0] * 0.5 + this->V[1] * 0.5 + this->V[2] * 0.5;
    double length = Segment(this->P[0], this->P[0] + this->V[0] + this->V[1] + this->V[2]).GetLength() / 2;
    return (
        Segment(mid, p.GetProjection(Droite(this->P[0], this->V[0]))).GetLength() <= length &&
        Segment(mid, p.GetProjection(Droite(this->P[0], this->V[1]))).GetLength() <= length &&
        Segment(mid, p.GetProjection(Droite(this->P[0], this->V[2]))).GetLength() <= length
    );
}