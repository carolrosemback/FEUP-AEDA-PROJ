#ifndef PROJECT1_EMPRESAS_H
#define PROJECT1_EMPRESAS_H

#include <iostream>
#include <queue>

using namespace std;

class Empresa{
    int disponibilidade; //numero de horas que falta para que esteja disponivel
    int manutencoes; //numero de manutenccoes ja feitas
    static const int duracao = 3; //tempo de manutencao de cada veiculo
     //ordenada de acordo com a disponibilidade
    //a do topo é a mais disponvivil
public:
    bool operator< (Empresa & e);
    void somaDisponibilidade(Empresa e);
};




#endif //PROJECT1_EMPRESAS_H
