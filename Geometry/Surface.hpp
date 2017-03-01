#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_SURFACE_HPP
#define PROG3D_SURFACE_HPP

class Surface {

    unsigned int n, m;
    std::vector<Curve> surf;

public:

    /****** OBJET ******/

    Surface();
    Surface(const Curve[], unsigned int, unsigned int);
    Surface(const Surface&);

    void Draw();
    void DrawWithLines();

    unsigned int GetN() const;
    unsigned int GetM();

    Curve& operator[](unsigned int);

    /****** STATIQUES ******/

    /**
     * Crée une surface cylindrique
     * Paramètres:
     * - points de contrôle de Bézier
     * - nombre de points de contrôle
     * - vecteur de la droite
     * - nombre de points à créer le long de la droite
     * - nombre de points à créer le long de la courbe
     * Retourne la surface
    */
    static Surface CylindricalSurface(const Point[], long, const Vecteur&, long, long);

    /**
     * Crée une surface réglée
     * Paramètres:
     * - points de contrôle de Bézier 1
     * - nombre de points de contrôle
     * - points de contrôle de Bézier 2
     * - nombre de points de contrôle
     * - nombre de points à créer le long de la droite
     * - nombre de points à créer le long des beziers
     * Retourne la surface
    */
    static Surface RuledSurface(const Point[], long, const Point[], long, long, long);

    /**
     * Crée une surface par carreaux surfaciques avec Casteljau
     * Paramètres:
     * - Surface de point de contrôle
     * - nombre de points à créer sur u
     * - nombre de points à créer sur v
     * Retourne la surface
    */
    static Surface BezierSurfaceByCasteljau(const Surface&, long, long);

};

#endif //PROG3D_SURFACE_HPP

#endif