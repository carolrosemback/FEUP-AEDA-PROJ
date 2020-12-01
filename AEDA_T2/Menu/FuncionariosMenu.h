#ifndef PROJECT1_FUNCIONARIOSMENU_H
#define PROJECT1_FUNCIONARIOSMENU_H

#include "Menu.h"

enum tipos_funcionarios
{
    TODOS,
    ADMINISTRATIVO,
    PILOTO,
    MEMBRO_TRIPULACAO
};

///Menu com o CRUD dos Funcionario de um aerporto especifico
class FuncionariosMenu:public Menu{
    enum tipos_funcionarios tipo;
    Aeroporto* a;

public:
    ///construtor da classe funcionario
    ///@param t
    FuncionariosMenu(enum tipos_funcionarios t);

    void CallMenu();

    ///funcao que cria um funcao administrativo
    void criarFuncionarioAdministrativo();

    ///funcao que cria um piloto
    void criarPiloto();

    ///funcao que cria um membro tripulacao
    void criarMembroTripulacao();

    ///funcao que edita funcionario administrativo
    void editarFuncionarioAdministrativo();

    ///funcao que edita piloto
    void editarPiloto();

    ///funcao que edita membro tripulacao
    void editarMembroTripulacao();

    ///funcao que deleta funcionario administrativo
    void deletarFuncionarioAdministrativo();

    ///funcao que deleta piloto
    void deletarPiloto();

    ///funcao que deleta membro tripulacao
    void deletarMembroTripulacao();

    ///funcao que lista todos os funcionarios
    void listarFuncionarios();

    ///funcao que acha o funcionario dentro do vetor
    Funcionario_administrativos* acharFuncionarioAdministrativo();

    ///funcao que acha o funcionario dentro do vetor
    Piloto* acharPiloto();

    ///funcao que acha o funcionario dentro do vetor
    Membro_tripulacao* acharMembroTripulacao();

    ///setter do aeroporto
    ///@param a
    void setAeroporto(Aeroporto* a);

    ///setter do aviao
    ///@param a
    void setAviao(Aviao* a){};
};

#endif //PROJECT1_FUNCIONARIOSMENU_H
