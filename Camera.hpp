#ifndef PROG3D_MAIN_HPP
#include "main.hpp"

#else

#ifndef PROG3D_CAMERA_HPP
#define PROG3D_CAMERA_HPP

class Camera {

private:

    static double fovy, aspect, zNear, zFar;

public:

    static const double zoom_speed;

    static const double rotation_speed;

    static void Perspective(double, double, double, double);

private:

    Point saved_pos;
    bool left_click;
    int pos_x, pos_y;

public:

    Point pos;

    Camera();
    Camera(const Point&);
    Camera(const Camera&);

    void RotateLatitude(double);
    void RotateLongitude(double);
    void Zoom(double);

    void OnMouseEvent(int, int, int, int);
    void OnMotionPressedEvent(int, int);

    void Apply() const;

};

#endif //PROG3D_CAMERA_HPP

#endif