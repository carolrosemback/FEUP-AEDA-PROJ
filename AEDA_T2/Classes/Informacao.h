#ifndef PROJECT1_INFORMACAO_H
#define PROJECT1_INFORMACAO_H

#include "../Classes/Voo.h"

///Informacao de um voo
class Informacao{
    Voo* voo;
    Hora hora_prevista;
    Hora hora_real;
    bool cancelado;
public:
    ///Construtor de Informacao de um voo
    ///@param [in] v Voo a qual a informacao pertence
    ///@param [in] hp Hora prevista do voo
    ///@param [in] hr Hora real do voo
    ///@param [in] canc Se o voo foi cancelado ou nao
    Informacao(Voo* v, Hora hp, Hora hr, bool canc)
    {
        voo = v;
        hora_prevista = hp;
        hora_real = hr;
        cancelado = canc;
    }

    ///Getter do Voo a qual a informacao pertence
    Voo* getVoo() const {
        return voo;
    }

    ///Setter do voo da informacao
    ///@param [in] voo Voo a qual a informcao pertende
    void setVoo(Voo *voo) {
        Informacao::voo = voo;
    }

    ///Getter da Hora prevista do voo
    const Hora &getHoraPrevista() const {
        return hora_prevista;
    }

    ///Setter da Hora prevista do voo de informacao
    ///@param [in] horaPrevista Hora prevista
    void setHoraPrevista(const Hora &horaPrevista) {
        hora_prevista = horaPrevista;
    }

    ///Getter de Hora real do voo de informacao
    const Hora &getHoraReal() const {
        return hora_real;
    }

    ///Setter da Hora real do voo de informacao
    ///@param horaPrevista
    void setHoraReal(const Hora &horaReal) {
        hora_real = horaReal;
    }

    ///Diz se o voo foi cancelado
    bool isCancelado() const {
        return cancelado;
    }

    ///Cancela ou descancela um voo
    void setCancelado(bool cancelado) {
        Informacao::cancelado = cancelado;
    }

    ///Overload do operador << para perminir comando do tipo "cout << informacao"
    ///@param os
    ///@param i
    friend ostream& operator<<(ostream& os, const Informacao& i)
    {
        os << i.getVoo()->getDestino() << ": " << i.getVoo()->getData() << endl;
        os << "Horario previsto: " << i.getHoraPrevista() << endl;
        os << "Horario real: " << i.getHoraReal() << endl;
        os << (i.cancelado ? "Cancelado" : "A tempo") << endl;
        return os;
    }

};


#endif //PROJECT1_INFORMACAO_H
