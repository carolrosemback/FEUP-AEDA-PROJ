#ifndef PROJECT1_VOOMENU_H
#define PROJECT1_VOOMENU_H

#include "Menu.h"
#include "../Utils/split.h"

///Menu com o CRUD dos voos
class VooMenu:public Menu{
    Aviao* a;
    Aeroporto* aeroporto;
public:

    ///Construtor
    VooMenu();

    ///Apresenta um voo especifico
    void visualizarVoo();

    ///Esolhe um voo de acordo com os inputs do usaurio
    ///@return Voo escolhido
    Voo* escolherVoo();

    ///Altera a data de um voo de acordo com os inputs do usaurio
    void alterarData();

    ///Altera a hora de um voo de acordo com os inputs do usaurio
    ///@return Hora alterada
    Hora alterarHora();

    ///Altera a Hora prevista de um voo de acordo com os inputs do usaurio
    void alterarHoraPrevista();

    ///Altera a hora real de um voo de acordo com os inputs do usaurio
    void alterarHoraReal();

    ///Altera o destino de um voo de acordo com os inputs do usaurio
    void alterarDestino();

    ///Altera o estado de um voo de acordo com os inputs do usaurio
    void alterarEstado();

    ///Altera o tempo de pista de um voo de acordo com os inputs do usaurio
    void alterarTempoPista();

    ///Cria um novo voo de acordo com os inputs do usaurio
    void criarVoo();


    void CallMenu();

    ///Essa  classe nao usa esta funcao
    void setAeroporto(Aeroporto* a){};

    ///Define o aviao a qual o menu esta acessando
    void setAviao(Aviao* a);

    ///Apresenta todos os voos desse aviao
    void listarVoos();
};

#endif //PROJECT1_VOOMENU_H
