#ifndef PROJECT1_EMPRESAS_H
#define PROJECT1_EMPRESAS_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Empresa{
    int id;
    int disponibilidade; //numero de horas que falta para que esteja disponivel
    int manutencoes; //numero de manutenccoes ja feitas
    //static const int duracao = 3; //tempo de manutencao de cada veiculo
     //ordenada de acordo com a disponibilidade
    //a do topo é a mais disponvivil
public:
    Empresa(int id, int disponibilidade, int manutencoes);
    int getId() const;
    void setId(int n);
    int getDisponibilidade() const;
    void setDisponibilidade(int n);
    void setManutencao(int n);
    int getManutencao();
    bool operator< (Empresa e) const;
    friend ostream& operator<<(ostream& os, Empresa e);
};

class EmpresaJaExiste{
    int id;
public:
    EmpresaJaExiste(int i){id = i;}
};




#endif //PROJECT1_EMPRESAS_H
