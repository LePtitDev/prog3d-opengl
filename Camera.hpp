#ifndef PROG3D_MAIN_HPP
#include "main.hpp"

#else

#ifndef PROG3D_CAMERA_HPP
#define PROG3D_CAMERA_HPP

class Camera {

private:

    static const double zoom_speed;
    static const double rotation_speed;

    static double fovy, aspect, zNear, zFar;

public:

    static const double FOVY, ASPECT, ZNEAR, ZFAR;

    static double GetFOVY();
    static double GetAspect();
    static double GetZNear();
    static double GetZFar();
    static void Perspective();
    static void Perspective(double, double, double, double);

private:

    Point saved_pos, target;
    bool left_click, to_target;
    int pos_x, pos_y;

public:

    Point pos;

    Camera();
    Camera(const Point&);
    Camera(const Camera&);

    const Point& GetPosition() const;
    RRectangle GetNearViewport() const;
    RRectangle GetFarViewport() const;
    std::array<RRectangle, 2> GetViewports() const;

    void RotateLatitude(double);
    void RotateLongitude(double);
    void Zoom(double);

    void OnMouseEvent(int, int, int, int);
    void OnMotionPressedEvent(int, int);

    void ToOrigin();
    void ToTarget();

    void SetTarget(const Point&);
    Point GetTarget() const;
    void Reposition(const Box&);

    void Apply() const;

};

#endif //PROG3D_CAMERA_HPP

#endif