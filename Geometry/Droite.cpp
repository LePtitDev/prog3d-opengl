#include "Droite.hpp"

Droite::Droite() :
    p(), v(1.f, 0.f, 0.f)
{

}

Droite::Droite(const Point & p, const Vecteur & v) :
    p(p), v(v)
{

}

Droite::Droite(const Droite & d) :
    p(d.p), v(d.v)
{

}