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

using namespace std;
extern map<string, Menu*> menus_to_call;
extern vector<Aeroporto*> aeroportos;

int main() {
/*
    Voo v(Data(20,11,2019),Hora(10,00,00),"Curitiba");
    Informacao i(&v,Hora(10,00,00),Hora(10,10,00),false);
    v.setInfo(&i);
    Membro_tripulacao m({&v},{&i});
    Funcionario_administrativos f("Gisele",Data(30,01,1990),"Master",pair<Hora,Hora>(Hora(8,00,00),Hora(17,0,0)),"Diretora","Financeiro");
    Aviao a("Boing747",500,{&v},{&m},10000);
    Piloto p("Sergio",Data(20,06,1958),"principal",{&a},{&v});
    Aeroporto ae(&f,Localizacao("Brasil","Rio de Janeiro",GPS(-22.908333,-43.196388)),{&p,&f,&m},{&a},{&p},{&m},{&f});
    aeroportos.push_back(&ae);

    Voo v2(Data(23,12,2019),Hora(17,00,00),"Rio de Janeiro");
    Informacao i2(&v2,Hora(17,00,00),Hora(17,10,00),false);
    v2.setInfo(&i2);
    Membro_tripulacao m2({&v2},{&i2});
    Funcionario_administrativos f2("Joana",Data(12,05,1975),"Gold",pair<Hora,Hora>(Hora(10,30,00),Hora(20,30,0)),"Secretaria","Administrativo");
    Aviao a2("Airbus 970",950,{&v2},{&m2},17500);
    Piloto p2("Rogerio",Data(15,9,1976),"Co-piloto",{&a2},{&v2});
    Aeroporto ae2(&f,Localizacao("Brasil","Curitiba",GPS(-25.441105,-49.276855)),{&p2,&f2,&m2},{&a2},{&p2},{&m2},{&f2});
    aeroportos.push_back(&ae2);
*/
    menus_to_call.insert(pair<string,Menu*>("MainMenu",new MainMenu));
    menus_to_call.insert(pair<string,Menu*>("ListarAeroportoMenu",new ListarAeroportoMenu));
    menus_to_call.insert(pair<string,Menu*>("AcessarAeroportoMenu",new AcessarAeroportoMenu));
    menus_to_call.insert(pair<string,Menu*>("TodosFuncionariosMenu",new FuncionariosMenu(TODOS)));
    menus_to_call.insert(pair<string,Menu*>("PilotosFuncionariosMenu",new FuncionariosMenu(PILOTO)));
    menus_to_call.insert(pair<string,Menu*>("FuncionariosAdministrativosMenu",new FuncionariosMenu(ADMINISTRATIVO)));
    menus_to_call.insert(pair<string,Menu*>("MembrosTripulacaoFuncionariosMenu",new FuncionariosMenu(MEMBRO_TRIPULACAO)));
    menus_to_call.insert(pair<string,Menu*>("AviaoMenu",new AviaoMenu));
    menus_to_call.insert(pair<string,Menu*>("VooMenu",new VooMenu));

    menus_to_call["MainMenu"]->load();
    menus_to_call["MainMenu"]->play();

    return 0;
}