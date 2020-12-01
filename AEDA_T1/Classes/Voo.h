#ifndef PROJECT1_VOO_H
#define PROJECT1_VOO_H

#include "../Utils/split.h"
#include "../Utils/Hora.h"
#include "../Utils/Data.h"
#include "../Classes/BinaryTree.h"

class Informacao;

///Voo
class Voo{
    Data data;
    Hora hora;
    string destino;
    Informacao* info;
    int tempoPista;


public:
    ///contrtutor da classe Voo
    ///@param D
    ///@param d
    ///@param h
    Voo(Data D, Hora h, string d, int tpista)
    {
        data = D;
        hora = h;
        destino = d;
        tempoPista = tpista;
    }

    ///getter da data
    const Data &getData() const {
        return data;
    }

    ///setter da data
    ///@param data
    void setData(const Data &data) {
        Voo::data = data;
    }

    ///getter da hora
    const Hora &getHora() const {
        return hora;
    }

    ///setter da hora
    ///@param  hora
    void setHora(const Hora &hora) {
        Voo::hora = hora;
    }

    ///getter do destino
    const string &getDestino() const {
        return destino;
    }

    ///setter do destino
    ///@param destino
    void setDestino(const string &destino) {
        Voo::destino = destino;
    }

    ///getter da informacao
    Informacao *getInfo() const {return info;}

    ///setter da informacao
    ///@param info
    void setInfo(Informacao *info) {Voo::info = info;}

    ///implementacao do operator <<
    ///@param os
    ///@param v
    friend ostream& operator<<(ostream& os, const Voo& v)
    {
        os << "Destino: " << v.destino << endl;
        os << "Dia: " << v.data << endl;
        os << "Hora: " << v.hora  << endl;
        return os;
    }

    ///Setter tempo em pista
    ///@param min
    void setTempoPista(int min)
    {
        tempoPista = min;
    }

    /// Getter tempo em pista
    int getTempoPista() const
    {return tempoPista;}
};

#endif //PROJECT1_VOO_H

