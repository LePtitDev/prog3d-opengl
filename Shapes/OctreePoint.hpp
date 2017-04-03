#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_OCTREEPOINT_HPP
#define PROG3D_OCTREEPOINT_HPP

#define PROG3D_OCTREEPOINT_MAXPOINT 80

class OctreePoint {

    Voxel vox;

    DynamicMesh& mesh;
    std::vector<unsigned int> P;
    bool node;
    std::array<OctreePoint *, 8> child;

public:
    
    OctreePoint(const Voxel&, DynamicMesh&, const std::vector<unsigned int>&);
    ~OctreePoint();

    Voxel GetChild(int) const;

    std::vector<unsigned int> GetPointsInside(const Point&, double) const;

    double GetDistance(const Point&, bool = true, unsigned int * = nullptr) const;

private:

    bool Intersect(const Point&, double) const;

};

#endif //PROG3D_VOLUME_HPP

#endif