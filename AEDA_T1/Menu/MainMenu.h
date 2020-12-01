#ifndef PROJECT1_MAINMENU_H
#define PROJECT1_MAINMENU_H

#include "Menu.h"

///Primeiro menu apresentado ao usuario
class MainMenu :public Menu{
public:

    ///Construtor
    MainMenu();

    ///Cria Aeroporto de acordo com os inputs do usario
    void criarAeroporto();

    ///Remove um aeroporto de acordo com os inputs do usarios
    void deletarAeroporto();

    void verFuncionarios();

    void CallMenu();

    ///Define o aeroporto a qual o menu esta acessando
    Aeroporto* escolherAeroporto();

    ///Essa  classe nao usa esta funcao
    void setAeroporto(Aeroporto* a){};

    ///Essa  classe nao usa esta funcao
    void setAviao(Aviao* a){};
};

#endif //PROJECT1_MAINMENU_H
