#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_CURVE_HPP
#define PROG3D_CURVE_HPP

class Curve {

    std::vector<Point> P;

public:

    /****** OBJET ******/

    Curve();
    Curve(const Point[], unsigned int);
    Curve(const Curve&);

    void Draw() const;

    unsigned int Size() const;

    Point& operator[](unsigned int);

    const Point * GetArray() const;

    /****** STATIQUES ******/

    /**
     * Crée une courbe cubique d'Hermite
     * Paramètres:
     * - point de départ
     * - point d'arrivée
     * - vecteur de départ
     * - vecteur d'arrivée
     * - nombre de points à créer sur la courbe
     * Retourne la courbe
    */
    static Curve HermiteCubic(const Point&, const Point&, const Vecteur&, const Vecteur&, long);

    /**
     * Crée une courbe de Bézier par Bernstein
     * Paramètres:
     * - points de contrôle
     * - nombre de points de contrôles
     * - nombre de points à créer sur la courbe
     * Retourne la courbe
    */
    static Curve BezierByBernstein(const Point[], long, long);

    /**
     * Crée une courbe de Bézier par Casteljau
     * Paramètres:
     * - points de contrôle
     * - nombre de points de contrôles
     * - nombre de points à créer sur la courbe
     * Retourne la courbe
    */
    static Curve BezierByCasteljau(const Point[], long, long);

};

#endif //PROG3D_CURVE_HPP

#endif