#include "Volume.hpp"

Volume * Volume::_vox_op1 = nullptr;
Volume * Volume::_vox_op2 = nullptr;

Volume::Volume() :
    vox(), exist(false), has_child(false), complete(false), depth_tree(1)
{
    for (int i = 0; i < 8; i++) {
        this->child[i] = nullptr;
    }
}

Volume::Volume(const Point & p, double l, int depth, bool (*check)(void*, double, double, double), void * args) :
    vox(p, l), exist(false), has_child(false), complete(true), depth_tree(depth)
{
    if (depth < 1) {
        complete = exist = check(args, p.x, p.y, p.z);
        return;
    }

    Voxel v;
    for (int i = 0; i < 8; i++) {
        v = this->GetChild(i);
        this->child[i] = new Volume(v.p, v.l, depth - 1, check, args);
        if (this->child[i]->exist) {
            has_child = true;
            if (!this->child[i]->complete)
                complete = false;
        }
        else {
            delete this->child[i];
            this->child[i] = nullptr;
            complete = false;
        }
    }

    exist = (has_child) ? true : check(args, p.x, p.y, p.z);
    if (complete) {
        for (int i = 0; i < 8; i++) {
            if (this->child[i] != nullptr)
                delete this->child[i];
        }
        has_child = false;
    }
}

Volume::Volume(const Volume & v) :
    vox(v.vox), exist(v.exist), has_child(v.has_child), complete(v.complete), depth_tree(v.depth_tree)
{
    for (int i = 0; i < 8; i++) {
        this->child[i] = (!v.has_child || v.child[i] == nullptr) ? nullptr : new Volume(*(v.child[i]));
    }
}

Volume::~Volume() {
    if (has_child) {
        for (int i = 0; i < 8; i++) {
            if (this->child[i] != nullptr)
                delete this->child[i];
        }
    }
}

bool Volume::Inside(double x, double y, double z) const {
    if (!vox.Inside(x, y, z))
        return false;
    if (!has_child)
        return true;
    for (int i = 0; i < 8; i++) {
        if (this->child[i] != nullptr && this->child[i]->Inside(x, y, z))
            return true;
    }
    return false;
}

Volume Volume::Intersection(Volume& v) {
    Volume::_vox_op1 = this;
    Volume::_vox_op2 = &v;
    return Volume(this->vox.p, this->vox.l, this->depth_tree, [](void *, double x, double y, double z) {
        return (Volume::_vox_op1->Inside(x, y, z) && Volume::_vox_op2->Inside(x, y, z));
    }, nullptr);
}

Volume Volume::Soustraction(Volume& v) {
    Volume::_vox_op1 = this;
    Volume::_vox_op2 = &v;
    return Volume(this->vox.p, this->vox.l, this->depth_tree, [](void *, double x, double y, double z) {
        return (Volume::_vox_op1->Inside(x, y, z) && !Volume::_vox_op2->Inside(x, y, z));
    }, nullptr);
}

Volume Volume::Union(Volume& v) {
    Volume::_vox_op1 = this;
    Volume::_vox_op2 = &v;
    return Volume(this->vox.p, this->vox.l, this->depth_tree, [](void *, double x, double y, double z) {
        return (Volume::_vox_op1->Inside(x, y, z) || Volume::_vox_op2->Inside(x, y, z));
    }, nullptr);
}

void Volume::Draw() const {
    if (has_child) {
        for (int i = 0; i < 8; i++) {
            if (this->child[i] != nullptr) {
                this->child[i]->Draw();
            }
        }
    }
    else {
        if (exist) {
            this->vox.Draw();
        }
    }
}

void Volume::DrawLines() const {
    if (has_child) {
        for (int i = 0; i < 8; i++) {
            if (this->child[i] != nullptr) {
                this->child[i]->DrawLines();
            }
        }
    }
    else {
        if (exist) {
            this->vox.DrawLines();
        }
    }
}

void Volume::operator=(const Volume & v) {
    if (has_child) {
        for (int i = 0; i < 8; i++) {
            if (this->child[i] != nullptr)
                delete this->child[i];
        }
    }

    vox = v.vox;
    exist = v.exist;
    has_child = v.has_child;
    complete = v.complete;
    depth_tree = v.depth_tree;
    for (int i = 0; i < 8; i++) {
        this->child[i] = (v.child[i] == nullptr) ? nullptr : new Volume(*(v.child[i]));
    }
}

Voxel Volume::GetChild(int i) const {
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