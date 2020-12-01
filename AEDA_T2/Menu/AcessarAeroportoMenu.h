#ifndef PROJECT1_ACESSARAEROPORTOMENU_H
#define PROJECT1_ACESSARAEROPORTOMENU_H

#include "Menu.h"

///Menu com o CRUD de um aeroporto especifico
class AcessarAeroportoMenu: public Menu{
    Aeroporto* aeroporto;
public:
    ///Construtor
    AcessarAeroportoMenu();

    void CallMenu();

    ///Altera o gerente do aeroporto com os inputs do usuario
    void alterarGerente();

    ///Altera a localizacao do aeroporto com os inputs do usuario
    void alterarLocalizacao();

    ///Define o aeroporto a qual o menu esta acessando
    void setAeroporto(Aeroporto* a);

    ///Essa  classe nao usa esta funcao
    void setAviao(Aviao* a){};
};

#endif //PROJECT1_ACESSARAEROPORTOMENU_H
