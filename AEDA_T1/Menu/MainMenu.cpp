#include "MainMenu.h"
#include "../Classes/Aviao.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;
extern priority_queue<Empresa> empresas;
extern unordered_set<Funcionario*,hash_func,equality_func> tab_funcionarios;

MainMenu::MainMenu() {
    opcoes = {"Ver todos os funcionarios", "Criar aeroporto","Listar aeroportos","Acessar aeroporto", "Remover Aeroporto", "Acessar empresas de manutencao", "Sair"};
}

void MainMenu::CallMenu() {
    switch(input)
    {
        case 0:
        {
            verFuncionarios();
            break;
        }
        case 1:
        {
            criarAeroporto();
            break;
        }
        case 2:
        {
            menus_to_call["ListarAeroportoMenu"]->play();
            break;
        }
        case 3:
        {
            Aeroporto* a = escolherAeroporto();
            if(a == NULL)
            {
                menus_to_call["MainMenu"]->play();
                break;
            }
            menus_to_call["AcessarAeroportoMenu"]->setAeroporto(a);
            menus_to_call["AcessarAeroportoMenu"]->play();
            break;
        }
        case 4:
        {
            deletarAeroporto();
            menus_to_call["MainMenu"]->play();
            break;
        }
        case 5:
        {
            menus_to_call["EmpresaMenu"]->play();
            break;
        }
        case 6:
        {
            save();
            cout << endl
            << "Trabalho de AEDA T1 - 2019" << endl
            << "Desenvolvido por:" << endl
            << "    Bianca Mota" << endl
            << "    Carolina Rosemback" << endl
            << "    Iohan Sardinha" << endl << endl
            << "Muito Obrigado e ate a proxima!!!" << endl;
            return;
        }
    }
}

void MainMenu::deletarAeroporto()
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
            if (lower(aeroportos.at(i)->getLocalizacao().getPais()) == lower(p) && lower(aeroportos.at(i)->getLocalizacao().getCidade()) == lower(c))
            {
                for(Funcionario* f: aeroportos[i]->getFuncionarios())
                {
                    for(auto it = tab_funcionarios.begin(); it != tab_funcionarios.end(); it++)
                    {
                        if(*it == f)
                        {
                            (*it)->setAtual(false);
                            break;
                        }
                    }
                }
                aeroportos.erase(aeroportos.begin()+i);
                return;
            }
        }
        cout << "Parametros dados nao indicam nenhum aeroporto" << endl;
    }
}

Aeroporto* MainMenu::escolherAeroporto()
{
    cin.ignore(1024,'\n');
    string p, c;
    cout << "Pais no qual o aeroporto esta localizado: ";
    getline(cin, p);
    cout << "Cidade do aeroporto: ";
    getline(cin, c);
    for (int i = 0; i < aeroportos.size(); i++) {
        if (lower(aeroportos.at(i)->getLocalizacao().getPais()) == lower(p) && lower(aeroportos.at(i)->getLocalizacao().getCidade()) == lower(c)) {
            return aeroportos.at(i);
        }
    }
    cout << "Parametros dados nao indicam nenhum aeroporto" << endl;
    wait();
    return NULL;
}

void MainMenu::criarAeroporto() {
    //Localizacao
    string cidade, pais;
    cout << "Pais do novo aeroporto: ";
    cin.ignore(1024, '\n');
    getline(cin, pais);
    cout << "Cidade do novo aeroporto: ";
    getline(cin, cidade);

    //GPS
    float lat, lang;
    while(1)
    {
        cout << "Latitude do novo aeroporto: ";
        cin >> lat;
        cout << "Longitude do novo aeroporto: ";
        cin >> lang;
        try
        {
            Localizacao localizacao(pais,cidade,GPS(lat,lang));
            break;
        }
        catch (LatInvalida l)
        {
            cout << l.what() << endl;
        }
        catch (LongInvalida l)
        {
            cout << l.what() << endl;
        }
    }

    Localizacao localizacao(pais,cidade,GPS(lat,lang));
    aeroportos.push_back(new Aeroporto(NULL,localizacao,{},{},{},{},{}));
    cout << "Para adicionar funcionarios e avioes ao aeroporto va para:"<< endl;
    cout << "2 - Acessar aeroporto" << endl << endl;
    menus_to_call["MainMenu"]->play();
}

void MainMenu::verFuncionarios()
{
    cout << string(40,'\n');
    cout << "0-Atuais" << endl;
    cout << "1-Antigos" << endl;
    cout << "2-Todos" << endl;
    string field;
    cin.ignore(1024,'\n');
    getline(cin, field);

    cout << string(40,'\n');
    cout << "0-Administrativos" << endl;
    cout << "1-Pilotos" << endl;
    cout << "2-Membros de tripulacao" << endl;
    cout << "3-Todos" << endl;
    string type;
    getline(cin, type);

    auto it = tab_funcionarios.begin();
    while(it!=tab_funcionarios.end())
    {
        Funcionario* funcionario = *it;

        if(type == "0")
        {
            if(field == "0")
            {
                if(funcionario->tipo() == "ADM" && funcionario->isAtual()) funcionario->print();
            }
            else if(field == "1")
            {
                if(funcionario->tipo() == "ADM" && !funcionario->isAtual()) funcionario->print();
            }
            else
            {
                if(funcionario->tipo() == "ADM") funcionario->print();
            }
        }
        else if(type == "1")
        {
            if(field == "0")
            {
                if(funcionario->tipo() == "PIL" && funcionario->isAtual()) funcionario->print();
            }
            else if(field == "1")
            {
                if(funcionario->tipo() == "PIL" && !funcionario->isAtual()) funcionario->print();
            }
            else
            {
                if(funcionario->tipo() == "PIL") funcionario->print();
            }
        }
        else if(type == "2")
        {
            if(field == "0")
            {
                if(funcionario->tipo() == "MEM" && funcionario->isAtual()) funcionario->print();
            }
            else if(field == "1")
            {
                if(funcionario->tipo() == "MEM" && !funcionario->isAtual()) funcionario->print();
            }
            else
            {
                if(funcionario->tipo() == "MEM") funcionario->print();
            }
        }
        else
        {
            if(field == "0")
            {
                if(funcionario->isAtual()) funcionario->print();
            }
            else if(field == "1")
            {
                if(!funcionario->isAtual()) funcionario->print();
            }
            else
            {
                funcionario->print();
            }
        }

        it++;
    }
    wait();
    menus_to_call["MainMenu"]->play();
}
