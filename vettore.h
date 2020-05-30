#ifndef VETTORE_H
#define VETTORE_H

template <class T>
class Vettore {
private:
    T *container;
    unsigned int _size;
    unsigned int _capacity;

public:
    Vettore();
    explicit Vettore(unsigned int);
    Vettore(T, unsigned int);
    Vettore(const Vettore<T> &);

    ~Vettore();

    Vettore & operator=(const Vettore<T> &);

    bool operator==(const Vettore<T> &) const;
    bool operator!=(const Vettore<T> &) const;

    unsigned int getCapacity() const;
    unsigned int getSize() const;

    void push_back(T &);

    // void pop_back();

    T& operator[](unsigned int);
    const T& operator[](unsigned int) const;

    class Iteratore {
        friend class Vettore;
    private:
        T* punt;
    public:
        Iteratore();
        Iteratore(const Iteratore &);
        ~Iteratore();

        bool operator!=(const Iteratore &) const;
        bool operator==(const Iteratore &) const;
        bool operator<(const Iteratore &) const;
        bool operator<=(const Iteratore &) const;
        bool operator>(const Iteratore &) const;
        bool operator>=(const Iteratore &) const;

        Iteratore& operator++();
        Iteratore& operator--();

        T* operator->() const;
        T& operator*() const;
    };

    class ConstIteratore {
        friend class Vettore;
    private:
        const T* punt;
    public:
        ConstIteratore();
        ConstIteratore(const ConstIteratore &);
        ~ConstIteratore();

        bool operator!=(const ConstIteratore &) const;
        bool operator==(const ConstIteratore &) const;
        bool operator<(const ConstIteratore &) const;
        bool operator<=(const ConstIteratore &) const;
        bool operator>(const ConstIteratore &) const;
        bool operator>=(const ConstIteratore &) const;

        ConstIteratore& operator++();
        ConstIteratore& operator--();

        const T* operator->() const;
        const T& operator*() const;
    };

    Iteratore Begin();
    Iteratore End();
    ConstIteratore Begin() const;
    ConstIteratore End() const;

    void erase(Iteratore pos);
};

template<class T>
Vettore<T>::Vettore() : container(nullptr), _size(0), _capacity(0) {}

template<class T>
Vettore<T>::Vettore(unsigned int s) : container(s!=0 ? new T[s] : nullptr), _size(s), _capacity(s) {}

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
    _size = 0U;
    _capacity = 0U;
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
        container[_size] = new T(t);
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
typename Vettore<T>::Iteratore Vettore<T>::Begin()
{
    return container[0];
}

template<class T>
typename Vettore<T>::Iteratore Vettore<T>::End()
{
    return container[_size];
}

template<class T>
typename Vettore<T>::ConstIteratore Vettore<T>::Begin() const
{
    return container[0];
}

template<class T>
typename Vettore<T>::ConstIteratore Vettore<T>::End() const
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
bool Vettore<T>::Iteratore::operator!=(const Iteratore & it) const
{
    return punt != it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator==(const Iteratore & it) const
{
    return punt == it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator<(const Iteratore & it) const
{
    return punt < it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator<=(const Iteratore & it) const
{
    return punt <= it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator>(const Iteratore & it) const
{
    return punt > it.punt;
}

template<class T>
bool Vettore<T>::Iteratore::operator>=(const Iteratore & it) const
{
    return punt >= it.punt;
}

template<class T>
typename Vettore<T>::Iteratore& Vettore<T>::Iteratore::operator++()
{
    punt++;
    return *this;
}

template<class T>
typename Vettore<T>::Iteratore& Vettore<T>::Iteratore::operator--()
{
    punt--;
    return *this;
}

template<class T>
T* Vettore<T>::Iteratore::operator->() const
{
    return punt;
}

template<class T>
T& Vettore<T>::Iteratore::operator*() const
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
typename Vettore<T>::ConstIteratore& Vettore<T>::ConstIteratore::operator++()
{
    punt++;
    return *this;
}

template<class T>
typename Vettore<T>::ConstIteratore& Vettore<T>::ConstIteratore::operator--()
{
    punt--;
    return *this;
}

template<class T>
const T* Vettore<T>::ConstIteratore::operator->() const
{
    return punt;
}

template<class T>
const T& Vettore<T>::ConstIteratore::operator*() const
{
    return *punt;
}

#endif // VETTORE_H
