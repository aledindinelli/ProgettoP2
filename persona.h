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
    virtual ~Persona();
    virtual std::string getNome() const;
    virtual unsigned short getEta() const;
    virtual unsigned short costo() const = 0;
    virtual mansione() const;
};

#endif // PERSONA_H
