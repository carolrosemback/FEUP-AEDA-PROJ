#include "AviaoMenu.h"
#include "../Classes/Informacao.h"
#include "../Classes/Aviao.h"

extern map<string, Menu*> menus_to_call;

AviaoMenu::AviaoMenu() {
    opcoes = {"Criar Aviao", "Editar Tipo do Aviao", "Editar Capacidade Aviao", "Editar Voos","Ver avioes", "Voltar"};
}

void AviaoMenu::CallMenu() {
    switch(input)
    {
        case 0:
        {
            criarAviao();
            break;
        }
        case 1:{
            editarTipo();
            break;
        }
        case 2:
        {
            editarCapacidade();
            break;
        }
        case 3:
        {
            menus_to_call["VooMenu"]->setAeroporto(aeroporto);
            menus_to_call["VooMenu"]->setAviao(escolherAviao());
            menus_to_call["VooMenu"]->play();
            break;
        }
        case 4:
        {
            listarAvioes();
            break;
        }
        case 5:
        {
            menus_to_call["AcessarAeroportoMenu"]->play();
            break;
        }
    }
}

void AviaoMenu::criarAviao() {
    string tipo;
    int capacidade, v, f, custo;
    vector<Voo*> voo;
    vector<Funcionario*> funcionario;
    cout << "Qual o tipo do aviao: ";
    cin.ignore(1024, '\n');

    getline(cin, tipo);
    cout << "Qual a capacidade do aviao: ";
    cin >> capacidade;
    cout << "Quantos voos deseja adicionar? ";
    cin >> v;
    for (; v > 0; v--) {
        cin.ignore(1024, '\n');
        voo.push_back(criarVoo());
    }
    cout << "Um voo precisa ter 2 pilotos e 2 membros tripulacao." << endl << "Diga as informacoes do novo piloto: " << endl;
    //cin.ignore(1024, '\n');
    Piloto* piloto1 = criarPiloto(voo);
    funcionario.push_back(piloto1);
    aeroporto->adicionarPiloto(piloto1);

    cout << "Diga as informacoes do segundo piloto: " << endl;
    Piloto* piloto2 = criarPiloto(voo);
    funcionario.push_back(piloto1);
    aeroporto->adicionarPiloto(piloto1);

    cout << "Diga as informacoes do primeito membro tripulacao: " << endl;
    Membro_tripulacao* membroTripulacao1 = criarMembroTripulacao(voo);
    funcionario.push_back(membroTripulacao1);
    aeroporto->adicionarMembro(membroTripulacao1);

    cout << "Diga as informacoes do segundo membro tripulacao: " << endl;
    Membro_tripulacao* membroTripulacao2 = criarMembroTripulacao(voo);
    funcionario.push_back(membroTripulacao2);
    aeroporto->adicionarMembro(membroTripulacao2);

    cout << "Qual o custo da operacao: ";
    cin >> custo;

    string tempoMed;
    cout << "Quanto tempo de pista? " << endl;
    cin >> tempoMed;

    string tempoTot;
    cout << "Quanto tempo de pista? " << endl;
    cin >> tempoTot;

    Aviao* a = new Aviao(tipo, capacidade, voo, piloto1, piloto2, membroTripulacao1, membroTripulacao2, funcionario, custo);
    aeroporto->adicionarAviao(a);
    menus_to_call["AviaoMenu"]->play();
}

void AviaoMenu::listarAvioes() {
    for(Aviao* aviao: aeroporto->getAvioes())
    {
        cout << *aviao;
    }
    cin.ignore(1024,'\n');
    wait();
    menus_to_call["AviaoMenu"]->play();
}

Voo* AviaoMenu::criarVoo() {
    int dia, mes, ano;
    int min1, hora1, seg1;
    int min2, hora2, seg2;
    string data, horap, horar;
    string destino;
    string resp;
    bool cancelado;
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
        catch(MesInvalido m){
            cout << m.what() << endl;
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
        catch (MinInvalida m)
        {
            cout << m.what() << endl;
        }
        catch (SegInvalida m)
        {
            cout << m.what() << endl;
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
        catch (MinInvalida m)
        {
            cout << m.what() << endl;
        }
        catch (SegInvalida m)
        {
            cout << m.what() << endl;
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

    return voo;

}

Membro_tripulacao* AviaoMenu::criarMembroTripulacao(vector<Voo*> voos)
{
    for(Aviao* aviao: aeroporto->getAvioes())
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
    cout << "Destino voo o qual o funcionario vai trabalhar: ";
    //cin.ignore(1024,'\n');
    getline(cin,in);
    for(Voo* voo: voos)
    {
        if(lower(voo->getDestino()) == lower(in))
        {
            novoFuncionario->adicionarVoo(voo);
            novoFuncionario->adicionarInfo(voo->getInfo());
            break;
        }
    }

    return novoFuncionario;
}

Piloto* AviaoMenu::criarPiloto(vector<Voo*> voos) {
    string nome;
    int data_nascimentoD,data_nascimentoM,data_nascimentoA;
    string categoria;

    string in;
    cout << "Nome: ";
    getline(cin,nome);
    cout << "Data de nascimento: (DD/MM/AAAA) ";
    getline(cin,in);
    vector<string> splitted = split(in,"/");
    data_nascimentoD = stoi(splitted[0]);
    data_nascimentoM = stoi(splitted[1]);
    data_nascimentoA = stoi(splitted[2]);
    cout << "Categoria: ";
    getline(cin,categoria);
    cout << "OBS: para adicionar voos e avioes de voos ao piloto va para editar pilotos" << endl;
    Piloto* novoFuncionario = new Piloto(nome,Data(data_nascimentoD,data_nascimentoM,data_nascimentoA),categoria,{},{});
    aeroporto->adicionarPiloto(novoFuncionario);
    cin.ignore(1024,'\n');
    return novoFuncionario;
}

Aviao* AviaoMenu::escolherAviao()
{
    int i, capacidade;
    string tipo;
    while (1) {
        cout << "Deseja escolher o aviao por: " << endl;
        cout << "0 - Tipo de aviao" << endl << "1 - Capacidade do aviao" << endl;
        cin >> i;
        switch (i) {
            case 0: {
                cout << "Qual o tipo de aviao que deseja: " << endl;
                cin.ignore(1024, '\n');
                getline(cin, tipo);
                for (int j = 0; j < aeroporto->getAvioes().size(); j++) {
                    if (lower(aeroporto->getAvioes().at(j)->getTipo()) == lower(tipo))
                        return aeroporto->getAvioes().at(j);
                }
                break;
            }
            case 1: {
                cout << "Qual a capacidade do aviao que deseja: " << endl;
                cin >> capacidade;
                for (int j = 0; j < aeroporto->getAvioes().size(); j++) {
                    if (aeroporto->getAvioes().at(j)->getCapacidade() == capacidade)
                        return aeroporto->getAvioes().at(j);
                }
                break;
            }
        }
        cout << "Aviao com o campo indicado nao existe" << endl;
    }
}

void AviaoMenu::editarTipo() {
    string tipo;
    Aviao* aviao = escolherAviao();
    cin.ignore(1024, '\n');
    cout << "Qual o novo tipo do aviao: " << endl;
    getline(cin, tipo);
    aviao->setTipo(tipo);
    menus_to_call["AviaoMenu"]->play();
}

void AviaoMenu::editarCapacidade() {
    int capacidade;
    Aviao* aviao = escolherAviao();
    cout << "Qual a nova capacidade do aviao: " << endl;
    cin >> capacidade;
    aviao->setCapacidade(capacidade);
    menus_to_call["AviaoMenu"]->play();
}


void AviaoMenu::setAeroporto(Aeroporto* a)
{
    aeroporto = a;
}
