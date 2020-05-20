#include "vettore.h"

template<class T>
Vettore<T>::Vettore() : container(nullptr), _size(0), _capacity(0) {}

template<class T>
Vettore<T>::Vettore(unsigned int s) : _size(s), _capacity(s)
{
    container = new T[s];
}

template<class T>
Vettore<T>::Vettore(T t, unsigned int s) : _size(s), _capacity(s)
{
    container = new T[_size];
    for (unsigned int i=0; i<_size; i++) {
        container[i]=t;
    }
}

template<class T>
Vettore<T>::Vettore(const Vettore &v) : _size(v._size), _capacity(v._capacity)
{
    container = new T[_size];
    for (unsigned int i=0; i<_size; i++) {
        container[i]=v.container[i];
    }
}

template<class T>
Vettore<T>::~Vettore()
{
    delete[] container;
}

template<class T>
Vettore<T>& Vettore<T>::operator=(const Vettore &v)
{
    if (this == &v) {
        return *this;
    }

    delete[] container;
    _size = v._size;
    _capacity = v._capacity;
    container = new T[_size];

    for (unsigned int i=0; i<_size; i++) {
        container[i]=v.container[i];
    }

    return *this;
}

template<class T>
bool Vettore<T>::operator==(const Vettore &v) const
{
    if (_size != v._size || _capacity != v._capacity)
        return false;

    for (unsigned int i = 0; i < _size; i++)
        if (container[i] != v.container[i])
            return false;

    return true;
}

template<class T>
bool Vettore<T>::operator!=(const Vettore &v) const
{
    return !operator==(v);
}

template<class T>
unsigned int Vettore<T>::getCapacity() const
{
    return _capacity;
}

template<class T>
unsigned int Vettore<T>::getSize() const
{
    return _size;
}

template<class T>
void Vettore<T>::push_back(T &t)
{
    if (_size == _capacity) {
        T *temp = new T[2*_capacity];
        for (unsigned int i = 0; i < _size; i++) {
            temp[i] = container[i];
        }
        temp[_size] = t;
        delete[] container;
        container = temp;
        _size++;
    } else {
        container[_size] = t;
        _size++;
    }
}

template<class T>
T& Vettore<T>::operator[](unsigned int i)
{
    return container[i];
}

template<class T>
const T& Vettore<T>::operator[](unsigned int i) const
{
    return container[i];
}

template<class T>
typename Vettore<T>::Iteratore Vettore<T>::itBegin() const
{
    return container[0];
}

template<class T>
typename Vettore<T>::Iteratore Vettore<T>::itEnd() const
{
    return container[_size];
}

template<class T>
typename Vettore<T>::ConstIteratore Vettore<T>::citBegin() const
{
    return container[0];
}

template<class T>
typename Vettore<T>::ConstIteratore Vettore<T>::citEnd() const
{
    return container[_size];
}

template<class T>
void Vettore<T>::erase(Vettore::Iteratore pos)
{
    Iteratore it = (*this).begin();

    for (it; it != pos && it < _size; it++) {
        container[it] = container[it +1];
    }

    _size--;
}

// Iteratore

template<class T>
Vettore<T>::Iteratore::Iteratore() : punt(nullptr) {}

template<class T>
Vettore<T>::Iteratore::Iteratore(const Vettore::Iteratore & it) : punt(it.punt) {}

template<class T>
Vettore<T>::Iteratore::~Iteratore()
{
    if (this) {
        delete this;
    }
}

template<class T>
bool Vettore<T>::Iteratore::operator!=(const Iteratore & it)
{
    return punt != it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator==(const Iteratore & it)
{
    return punt == it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator<(const Iteratore & it)
{
    return punt < it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator<=(const Iteratore & it)
{
    return punt <= it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator>(const Iteratore & it)
{
    return punt > it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator>=(const Iteratore & it)
{
    return punt >= it.punt;
}

template<class T>
typename Vettore<T>::Iteratore &Vettore<T>::Iteratore::operator++()
{
    punt++;
    return *this;
}

template<class T>
typename Vettore<T>::Iteratore &Vettore<T>::Iteratore::operator--()
{
    punt--;
    return *this;
}

template<class T>
T &Vettore<T>::Iteratore::operator*()
{
    return *punt;
}

// ConstIteratore

template<class T>
Vettore<T>::ConstIteratore::ConstIteratore() : punt(nullptr) {}

template<class T>
Vettore<T>::ConstIteratore::ConstIteratore(const Vettore::ConstIteratore & cit) : punt(cit.punt) {}

template<class T>
Vettore<T>::ConstIteratore::~ConstIteratore()
{
    if (this) {
        delete this;
    }
}

template<class T>
bool Vettore<T>::ConstIteratore::operator!=(const Vettore::ConstIteratore & cit) const
{
    return punt != cit.punt;
}

template<class T>
bool Vettore<T>::ConstIteratore::operator==(const Vettore::ConstIteratore & cit) const
{
    return punt == cit.punt;
}

template<class T>
bool Vettore<T>::ConstIteratore::operator<(const Vettore::ConstIteratore & cit) const
{
    return punt < cit.punt;
}

template<class T>
bool Vettore<T>::ConstIteratore::operator<=(const Vettore::ConstIteratore & cit) const
{
    return punt <= cit.punt;
}

template<class T>
bool Vettore<T>::ConstIteratore::operator>(const Vettore::ConstIteratore & cit) const
{
    return punt > cit.punt;
}

template<class T>
bool Vettore<T>::ConstIteratore::operator>=(const Vettore::ConstIteratore & cit) const
{
    return punt >= cit.punt;
}

template<class T>
typename Vettore<T>::ConstIteratore &Vettore<T>::ConstIteratore::operator++()
{
    punt++;
    return *this;
}

template<class T>
typename Vettore<T>::ConstIteratore &Vettore<T>::ConstIteratore::operator--()
{
    punt--;
    return *this;
}

template<class T>
const T &Vettore<T>::ConstIteratore::operator*()
{
    return *punt;
}
