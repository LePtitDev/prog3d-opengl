#include "OFF.hpp"

FileOFF::FileOFF(const char * fname) {
    this->Load(fname);
}

void FileOFF::Load(const char * fname) {
    this->mesh = Mesh();

    std::ifstream file(fname);
    if (!file.is_open()) return;

    char buff[64], * tmp;

    //On lit l'en-tête "OFF"
    file.getline(buff, 64);
    if (strcmp(buff, "OFF")) return;

    //On lit le nombre de points et triangles
    file.getline(buff, 64);
    tmp = strtok(buff, " ");
    unsigned int nbP = atoi(tmp);
    tmp = strtok(nullptr, " ");
    unsigned int nbT = atoi(tmp);

    //On lit les points
    Point pt;
    for (unsigned int i = 0; i < nbP; i++) {
        file.getline(buff, 64);
        tmp = strtok(buff, " ");
        pt.x = atof(tmp);
        tmp = strtok(nullptr, " ");
        pt.y = atof(tmp);
        tmp = strtok(nullptr, " ");
        pt.z = atof(tmp);
        this->mesh.PushPoint(pt);
    }
    
    //On lit les triangles
    unsigned int a, b, c;
    for (unsigned int i = 0; i < nbT; i++) {
        file.getline(buff, 64);
        tmp = strtok(buff, " ");
        tmp = strtok(nullptr, " ");
        a = atoi(tmp);
        tmp = strtok(nullptr, " ");
        b = atoi(tmp);
        tmp = strtok(nullptr, " ");
        c = atoi(tmp);
        this->mesh.PushTriangle(a, b, c);
    }
}

const Mesh& FileOFF::GetMesh() const {
    return this->mesh;
}