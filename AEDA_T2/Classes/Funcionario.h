#ifndef PROJECT1_FUNCIONARIO_H
#define PROJECT1_FUNCIONARIO_H

#include "../Utils/split.h"
#include "../Utils/Data.h"
#include "../Utils/Hora.h"
#include "../Classes/Voo.h"
#include <iostream>
#include <utility>


using namespace std;

class Aviao;

///Classe abstrata funcionario de aeroporto
class Funcionario{
protected:
    int salario;
public:
    ///contutor da classe funcionario
    ///@param salario
    Funcionario(int salario);

    ///getter do salario
    int getSalario() const;

    ///setter do Salario
    ///@param s
    void setSalario(int s){salario=s;};

    ///class pure virctual criada par printar os funcionario
    virtual void print() = 0;
};

///Funcionario Administrativo de Aerporto
class Funcionario_administrativos :public Funcionario{
    string nome;
    Data data_nascimento;
    string categoria;
    pair<Hora,Hora> horario_de_trabalho;
    string funcao;
    string departamento;
    bool atual; //true se for atual
public:
    ///construtor da classe funcionario administrativo
    ///@param nome
    ///@param nome
    ///@param data_nascimento
    ///@param categoria
    ///@param horario_de_trabalho
    ///@param funcao
    ///@param departamento
    Funcionario_administrativos(const string& nome,const Data& data_nascimento,const string& categoria,const pair<Hora,Hora> horario_de_trabalho,const string &funcao, const string &departamento);

    ///getter da funcao
    string getFuncao() const;

    ///setter da funcao
    ///@param funcao
    void setFuncao(const string &funcao);

    ///getter do departamento
    string getDepartamento() const;

    ///setter do departamento
    ///@param departamento
    void setDepartamento(const string &departamento);

    ///printter do funcionario administrativo
    void print();

    ///getter do nome
    const string &getNome() const;

    ///setter do nome
    ///@param nome
    void setNome(const string &nome);

    ///getter da data de nascimento
    const Data &getDataNascimento() const;

    ///setter da data de nascimento
    ///@param dataNascimento
    void setDataNascimento(const Data &dataNascimento);

    ///getter da categoria
    const string &getCategoria() const;

    ///setter da categoria
    ///@param categoria
    void setCategoria(const string &categoria);

    ///getter do horario de trabalho
    const pair<Hora,Hora> &gethorario_de_trabalho() const;

    ///setter do horario de trabalho
    ///@param horario_de_trabalho
    void setHorarioDeTrabalho(const pair<Hora,Hora> &horario_de_trabalho);
};

///Membro de tripulacao de aerporto
class Membro_tripulacao :public Funcionario{
    vector<Voo*> voos_alocados;
    vector<Informacao*> info_voos;
public:
    ///contrutor da classe membro tripulacao
    ///@param voosAlocados
    ///@param infoVoos
    Membro_tripulacao(const vector<Voo*> & voosAlocados, const vector<Informacao*> &infoVoos);

    ///getter dos voos
    vector<Voo*> getVoos();

    ///getter das infos
    vector<Informacao*> getInfos();

    ///print da classe membro tripulacao
    void print();

    ///funcao que adiciona o voo ao final do vetor de voos
    ///@param v
    void adicionarVoo(Voo* v){voos_alocados.push_back(v);}

    ///funcao que adiciona a informacao no fincal do vetor de informacoes
    ///@param i
    void adicionarInfo(Informacao* i){info_voos.push_back(i);}
};

///Piloto de aerporto
class Piloto :public Funcionario{
    string nome;
    Data data_nascimento;
    string categoria;
    vector<Aviao*> tipos_aviao; //vetor com tipos de aviao habilitado a pilotar
    vector<Voo*> voos_realizados;
public:
    ///getter de voos
    vector<Voo*> getVoos(){ return voos_realizados;};

    ///getter de avioes
    vector<Aviao*> getAvioes(){ return tipos_aviao;};

    ///construtor da classe pilotp
    ///@param categoria
    ///@param nome
    ///@param dataNascimento
    ///@param tiposAviao
    ///@param voosRealizados
    Piloto(const string &nome, const Data &dataNascimento, const string &categoria,
           const vector<Aviao*> &tiposAviao, const vector<Voo*> & voosRealizados);

    ///getter do nome
    const string &getNome() const;

    ///setter do nome
    ///@param nome
    void setNome(const string &nome);

    ///getter da data de nascimento
    const Data &getDataNascimento() const;

    ///setter da data de nascimento
    ///@param dataNascimento
    void setDataNascimento(const Data &dataNascimento);

    ///getter da categora
    const string &getCategoria() const;

    ///setter da categora
    ///@param categoria
    void setCategoria(const string &categoria);

    ///funcao que adiciona voo no final do vetor de voos
    ///@param v
    void adicionarVoo(Voo* v){voos_realizados.push_back(v);salario+=250;}

    ///funcao que adiciona Aviao no final do vetor de avioes
    ///@param a
    void adicionarAviao(Aviao* a){tipos_aviao.push_back(a);}

    ///funcao que printa o piloto
    void print();
};

#endif //PROJECT1_FUNCIONARIO_H
