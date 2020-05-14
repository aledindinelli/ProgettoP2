#include "vettore.h"

template<class T>
Vettore<T>::Vettore(unsigned int s, T x)
    : info(s!=0 ? new int[s] : nullptr), _size(s)
{
    for (unsigned int i=0; i<_size; ++i) {info[i]=x;}
}

template<class T>
Vettore<T>::Vettore(const Vettore &c)
    : info(c.size()==0 ? nullptr : new int[c.getSize()]), _size(c.size())
{
    for (unsigned int i=0; i<_size; i++) {info[i]=c.info[i];}
}

template<class T>
Vettore<T>::~Vettore()
{
    delete[] info;
}

template<class T>
unsigned int Vettore<T>::getSize() const
{
    return _size;
}

template<class T>
Vettore<T> &Vettore<T>::operator=(const Vettore &c)
{
    if (this != &c)
    {
        delete[] info;
        info = c.size()==0 ? nullptr : new int[c.size()];
        _size = c.size();
        for (unsigned int i=0; i<_size; i++) {info[i]=c.info[i];}
    }
    return *this;
}

template<class T>
bool Vettore<T>::operator==(const Vettore &c) const
{
    if (this == &c) return true;
    if (getSize() != c.size()) return false;
    for (unsigned int i=0; i<getSize(); i++)
    {
        if (info[i] != c[i]) return false;
    }
    return true;
}

template<class T>
T &Vettore<T>::operator[](unsigned int i) const
{
    return i < _size && i>-1 ? info[i] : nullptr;
}

template<class T>
Vettore<T> operator+ (const Vettore<T> & v1, const Vettore<T> & v2) // (1)
{
    Vettore<T> aux(v1.getSize()+v2.getSize());
    for (unsigned int i=0; i<v1.getSize(); i++)
    {
        aux[i] = v1[i];
    }
    for (unsigned int i=0; i<v2.getSize(); i++)
    {
        aux[i+v1.getSize()] = v2[i];
    }
    return aux;
}

template<class T>
void Vettore<T>::append(const Vettore & v)
{
    *this = *this + v;
}
