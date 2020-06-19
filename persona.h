#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona
{
private:
    std::string nome;
    unsigned short eta;

public:
    Persona(std::string, unsigned short);
    virtual ~Persona() = default;

    virtual std::string getNome() const;
    virtual unsigned short getEta() const;

    virtual void setNome(std::string);
    virtual void setEta(unsigned short);

    virtual double costo() const = 0;
    virtual void migliora() = 0;
};

#endif // PERSONA_H
