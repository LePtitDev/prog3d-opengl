#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_MESH_HPP
#define PROG3D_MESH_HPP

typedef struct {
    unsigned int A, B, C;
} basic_meshtriangle;

typedef struct {
    unsigned int P1, P2, T1, T2;
} basic_mesharete;

class Mesh {

    std::vector<Point> P;
    std::vector<Vecteur> N;
    std::vector<basic_meshtriangle> T;
    std::vector<basic_mesharete> A;

public:

    Mesh();
    Mesh(const Mesh&);

    unsigned int PointNumber() const;
    unsigned int TriangleNumber() const;
    unsigned int AreteNumber() const;

    void PushPoint(const Point&);
    void PushTriangle(unsigned int, unsigned int, unsigned int);

    void Normalize();

    void Translate(double, double, double);
    void RotateX(double);
    void RotateY(double);
    void RotateZ(double);
    void Scale(double, double, double);

    void Draw() const;
    void DrawNormals() const;

    Point& operator[](unsigned int);

private:

    static bool is_smooth;

public:

    static void EnableSmooth();
    static void DisableSmooth();

};

#endif //PROG3D_MESH_HPP

#endif