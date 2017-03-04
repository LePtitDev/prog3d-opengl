#include "Camera.hpp"

double Camera::fovy = 0;
double Camera::aspect = 0;
double Camera::zNear = 0;
double Camera::zFar = 0;

const double Camera::zoom_speed = 0.2;

const double Camera::rotation_speed = 0.01;

void Camera::Perspective(double fovy, double aspect, double zNear, double zFar) {
    Camera::fovy = fovy;
    Camera::aspect = aspect;
    Camera::zNear = zNear;
    Camera::zFar = zFar;
    gluPerspective(fovy, aspect, zNear, zFar);
}

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

const Point & Camera::GetPosition() const {
    return this->pos;
}

RRectangle Camera::GetNearViewport() {
    double n_height_2 = tan(Camera::fovy / 2.0), n_width_2 = Camera::aspect * n_height_2;
    Vecteur v_near = Vecteur::VectorByPoints(this->pos, Point(0, 0, 0)), v_top(0, 1, 0);
    v_near.Normalize();
    Vecteur v_width = v_near.GetVectoriel(v_top) * n_width_2, v_height = v_near.GetVectoriel(v_width) * n_height_2;
    v_near = v_near * Camera::zNear;
    return RRectangle(this->pos + v_near - v_width * Camera::zNear - v_height * Camera::zNear, this->pos + v_near + v_width * Camera::zNear - v_height * Camera::zNear, this->pos + v_near + v_width * Camera::zNear + v_height * Camera::zNear);
}

RRectangle Camera::GetFarViewport() {
    double n_height_2 = tan(Camera::fovy / 2.0), n_width_2 = Camera::aspect * n_height_2;
    Vecteur v_far = Vecteur::VectorByPoints(this->pos, Point(0, 0, 0)), v_top(0, 1, 0);
    v_far.Normalize();
    Vecteur v_width = v_far.GetVectoriel(v_top) * n_width_2, v_height = v_far.GetVectoriel(v_width) * n_height_2;
    v_far = v_far * Camera::zFar;
    return RRectangle(this->pos + v_far - v_width * Camera::zFar - v_height * Camera::zFar, this->pos + v_far + v_width * Camera::zFar - v_height * Camera::zFar, this->pos + v_far + v_width * Camera::zFar + v_height * Camera::zFar);
}

std::array<RRectangle, 2> Camera::GetViewports() {
    std::array<RRectangle, 2> res;
    double n_height_2 = tan(Camera::fovy / 2.0), n_width_2 = Camera::aspect * n_height_2;
    Vecteur v_near = Vecteur::VectorByPoints(this->pos, Point(0, 0, 0)), v_top(0, 1, 0);
    v_near.Normalize();
    Vecteur v_far = v_near * Camera::zFar, v_width = v_near.GetVectoriel(v_top) * n_width_2, v_height = v_near.GetVectoriel(v_width) * n_height_2;
    v_near = v_near * Camera::zNear;
    res[0] = RRectangle(this->pos + v_near - v_width * Camera::zNear - v_height * Camera::zNear, this->pos + v_near + v_width * Camera::zNear - v_height * Camera::zNear, this->pos + v_near + v_width * Camera::zNear + v_height * Camera::zNear);
    res[1] = RRectangle(this->pos + v_far - v_width * Camera::zFar - v_height * Camera::zFar, this->pos + v_far + v_width * Camera::zFar - v_height * Camera::zFar, this->pos + v_far + v_width * Camera::zFar + v_height * Camera::zFar);
    return res;
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
    double nv_a;
    if (vp.z >= 0)
        nv_a = acos(vp.x) + a;
    else
        nv_a = -acos(vp.x) + a;
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