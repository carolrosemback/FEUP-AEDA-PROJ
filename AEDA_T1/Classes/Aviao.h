#ifndef PROJECT1_AVIAO_H
#define PROJECT1_AVIAO_H

#include <iostream>
#include <string>
#include "../Classes/Voo.h"
#include "Aeroporto.h"
#include "../Classes/BinaryTree.h"


///Aviao
class Aviao{
    string tipo;
    int capacidade;
    vector<Voo*> voos;
    vector<Funcionario*> tripulacao; //2 pilotos e 2 membros de cabine
    int custo_operacao;



public:
    ///Construtor de Aviao
    ///@param [in] tipo Modelo do aviao
    ///@param [in] capacidade Quantas pessoas cabem no aviao
    ///@param [in] voos Voos que o aviao esta alocado para realizar
    ///@param [in] funcionarios Funcionarios do aviao
    ///@param [in] custo_operacao Custo de operacao do aviao
    Aviao(string tipo, int capacidade, vector<Voo*> voos, vector<Funcionario*> funcionarios, int custo_operacao)
    {
        this->tipo = tipo;
        this->capacidade = capacidade;
        this->voos = voos;
        this->tripulacao = funcionarios;
        this->custo_operacao = custo_operacao;

    }

    ///Construtor de Aviao
    ///@param [in] tipo Modelo do aviao
    ///@param [in] capacidade Quantas pessoas cabem no aviao
    ///@param [in] voos Voos que o aviao esta alocado para realizar
    ///@param [in] piloto1 Piloto principal do aviao
    ///@param [in] piloto2 Co-piloto do aviao
    ///@param [in] membro_cabine1 Primeiro membro de Cabine do aviao
    ///@param [in] membro_cabine2 Primeiro membro de Cabine do aviao
    ///@param [in] mais_tripulacao Funcionarios do aviao que nao piloto, co-piloto e os dois membros de cabine
    ///@param [in] custo_operacao Custo de operacao do aviao
    Aviao(string tipo, int capacidade, vector<Voo*> voos, Funcionario* piloto1, Funcionario* piloto2,Funcionario* membro_cabine1,Funcionario* membro_cabine2,vector<Funcionario*> mais_tripulacao, int custo_operacao)
    {
        tripulacao.push_back(piloto1);
        tripulacao.push_back(piloto2);
        tripulacao.push_back(membro_cabine1);
        tripulacao.push_back(membro_cabine2);
        tripulacao.insert(tripulacao.end(),mais_tripulacao.begin(),mais_tripulacao.end());
        this->tipo = tipo;
        this->capacidade = capacidade;
        this->voos = voos;
        this->tripulacao = tripulacao;
        this->custo_operacao = custo_operacao;

    }

    ///Getter do vetor Tripulacao do aviao
    vector<Funcionario*> getTripulacao() const{ return tripulacao;}

    ///Adiciona um novo Funcionario ao vetor Tripulacao do aviao
    ///@param [in] funcionario Funcionario a ser adicionado
    void adicionarTripulacao(Funcionario* funcionario)
    {
        tripulacao.push_back(funcionario);
    }

    ///Adiciona um novo voo ao vetor Voos alocados do aviao
    ///@param [in] voo Voo a ser adicionado
    void adicionarVoo(Voo* voo)
    {
        voos.push_back(voo);
    }

    ///Remove um Funcionario do vetor funcionarios do aeroporto
    ///@param [in] f Funcionario a ser removido
    void removerTripulacao(Funcionario* funcionario)
    {
        for(int i = 0; i < tripulacao.size(); i++)
        {
            if(tripulacao.at(i) == funcionario)
            {
                tripulacao.erase(tripulacao.begin()+i);
                break;
            }
        }
    }

    ///Remove um Voo do vetor voos do aeroporto
    ///@param [in] voo Voo a ser removido
    void removerVoo(Voo* voo)
    {
        for(int i = 0; i < voos.size(); i++)
        {
            if(voos.at(i) == voo)
            {
                voos.erase(voos.begin()+i);
                break;
            }
        }
    }

    ///Getter do modelo do aviao
    const string &getTipo() const {
        return tipo;
    }

    ///Setter do modelo do aviao
    ///@param [in] tipo novo modelo do aviao
    void setTipo(const string &tipo) {
        Aviao::tipo = tipo;
    }

    ///Getter da capicade do aviao
    int getCapacidade() const {
        return capacidade;
    }

    ///Setter da capacidade do aviao
    ///@param [in] tipo novo modelo do aviao
    void setCapacidade(int capacidade) {
        Aviao::capacidade = capacidade;
    }

    ///Getter do vetor de voos do aviao
    vector<Voo*> getVoos() const{
        return voos;
    }

    ///Setter do vetor de voos do aviao
    ///@param [in] voos novo vetor de voos do aviao
    void setVoos(const vector<Voo*> voos) {
        Aviao::voos = voos;
    }

    ///Getter do custo de operacao do aviao
    int getCustoOperacao() const {
        return custo_operacao;
    }

    ///Setter do custo de operacao do aviao
    ///@param [in] novo custoOperacao do aviao
    void setCustoOperacao(int custoOperacao) {
        custo_operacao = custoOperacao;
    }

    ///Overload do operador << para possibilitar o comando "cout << aviao"
    ///@param [in] os ostream no qual sera escrito
    ///@param [in] a aviao a ser escrito
    friend ostream& operator<<(ostream& os, const Aviao& a);


    ///Getter do tempo medio
    int getTempoMedio()
    {
        int tempMedio =0;
        tempMedio = getTempoTotal()/(voos.size());
        return tempMedio;
    }

    int getTempoTotal()
    {
        int tempTotal;
        for(int i= 0; i < voos.size(); i++)
            tempTotal += voos[i]->getTempoPista();
        return tempTotal;
    }
};

#endif //PROJECT1_AVIAO_H
