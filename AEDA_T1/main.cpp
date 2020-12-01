#include <iostream>
#include <vector>
#include "Menu/Menu.h"
#include "Menu/MainMenu.h"
#include "Menu/ListarAeroportoMenu.h"
#include "Menu/AcessarAeroportoMenu.h"
#include "Menu/FuncionariosMenu.h"
#include "Menu/AviaoMenu.h"
#include "Menu/VooMenu.h"
#include "Classes/Informacao.h"
#include "Classes/Aviao.h"
#include "Menu/EmpresaMenu.h"

using namespace std;
extern map<string, Menu*> menus_to_call;
extern vector<Aeroporto*> aeroportos;
extern priority_queue<Empresa> empresas;
extern unordered_set<Funcionario*,hash_func,equality_func> tab_funcionarios;

int main() {

    menus_to_call.insert(pair<string,Menu*>("MainMenu",new MainMenu));
    menus_to_call.insert(pair<string,Menu*>("ListarAeroportoMenu",new ListarAeroportoMenu));
    menus_to_call.insert(pair<string,Menu*>("AcessarAeroportoMenu",new AcessarAeroportoMenu));
    menus_to_call.insert(pair<string,Menu*>("TodosFuncionariosMenu",new FuncionariosMenu(TODOS)));
    menus_to_call.insert(pair<string,Menu*>("PilotosFuncionariosMenu",new FuncionariosMenu(PILOTO)));
    menus_to_call.insert(pair<string,Menu*>("FuncionariosAdministrativosMenu",new FuncionariosMenu(ADMINISTRATIVO)));
    menus_to_call.insert(pair<string,Menu*>("MembrosTripulacaoFuncionariosMenu",new FuncionariosMenu(MEMBRO_TRIPULACAO)));
    menus_to_call.insert(pair<string,Menu*>("AviaoMenu",new AviaoMenu));
    menus_to_call.insert(pair<string,Menu*>("VooMenu",new VooMenu));
    menus_to_call.insert(pair<string, Menu*>("EmpresaMenu", new EmpresaMenu));

    menus_to_call["MainMenu"]->load();
    menus_to_call["MainMenu"]->play();

    return 0;
}