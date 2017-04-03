#include "OFF.hpp"

FileOFF::FileOFF() {}
FileOFF::FileOFF(const char * fname) {
    this->Load(fname);
}

void FileOFF::Load(const char * fname) {
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
        this->P.push_back(pt);
    }

    //On lit les triangles
    unsigned int t, a, b, c;
    std::array<unsigned int, 3> tmp_tr;
    for (unsigned int i = 0; i < nbT; i++) {
        file.getline(buff, 256);
        sscanf(buff, "%d %d %d %d", &t, &tmp_tr[0], &tmp_tr[1], &tmp_tr[2]);
        this->T.push_back(tmp_tr);
    }
}

void FileOFF::Save(const char * fname) {
    std::ofstream file(fname);
    if (!file.is_open()) return;

    file << "OFF" << std::endl;
    file << this->P.size() << " " << this->T.size() << " 0" << std::endl;
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++)
        file << this->P[i].x << " " << this->P[i].y << " " << this->P[i].z << std::endl;
    for (unsigned int i = 0, sz = this->T.size(); i < sz; i++) {
        file << "3 " << this->T[i][0] << " " << this->T[i][1] << " " << this->T[i][2] << std::endl;
    }

    file.close();
}

Mesh FileOFF::GetMesh() const {
    Mesh mesh;
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++)
        mesh.PushPoint(this->P[i]);
    for (unsigned int i = 0, sz = this->T.size(); i < sz; i++)
        mesh.PushTriangle(this->T[i][0], this->T[i][1], this->T[i][2]);
    return mesh;
}

DynamicMesh FileOFF::GetDynamicMesh() const {
    DynamicMesh mesh;
    for (unsigned int i = 0, sz = this->P.size(); i < sz; i++)
        mesh.AddPoint(this->P[i]);
    for (unsigned int i = 0, sz = this->T.size(); i < sz; i++)
        mesh.AddTriangle(this->T[i][0], this->T[i][1], this->T[i][2]);
    return mesh;
}