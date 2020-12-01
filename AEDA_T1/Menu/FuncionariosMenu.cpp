#include "FuncionariosMenu.h"
#include "../Classes/Aviao.h"
#include "../Classes/Informacao.h"

extern map<string, Menu*> menus_to_call;
extern unordered_set<Funcionario*,hash_func,equality_func> tab_funcionarios;

FuncionariosMenu::FuncionariosMenu(enum tipos_funcionarios t) {
    tipo = t;
    switch (tipo)
    {
        case TODOS:
            opcoes = {"Adicionar funcionario","Deletar funcionario","Ver funcionarios","Editar funcionarios"};
            break;
        case ADMINISTRATIVO:
            opcoes = {"Adicionar funcionario administrativo","Deletar funcionario administrativo","Ver funcionarios administrativos","Editar funcionario administrativo"};
            break;
        case PILOTO:
            opcoes = {"Adicionar piloto","Deletar piloto","Ver pilotos","Editar pilotos"};
            break;
        case MEMBRO_TRIPULACAO:
            opcoes = {"Adicionar membro da tripulacao","Deletar membro da tripulacao","Ver membros da tripulacaos","Editar membro da tripulacao"};
            break;
    }
    opcoes.push_back("Voltar");
}

void FuncionariosMenu::CallMenu() {
    string in;
    //cin.ignore(1024,'\n');
    switch(input)
    {
        case 0:
        {
            switch (tipo)
            {
                case TODOS:
                    cin.ignore(1024,'\n');
                    cout << "Tipo de funcionario(Administrativo, Piloto, Tripulacao): ";
                    getline(cin,in);
                    if(lower(in) == "administrativo")
                    {
                        criarFuncionarioAdministrativo();
                    }
                    else if(lower(in) == "piloto")
                    {
                        criarPiloto();
                    }
                    else if(lower(in) == "tripulacao")
                    {
                        criarMembroTripulacao();
                    }
                    menus_to_call["TodosFuncionariosMenu"]->play();
                    break;
                case ADMINISTRATIVO:
                    criarFuncionarioAdministrativo();
                    menus_to_call["FuncionariosAdministrativosMenu"]->play();
                    break;
                case PILOTO:
                    criarPiloto();
                    menus_to_call["PilotosFuncionariosMenu"]->play();
                    break;
                case MEMBRO_TRIPULACAO:
                    criarMembroTripulacao();
                    menus_to_call["MembrosTripulacaoFuncionariosMenu"]->play();
                    break;
            }
            break;
        }
        case 1:
        {
            switch (tipo)
            {
                case TODOS:
                    cout << "Tipo de funcionario(Administrativo, Piloto, Tripulacao): ";
                    getline(cin,in);
                    if(lower(in) == "administrativo")
                    {
                        deletarFuncionarioAdministrativo();
                    }
                    else if(lower(in) == "piloto")
                    {
                        deletarPiloto();
                    }
                    else if(lower(in) == "tripulacao")
                    {
                        deletarMembroTripulacao();
                    }
                    menus_to_call["TodosFuncionariosMenu"]->play();
                    break;
                case ADMINISTRATIVO:
                    deletarFuncionarioAdministrativo();
                    menus_to_call["FuncionariosAdministrativosMenu"]->play();
                    break;
                case PILOTO:
                    deletarPiloto();
                    menus_to_call["PilotosFuncionariosMenu"]->play();
                    break;
                case MEMBRO_TRIPULACAO:
                    deletarMembroTripulacao();
                    menus_to_call["MembrosTripulacaoFuncionariosMenu"]->play();
                    break;
            }
            break;
        }
        case 2:
        {
            listarFuncionarios();
            switch (tipo)
            {
                case TODOS:
                    menus_to_call["TodosFuncionariosMenu"]->play();
                    break;
                case PILOTO:
                    menus_to_call["PilotosFuncionariosMenu"]->play();
                    break;
                case MEMBRO_TRIPULACAO:
                    menus_to_call["MembrosTripulacaoFuncionariosMenu"]->play();
                    break;
                case ADMINISTRATIVO:
                    menus_to_call["FuncionariosAdministrativosMenu"]->play();
                    break;
            }
            break;
        }
        case 3:
        {
            switch (tipo)
            {
                case TODOS:
                    cout << "Tipo de funcionario(Administrativo, Piloto, Tripulacao): ";
                    getline(cin,in);
                    if(lower(in) == "administrativo")
                    {
                        editarFuncionarioAdministrativo();
                    }
                    else if(lower(in) == "piloto")
                    {
                        editarPiloto();
                    }
                    else if(lower(in) == "tripulacao")
                    {
                        editarMembroTripulacao();
                    }
                    menus_to_call["TodosFuncionariosMenu"]->play();
                    break;
                case ADMINISTRATIVO:
                    editarFuncionarioAdministrativo();
                    menus_to_call["FuncionariosAdministrativosMenu"]->play();
                    break;
                case PILOTO:
                    editarPiloto();
                    menus_to_call["PilotosFuncionariosMenu"]->play();
                    break;
                case MEMBRO_TRIPULACAO:
                    editarMembroTripulacao();
                    menus_to_call["MembrosTripulacaoFuncionariosMenu"]->play();
                    break;
            }
            break;
        }
        case 4:
        {
            menus_to_call["AcessarAeroportoMenu"]->play();
            break;
        }
    }
}

Funcionario_administrativos* FuncionariosMenu::acharFuncionarioAdministrativo() {
    string in;
    cin.ignore(1024,'\n');
    while (1)
    {
        cout << "Nome do funcionario: ";
        getline(cin,in);
        for (Funcionario_administrativos* funcionario: a->getFuncionariosAdministrativos())
        {Funcionario* inserirFuncionario();
            if (lower(funcionario->getNome()) == lower(in))
            {
                return funcionario;
            }
        }
        cout << "Funcionario com parametro requerido nao encontrado, tente novamente" << endl ;
    }
}

Piloto* FuncionariosMenu::acharPiloto() {
    string in;
    cin.ignore(1024,'\n');
    while (1)
    {
        cout << "Nome do funcionario: ";
        getline(cin,in);
        for (Piloto* funcionario: a->getPilotos()) {
            if (lower(funcionario->getNome()) == lower(in)) {
                return funcionario;
            }
        }
        cout << "Funcionario com parametro requerido nao encontrado, tente novamente" << endl ;
    }
}

Membro_tripulacao* FuncionariosMenu::acharMembroTripulacao(){
    string in;
    cin.ignore(1024,'\n');
    while (1)
    {
        cout << "Destino para qual o funcionario vai: ";
        getline(cin,in);
        for(Membro_tripulacao* funcionario: a->getMembros())
        {
            for(Voo* voo: funcionario->getVoos())
            {
                if(lower(voo->getDestino()) == lower(in))
                {
                    return funcionario;
                }
            }
        }
        cout << "Funcionario com parametro requerido nao encontrado, tente novamente" << endl ;
    }
}

void FuncionariosMenu::criarFuncionarioAdministrativo() {
    string nome;
    int data_nascimentoD,data_nascimentoM,data_nascimentoA;
    string categoria;
    int horario_de_trabalhoH1,horario_de_trabalhoM1,horario_de_trabalhoS1;
    int horario_de_trabalhoH2,horario_de_trabalhoM2,horario_de_trabalhoS2;
    string funcao;
    string departamento;

    string in;
    cout << "Nome:";
    getline(cin,nome);

    while(1)
    {
        cout << "Data de nascimento: (DD/MM/AAAA) ";
        getline(cin, in);
        vector<string> splitted = split(in, "/");
        data_nascimentoD = stoi(splitted[0]);
        data_nascimentoM = stoi(splitted[1]);
        data_nascimentoA = stoi(splitted[2]);
        try
        {
            Data data_nasc(data_nascimentoD, data_nascimentoM, data_nascimentoA);
            break;
        }
        catch (DiaInvalida d)
        {
            cout << d.what() << endl;
        }
        catch (MesInvalido d)
        {
            cout << d.what() << endl;
        }
    }
    Data data_nasc(data_nascimentoD, data_nascimentoM, data_nascimentoA);

    cout << "Categoria: ";
    getline(cin,categoria);

    while(1) {
        cout << "Hora que comeca o servico: (hh:mm:ss) ";
        getline(cin, in);
        vector<string> splitted = split(in, ":");
        horario_de_trabalhoH1 = stoi(splitted[0]);
        horario_de_trabalhoM1 = stoi(splitted[1]);
        horario_de_trabalhoS1 = stoi(splitted[2]);

        try
        {
            Hora horario_trabalho2(horario_de_trabalhoH1, horario_de_trabalhoM1, horario_de_trabalhoS1);
            break;
        }
        catch (HoraInvalida h)
        {
            cout<< h.what() << endl;
        }
        catch (MinInvalida h)
        {
            cout<< h.what() << endl;
        }
        catch (SegInvalida h)
        {
            cout<< h.what() << endl;
        }
    }
    Hora horario_trabalho1(horario_de_trabalhoH1, horario_de_trabalhoM1, horario_de_trabalhoS1);

    while (1) {
        cout << "Hora que acaba o servico: (hh:mm:ss) ";
        getline(cin, in);
        vector<string> splitted = split(in, ":");
        horario_de_trabalhoH2 = stoi(splitted[0]);
        horario_de_trabalhoM2 = stoi(splitted[1]);
        horario_de_trabalhoS2 = stoi(splitted[2]);
        try
        {
            Hora horario_trabalho2(horario_de_trabalhoH2, horario_de_trabalhoM2, horario_de_trabalhoS2);
            break;
        }
        catch (HoraInvalida h)
        {
            cout<< h.what() << endl;
        }
        catch (MinInvalida h)
        {
            cout<< h.what() << endl;
        }
        catch (SegInvalida h)
        {
            cout<< h.what() << endl;
        }
    }
    Hora horario_trabalho2(horario_de_trabalhoH2, horario_de_trabalhoM2, horario_de_trabalhoS2);

    cout << "Funcao: ";
    getline(cin,funcao);
    cout << "Departamento: ";
    getline(cin,departamento);
    Funcionario_administrativos* novoFuncionario = new Funcionario_administrativos(nome,Data(data_nascimentoD,data_nascimentoM,data_nascimentoA),categoria,
                                                                              pair<Hora,Hora>(Hora(horario_de_trabalhoH1,horario_de_trabalhoM1,horario_de_trabalhoS1),
                                                                                              Hora(horario_de_trabalhoH2,horario_de_trabalhoM2,horario_de_trabalhoS2)),funcao,departamento);
    a->adicionarFuncionarioAdministrativo(novoFuncionario);
    tab_funcionarios.insert(novoFuncionario);
}

void FuncionariosMenu::criarPiloto() {
    string nome;
    int data_nascimentoD,data_nascimentoM,data_nascimentoA;
    string categoria;

    string in;
    cout << "Nome:";
    getline(cin,nome);


    while(1)
    {
        cout << "Data de nascimento: (DD/MM/AAAA) ";
        getline(cin, in);
        vector<string> splitted = split(in, "/");
        data_nascimentoD = stoi(splitted[0]);
        data_nascimentoM = stoi(splitted[1]);
        data_nascimentoA = stoi(splitted[2]);
        try
        {
            Data data_nasc(data_nascimentoD, data_nascimentoM, data_nascimentoA);
            break;
        }
        catch (DiaInvalida d)
        {
            cout << d.what() << endl;
        }
        catch (MesInvalido d)
        {
            cout << d.what() << endl;
        }
    }
    Data data_nasc(data_nascimentoD, data_nascimentoM, data_nascimentoA);

    cout << "Categoria: ";
    getline(cin,categoria);
    cout << "OBS: para adicionar voos e avioes de voos ao piloto va para editar pilotos" << endl;
    Piloto* novoFuncionario = new Piloto(nome,Data(data_nascimentoD,data_nascimentoM,data_nascimentoA),categoria,{},{});
    a->adicionarPiloto(novoFuncionario);
    tab_funcionarios.insert(novoFuncionario);
    cin.ignore(1024,'\n');
    wait();
}

void FuncionariosMenu::criarMembroTripulacao()
{
    vector<Voo*> voos;
    for(Aviao* aviao: a->getAvioes())
    {
        for(Voo* voo: aviao->getVoos())
        {
            bool in_voos = false;
            for(Voo* v : voos)
            {
                if(v == voo)
                {
                    in_voos = true;
                    break;
                }
            }
            if(!in_voos)
            {
                voos.push_back(voo);
            }
        }
    }

    Membro_tripulacao* novoFuncionario = new Membro_tripulacao({},{});
    string in;
    cin.ignore(1024, '\n');
    while (1)
    {
        cout << "Destino do voo o qual o funcionario vai trabalhar(0 para parar de adicionar): ";
        getline(cin, in);
        if(in == "0")
        {
            break;
        }
        for(Voo* voo: voos)
        {
            if(lower(voo->getDestino()) == lower(in))
            {
                novoFuncionario->adicionarVoo(voo);
                novoFuncionario->adicionarInfo(voo->getInfo());
            }
        }
    }

    a->adicionarMembro(novoFuncionario);
    tab_funcionarios.insert(novoFuncionario);
}

void FuncionariosMenu::editarFuncionarioAdministrativo() {
    Funcionario_administrativos* funcionario = acharFuncionarioAdministrativo();
    while (1)
    {
        cout << "Escolha o campo para alterar:" << endl;
        cout << "0 - Nome" << endl;
        cout << "1 - Data de nascimento" << endl;
        cout << "2 - Categoria" << endl;
        cout << "3 - Horario de trabalho" << endl;
        cout << "4 - Funcao" << endl;
        cout << "5 - Departamento" << endl;
        cout << "6 - Sair" << endl;
        cin >> input;

        switch (input)
        {
            case 0:{
                string nome;
                cout << "Digite o novo nome: ";
                cin.ignore(1024, '\n');
                getline(cin,nome);
                funcionario->setNome(nome);
                continue;
            }
            case 1: {
                string in;
                int data_nascimentoD,data_nascimentoM,data_nascimentoA;
                cin.ignore(1024, '\n');
                while(1)
                {
                    cout << "Data de nascimento: (DD/MM/AAAA) ";
                    getline(cin, in);
                    vector<string> splitted = split(in, "/");
                    data_nascimentoD = stoi(splitted[0]);
                    data_nascimentoM = stoi(splitted[1]);
                    data_nascimentoA = stoi(splitted[2]);
                    try
                    {
                        Data data_nasc(data_nascimentoD, data_nascimentoM, data_nascimentoA);
                        break;
                    }
                    catch (DiaInvalida d)
                    {
                        cout << d.what() << endl;
                    }
                    catch (MesInvalido d)
                    {
                        cout << d.what() << endl;
                    }
                }
                Data data_nasc(data_nascimentoD, data_nascimentoM, data_nascimentoA);
                funcionario->setDataNascimento(Data(data_nascimentoD,data_nascimentoM,data_nascimentoA));
                continue;
            }
            case 2: {
                string cat;
                cout << "Digite a nova categoria: ";
                cin.ignore(1024, '\n');
                getline(cin,cat);
                funcionario->setCategoria(cat);
                continue;
            }
            case 3:
            {
                string in;
                int horario_de_trabalhoH1,horario_de_trabalhoM1,horario_de_trabalhoS1;
                int horario_de_trabalhoH2,horario_de_trabalhoM2,horario_de_trabalhoS2;
                cin.ignore(1024, '\n');
                while(1) {
                    cout << "Hora que comeca o servico: (hh:mm:ss) ";
                    getline(cin, in);
                    vector<string> splitted = split(in, ":");
                    horario_de_trabalhoH1 = stoi(splitted[0]);
                    horario_de_trabalhoM1 = stoi(splitted[1]);
                    horario_de_trabalhoS1 = stoi(splitted[2]);

                    try
                    {
                        Hora horario_trabalho2(horario_de_trabalhoH1, horario_de_trabalhoM1, horario_de_trabalhoS1);
                        break;
                    }
                    catch (HoraInvalida h)
                    {
                        cout<< h.what() << endl;
                    }
                    catch (MinInvalida h)
                    {
                        cout<< h.what() << endl;
                    }
                    catch (SegInvalida h)
                    {
                        cout<< h.what() << endl;
                    }
                }
                Hora horario_trabalho1(horario_de_trabalhoH1, horario_de_trabalhoM1, horario_de_trabalhoS1);


                while (1) {
                    cout << "Hora que acaba o servico: (hh:mm:ss) ";
                    getline(cin, in);
                    vector<string> splitted = split(in, ":");
                    horario_de_trabalhoH2 = stoi(splitted[0]);
                    horario_de_trabalhoM2 = stoi(splitted[1]);
                    horario_de_trabalhoS2 = stoi(splitted[2]);
                    try
                    {
                        Hora horario_trabalho2(horario_de_trabalhoH2, horario_de_trabalhoM2, horario_de_trabalhoS2);
                        break;
                    }
                    catch (HoraInvalida h)
                    {
                        cout<< h.what() << endl;
                    }
                    catch (MinInvalida h)
                    {
                        cout<< h.what() << endl;
                    }
                    catch (SegInvalida h)
                    {
                        cout<< h.what() << endl;
                    }
                }
                Hora horario_trabalho2(horario_de_trabalhoH2, horario_de_trabalhoM2, horario_de_trabalhoS2);

                funcionario->setHorarioDeTrabalho(pair<Hora,Hora>(Hora(horario_de_trabalhoH1,horario_de_trabalhoM1,horario_de_trabalhoS1),
                                                                  Hora(horario_de_trabalhoH2,horario_de_trabalhoM2,horario_de_trabalhoS2)));
                continue;
            }
            case 4: {
                string funcao;
                cout << "Nova funcao: ";
                cin.ignore(1024, '\n');
                getline(cin,funcao);
                funcionario->setFuncao(funcao);
                continue;
            }
            case 5: {
                string departamento;
                cout << "Novo departamento: ";
                cin.ignore(1024, '\n');
                getline(cin,departamento);
                funcionario->setDepartamento(departamento);
                continue;
            }
            case 6:
                return;
        }
        cout << "Entrada invalida" << endl;
    }
}

void FuncionariosMenu::editarPiloto() {
    Piloto* funcionario = acharPiloto();
    while (1)
    {
        cout << "Escolha o campo para alterar:" << endl;
        cout << "0 - Nome" << endl;
        cout << "1 - Data de nascimento" << endl;
        cout << "2 - Categoria" << endl;
        cout << "3 - Ver voos" << endl;
        cout << "4 - Ver avioes habilitados a dirigir" << endl;
        cout << "5 - Adicionar voo" << endl;
        cout << "6 - Adicionar aviao habilitado a dirigir" << endl;
        cout << "7 - Remover voo" << endl;
        cout << "8 - Remover aviao habilitado a dirigir" << endl;
        cout << "9 - Sair" << endl;
        cin >> input;

        switch (input)
        {
            case 0:{
                string nome;
                cout << "Digite o novo nome: ";
                cin.ignore(1024, '\n');
                getline(cin,nome);
                funcionario->setNome(nome);
                continue;
            }
            case 1: {
                string in;
                int data_nascimentoD,data_nascimentoM,data_nascimentoA;
                cin.ignore(1024, '\n');
                while(1)
                {
                    cout << "Data de nascimento: (DD/MM/AAAA) ";
                    getline(cin, in);
                    vector<string> splitted = split(in, "/");
                    data_nascimentoD = stoi(splitted[0]);
                    data_nascimentoM = stoi(splitted[1]);
                    data_nascimentoA = stoi(splitted[2]);
                    try
                    {
                        Data data_nasc(data_nascimentoD, data_nascimentoM, data_nascimentoA);
                        break;
                    }
                    catch (HoraInvalida h)
                    {
                        cout<< h.what() << endl;
                    }
                    catch (MinInvalida h)
                    {
                        cout<< h.what() << endl;
                    }
                    catch (SegInvalida h)
                    {
                        cout<< h.what() << endl;
                    }
                }
                Data data_nasc(data_nascimentoD, data_nascimentoM, data_nascimentoA);
                funcionario->setDataNascimento(Data(data_nascimentoD,data_nascimentoM,data_nascimentoA));
                continue;
            }
            case 2: {
                string cat;
                cout << "Digite a nova categoria: ";
                cin.ignore(1024, '\n');
                getline(cin,cat);
                funcionario->setCategoria(cat);
                continue;
            }
            case 3:
            {
                for(Voo* voo: funcionario->getVoos())
                {

                    cout << *voo;
                }
                continue;
            }
            case 4: {
                for(Aviao* aviao: funcionario->getAvioes())
                {
                    cout << *aviao;
                }
                continue;
            }
            case 5: {
                vector<Voo*> voos;
                for(Aviao* aviao: a->getAvioes())
                {
                    for(Voo* voo: aviao->getVoos())
                    {
                        bool in_voos = false;
                        for(Voo* v : voos)
                        {
                            if(v == voo)
                            {
                                in_voos = true;
                                break;
                            }
                        }
                        if(!in_voos)
                        {
                            voos.push_back(voo);
                        }
                    }
                }
                string destino;
                cin.ignore(1024, '\n');
                cout << "Digite o destino do voo que quer adicionar: ";
                getline(cin,destino);
                for(Voo* voo : voos)
                {
                    if(lower(destino) == lower(voo->getDestino()))
                    {
                        bool add = true;
                        for(Voo* v: funcionario->getVoos())
                        {
                            if(v == voo)
                            {
                                cout << "Funcionario ja esta alocado para este voo" << endl;
                                add = false;
                                break;
                            }
                        }
                        if(add)
                            funcionario->adicionarVoo(voo);
                        break;
                    }
                }
                continue;
            }
            case 6: {
                string modelo;
                cout << "Digite o modelo do aviao: ";
                cin.ignore(1023, '\n');
                getline(cin,modelo);;
                for(Aviao* aviao: a->getAvioes())
                {
                    if(lower(modelo) == lower(aviao->getTipo()))
                    {
                        bool add = true;
                        for(Aviao* av: funcionario->getAvioes())
                        {
                            if(av == aviao)
                            {
                                cout << "Piloto ja dirige este aviao" << endl;
                                add = false;
                                break;
                            }
                        }
                        if(add)
                            funcionario->adicionarAviao(aviao);
                        break;
                    }
                }
                continue;
            }
            case 7: {
                string destino;
                cout << "Digite o destino do voo que quer remover: ";
                cin.ignore(1024, '\n');
                getline(cin,destino);
                bool found = false;
                for(int i = 0; i < funcionario->getVoos().size(); i++)
                {
                    if(lower(funcionario->getVoos().at(i)->getDestino()) == lower(destino))
                    {
                        funcionario->getVoos().erase(funcionario->getVoos().begin()+i);
                        found = true;
                    }
                }
                if(!found)
                {
                    cout << "Voo nao esta alocado para o funcionario" << endl;
                }
                continue;
            }
            case 8: {
                string modelo;
                cout << "Digite o modelo do aviao que quer remover: ";
                cin.ignore(1024, '\n');
                getline(cin,modelo);
                bool found = false;
                for(int i = 0; i < funcionario->getAvioes().size(); i++)
                {
                    if(lower(funcionario->getAvioes().at(i)->getTipo()) == lower(modelo))
                    {
                        funcionario->getAvioes().erase(funcionario->getAvioes().begin()+i);
                        found = true;
                    }
                }
                if(!found)
                {
                    cout << "Piloto ja nao e habito a pilotar esse aviao" << endl;
                }
                continue;
            }
            case 9:
                return;
        }
        cout << "Entrada invalida" << endl;
    }
}

void FuncionariosMenu::editarMembroTripulacao(){
    Membro_tripulacao* funcionario = acharMembroTripulacao();
    while (1)
    {
        cout << "Escolha o campo para alterar:" << endl;
        cout << "0 - Ver voos alocados" << endl;
        cout << "1 - Alocar voo" << endl;
        cout << "2 - Remover voo" << endl;
        cout << "3 - Ver informacoes dos voos" << endl;
        cout << "4 - Sair" << endl;
        cin >> input;

        switch (input)
        {
            case 0:
            {
                for(Voo* voo: funcionario->getVoos())
                {
                    cout << *voo;
                }
                continue;
            }
            case 1: {
                vector<Voo*> voos;
                for(Aviao* aviao: a->getAvioes())
                {
                    for(Voo* voo: aviao->getVoos())
                    {
                        bool in_voos = false;
                        for(Voo* v : voos)
                        {
                            if(v == voo)
                            {
                                in_voos = true;
                                break;
                            }
                        }
                        if(!in_voos)
                        {
                            voos.push_back(voo);
                        }
                    }
                }
                string destino;
                cout << "Digite o destino do voo que quer adicionar: ";
                cin.ignore(1024, '\n');
                getline(cin,destino);
                for(Voo* voo : voos)
                {
                    if(lower(destino) == lower(voo->getDestino()))
                    {
                        bool add = true;
                        for(Voo* v: funcionario->getVoos())
                        {
                            if(v == voo)
                            {
                                cout << "Funcionario ja esta alocado para este voo" << endl;
                                add = false;
                                break;
                            }
                        }
                        if(add)
                            funcionario->getVoos().push_back(voo);
                        break;
                    }
                }
                continue;
            }
            case 2: {
                string destino;
                cout << "Digite o destino do voo que quer remover: ";
                cin.ignore(1024, '\n');
                getline(cin,destino);
                bool found = false;
                for(int i = 0; i < funcionario->getVoos().size(); i++)
                {
                    if(lower(funcionario->getVoos().at(i)->getDestino()) == lower(destino))
                    {
                        funcionario->getVoos().erase(funcionario->getVoos().begin()+i);
                        funcionario->setSalario(funcionario->getSalario()-250);
                        found = true;
                    }
                }
                if(!found)
                {
                    cout << "Voo nao esta alocado para o funcionario" << endl;
                }
                continue;
            }
            case 3:
            {
                for(Informacao* info: funcionario->getInfos())
                {
                    cout << *info;
                }
                continue;
            }
            case 4:
                return;
        }
        cout << "Entrada invalida" << endl;
    }
}

void remove_from_tab(Funcionario* f)
{
    for(auto it = tab_funcionarios.begin(); it != tab_funcionarios.end(); it++)
    {
        if(*it == f)
        {
            (*it)->setAtual(false);
            return;
        }
    }
}

void FuncionariosMenu::deletarFuncionarioAdministrativo() {
    string nome;
    cout << "Nome do funcionario a ser removido: ";
    getline(cin,nome);
    for(Funcionario_administrativos* funcionario: a->getFuncionariosAdministrativos())
    {
        if(lower(funcionario->getNome()) == lower(nome))
        {
            a->removerFuncionarioAdministrativo(funcionario);
            remove_from_tab(funcionario);
        }
    }
}

void FuncionariosMenu::deletarPiloto(){
    string nome;
    cout << "Nome do funcionario a ser removido: ";
    getline(cin,nome);
    for(Piloto* funcionario: a->getPilotos())
    {
        if(lower(funcionario->getNome()) == lower(nome))
        {
            a->removerPiloto(funcionario);
            remove_from_tab(funcionario);
        }
    }
}

void FuncionariosMenu::deletarMembroTripulacao(){

    for(int i = 0; i < a->getMembros().size(); i++)
    {
        cout << "Membro " << i << ":" << endl;
        a->getMembros().at(i)->print();
    }
    cout << "Qual o membro que deseja remover?: ";
    int i;
    cin.ignore(1024,'\n');
    cin >> i;
    Funcionario* funcionario = a->getMembros().at(i);
    a->removerMembro(a->getMembros().at(i));
    remove_from_tab(funcionario);
}

void FuncionariosMenu::listarFuncionarios() {
    switch (tipo)
    {
        case TODOS:
            for(Funcionario* funcionario: a->getFuncionarios())
            {
                funcionario->print();
            }
            break;
        case ADMINISTRATIVO:
            for(Funcionario* funcionario: a->getFuncionariosAdministrativos())
            {
                funcionario->print();
            }
            break;
        case PILOTO:
            for(Funcionario* funcionario: a->getPilotos())
            {
                funcionario->print();
            }
            break;
        case MEMBRO_TRIPULACAO:
            for(Funcionario* funcionario: a->getMembros())
            {
                funcionario->print();
            }
            break;
    }
    cin.ignore(1024,'\n');
    wait();
}

void FuncionariosMenu::setAeroporto(Aeroporto* a)
{
    this->a = a;
}