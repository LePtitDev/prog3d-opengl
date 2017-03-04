#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_MATRICE_HPP
#define PROG3D_MATRICE_HPP

template <typename T, unsigned char N, unsigned char M>
class Matrice {

public:

    const unsigned char n, m;
    std::array<std::array<T, M>, N> data;

    Matrice();
    Matrice(const Matrice<T, N, M>&);

    T GetDeterminant() const;

    template <unsigned char _M>
    Matrice<T, N, _M> operator*(const Matrice<T, M, _M>&);

    std::array<T, M>& operator[](unsigned char);

};

template <typename T, unsigned char N, unsigned char M>
Matrice<T, N, M>::Matrice() :
    m(M), n(N)
{

}

template <typename T, unsigned char N, unsigned char M>
Matrice<T, N, M>::Matrice(const Matrice<T, N, M> & x) :
    m(M), n(N)
{
    for (unsigned char i = 0; i < N; i++) {
        for (unsigned char j = 0; j < M; j++) {
            this->data[i][j] = x.data[i][j];
        }
    }
}

template <typename T, unsigned char N, unsigned char M>
T Matrice<T, N, M>::GetDeterminant() const {
    if (N != M) return 0;
    if (N <= 1) return this->data[0][0];
    T res = 0;
    for (unsigned char i = 0; i < N; i++) {
        Matrice<T, N-1, M-1> delta;
        for (unsigned char _i = 0; _i < i; _i++) {
            for (unsigned char _j = 1; _j < M; _j++) {
                delta.data[_i][_j-1] = this->data[_i][_j];
            }
        }
        for (unsigned char _i = i + 1; _i < N; _i++) {
            for (unsigned char _j = 1; _j < M; _j++) {
                delta.data[_i-1][_j-1] = this->data[_i][_j];
            }
        }
        if (i % 2 == 0)
            res += this->data[i][0] * delta.GetDeterminant();
        else
            res -= this->data[i][0] * delta.GetDeterminant();
    }
    return res;
}

template <typename T, unsigned char N, unsigned char M>
template <unsigned char _M>
Matrice<T, N, _M> Matrice<T, N, M>::operator*(const Matrice<T, M, _M> & x) {
    Matrice<T, N, _M> res;
    for (unsigned char i = 0; i < N; i++) {
        for (unsigned char j = 0; j < _M; j++) {
            res[i][j] = 0;
            for (unsigned char k = 0; k < M; k++) {
                res[i][j] += this->data[i][k] * x.data[k][j];
            }
        }
    }
    return res;
}

template <typename T, unsigned char N, unsigned char M>
std::array<T, M> & Matrice<T, N, M>::operator[](unsigned char i) {
    return this->data[i];
}

#endif //PROG3D_MATRICE_HPP

#endif