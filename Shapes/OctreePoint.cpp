#include "OctreePoint.hpp"

OctreePoint::OctreePoint(const Voxel& voxel, DynamicMesh& mesh, const std::vector<unsigned int>& pl) :
    vox(voxel), node(false), mesh(mesh)
{
    for (unsigned int i = 0, sz = pl.size(); i < sz; i++) {
        if (this->vox.Inside(mesh.GetPoint(pl[i])))
            this->P.push_back(pl[i]);
    }

    if (this->P.size() > PROG3D_OCTREEPOINT_MAXPOINT) {
        for (unsigned int i = 0; i < 8; i++) {
            this->child[i] = new OctreePoint(this->GetChild(i), this->mesh, this->P);
        }
        this->node = true;
    }
}
OctreePoint::~OctreePoint() {
    if (this->node) {
        for (unsigned int i = 0; i < 8; i++)
            delete this->child[i];
    }
}

Voxel OctreePoint::GetChild(int i) const {
    double h = vox.l / 4.0, h2 = vox.l / 2.0;
    switch (i) {
        case 0: return Voxel(Point(vox.p.x - h, vox.p.y - h, vox.p.z - h), h2);
        case 1: return Voxel(Point(vox.p.x - h, vox.p.y - h, vox.p.z + h), h2);
        case 2: return Voxel(Point(vox.p.x - h, vox.p.y + h, vox.p.z - h), h2);
        case 3: return Voxel(Point(vox.p.x - h, vox.p.y + h, vox.p.z + h), h2);
        case 4: return Voxel(Point(vox.p.x + h, vox.p.y - h, vox.p.z - h), h2);
        case 5: return Voxel(Point(vox.p.x + h, vox.p.y - h, vox.p.z + h), h2);
        case 6: return Voxel(Point(vox.p.x + h, vox.p.y + h, vox.p.z - h), h2);
        case 7: return Voxel(Point(vox.p.x + h, vox.p.y + h, vox.p.z + h), h2);
        default: return Voxel();
    }
}

std::vector<unsigned int> OctreePoint::GetPointsInside(const Point& center, double radius) const {
    std::vector<unsigned int> res, tmp;

    if (!this->Intersect(center, radius) || this->P.size() == 0) return res;
    if (this->node) {
        for (unsigned int i = 0; i < 8; i++) {
            tmp = this->child[i]->GetPointsInside(center, radius);
            for (unsigned int e : tmp)
                res.push_back(e);
        }
    }
    else {
        for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
            if (this->mesh.GetPoint(this->P[i]).GetDistance(center) <= radius)
                res.push_back(this->P[i]);
        }
    }
    return res;
}

double OctreePoint::GetDistance(const Point& p, bool first, unsigned int * idx) const {
    double res = NAN, tmp_d;
    unsigned int index = -1;
    if (this->P.size() == 0 && !this->node) return res;
    if (this->node) {
        std::vector<unsigned int> sorted, unsorted;
        for (unsigned int i = 0; i < 8; i++) unsorted.push_back(i);
        while (unsorted.size() > 0) {
            unsigned int min_i = 0;
            double min_d = this->mesh.GetPoint(unsorted[0]).GetDistance(p);
            for (unsigned int i = 0, sz = unsorted.size(); i < sz; i++) {
                if ((tmp_d = this->mesh.GetPoint(unsorted[i]).GetDistance(p)) < min_d) {
                    min_i = i;
                    min_d = tmp_d;
                }
            }
            sorted.push_back(unsorted[min_i]);
            unsorted.erase(unsorted.begin() + min_i);
        }
        for (unsigned int i = 0; i < 8 && __isnan(res); i++) {
            res = this->child[sorted[i]]->GetDistance(p, false, &index);
        }
    }
    else {
        res = this->mesh.GetPoint(this->P[0]).GetDistance(p);
        index = 0;
        for (unsigned int i = 1, sz = this->P.size(); i < sz; i++) {
            if ((tmp_d = this->mesh.GetPoint(this->P[i]).GetDistance(p)) < res) {
                res = tmp_d;
                index = this->P[i];
            }
        }
    }
    if (first) {
        std::vector<unsigned int> tmp_v = this->GetPointsInside(p, res);
        for (unsigned int i = 0, sz = tmp_v.size(); i < sz; i++) {
            if ((tmp_d = this->mesh.GetPoint(tmp_v[i]).GetDistance(p)) < res) {
                index = tmp_v[i];
                res = tmp_d;
            }
        }
        if (index != -1)
            res = this->mesh.GetDistance(p, index);
    }
    else
        *idx = index;
    return res;
}

bool OctreePoint::Intersect(const Point& center, double radius) const {
    return (center.GetDistance(this->vox.p) <= radius + sqrt(2) * this->vox.l / 2);
}
