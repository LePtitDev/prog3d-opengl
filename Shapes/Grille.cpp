#include "Grille.hpp"

Grille3D::Grille3D() :
    pos(), ortho(1, 1, 1), nbX(0), nbY(0), nbZ(0)
{

}

Grille3D::Grille3D(const Point& p, const Vecteur& v) :
    pos(p), ortho(v), nbX(1), nbY(1), nbZ(1)
{

}

Grille3D::Grille3D(const Point& p, const Vecteur& v, unsigned int nb) :
    pos(p), ortho(v), nbX(nb), nbY(nb), nbZ(nb)
{

}

Grille3D::Grille3D(const Grille3D& g) :
    pos(g.pos), ortho(g.ortho), nbX(g.nbX), nbY(g.nbY), nbZ(g.nbZ)
{

}

void Grille3D::Draw() const {
    for (unsigned int i = 0; i < this->nbX; i++) {
        for (unsigned int j = 0; j < this->nbY; j++) {
            for (unsigned int k = 0; k < this->nbZ; k++) {
                this->Get(i, j, k).Draw();
            }
        }
    }
}

Box Grille3D::Get(unsigned int i, unsigned int j, unsigned int k) const {
    Vecteur u(this->ortho.x, 0, 0), v(0, this->ortho.y, 0), w(0, 0, this->ortho.z);
    return Box(this->pos + u * i + v * j + w * k, u, v, w);
}