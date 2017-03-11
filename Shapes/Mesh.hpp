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

class MeshColor {

public:

    enum MESH_COLOR {
        WHITE,
        EMERALD,
        JADE,
        OBSIDIAN,
        PEARL,
        RUBY,
        TURQUOISE,
        BRASS,
        BRONZE,
        CHROME,
        COPPER,
        GOLD,
        SILVER,
        BLACK_PLASTIC,
        CYAN_PLASTIC,
        GREEN_PLASTIC,
        RED_PLASTIC,
        WHITE_PLASTIC,
        YELLOW_PLASTIC,
        BLACK_RUBBER,
        CYAN_RUBBER,
        GREEN_RUBBER,
        RED_RUBBER,
        WHITE_RUBBER,
        YELLOW_RUBBER
    };

private:

    float ambiant[3], diffuse[3], specular[3], shininess;

public:

    MeshColor(MeshColor::MESH_COLOR = MeshColor::WHITE);
    MeshColor(const MeshColor&);

    void Apply() const;

};

class Mesh {

    std::vector<Point> P;
    std::vector<Vecteur> N;
    std::vector<basic_meshtriangle> T;
    std::vector<basic_mesharete> A;

    int polygon_mode;
    int shade_mode;

public:

    MeshColor color;

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

    Box GetBox() const;

    void Reposition(const Box&);

    void Draw() const;
    void DrawFront() const;
    void DrawBack() const;
    void DrawNormals() const;

    void PolygonMode(int);
    void ShadeMode(int);

    Point& operator[](unsigned int);
    Vecteur GetNormal(unsigned int) const;
    Triangle GetTriangle(unsigned int) const;

private:

    void _draw_() const;
    void _draw_invert_() const;

private:

    static bool is_smooth;

public:

    static void EnableSmooth();
    static void DisableSmooth();

};

#endif //PROG3D_MESH_HPP

#endif