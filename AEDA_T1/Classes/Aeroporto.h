#ifndef PROJECT1_AEROPORTO_H
#define PROJECT1_AEROPORTO_H

#include <iostream>
#include "Funcionario.h"
#include "../Utils/Localizacao.h"
#include "Aviao.h"
#include "../Classes/BinaryTree.h"

///Aeroporto da rede O connor
class Aeroporto{
    Funcionario* gerente;
    Localizacao localizacao;
    vector<Funcionario*> funcionarios;
    vector<Aviao*> avioes;
    vector<Piloto*> pilotos;
    vector<Membro_tripulacao*> membros;
    vector<Funcionario_administrativos*> funcionarios_administrativos;


public:
    ///Construtor de Aeroporto
    ///@param [in] ger Gerente do aeroporto
    ///@param [in] loc Localizacao do aeroporto
    ///@param [in] fu Vetor com todos os funcionarios do aeroporto
    ///@param [in] av Avioes do aerporto
    ///@param [in] pil Pilotos do aerporto
    ///@param [in] mem Membros de Tripulacao do aeroporto
    ///@param [in] f_adm Funcionarios Administrativos do aeroporto
    Aeroporto(Funcionario* ger, Localizacao loc, vector<Funcionario*> fu, vector<Aviao*> av, vector<Piloto*> pil, vector<Membro_tripulacao*> mem, vector<Funcionario_administrativos*> f_adm );

    ///Getter do gerente do aeroporto
    Funcionario* getGerente() const;

    ///Getter da localizacao do aeroporto
    Localizacao getLocalizacao() const;

    ///Setter da localizacao
    ///@param [in] p Pais da nova localizacao
    ///@param [in] c Cidade da nova localizacao
    ///@param [in] g GPS(lat,long) da nova localizacao
    void setLocalizacao(string p, string c, GPS g);

    ///Setter do gerente
    ///@param [in] f Funcionario que sera o novo gerente
    void setGerente(Funcionario* f);

    ///Adiciona um novo Funcionario ao vetor funcionarios do aeroporto
    ///@param [in] f Funcionario a ser adicionado
    void adicionarFuncionario(Funcionario* f);

    ///Adiciona um novo Piloto ao vetor funcionarios do aeroporto e ao de funcionarios
    ///@param [in] p Piloto a ser adicionado
    void adicionarPiloto(Piloto* p);

    ///Adiciona um novo Aviao ao vetor avioes do aeroporto
    ///@param [in] a Aviao a ser adicionado
    void adicionarAviao(Aviao* a);

    ///Adiciona um novo Memebro de tripulacao ao vetor Memebros de tripulacao do aeroporto e ao de funcionarios
    ///@param [in] m Membro de tripulacao a ser adicionado
    void adicionarMembro(Membro_tripulacao* m);

    ///Adiciona um novo Funcionario administrativo ao vetor Funcionarios administrativos do aeroporto e ao de funcionarios
    ///@param [in] f Funcionario administrativo a ser adicionado
    void adicionarFuncionarioAdministrativo(Funcionario_administrativos* f);

    ///Remove um Funcionario do vetor funcionarios do aeroporto
    ///@param [in] f Funcionario a ser removido
    void removerFuncionario(Funcionario* f);

    ///Remove um Piloto do vetor pilotos do aeroporto e do de funcionarios
    ///@param [in] p Piloto a ser removido
    void removerPiloto(Piloto* p);

    ///Remove um Aviao do vetor Avioes do aeroporto
    ///@param [in] a Aviao a ser removido
    void removerAviao(Aviao* a);

    ///Remove um Membro de tripulacao do vetor membros de tripulacao do aeroporto e do de funcionarios
    ///@param [in] m Membro de tripulacao a ser removido
    void removerMembro(Membro_tripulacao* m);

    ///Remove um Funcionario administrativo do vetor Funcionarios Adinistrativos do aeroporto e do de funcionarios
    ///@param [in] f Funcionario administrativo a ser removido
    void removerFuncionarioAdministrativo(Funcionario_administrativos* f);

    ///Overload do operador << para possibilitar o comando "cout << aeroporto"
    ///@param [in] os osstream no qual sera escrito
    ///@param [in] a aeroporto a ser escrito
    friend ostream& operator<<(ostream& os, const Aeroporto& a);

    ///Getter do vetor funcionarios
    vector<Funcionario*> & getFuncionarios();

    ///Getter do vetor avioes
    vector<Aviao*> & getAvioes();

    ///Getter do vetor pilotos
    vector<Piloto*> & getPilotos();

    ///Getter do vetor membros de tripulacao
    vector<Membro_tripulacao*> & getMembros();

    ///Getter vetor Funcionarios Administrativos
    vector<Funcionario_administrativos*> & getFuncionariosAdministrativos();

    ///Getter do numero do paragens no aeroporto
    int getParagens() const;

    ///Getter do tempo medio
    int getTempoMedio();

    bool operator < (Aeroporto &a1);

    bool operator == (Aeroporto &a1);

};

#endif //PROJECT1_AEROPORTO_H