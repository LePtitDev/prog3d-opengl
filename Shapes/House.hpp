#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_HOUSE_HPP
#define PROG3D_HOUSE_HPP

class House {

public:

    typedef struct {
        unsigned char * data;
        int width, height;
    } Texture;

private:

    //Points
    std::array<Point, 10> P;
    //Textures
    std::array<Texture, 3> T;
    //Indique si les textures sont gardées
    bool loaded;

public:

    /**
     * Constructeur de base
     * Paramètres:
     * - position du centre de la maison
     * - largeur de la maison
     * - hauteur de la maison
     * - profondeur de la maison
     * - proportion du toit
     */
    House(const Point&, float, float, float, float);

    /**
     * Charge les Textures
     */
    void LoadTextures();

    void Draw() const;

};

#endif //PROG3D_HOUSE_HPP

#endif