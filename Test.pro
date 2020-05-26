TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        docente.cpp \
        dottorando.cpp \
        impiegato.cpp \
        laureando.cpp \
        main.cpp \
        modello.cpp \
        persona.cpp \
        studente.cpp \
        studentelavoratore.cpp \
        tecnico.cpp

HEADERS += \
    docente.h \
    dottorando.h \
    impiegato.h \
    laureando.h \
    modello.h \
    persona.h \
    studente.h \
    studentelavoratore.h \
    tecnico.h \
    vettore.h

DISTFILES += \
    note.txt
