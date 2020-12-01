#ifndef PROJECT1_MENU_H
#define PROJECT1_MENU_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include<iomanip>
#include <iostream>
#include "../Classes/Empresa.h"
#include "../Classes/Aeroporto.h"
#include "../Utils/sorts.h"
#include "../Utils/lower.h"
#include "../Utils/split.h"

using namespace std;

///Classe Abstrata Menu com funcoes comuns a todos os menus
class Menu {
protected:
    vector<string> opcoes;
    int input;
public:
    ///Construtor vazio de Menu
    Menu()= default;

    ///Apresenta as opcoes ao usuario
    void print();

    ///Roda o menu
    void play();

    ///Pede ao usuario um input
    void getInput();

    ///Faz a acao devida de acordo com o input do usuario
    virtual void CallMenu() = 0;

    ///Algumas subclasses de Menu possuem um atributo aeroporto
    virtual void setAeroporto(Aeroporto* a) = 0;

    ///Algumas subclasses de Menu possuem um atributo aviao
    virtual void setAviao(Aviao* a) = 0;

    ///Guarda os dados em um arquivo de texto
    void save();

    ///Carrega os dados do arquivo de texto
    void load();

    ///Espera por qualquer input do usuário
    void wait();
};

#endif //PROJECT1_MENU_H
