#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_DYNAMICMESH_HPP
#define PROG3D_DYNAMICMESH_HPP

class DynamicMesh {

    typedef struct { Point P; Vecteur N; std::vector<unsigned int> A; } point_type;
    typedef struct { unsigned int P[2]; std::vector<unsigned int> T; } arete_type;
    typedef struct { unsigned int P[3], A[3]; } triangle_type;

    std::vector<point_type> P;
    std::vector<arete_type> A;
    std::vector<triangle_type> T;

    std::vector<double> D;

public:

    DynamicMesh();
    DynamicMesh(const DynamicMesh&);

    unsigned int Points() const;
    unsigned int Aretes() const;
    unsigned int Triangles() const;

    Point GetPoint(unsigned int) const;
    Vecteur GetNormal(unsigned int) const;
    std::array<unsigned int, 2> GetArete(unsigned int) const;
    std::array<unsigned int, 3> GetTriangle(unsigned int) const;

    void Draw() const;
    void DrawPoints() const;
    void DrawLines() const;
    void DrawNormals() const;
    void DrawDistances() const;

    void Normalize();

    void Translate(double, double, double);
    void RotateX(double);
    void RotateY(double);
    void RotateZ(double);
    void Scale(double, double, double);

    Box GetBox() const;
    void Reposition(const Box&);

    unsigned int    AddPoint(const Point&);
    void            RemovePoint(unsigned int);

    unsigned int    AddArete(unsigned int, unsigned int);
    unsigned int    AddAreteSafe(unsigned int, unsigned int);
    void            RemoveArete(unsigned int);

    unsigned int    AddTriangle(unsigned int, unsigned int, unsigned int, bool = true);
    unsigned int    AddTriangleSafe(unsigned int, unsigned int, unsigned int);
    void            RemoveTriangle(unsigned int);

    int FindPoint(const Point&) const;

    std::vector<unsigned int> FindPointsNeighbors(unsigned int) const;
    std::vector<unsigned int> FindAretesNeighbors(unsigned int) const;
    std::vector<unsigned int> FindTrianglesNeighbors(unsigned int) const;

    bool AreNeighbors(unsigned int, unsigned int) const;

    void Merge(unsigned int);
    Point Merge(unsigned int, unsigned int);
    void Merge(const Box&);
    void Merge(const Grille3D&);

    void Subdivide();
    void SubdivideByButterfly();

    bool Correct() const;
    bool Closed() const;
    bool FreePoint() const;

    double GetDistance(const Point&) const;
    double GetDistance(const Point&, unsigned int) const;
    void CalculateDistance(const DynamicMesh&);
    void CalculateDistanceByOctree(DynamicMesh&);

};

#endif //PROG3D_DYNAMICMESH_HPP

#endif