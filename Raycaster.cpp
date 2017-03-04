#include "Raycaster.hpp"

Raycaster::Raycaster() {

}

Raycaster::Raycaster(const Raycaster & r) {
    for (unsigned int i = 0, sz = r.mesh.size(); i < sz; i++) {
        this->mesh.push_back(r.mesh[i]);
    }
}

void Raycaster::Add(const Mesh & m) {
    this->mesh.push_back(&m);
}

unsigned int Raycaster::MeshNumber() const {
    return this->mesh.size();
}

const Mesh & Raycaster::operator[](unsigned int i) const {
    return *(this->mesh[i]);
}

std::vector<Point> Raycaster::Ray(const Droite & d) const {
    std::vector<Point> res, tmp;
    for (unsigned int i = 0, sz = this->mesh.size(); i < sz; i++) {
        tmp.clear();
        tmp = Raycaster::Ray(d, *(this->mesh[i]));
        for (unsigned int j = 0, sz2 = tmp.size(); j < sz2; j++) {
            res.push_back(tmp[j]);
        }
    }
    return res;
}

std::vector<Point> Raycaster::Ray(const Droite & d, const Mesh & m) {
    Point tmp;
    std::vector<Point> res;
    for (unsigned int i = 0, sz = m.TriangleNumber(); i < sz; i++) {
        if (Raycaster::Ray(d, m.GetTriangle(i), tmp))
            res.push_back(tmp);
    }
    return res;
}

bool Raycaster::Ray(const Droite & d, const Triangle & t, Point & res) {
    Plan P = t.GetPlan();
    if (d.GetIntersection(P, res)) {
        Vecteur vAB = Vecteur::VectorByPoints(t.A, t.B), vAC = Vecteur::VectorByPoints(t.A, t.C), vAP = Vecteur::VectorByPoints(t.A, res);
        double BAC = vAB.GetAngle(vAC), BAP = vAB.GetAngle(vAP), CAP = vAC.GetAngle(vAP);
        if (BAP > BAC || CAP > BAC) return false;
        Vecteur vBA = Vecteur::VectorByPoints(t.B, t.A), vBC = Vecteur::VectorByPoints(t.B, t.C), vBP = Vecteur::VectorByPoints(t.B, res);
        double ABC = vBA.GetAngle(vBC), ABP = vBA.GetAngle(vBP), CBP = vBC.GetAngle(vBP);
        if (ABP > ABC || CBP > ABC) return false;
        else return true;
    }
    else {
        return false;
    }
}