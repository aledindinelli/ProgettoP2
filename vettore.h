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

        // Ricontrollo metodi const
        bool operator!=(const Iteratore &) const;
        bool operator==(const Iteratore &) const;
        bool operator<(const Iteratore &) const;
        bool operator<=(const Iteratore &) const;
        bool operator>(const Iteratore &) const;
        bool operator>=(const Iteratore &) const;

        Iteratore& operator++();
        Iteratore& operator--();

        T& operator*();
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

        const T& operator*();
    };

    Iteratore itBegin() const;
    Iteratore itEnd() const;
    ConstIteratore citBegin() const;
    ConstIteratore citEnd() const;

    void erase(Iteratore pos);
};

#endif // VETTORE_H
