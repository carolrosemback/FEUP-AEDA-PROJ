#include "ListarAeroportoMenu.h"


extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;
extern BST<Aeroporto*> ArvAeroporto;

ListarAeroportoMenu::ListarAeroportoMenu(){
    opcoes = {"Listar por localizacao", "Listar por quantidade de funcionario", "Listar por quantidade de funcionario administrativo",
              "Listar por quantidade de pilotos", "Listar por quantidade de Membro de tripulacao", "Listar por quantidade de avioes",
              "Escolher um aeroporto", "Numeros de voos", "Voltar"};
}

void ListarAeroportoMenu::CallMenu() {
    switch(input){
        case 0:
        {
            porLocalizacao();
            break;
        }
        case 1:
        {
            porQuantidadeFuncionario();
            break;
        }
        case 2:
        {
            porQuantidadeFuncionarioAdministrativo();
            break;
        }
        case 3:
        {
            porQuantidadePilotos();
            break;
        }
        case 4:
        {
            porQuantidadeMembroTripulacao();
            break;
        }
        case 5:
        {
            porQuantidadeAvioes();
            break;
        }
        case 6:
        {
            escolherAeroporto();
            break;
        }
        case 7:
        {
            porNumeroVoos();
            break;
        }
        case 8:
        {
            menus_to_call["MainMenu"]->play();
            return;
        }
    }
    cin.ignore(1024,'\n');
    wait();
    menus_to_call["ListarAeroportoMenu"]->play();
}

void ListarAeroportoMenu::porLocalizacao()
{
    sort(aeroportos.begin(), aeroportos.end(), compLocalizacao);
    for(int i=0; i< aeroportos.size(); i++)
    {
        cout << "::::::::::::::::::::::::::" << endl;
        cout << *aeroportos.at(i);
    }

}

void ListarAeroportoMenu::porQuantidadeFuncionarioAdministrativo()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadeFuncionariosAdministrativos);
    for(int i = 0; i< aeroportos.size(); i++)
    {
        cout << "::::::::::::::::::::::::::" << endl;
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::porQuantidadeFuncionario()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadefuncionarios);
    for(int i = 0; i < aeroportos.size(); i++)
    {
        cout << "::::::::::::::::::::::::::" << endl;
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::porQuantidadePilotos()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadePilotos);
    for(int i = 0; i< aeroportos.size(); i++)
    {
        cout << "::::::::::::::::::::::::::" << endl;
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::porQuantidadeMembroTripulacao()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadeMembroTripulacao);
    for(int i = 0; i< aeroportos.size(); i++)
    {
        cout << "::::::::::::::::::::::::::" << endl;
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::porQuantidadeAvioes()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadeAvioes);
    for(int i = 0; i<aeroportos.size(); i++)
    {
        cout << "::::::::::::::::::::::::::" << endl;
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::escolherAeroporto()
{
    while (1)
    {
        string p, c;
        cout << "Pais no qual o aeroporto esta localizado: ";
        cin.ignore(1024, '\n');
        getline(cin, p);
        cout << "Cidade do aeroporto: ";
        getline(cin, c);
        for (int i = 0; i < aeroportos.size(); i++) {
            if (lower(aeroportos.at(i)->getLocalizacao().getPais()) == lower(p) && lower(aeroportos.at(i)->getLocalizacao().getCidade()) == lower(c)) {
                cout << *aeroportos.at(i);
                return;
            }
        }
        cout << "Parametros dados nao indicam nenhum aeroporto" << endl;
    }
}

void ListarAeroportoMenu::porNumeroVoos()
{
    ArvAeroporto.printTree();
}