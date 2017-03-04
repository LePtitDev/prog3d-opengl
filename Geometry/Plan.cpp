#include "Plan.hpp"

Plan::Plan() :
    p(), n(0.f, 1.f, 0.f), u(1.f, 0.f, 0.f), v(0.f, 0.f, 1.f)
{
    this->n.Normalize();
    this->u.Normalize();
    this->v.Normalize();
}

Plan::Plan(const Point & p, const Vecteur & v) :
    p(p), n(v)
{
    Vecteur tmp(cos(this->n.x), sin(this->n.x), cos(this->n.x + this->n.y + this->n.z));
    this->u = this->n.GetVectoriel(tmp);
    this->v = this->n.GetVectoriel(this->u);
    this->n.Normalize();
    this->u.Normalize();
    this->v.Normalize();
}

Plan::Plan(const Point & p, const Vecteur & v1, const Vecteur & v2) :
    p(p), n(v1.GetVectoriel(v2)), u(v1), v(v2)
{
    this->n.Normalize();
    this->u.Normalize();
    this->v.Normalize();
}

Plan::Plan(const Plan & p) :
    p(p.p), n(p.n), u(p.u), v(p.v)
{

}

const Vecteur& Plan::GetU() const {
    return this->u;
}

const Vecteur& Plan::GetV() const {
    return this->v;
}

const Vecteur& Plan::GetNormal() const {
    return this->n;
}