#ifndef PROJECT1_LISTARAEROPORTOMENU_H
#define PROJECT1_LISTARAEROPORTOMENU_H

#include "MainMenu.h"
#include "../Classes/BinaryTree.h"

///Permite listar os aeroportos de diversas maneiras
class ListarAeroportoMenu: public Menu{
public:
    ///Construtor
    ListarAeroportoMenu();

    ///lista em ordem alfabetica da localizacao
    void porLocalizacao();

    ///lista pela quantidade de funcionarios administrativos
    void porQuantidadeFuncionarioAdministrativo();

    ///lista pela quantidade total de funcionarios
    void porQuantidadeFuncionario();

    ///lista pela quantidade de pilotos
    void porQuantidadePilotos();

    ///lista pela quantidade de membros de tripulacao
    void porQuantidadeMembroTripulacao();

    ///lista pela quantidade de avioes
    void porQuantidadeAvioes();

    ///Lista pelo numero de voos
    void porNumeroVoos();

    ///Lista pelo pais do aeroporto
    void porPais();

    ///Escolhe um aeroporto de acordo com os inputs do usuario
    void escolherAeroporto();

    void CallMenu();

    ///Essa  classe nao usa esta funcao
    void setAeroporto(Aeroporto* a){};

    ///Essa  classe nao usa esta funcao
    void setAviao(Aviao* a){};
};
#endif //PROJECT1_LISTARAEROPORTOMENU_H
