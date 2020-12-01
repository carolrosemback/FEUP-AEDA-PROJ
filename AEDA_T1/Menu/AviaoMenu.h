#ifndef PROJECT1_AVIAOMENU_H
#define PROJECT1_AVIAOMENU_H

#include "Menu.h"

///Menu com o CRUD dos avioes de um aeroporto
class AviaoMenu:public Menu{
    Aeroporto* aeroporto;
public:
    ///Escolhe um aviao baseado nos inputs do usuario
    ///@return Aviao escolhido
    Aviao* escolherAviao();

    ///Construtor
    AviaoMenu();

    void CallMenu();

    ///Cria um novo aviao baseado nos inputs do usuario
    void criarAviao();

    ///Edita o modelo do aviao com base nos inputs do usuario
    void editarTipo();

    ///Edita a capacidade do aviao com base nos inputs do usuario
    void editarCapacidade();

    ///Cria um voo para o aviao com base nos inputs do usuario
    ///@return Voo criado
    Voo* criarVoo();

    ///Cria um membro de tripulacao para o aviao com base nos inputs do usuario
    ///@return Membro criado
    Membro_tripulacao* criarMembroTripulacao(vector<Voo*> v);

    ///Cria um piloto para o aviao com base nos inputs do usuario
    ///@return Piloto criado
    Piloto* criarPiloto(vector<Voo*> v);

    ///Define o aeroporto a qual o menu esta acessando
    void setAeroporto(Aeroporto* a);

    ///Essa  classe nao usa esta funcao
    void setAviao(Aviao* a){};

    ///Mostra uma lista com todos os avioes do aeroporto
    void listarAvioes();
};

#endif //PROJECT1_AVIAOMENU_H
