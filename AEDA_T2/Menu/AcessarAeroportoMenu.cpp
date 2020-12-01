#include "AcessarAeroportoMenu.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;

AcessarAeroportoMenu::AcessarAeroportoMenu() {
    opcoes = {"Alterar gerente", "Alterar localizacao", "Acessar todos os funcionarios", "Acessar pilotos", "Acessar funcionarios administrativos", "Acessar membros da tripulacao", "Acessar Avioes", "Voltar"};
}

void AcessarAeroportoMenu::alterarGerente() {
    string inp;
    cout << "Novo gerente sera que tipo de funcionario(Administrativo, Piloto, Membro tripulacao):";
    cin.ignore(1024,'\n');
    getline(cin,inp);
    while(lower(inp) != "administrativo" && lower(inp) != "piloto" && lower(inp) != "membro tripulacao")
    {
        cout << "O tipo de funcionario so pode ser Administrativo, piloto ou mebro tripulacao. Diga um dos tres." << endl;
        getline(cin, inp);
    }
    if(lower(inp) == "administrativo")
    {
        while(1)
        {
            cout << "Nome do funcionario que sera o gerente: ";
            getline(cin, inp);
            bool found = false;
            for(Funcionario_administrativos* funcionario : aeroporto->getFuncionariosAdministrativos())
            {
                if(lower(funcionario->getNome()) == lower(inp))
                {
                    aeroporto->setGerente(funcionario);
                    found = true;
                    break;
                }
            }
            if(found)
                break;
            cout << "Nome inserido nao corresponde a nenhum funcionario" << endl;
        }
    }
    else if(lower(inp) == "piloto")
    {
        while(1)
        {
            cout << "Nome do piloto que sera o gerente: ";
            getline(cin, inp);
            bool found = false;
            for(Piloto* funcionario : aeroporto->getPilotos())
            {
                if(lower(funcionario->getNome()) == lower(inp))
                {
                    aeroporto->setGerente(funcionario);
                    found = true;
                    break;
                }
            }
            if(found)
                break;
            cout << "Nome inserido nao corresponde a nenhum piloto" << endl;
        }
    }
    else
    {
        while(1)
        {
            cout << "Destino de um voo do membro que sera o gerente: ";
            getline(cin, inp);
            bool found = false;
            for(Membro_tripulacao* funcionario : aeroporto->getMembros())
            {
                bool b = false;
                for(Voo* voo: funcionario->getVoos())
                {
                    if(lower(voo->getDestino()) == lower(inp))
                    {
                        aeroporto->setGerente(funcionario);
                        found = true;
                        b = true;
                        break;
                    }
                }
                if(b)
                    break;

            }
            if(found)
                break;
            cout << "Nome inserido nao corresponde a nenhum funcionario" << endl;
        }
    }
    menus_to_call["AcessarAeroportoMenu"]->play();
}

void AcessarAeroportoMenu::CallMenu() {
    switch(input)
    {
        case 0:
        {
            alterarGerente();
            break;
        }
        case 1:
        {
            alterarLocalizacao();
            break;
        }
        case 2:
        {
            menus_to_call["TodosFuncionariosMenu"]->setAeroporto(aeroporto);
            menus_to_call["TodosFuncionariosMenu"]->play();
            break;
        }
        case 3:
        {
            menus_to_call["PilotosFuncionariosMenu"]->setAeroporto(aeroporto);
            menus_to_call["PilotosFuncionariosMenu"]->play();
            break;
        }
        case 4:
        {
            menus_to_call["FuncionariosAdministrativosMenu"]->setAeroporto(aeroporto);
            menus_to_call["FuncionariosAdministrativosMenu"]->play();
            break;
        }
        case 5:
        {
            menus_to_call["MembrosTripulacaoFuncionariosMenu"]->setAeroporto(aeroporto);
            menus_to_call["MembrosTripulacaoFuncionariosMenu"]->play();
            break;
        }
        case 6:
        {
            menus_to_call["AviaoMenu"]->setAeroporto(aeroporto);
            menus_to_call["AviaoMenu"]->play();
            break;
        }
        case 7:{
            menus_to_call["MainMenu"]->play();
            break;
        }
    }
}

void AcessarAeroportoMenu::alterarLocalizacao() {
    string pais, cidade;
    float latitude, longitude;
    cin.ignore(1024, '\n');
    cout << "Qual o pais da nova localizacao: ";
    getline(cin, pais);
    cout << "Qual a cidade da nova localizacao: ";
    getline(cin, cidade);
    while(1)
    {
        cout << "Qual a latitude da nova localizacao: ";
        cin >> latitude;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Latitude tem que ser um float." << endl;
            cout << "Insira a nova latitude: ";
            cin >> latitude;
        }
        cout << "Qual a longitude da nova localizacao: ";
        cin >> longitude;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Longitude tem que ser um float." << endl;
            cout << "Insira a nova Longitude: ";
            cin >> longitude;
        }
        try
        {
            GPS gps(latitude, longitude);
            break;
        }
        catch (runtime_error r)
        {
            cout << "Latitude e longitude precisam estar entre -90 e 90" << endl;
        }
    }

    GPS gps(latitude, longitude);
    aeroporto->setLocalizacao(pais, cidade, gps);
    menus_to_call["AcessarAeroportoMenu"]->play();
}

void AcessarAeroportoMenu::setAeroporto(Aeroporto* a)
{
    aeroporto = a;
}

