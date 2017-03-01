#include "Camera.hpp"

const double Camera::zoom_speed = 0.2;

const double Camera::rotation_speed = 0.01;

Camera::Camera() :
    pos(Point(0.0, 0.0, 3.0)), saved_pos(Point()), left_click(false), pos_x(0), pos_y(0)
{

}

Camera::Camera(const Point& p) :
    pos(p), saved_pos(Point()), left_click(false), pos_x(0), pos_y(0)
{

}

Camera::Camera(const Camera & c) :
    pos(c.pos), saved_pos(c.saved_pos), left_click(c.left_click), pos_x(c.pos_x), pos_y(c.pos_y)
{

}

void Camera::RotateLatitude(double a) {
    Vecteur vp(this->pos.x, this->pos.y, this->pos.z);
    Vecteur v1(vp.x, 0.f, vp.z);
    vp.Normalize(); v1.Normalize();
    double nv_a = asin(vp.y) + a, cos_a = cos(nv_a), sin_a = sin(nv_a);
    double dist = sqrt(this->pos.x * this->pos.x + this->pos.y * this->pos.y + this->pos.z * this->pos.z);
    this->pos = Point(v1.x * cos_a * dist, (v1.y * cos_a + sin_a) * dist, v1.z * cos_a * dist);
}

void Camera::RotateLongitude(double a) {
    Vecteur vp(this->pos.x, 0.f, this->pos.z);
    vp.Normalize();
    double nv_a = acos(vp.x) + a;
    double dist = sqrt(this->pos.x * this->pos.x + this->pos.z * this->pos.z);
    this->pos = Point(cos(nv_a) * dist, this->pos.y, sin(nv_a) * dist);
}

void Camera::Zoom(double z) {
    this->pos.x *= z;
    this->pos.y *= z;
    this->pos.z *= z;
}

void Camera::OnMouseEvent(int button, int state, int x, int y) {
    switch (button) {
        case 0:
            this->left_click = (state == 0);
            this->pos_x = x;
            this->pos_y = y;
            this->saved_pos = Point(this->pos);
            break;
        case 3:
            if (state == 0)
                this->Zoom(1 - Camera::zoom_speed);
            break;
        case 4:
            if (state == 0)
                this->Zoom(1 + Camera::zoom_speed);
            break;
    }
}

void Camera::OnMotionPressedEvent(int x, int y) {
    if (this->left_click) {
        double dx = x - this->pos_x, dy = y - this->pos_y;
        this->pos = Point(this->saved_pos);
        this->RotateLongitude(dx * Camera::rotation_speed);
        this->RotateLatitude(dy * Camera::rotation_speed);
    }
}

void Camera::Apply() const {
    gluLookAt(this->pos.x, this->pos.y, this->pos.z, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);
}