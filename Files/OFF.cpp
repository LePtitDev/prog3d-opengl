#include "OFF.hpp"

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
    if (strcmp(buff, "OFF")) return;

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

const Mesh& FileOFF::GetMesh() const {
    return this->mesh;
}