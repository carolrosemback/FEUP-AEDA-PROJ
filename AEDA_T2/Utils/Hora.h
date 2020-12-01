#ifndef PROJECT1_HORA_H
#define PROJECT1_HORA_H

#include <iostream>

using namespace std;

///Hora
class Hora{
    int hora,
            minuto,
            segundo;
public:
    ///construtor de hora
    Hora()
    {
        hora = 0;
        minuto = 0;
        segundo = 0;
    }

    ///contrutor de hora com paramentros
    ///@param h
    ///@param m
    ///@param s
    Hora(int h, int m, int s)
    {
        if(h > 24 || h < 0)
        {
            throw runtime_error("Hour must be between 0 and 24");
        }
        if(m > 59 || m < 0)
        {
            throw runtime_error("Minutes must be between 0 and 59");
        }
        if(s > 59 || s < 0)
        {
            throw runtime_error("Seconds must be between 0 and 59");
        }

        hora = h;
        minuto = m;
        segundo = s;
    }

    ///getter de hora
    int getHora() const {
        return hora;
    }

    ///setter de hora
    ///@param hora
    void setHora(int hora) {
        Hora::hora = hora;
    }

    ///getter de minuto
    int getMinuto() const {
        return minuto;
    }

    ///setter de minuto
    ///@param minuto
    void setMinuto(int minuto) {
        Hora::minuto = minuto;
    }

    ///getter de minuto
    int getSegundo() const {
        return segundo;
    }

    ///setter de segundo
    ///@param segundo
    void setSegundo(int segundo) {
        Hora::segundo = segundo;
    }

    ///implementacao do operator <<
    friend ostream& operator<<(ostream& os, const Hora& hr)
    {
        os << hr.hora << ":" << hr.minuto << ":" << hr.segundo;
        return os;
    }
};

#endif //PROJECT1_HORA_H
