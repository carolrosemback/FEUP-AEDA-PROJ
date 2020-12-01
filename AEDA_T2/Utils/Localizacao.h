#ifndef PROJECT1_LOCALIZACAO_H
#define PROJECT1_LOCALIZACAO_H

#include <iostream>
#include <string>
#include "split.h"
#include "GPS.h"

///Localizacao
class Localizacao{
    string pais;
    string cidade;
    GPS cordenadas;
public:
    ///construtor de localizacao
    Localizacao()= default;

    ///contrutor de localizacao com parametros
    ///@param pais
    ///@param cidade
    ///@param coord
    Localizacao(string pais, string cidade, GPS coord)
    {
        cordenadas = coord;
        this->pais = pais;
        this->cidade = cidade;
    }

    ///getter de pasi
    const string &getPais() const {
        return pais;
    }

    ///setter de pais
    ///@param pais
    void setPais(const string &pais) {
        Localizacao::pais = pais;
    }

    ///getter da cidade
    const string &getCidade() const {
        return cidade;
    }

    ///setter da cidade
    ///@param cidade
    void setCidade(const string &cidade) {
        Localizacao::cidade = cidade;
    }

    ///getter da coordenada
    const GPS &getCordenadas() const {
        return cordenadas;
    }

    ///setter da coordenada
    ///@param cordenadas
    void setCordenadas(const GPS &cordenadas) {
        Localizacao::cordenadas = cordenadas;
    }

    ///implementacao do operator <<
    ///@param l
    ///@param os
    friend ostream& operator<<(ostream& os, const Localizacao& l)
    {
        os << l.cidade << ", " << l.pais << " " <<  l.cordenadas;
        return os;
    }

};

#endif //PROJECT1_LOCALIZACAO_H
