#ifndef PROJECT1_DATA_H
#define PROJECT1_DATA_H

#include <iostream>

using namespace std;

class DiaInvalida : std::exception{
    int dia;
public:
    DiaInvalida(int d){dia = d;}
    const char* what() const throw()
    {
        return "Dia deve estar entre 1 e 31";
    }
};

class MesInvalido : std::exception{
    int mes;
public:
    MesInvalido(int m){mes = m;}
    const char* what() const throw()
    {
        return "Mes deve estar entre 1 e 12";
    }
};

///Data
class Data{
    int dia,
            mes,
            ano;
public:
    ///construtor da classe data
    Data()
    {
        dia = 1;
        mes = 1;
        ano = 1970;
    }

    ///construtor com parametros da classe dat
    ///@param a
    ///@param m
    ///@param d
    Data(int d, int m, int a)
    {
        if(d > 31 || d < 1)
        {
            throw DiaInvalida(d);
        }
        if(m > 12 || m < 1)
        {
            throw MesInvalido(m);
        }
        dia = d;
        mes = m;
        ano = a;
    }

    ///getter do dia
    int getDia() const {
        return dia;
    }

    ///setter do dia
    ///@param dia
    void setDia(int dia) {
        if(dia > 31)
        {
            throw runtime_error("Day must be between 1 and 31");
        }
        Data::dia = dia;
    }

    ///getter do mes
    int getMes() const {
        return mes;
    }

    ///setter do mes
    ///@param  mes
    void setMes(int mes) {
        if(mes > 12)
        {
            throw runtime_error("Month must be between 1 and 12");
        }
        Data::mes = mes;
    }

    ///getter do ano
    int getAno() const {
        return ano;
    }

    ///setter do ano
    ///@param ano
    void setAno(int ano) {
        Data::ano = ano;
    }

    ///implementacao do operator <<
    ///@param os
    ///@param dt
    friend ostream& operator<<(ostream& os, const Data& dt)
    {
        os << dt.dia << "/" << dt.mes << "/" << dt.ano;
        return os;
    }
};



#endif //PROJECT1_DATA_H
