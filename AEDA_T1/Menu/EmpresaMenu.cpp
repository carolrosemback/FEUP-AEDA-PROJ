#include "EmpresaMenu.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;
extern priority_queue<Empresa> empresas;

EmpresaMenu::EmpresaMenu() {opcoes = {"Criar Empresa", "Editar Empresa", "Usar empresa mais disponivel", "Visualizar empresa", "Deletar empresa", "Voltar"};}

void EmpresaMenu::CallMenu() {
    switch(input)
    {
        case 0:
        {
            criarEmpresa();
            break;
        }
        case 1:
        {
            editarEmpresa();
            break;
        }
        case 2:
        {
            usarEmpresa();
            break;
        }
        case 3:
        {
            listarEmpresas();
            break;
        }
        case 4:
        {
            deletarEmpresa();
            break;
        }
        case 5:
        {
            menus_to_call["MainMenu"]->play();
            break;
        }
    }
}

Empresa EmpresaMenu::escolherEmpresa() {
    vector<Empresa> temp;
    int id;
    while(1){
        cout << "Qual o id da empresa que deseja? " << endl;
        cin >> id;
        while(!empresas.empty()){
            Empresa em = empresas.top();
            empresas.pop();
            if(em.getId() == id)
            {
                for (unsigned i=0; i<temp.size(); i++)
                    empresas.push(temp[i]);
                return em;
            }
            else
                temp.push_back(em);
        }
        for (unsigned i=0; i<temp.size(); i++)
            empresas.push(temp[i]);
        cout << "Nao existe nenhuma empresa com esse id. " << endl;
    }
}

int EmpresaMenu::maiorId() {
    vector<Empresa> temp;
    int maiorId = 0;
    while (!empresas.empty()) {
        Empresa em = empresas.top();
        empresas.pop();
        if (em.getId() > maiorId)
            maiorId = em.getId();
        temp.push_back(em);
    }
    for (unsigned i = 0; i < temp.size(); i++)
        empresas.push(temp[i]);
    return maiorId;
}

void EmpresaMenu::criarEmpresa(){
    int id, disponibilidade, manutencoes;
    id = maiorId()+1;
    cout << "O id da nova empresa sera: " << id << endl;
    cout << "Quanto tempo ate a empresa estar disponivel? " << endl;
    cin >> disponibilidade;
    cout << "Quantas manutencoes a empresa ja realizou? " << endl;
    cin >> manutencoes;
    Empresa e(id, disponibilidade, manutencoes);
    empresas.push(e);
    menus_to_call["EmpresaMenu"]->play();
}

void EmpresaMenu::deletarEmpresa() {
    escolherEmpresa();
    menus_to_call["EmpresaMenu"]->play();
}

void EmpresaMenu::editarEmpresa() {
    int i;
    Empresa e = escolherEmpresa();
    cout << "O que deseja alterar na empresa: " << endl;
    cout << "0 - Disponibilidade" << endl << "1 - Manutencoes" << endl;
    cin >> i;
    switch (i)
    {
        case 0:
        {
            int dis;
            cout << "Qual a nova disponibilidade da empresa: " << endl;
            cin >> dis;
            e.setDisponibilidade(dis);
            empresas.push(e);
            break;
        }
        case 1:
        {
            int man;
            cout << "Qual a nova manutencao da empresa: " << endl;
            cin >> man;
            e.setManutencao(man);
            empresas.push(e);
            break;
        }
    }
    menus_to_call["EmpresaMenu"]->play();
}

void EmpresaMenu::listarEmpresas() {
    int n;
    cout << "Deseja: " << endl << "0 - Listar uma empresa" << endl << "1 - Listar todas as empresas" << endl;
    cin >> n;
    switch (n){
        case 0:
        {
            Empresa e = escolherEmpresa();
            empresas.push(e);
            cout << e;
            break;
        }
        case 1:
        {
            vector<Empresa> temp;
            while(!empresas.empty()){
                Empresa em = empresas.top();
                cout << em;
                temp.push_back(em);
                empresas.pop();
            }
            for (unsigned i=0; i<temp.size(); i++)
                empresas.push(temp[i]);
            break;
        }
    }
    cin.ignore(1024,'\n');
    wait();
    menus_to_call["EmpresaMenu"]->play();
}

Aviao* EmpresaMenu::escolherAviao() {
    Aeroporto *ae;
    while(1){
        bool found = false;
        cin.ignore(1024,'\n');
        string p, c;
        cout << "Em qual Aeroporto se encontra o aviao que deseja? " << endl;
        cout << "Pais no qual o aeroporto esta localizado: ";
        getline(cin, p);
        cout << "Cidade do aeroporto: ";
        getline(cin, c);
        for (int i = 0; i < aeroportos.size(); i++) {
            if (lower(aeroportos.at(i)->getLocalizacao().getPais()) == lower(p) && lower(aeroportos.at(i)->getLocalizacao().getCidade()) == lower(c)) {
                ae = aeroportos.at(i);
                found = true;
            }
        }
        if (found)
            break;
        cout << "Parametros dados nao indicam nenhum aeroporto" << endl;
    }
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
                for (int j = 0; j < ae->getAvioes().size(); j++) {
                    if (lower(ae->getAvioes().at(j)->getTipo()) == lower(tipo))
                        return ae->getAvioes().at(j);
                }
                break;
            }
            case 1: {
                cout << "Qual a capacidade do aviao que deseja: " << endl;
                cin >> capacidade;
                for (int j = 0; j < ae->getAvioes().size(); j++) {
                    if (ae->getAvioes().at(j)->getCapacidade() == capacidade)
                        return ae->getAvioes().at(j);
                }
                break;
            }
        }
        cout << "Aviao com o campo indicado nao existe" << endl;
    }
}

void EmpresaMenu::usarEmpresa() {
    cout << "A empresa com melhor disponibilidade é: " << endl;
    cout << empresas.top();
    escolherAviao();
    int x = empresas.top().getDisponibilidade();
    Empresa e = empresas.top();
    empresas.pop();
    e.setDisponibilidade(x+3);
    int m = e.getManutencao();
    e.setManutencao(m+1);
    empresas.push(e);
    cout << "A nova disponibilidade dessa empresa é: " << endl;
    cout << e.getDisponibilidade();
    cin.ignore(1024, '\n');
    wait();
    menus_to_call["EmpresaMenu"]->play();
}

void EmpresaMenu::setAeroporto(Aeroporto* a){aeroporto = a;}

void EmpresaMenu::setAviao(Aviao* a){aviao = a;}
