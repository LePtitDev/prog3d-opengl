#include "OFF.hpp"

FileOFF::FileOFF() {}
FileOFF::FileOFF(DynamicMesh & dyn) {
    for (unsigned int i = 0, sz = dyn.Points(); i < sz; i++)
        this->mesh.PushPoint(dyn.GetPoint(i));
    for (unsigned int i = 0, sz = dyn.Triangles(); i < sz; i++) {
        std::array<unsigned int, 3> tr = dyn.GetTriangle(i);
        this->mesh.PushTriangle(tr[0], tr[1], tr[2]);
    }
}
FileOFF::FileOFF(const char * fname) {
    this->Load(fname);
}

void FileOFF::Load(const char * fname) {
    this->mesh = Mesh();

    std::ifstream file(fname);
    if (!file.is_open()) return;

    char buff[256], * tmp;

    //On lit l'en-tête "OFF"
    file.getline(buff, 256);
    if (strncmp(buff, "OFF", 3)) return;

    //On lit le nombre de points et triangles
    file.getline(buff, 256);
    tmp = strtok(buff, " ");
    unsigned int nbP = atoi(tmp);
    tmp = strtok(nullptr, " ");
    unsigned int nbT = atoi(tmp);

    //On lit les points
    Point pt;
    for (unsigned int i = 0; i < nbP; i++) {
        file.getline(buff, 256);
        sscanf(buff, "%lf %lf %lf", &(pt.x), &(pt.y), &(pt.z));
        this->mesh.PushPoint(pt);
    }

    //On lit les triangles
    unsigned int t, a, b, c;
    for (unsigned int i = 0; i < nbT; i++) {
        file.getline(buff, 256);
        sscanf(buff, "%d %d %d %d", &t, &a, &b, &c);
        this->mesh.PushTriangle(a, b, c);
    }
}

void FileOFF::Save(const char * fname) {
    std::ofstream file(fname);
    if (!file.is_open()) return;

    file << "OFF" << std::endl;
    file << this->mesh.PointNumber() << " " << this->mesh.TriangleNumber() << " 0" << std::endl;
    for (unsigned int i = 0, sz = this->mesh.PointNumber(); i < sz; i++)
        file << this->mesh[i].x << " " << this->mesh[i].y << " " << this->mesh[i].z << std::endl;
    for (unsigned int i = 0, sz = this->mesh.TriangleNumber(); i < sz; i++) {
        std::array<unsigned int, 3> tr = this->mesh.GetTriangle3(i);
        file << "3 " << tr[0] << " " << tr[1] << " " << tr[2] << std::endl;
    }

    file.close();
}

const Mesh& FileOFF::GetMesh() const {
    return this->mesh;
}