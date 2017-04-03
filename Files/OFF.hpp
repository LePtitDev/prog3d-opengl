#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_OFF_HPP
#define PROG3D_OFF_HPP

class FileOFF {

    std::vector<Point> P;
    std::vector<std::array<unsigned int, 3>> T;

public:

    FileOFF();
    FileOFF(const char *);

    void Load(const char *);
    void Save(const char *);

    Mesh GetMesh() const;
    DynamicMesh GetDynamicMesh() const;

};

#endif //PROG3D_OFF_HPP

#endif