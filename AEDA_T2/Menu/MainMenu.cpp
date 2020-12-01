#include "MainMenu.h"
#include "../Classes/Aviao.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;

MainMenu::MainMenu() {
    opcoes = {"Criar aeroporto","Listar aeroportos","Acessar aeroporto", "Remover Aeroporto", "Sair"};
}

void MainMenu::CallMenu() {
    switch(input)
    {
        case 0:
        {
            criarAeroporto();
            break;
        }
        case 1:
        {
            menus_to_call["ListarAeroportoMenu"]->play();
            break;
        }
        case 2:
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
        case 3:
        {
            deletarAeroporto();
            menus_to_call["MainMenu"]->play();
            break;
        }
        case 4:
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
        catch (runtime_error r)
        {
            cout << "latitude e longitude precisam ser float entre -90 e 90" << endl;
        }
    }

    Localizacao localizacao(pais,cidade,GPS(lat,lang));
    aeroportos.push_back(new Aeroporto(NULL, localizacao, {}, {}, {}, {}, {}));
    cout << "Para adicionar funcionarios e avioes ao aeroporto va para:"<< endl;
    cout << "2 - Acessar aeroporto" << endl << endl;
    menus_to_call["MainMenu"]->play();
}