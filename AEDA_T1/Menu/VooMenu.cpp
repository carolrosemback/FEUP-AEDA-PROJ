#include "VooMenu.h"
#include "../Classes/Informacao.h"
#include "../Classes/Aviao.h"


extern map<string, Menu*> menus_to_call;

VooMenu::VooMenu(){
    opcoes = {"Alterar data", "Alterar hora prevista", "Alterar hora real", "Alterar destino", "Alterar estado voo", "Visualizar um voo","Ver todos os voos", "Criar voo", "Alterar tempo de pista","Voltar"};
}

void VooMenu::CallMenu() {
    switch (input)
    {
        case 0:
        {
            alterarData();
            break;
        }
        case 1:
        {
            alterarHoraPrevista();
            break;
        }
        case 2:
        {
            alterarHoraReal();
            break;
        }
        case 3:
        {
            alterarDestino();
            break;
        }
        case 4:
        {
            alterarEstado();
            break;
        }
        case 5:
        {
            visualizarVoo();
            break;
        }
        case 6:
        {
            listarVoos();
            break;
        }
        case 7:
        {
            criarVoo();
            break;
        }

        case 8:
        {
            alterarTempoPista();
            break;
        }

        case 9:
        {
            menus_to_call["AviaoMenu"]->play();
            return;
        }
    }
    menus_to_call["VooMenu"]->play();
}

void VooMenu::listarVoos() {
    for(Voo* voo: a->getVoos())
    {
        cout << *voo;
    }
    cin.ignore(1024,'\n');
    wait();
}

void VooMenu::criarVoo() {
    int dia, mes, ano;
    int min1, hora1, seg1;
    int min2, hora2, seg2;
    string data, horap, horar;
    string destino;
    string resp;
    bool cancelado;
    cin.ignore(1024, '\n');
    while(1)
    {
        cout << "Diga a data do novo voo: (dia/mes/ano) " << endl;
        getline(cin,data);
        vector<string> splitted = split(data,"/");
        dia = stoi(splitted[0]);
        mes =  stoi(splitted[1]);
        ano =  stoi(splitted[2]);
        try
        {
            Data data_c(dia, mes, ano);
            break;
        }
        catch (DiaInvalida d)
        {
            cout<< d.what() << endl;
        }
        catch (MesInvalido d)
        {
            cout<< d.what() << endl;
        }
    }
    Data data_c(dia, mes, ano);

    while(1) {
        cout << "Diga a hora prevista do voo: (hora:min:seg)" << endl;
        getline(cin, horap);
        vector<string> splitted = split(horap, ":");
        hora1 = stoi(splitted[0]);
        min1 = stoi(splitted[1]);
        seg1 = stoi(splitted[2]);

        try
        {
            Hora hora_prevista(hora1, min1, seg1);
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
    Hora hora_prevista(hora1, min1, seg1);

    while(1)
    {
    cout << "Diga a hora real do voo: (hora:min:seg) " << endl;
    getline(cin,horar);
    vector<string> splitted = split(horar,":");
    hora2 = stoi(splitted[0]);
    min2 = stoi(splitted[1]);
    seg2 = stoi(splitted[2]);
        try
        {
            Hora hora_real(hora2, min2, seg2);
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
    Hora hora_real(hora2, min2, seg2);

    cout << "Diga o destino do voo: " << endl;
    getline(cin,destino);

    string tempo;

    cout << "Quanto tempo de pista? " << endl;
    cin >> tempo;

    Voo* voo = new Voo(data_c, hora_prevista, destino, stoi(tempo));

    cout << "O voo foi cancelado: (sim/nao)" << endl;
    getline(cin,resp);
    if (lower(resp) == "sim")
        cancelado = true;
    else
        cancelado = false;

    Informacao* info = new Informacao(voo, hora_prevista, hora_real, cancelado);
    voo->setInfo(info);
    a->adicionarVoo(voo);

    menus_to_call["VooMenu"]->play();

}

Voo* VooMenu::escolherVoo() {
    string destino, data;
    int op;
    int ano, mes, dia;
    while (1) {
        cout << "Como desejar escolher o Voo? " << endl;
        cout << "0 - destino" << endl << "1 - data" << endl;
        cin >> op;
        switch (op) {
            case 0: {
                cout << "Qual o destino do voo que deseja?" << endl;
                cin.ignore(1024, '\n');
                getline(cin, destino);

                for (int i = 0; i < a->getVoos().size(); i++) {
                    if (lower(a->getVoos().at(i)->getDestino()) == lower(destino))
                        return a->getVoos().at(i);

                }
            }
            case 1: {
                cout << "Qual a data do voo que deseja? (ano/mes/dia)" << endl;
                cin.ignore(1024, '\n');
                getline(cin,data);
                dia = stoi(data.substr(0, data.find_first_of("/")));
                mes = stoi(data.substr(data.find_first_of("/") + 1, 2));
                ano = stoi(data.substr(data.find_last_of("/") + 1, -1));
                Data data_c(dia, mes, ano);
                for (int i = 0; i < a->getVoos().size(); i++) {
                    if (a->getVoos().at(i)->getData().getDia() == dia && a->getVoos().at(i)->getData().getMes() == mes && a->getVoos().at(i)->getData().getAno() == ano)
                        return a->getVoos().at(i);

                }
            }
        }
        cout << "Voo com o campo indicado nao encontrado" << endl;
    }

}

void VooMenu::visualizarVoo() {
    Voo* voo = escolherVoo();
    cout << "Data: " << voo->getData() << endl;
    cout << "Hora: " << voo->getHora() << endl;
    cout << "Destino: " << voo->getDestino() << endl;
    cout << "Informacao: " << *(voo->getInfo()) << endl;
    cin.ignore(1024, '\n');
    wait();
    menus_to_call["VooMenu"]->play();
}

void VooMenu::alterarData() {
    string data;
    int ano, mes, dia;
    Voo* voo = escolherVoo();
    while(1)
    {
        cout << "Diga a data do novo voo: (dia/mes/ano) " << endl;

        getline(cin,data);
        vector<string> splitted = split(data,"/");
        dia = stoi(splitted[0]);
        mes =  stoi(splitted[1]);
        ano =  stoi(splitted[2]);
        try
        {
            Data data_c(dia, mes, ano);
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
    Data data_c(dia, mes, ano);
    voo->setData(data_c);
    menus_to_call["VooMenu"]->play();
}

Hora VooMenu::alterarHora() {
    int hora, min, seg;
    string horap;
    while(1) {
        cout << "Diga a hora prevista do voo: (hora:min:seg)" << endl;
        getline(cin, horap);
        vector<string> splitted = split(horap, ":");
        hora = stoi(splitted[0]);
        min = stoi(splitted[1]);
        seg = stoi(splitted[2]);
        try
        {
            Hora horas(hora, min, seg);
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
    Hora horas(hora, min, seg);
    return horas;
}

void VooMenu::alterarHoraPrevista() {
    Voo* voo = escolherVoo();
    Hora hora = alterarHora();
    voo->setHora(hora);
    voo->getInfo()->setHoraPrevista(hora);
    menus_to_call["VooMenu"]->play();
}

void VooMenu::alterarHoraReal() {
    Voo* voo = escolherVoo();
    voo->getInfo()->setHoraReal(alterarHora());
    menus_to_call["VooMenu"]->play();
}

void VooMenu::alterarEstado() {
    Voo* voo = escolherVoo();
    string booleano;
    cout << "O voo foi cancelado? (sim/nao)" << endl;
    getline(cin,booleano);
    if (lower(booleano) == "sim")
        voo->getInfo()->setCancelado(true);
    else
        voo->getInfo()->setCancelado(false);
    menus_to_call["VooMenu"]->play();
}

void VooMenu::alterarDestino() {
    Voo* voo = escolherVoo();
    string destino;
    cout << "Qual o nome destino: " << endl;
    getline(cin,destino);
    voo->setDestino(destino);
    menus_to_call["VooMenu"]->play();
}

void VooMenu::alterarTempoPista() {
    Voo* voo = escolherVoo();
    int tpista;
    cout << "Qual o tempo de pista: " << endl;
    cin >> tpista;
    voo->setTempoPista(tpista);
    menus_to_call["VooMenu"]->play();
}

void VooMenu::setAviao(Aviao* a)
{
    this->a = a;
}