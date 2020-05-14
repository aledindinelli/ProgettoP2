#ifndef CONTENITORE_H
#define CONTENITORE_H

template<class T>
class Vettore
{
private:
    T* info;
    unsigned int _size;

public:
    Vettore(unsigned int s=0, T x=0);
    Vettore(const Vettore &);
    ~Vettore();
    unsigned int getSize() const;
    Vettore& operator= (const Vettore &);
    bool operator== (const Vettore &) const;
    T& operator[](unsigned int) const;
    void append(const Vettore &);
};

#endif // CONTENITORE_H
