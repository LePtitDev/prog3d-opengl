#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_OFF_HPP
#define PROG3D_OFF_HPP

class FileOFF {

    Mesh mesh;

public:

    FileOFF(const char *);

    void Load(const char *);

    const Mesh& GetMesh() const;

};

#endif //PROG3D_OFF_HPP

#endif