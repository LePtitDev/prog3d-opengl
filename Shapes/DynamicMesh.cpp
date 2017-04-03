#include "DynamicMesh.hpp"

DynamicMesh::DynamicMesh() {}
DynamicMesh::DynamicMesh(const DynamicMesh & mesh) :
    P(mesh.P), A(mesh.A), T(mesh.T)
{

}

unsigned int DynamicMesh::Points() const { return this->P.size(); }
unsigned int DynamicMesh::Aretes() const { return this->A.size(); }
unsigned int DynamicMesh::Triangles() const { return this->T.size(); }

Point DynamicMesh::GetPoint(unsigned int i) const {
    return this->P[i].P;
}
Vecteur DynamicMesh::GetNormal(unsigned int i) const {
    return this->P[i].N;
}
std::array<unsigned int, 2> DynamicMesh::GetArete(unsigned int i) const {
    std::array<unsigned int, 2> res;
    res[0] = this->A[i].P[0];
    res[1] = this->A[i].P[1];
    return res;
}
std::array<unsigned int, 3> DynamicMesh::GetTriangle(unsigned int i) const {
    std::array<unsigned int, 3> res;
    res[0] = this->T[i].P[0];
    res[1] = this->T[i].P[1];
    res[2] = this->T[i].P[2];
    return res;
}

void DynamicMesh::Draw() const {
    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0, sz = this->T.size(); i < sz; i++) {
        Point p1 = this->P[this->T[i].P[0]].P;
        Point p2 = this->P[this->T[i].P[1]].P;
        Point p3 = this->P[this->T[i].P[2]].P;
        Vecteur n1 = this->P[this->T[i].P[0]].N;
        Vecteur n2 = this->P[this->T[i].P[1]].N;
        Vecteur n3 = this->P[this->T[i].P[2]].N;
        glNormal3f(n1.x, n1.y, n1.z);
        glVertex3f(p1.x, p1.y, p1.z);
        glNormal3f(n2.x, n2.y, n2.z);
        glVertex3f(p2.x, p2.y, p2.z);
        glNormal3f(n3.x, n3.y, n3.z);
        glVertex3f(p3.x, p3.y, p3.z);
    }
    glEnd();
}

void DynamicMesh::DrawPoints() const {
    glBegin(GL_POINTS);
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++)
        this->P[i].P.Apply();
    glEnd();
}

void DynamicMesh::DrawLines() const {
    glBegin(GL_LINES);
    for (unsigned int i = 0, sz = this->A.size(); i < sz; i++) {
        this->P[this->A[i].P[0]].P.Apply();
        this->P[this->A[i].P[1]].P.Apply();
    }
    glEnd();
}

void DynamicMesh::DrawNormals() const {
    glBegin(GL_LINES);
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        this->P[i].P.Apply();
        (this->P[i].P + this->P[i].N).Apply();
    }
    glEnd();
}

void DynamicMesh::DrawDistances() const {
    if (this->D.size() != this->P.size()) return;
    double max = this->D[0];
    for (unsigned int i = 1, sz = this->D.size(); i < sz; i++) {
        if (max < this->D[i])
            max = this->D[i];
    }

    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0, sz = this->T.size(); i < sz; i++) {
        Point p1 = this->P[this->T[i].P[0]].P;
        Point p2 = this->P[this->T[i].P[1]].P;
        Point p3 = this->P[this->T[i].P[2]].P;
        Vecteur n1 = this->P[this->T[i].P[0]].N;
        Vecteur n2 = this->P[this->T[i].P[1]].N;
        Vecteur n3 = this->P[this->T[i].P[2]].N;
        glColor3f(this->D[this->T[i].P[0]] / max, 1 - (this->D[this->T[i].P[0]] / max), 0.8);
        glNormal3f(n1.x, n1.y, n1.z);
        glVertex3f(p1.x, p1.y, p1.z);
        glColor3f(this->D[this->T[i].P[1]] / max, 1 - (this->D[this->T[i].P[1]] / max), 0.8);
        glNormal3f(n2.x, n2.y, n2.z);
        glVertex3f(p2.x, p2.y, p2.z);
        glColor3f(this->D[this->T[i].P[2]] / max, 1 - (this->D[this->T[i].P[2]] / max), 0.8);
        glNormal3f(n3.x, n3.y, n3.z);
        glVertex3f(p3.x, p3.y, p3.z);
    }
    glEnd();
}

void DynamicMesh::Normalize() {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++)
        this->P[i].N.Normalize();
}

void DynamicMesh::Translate(double x, double y, double z) {
    Vecteur t(x, y, z);
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        this->P[i].P = this->P[i].P + t;
    }
}

void DynamicMesh::RotateX(double a) {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        Point pnorm = this->P[i].P + this->P[i].N;
        double y = this->P[i].P.y, z = this->P[i].P.z;
        this->P[i].P.y = y * cos(a) - z * sin(a);
        this->P[i].P.z = y * sin(a) + z * cos(a);
        y = pnorm.y; z = pnorm.z;
        pnorm.y = y * cos(a) - z * sin(a);
        pnorm.z = y * sin(a) + z * cos(a);
        this->P[i].N = Vecteur::VectorByPoints(this->P[i].P, pnorm);
    }
}

void DynamicMesh::RotateY(double a) {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        Point pnorm = this->P[i].P + this->P[i].N;
        double x = this->P[i].P.x, z = this->P[i].P.z;
        this->P[i].P.x = x * cos(a) + z * sin(a);
        this->P[i].P.z = -x * sin(a) + z * cos(a);
        x = pnorm.x; z = pnorm.z;
        pnorm.x = x * cos(a) + z * sin(a);
        pnorm.z = -x * sin(a) + z * cos(a);
        this->P[i].N = Vecteur::VectorByPoints(this->P[i].P, pnorm);
    }
}

void DynamicMesh::RotateZ(double a) {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        Point pnorm = this->P[i].P + this->P[i].N;
        double x = this->P[i].P.x, y = this->P[i].P.y;
        this->P[i].P.x = x * cos(a) - y * sin(a);
        this->P[i].P.y = x * sin(a) + y * cos(a);
        x = pnorm.x; y = pnorm.y;
        pnorm.x = x * cos(a) - y * sin(a);
        pnorm.y = x * sin(a) + y * cos(a);
        this->P[i].N = Vecteur::VectorByPoints(this->P[i].P, pnorm);
    }
}

void DynamicMesh::Scale(double x, double y, double z) {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        this->P[i].P.x *= x;
        this->P[i].P.y *= y;
        this->P[i].P.z *= z;
    }
}

Box DynamicMesh::GetBox() const {
    double x_min = this->P[0].P.x, x_max = this->P[0].P.x, y_min = this->P[0].P.y, y_max = this->P[0].P.y, z_min = this->P[0].P.z, z_max = this->P[0].P.z;
    for (unsigned int i = 1, sz = this->P.size(); i < sz; i++) {
        if (this->P[i].P.x < x_min) x_min = this->P[i].P.x;
        if (this->P[i].P.x > x_max) x_max = this->P[i].P.x;
        if (this->P[i].P.y < y_min) y_min = this->P[i].P.y;
        if (this->P[i].P.y > y_max) y_max = this->P[i].P.y;
        if (this->P[i].P.z < z_min) z_min = this->P[i].P.z;
        if (this->P[i].P.z > z_max) z_max = this->P[i].P.z;
    }
    Point point(x_min, y_min, z_min);
    return Box(point, Vecteur(x_max - x_min, 0, 0), Vecteur(0, y_max - y_min, 0), Vecteur(0, 0, z_max - z_min));
}

void DynamicMesh::Reposition(const Box& b) {
    Box actual = this->GetBox();
    double dx = b.GetVector(0).x / actual.GetVector(0).x;
    double dy = b.GetVector(1).y / actual.GetVector(1).y;
    double dz = b.GetVector(2).z / actual.GetVector(2).z;
    double min_value = (dx < dy) ? dx : dy; min_value = (min_value < dz) ? min_value : dz;
    this->Scale(min_value, min_value, min_value);
    actual = this->GetBox();
    dx = b.GetPoint(0).x - actual.GetPoint(0).x;
    dy = b.GetPoint(0).y - actual.GetPoint(0).y;
    dz = b.GetPoint(0).z - actual.GetPoint(0).z;
    double diff_x = b.GetVector(0).x - actual.GetVector(0).x;
    double diff_y = b.GetVector(1).y - actual.GetVector(1).y;
    double diff_z = b.GetVector(2).z - actual.GetVector(2).z;
    this->Translate(dx + diff_x / 2, dy + diff_y / 2, dz + diff_z / 2);
    actual = this->GetBox();
}

unsigned int DynamicMesh::AddPoint(const Point & p) {
    this->P.push_back({ p, Vecteur(0, 0, 0), std::vector<unsigned int>() });
    return this->P.size() - 1;
}
void DynamicMesh::RemovePoint(unsigned int p) {
    //Pour chaque arète voisine, on supprime l'arète
    for (int i = this->P[p].A.size() - 1; i >= 0; i--)
        this->RemoveArete(this->P[p].A[i]);
    unsigned int last = this->P.size() - 1;
    //Si le point n'est pas le dernier
    if (p != last) {
        std::vector<unsigned int> aretes = this->FindAretesNeighbors(last), triangles = this->FindTrianglesNeighbors(last);
        //On remplace le point actuel par le dernier
        this->P[p] = this->P[last];
        //On change les références pour chaque arète voisine
        for (unsigned int e : aretes) {
            if (this->A[e].P[0] == last) {
                this->A[e].P[0] = p;
            }
            else {
                if (p >= this->A[e].P[0])
                    this->A[e].P[1] = p;
                else {
                    this->A[e].P[1] = this->A[e].P[0];
                    this->A[e].P[0] = p;
                }
            }
        }
        //On change les références pour chaque triangle voisin
        for (unsigned int e : triangles) {
            if (this->T[e].P[0] == last)
                this->T[e].P[0] = p;
            else if (this->T[e].P[1] == last) {
                if (p >= this->T[e].P[0])
                    this->T[e].P[1] = p;
                else {
                    this->T[e].P[1] = this->T[e].P[0];
                    this->T[e].P[0] = p;
                }
            }
            else {
                if (p >= this->T[e].P[1])
                    this->T[e].P[2] = p;
                else {
                    this->T[e].P[2] = this->T[e].P[1];
                    if (p >= this->T[e].P[0]) {
                        this->T[e].P[1] = p;
                    }
                    else {
                        this->T[e].P[1] = this->T[e].P[0];
                        this->T[e].P[0] = p;
                    }
                }
            }
        }
    }
    this->P.pop_back();
}
unsigned int DynamicMesh::AddArete(unsigned int p1, unsigned int p2) {
    if (p1 > p2) return this->AddArete(p2, p1);
    else {
        unsigned int index = this->A.size();
        this->A.push_back({ { p1, p2 }, std::vector<unsigned int>() });
        this->P[p1].A.push_back(index);
        this->P[p2].A.push_back(index);
        return index;
    }
}
unsigned int DynamicMesh::AddAreteSafe(unsigned int p1, unsigned int p2) {
    if (p1 > p2) return this->AddAreteSafe(p2, p1);
    else {
        //S'il existe déjà, on retourne son index
        std::vector<unsigned int> neighbors = this->FindAretesNeighbors(p1);
        for (unsigned int e : neighbors) if (this->A[e].P[1] == p2) return e;
        //Sinon on l'ajoute
        return this->AddArete(p1, p2);
    }
}
void DynamicMesh::RemoveArete(unsigned int a) {
    //Pour chaque point de l'arète, on supprime la référence à l'arète
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0, sz = this->P[this->A[a].P[i]].A.size(); j < sz; j++) {
            if (this->P[this->A[a].P[i]].A[j] == a) {
                this->P[this->A[a].P[i]].A.erase(this->P[this->A[a].P[i]].A.begin() + j);
                break;
            }
        }
    }
    //On supprime les triangles associés
    for (int i = this->A[a].T.size() - 1; i >= 0; i--)
        this->RemoveTriangle(this->A[a].T[i]);
    unsigned int last = this->A.size() - 1;
    //Si l'arète n'est pas la dernière
    if (a != last) {
        //On remplace l'arète par la dernière
        this->A[a] = this->A[last];
        //Pour tous les points de l'arète, on change la référence
        for (unsigned int i = 0; i < 2; i++) {
            for (unsigned int j = 0, sz = this->P[this->A[a].P[i]].A.size(); j < sz; j++)
                if (this->P[this->A[a].P[i]].A[j] == last) { this->P[this->A[a].P[i]].A[j] = a; break; }
        }
        //Pour tous les triangles de l'arète, on change la référence
        for (unsigned int i = 0, sz = this->A[a].T.size(); i < sz; i++) {
            for (unsigned int j = 0; j < 3; j++)
                if (this->T[this->A[a].T[i]].A[j] == last) { this->T[this->A[a].T[i]].A[j] = a; break; }
        }
    }
    this->A.pop_back();
}
unsigned int DynamicMesh::AddTriangle(unsigned int p1, unsigned int p2, unsigned int p3, bool calculate_normal) {
    unsigned int res;
    if (p1 > p2) res = this->AddTriangle(p2, p1, p3, false);
    else if (p2 > p3) res = this->AddTriangle(p1, p3, p2, false);
    else {
        unsigned int index = this->T.size();
        this->T.push_back({
                                  { p1, p2, p3 },
                                  {
                                          this->AddAreteSafe(p1, p2),
                                          this->AddAreteSafe(p2, p3),
                                          this->AddAreteSafe(p1, p3)
                                  }
                          });
        for (int i = 0; i < 3; i++)
            this->A[this->T[index].A[i]].T.push_back(index);
        res = index;
    }
    if (calculate_normal) {
        Vecteur normal = Vecteur::VectorByPoints(this->P[p1].P, this->P[p2].P).GetVectoriel(Vecteur::VectorByPoints(this->P[p1].P, this->P[p3].P));
        this->P[p1].N = this->P[p1].N + normal;
        this->P[p2].N = this->P[p2].N + normal;
        this->P[p3].N = this->P[p3].N + normal;
    }
    return res;
}
unsigned int DynamicMesh::AddTriangleSafe(unsigned int p1, unsigned int p2, unsigned int p3) {
    if (p1 > p2) return this->AddTriangleSafe(p2, p1, p3);
    else if (p2 > p3) return this->AddTriangleSafe(p1, p3, p2);
    else {
        //S'il existe déjà, on retourne son index
        std::vector<unsigned int> neighbors = this->FindTrianglesNeighbors(p1);
        for (unsigned int e : neighbors) if (this->T[e].P[1] == p2 && this->T[e].P[2] == p3) return e;
        //Sinon on l'ajoute
        this->AddTriangle(p1, p2, p3);
    }
}
void DynamicMesh::RemoveTriangle(unsigned int t) {
    //Pour chaque arète du triangle, on supprime le triangle référencé
    for (int i = 0; i < 3; i++) {
        for (unsigned int j = 0, sz = this->A[this->T[t].A[i]].T.size(); j < sz; j++)
            if (this->A[this->T[t].A[i]].T[j] == t) {
                this->A[this->T[t].A[i]].T.erase(this->A[this->T[t].A[i]].T.begin() + j);
                break;
            }
    }
    unsigned int last = this->T.size() - 1;
    //Si le triangle n'est pas le dernier
    if (t != last) {
        //Alors on remplace le triangle actuel par le dernier
        this->T[t] = this->T[last];
        for (int i = 0; i < 3; i++) {
            //Pour chaque arète du triangle, on change le triangle référencé
            for (unsigned int j = 0, sz = this->A[this->T[t].A[i]].T.size(); j < sz; j++)
                if (this->A[this->T[t].A[i]].T[j] == last) { this->A[this->T[t].A[i]].T[j] = t; break; }
        }
    }
    this->T.pop_back();
}

int DynamicMesh::FindPoint(const Point & p) const {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        if (p.x == this->P[i].P.x && p.y == this->P[i].P.y && p.z == this->P[i].P.z)
            return i;
    }
    return -1;
}

std::vector<unsigned int> DynamicMesh::FindPointsNeighbors(unsigned int p) const {
    std::vector<unsigned int> res;
    for (unsigned int a : this->P[p].A) {
        if (this->A[a].P[0] == p)
            res.push_back(this->A[a].P[1]);
        else
            res.push_back(this->A[a].P[0]);
    }
    return res;
}

std::vector<unsigned int> DynamicMesh::FindAretesNeighbors(unsigned int p) const {
    return this->P[p].A;
}

std::vector<unsigned int> DynamicMesh::FindTrianglesNeighbors(unsigned int p) const {
    std::vector<unsigned int> res;
    for (unsigned int a : this->P[p].A) {
        for (unsigned int i = 0, sz = this->A[a].T.size(); i < sz; i++) {
            bool founded = false;
            for (unsigned int e : res)
                if (e == this->A[a].T[i]) { founded = true; break; }
            if (!founded)
                res.push_back(this->A[a].T[i]);
        }
    }
    return res;
}

bool DynamicMesh::AreNeighbors(unsigned int p1, unsigned int p2) const {
    for (unsigned int a : this->P[p1].A) {
        if (this->A[a].P[0] == p2 || this->A[a].P[1] == p2)
            return true;
    }
    return false;
}

void DynamicMesh::Merge(unsigned int p) {
    std::vector<unsigned int> neighbors = this->FindPointsNeighbors(p);
    if (neighbors.size() == 0) return;
    this->Merge(p, neighbors[0]);
}

Point DynamicMesh::Merge(unsigned int p1, unsigned int p2) {
    std::vector<unsigned int> neighbors = this->FindPointsNeighbors(p1), tmp_v = this->FindPointsNeighbors(p2);
    for (unsigned int i = 0, sz = neighbors.size(); i < sz; i++)
        if (neighbors[i] == p2) { neighbors.erase(neighbors.begin() + i); break; }
    for (unsigned int e : tmp_v) {
        if (e == p1) continue;
        bool founded = false;
        for (unsigned int tmp_i : neighbors)
            if (e == tmp_i) { founded = true; break; }
        if (!founded)
            neighbors.push_back(e);
    }

    Point point((this->P[p1].P.x + this->P[p2].P.x) / 2, (this->P[p1].P.y + this->P[p2].P.y) / 2, (this->P[p1].P.z + this->P[p2].P.z) / 2);
    unsigned int index = this->P.size();
    this->AddPoint(point);
    if (neighbors.size() == 0) {
        this->RemovePoint(p1);
        this->RemovePoint(p2);
        return point;
    }

    std::vector<unsigned int> commun;
    for (unsigned int e : neighbors) {
        this->AddArete(index, e);
        commun = this->FindPointsNeighbors(e);
        for (int i = commun.size() - 1; i >= 0; i--) {
            bool founded = false;
            for (unsigned int e2 : neighbors) {
                if (e2 == commun[i]) {
                    founded = true;
                    break;
                }
            }
            if (!founded)
                commun.erase(commun.begin() + i);
        }
        for (unsigned int e2 : commun) {
            this->AddTriangle(index, e, e2);
        }
    }

    this->RemovePoint(p1);
    this->RemovePoint(p2);
    return point;
}

void DynamicMesh::Merge(const Box & box) {
    bool success = false;
    unsigned int node;
    std::vector<unsigned int> neighbors;
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        if (box.Inside(this->P[i].P)) {
            node = i;
            success = true;
            break;
        }
    }

    while (success) {
        success = false;
        for (unsigned int e : this->P[node].A) {
            unsigned int neigh = (this->A[e].P[0] == node) ? this->A[e].P[1] : this->A[e].P[0];
            if (box.Inside(this->P[neigh].P)) {
                node = this->FindPoint(this->Merge(node, neigh));
                success = true;
                break;
            }
        }
    }
}

void DynamicMesh::Merge(const Grille3D & grille) {
    for (unsigned int x = 0; x < grille.nbX; x++) {
        for (unsigned int y = 0; y < grille.nbY; y++) {
            for (unsigned int z = 0; z < grille.nbZ; z++) {
                this->Merge(grille.Get(x, y, z));
            }
        }
    }
}

void DynamicMesh::Subdivide() {
    unsigned int first_new = this->P.size();
    std::vector<triangle_type> t_cpy = this->T;
    this->T.clear();

    // On nettoie les points
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++)
        this->P[i] = { this->P[i].P, Vecteur(), std::vector<unsigned int>() };
    // On ajoute les points centraux pour chaque arète
    for (unsigned int i = 0, sz = this->A.size(); i < sz; i++)
        this->AddPoint(this->P[this->A[i].P[0]].P.GetMiddle(this->P[this->A[i].P[1]].P));
    this->A.clear();
    // On ajoute les triangles
    unsigned int tmp[3];
    for (unsigned int i = 0, sz = t_cpy.size(); i < sz; i++) {
        for (unsigned int j = 0; j < 3; j++)
            tmp[j] = first_new + t_cpy[i].A[j];
        this->AddTriangle(t_cpy[i].P[0], tmp[0], tmp[2]);
        this->AddTriangle(t_cpy[i].P[1], tmp[1], tmp[0]);
        this->AddTriangle(t_cpy[i].P[2], tmp[2], tmp[1]);
        this->AddTriangle(tmp[0], tmp[1], tmp[2]);
    }
}

void DynamicMesh::SubdivideByButterfly() {
    unsigned int first_new = this->P.size();
    std::vector<triangle_type> t_cpy = this->T;
    this->T.clear();

    // On ajoute les points centraux pour chaque arète
    Point nv_p;
    unsigned int neigh;
    std::vector<unsigned int> neighbors;
    for (unsigned int i = 0, sz = this->A.size(); i < sz; i++) {
        //Points de l'arète
        nv_p = this->P[this->A[i].P[0]].P / 2 + this->P[this->A[i].P[1]].P / 2;
        //Points communs
        for (unsigned int j = 0, sz_j = this->A[i].T.size(); j < sz_j; j++) {
            neigh = (t_cpy[this->A[i].T[j]].P[0] == this->A[i].P[0] || t_cpy[this->A[i].T[j]].P[0] == this->A[i].P[1]) ?
                    (t_cpy[this->A[i].T[j]].P[1] == this->A[i].P[0] || t_cpy[this->A[i].T[j]].P[1] == this->A[i].P[1]) ?
                    t_cpy[this->A[i].T[j]].P[2] : t_cpy[this->A[i].T[j]].P[1] : t_cpy[this->A[i].T[j]].P[0];
            neighbors = this->FindPointsNeighbors(neigh);
            for (int k = neighbors.size() - 1; k >= 0; k--) {
                if (neighbors[k] == this->A[i].P[0] || neighbors[k] == this->A[i].P[1] || (!this->AreNeighbors(neighbors[k], this->A[i].P[0]) && !this->AreNeighbors(neighbors[k], this->A[i].P[1])))
                    neighbors.erase(neighbors.begin() + k);
            }

            if (neighbors.size() >= 2)
                nv_p = nv_p + this->P[neigh].P / 8 - this->P[neighbors[0]].P / 16 - this->P[neighbors[1]].P / 16;
        }
        this->AddPoint(nv_p);
    }

    // On nettoie les points
    for (unsigned int i = 0, sz = first_new; i < sz; i++)
        this->P[i] = { this->P[i].P, Vecteur(), std::vector<unsigned int>() };
    this->A.clear();
    // On ajoute les triangles
    unsigned int tmp[3];
    for (unsigned int i = 0, sz = t_cpy.size(); i < sz; i++) {
        for (unsigned int j = 0; j < 3; j++)
            tmp[j] = first_new + t_cpy[i].A[j];
        this->AddTriangle(t_cpy[i].P[0], tmp[0], tmp[2]);
        this->AddTriangle(t_cpy[i].P[1], tmp[1], tmp[0]);
        this->AddTriangle(t_cpy[i].P[2], tmp[2], tmp[1]);
        this->AddTriangle(tmp[0], tmp[1], tmp[2]);
    }
}

bool DynamicMesh::Correct() const {
    for (unsigned int i = 0, sz = this->A.size(); i < sz; i++) {
        if (this->A[i].T.size() > 2)
            return false;
    }
    return true;
}

bool DynamicMesh::Closed() const {
    for (unsigned int i = 0, sz = this->A.size(); i < sz; i++) {
        if (this->A[i].T.size() < 2)
            return false;
    }
    return true;
}

bool DynamicMesh::FreePoint() const {
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        if (this->P[i].A.size() == 0)
            return true;
    }
    return false;
}

double DynamicMesh::GetDistance(const Point& p) const {
    unsigned int nearest_point = 0;
    double nearest_dist = this->P[0].P.GetDistance(p), tmp_d;
    for (unsigned int i = 1, sz = this->P.size(); i < sz; i++) {
        if (nearest_dist > (tmp_d = this->P[i].P.GetDistance(p))) {
            nearest_point = i;
            nearest_dist = tmp_d;
        }
    }

    Point proj = p.GetProjection(Droite(this->P[nearest_point].P, this->P[nearest_point].N));
    return this->P[nearest_point].P.GetDistance(proj);
}

double DynamicMesh::GetDistance(const Point& p, unsigned int i) const {
    Point proj = p.GetProjection(Droite(this->P[i].P, this->P[i].N));
    return this->P[i].P.GetDistance(proj);
}

void DynamicMesh::CalculateDistance(const DynamicMesh& mesh) {
    this->D.clear();
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        this->D.push_back(mesh.GetDistance(this->P[i].P));
    }
}

void DynamicMesh::CalculateDistanceByOctree(DynamicMesh& mesh) {
    this->D.clear();
    Box box = mesh.GetBox();
    double length = std::max(box.GetVector(0).GetNorm(), std::max(box.GetVector(1).GetNorm(), box.GetVector(2).GetNorm()));
    Voxel voxel(box.GetPoint(0) + Vecteur::VectorByPoints(box.GetPoint(0), box.GetPoint(7)) * (1 / 2), length / 2);
    std::vector<unsigned int> tmp_v;
    for (unsigned int i = 0, sz = mesh.P.size(); i < sz; i++) tmp_v.push_back(i);
    OctreePoint tree(voxel, mesh, tmp_v);
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++) {
        this->D.push_back(tree.GetDistance(this->P[i].P));
    }
}