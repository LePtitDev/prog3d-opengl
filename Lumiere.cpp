#include "Lumiere.hpp"

Lumiere::Lumiere(const Point & pos) :
    light(GL_LIGHT0 + Lumiere::nb_lights), pos(pos), intensity(1)
{
    if (Lumiere::nb_lights == 0)
        Lumiere::EnableLights();
    Lumiere::nb_lights++;

    if (Lumiere::nb_lights >= GL_MAX_LIGHTS)
        light = GL_LIGHT0 + GL_MAX_LIGHTS - 1;
}

Lumiere::~Lumiere() {
    Lumiere::nb_lights--;
    if (Lumiere::nb_lights == 0)
        glDisable(GL_LIGHTING);
}

void Lumiere::Apply() const {
    glEnable(GL_LIGHT0);
    float position[4] = { (float)this->pos.x, (float)this->pos.y, (float)this->pos.z, 1 };
    glLightfv(this->light, GL_POSITION, position);
}

int Lumiere::nb_lights = 0;

void Lumiere::Mode2D() {
    if (Lumiere::nb_lights > 0) Lumiere::DisableLights();
}

void Lumiere::Mode3D() {
    if (Lumiere::nb_lights > 0) Lumiere::EnableLights();
}

void Lumiere::EnableLights() {
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void Lumiere::DisableLights() {
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
}