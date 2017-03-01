#include "Plan.hpp"

Plan::Plan() :
    p(), n(0.f, 1.f, 0.f)
{

}

Plan::Plan(const Point & p, const Vecteur & v) :
    p(p), n(v)
{

}

Plan::Plan(const Point & p, const Vecteur & v1, const Vecteur & v2) :
    p(p), n(v1.GetVectoriel(v2))
{

}

Plan::Plan(const Plan & p) :
    p(p.p), n(p.n)
{

}