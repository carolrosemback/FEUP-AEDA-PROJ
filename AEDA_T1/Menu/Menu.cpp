#include "Menu.h"
#include "../Classes/Aviao.h"
#include "../Classes/Informacao.h"

vector<Aeroporto*> aeroportos;
map<string, Menu*> menus_to_call;
unordered_set<Funcionario*,hash_func,equality_func> tab_funcionarios;
priority_queue<Empresa> empresas;
BST<Aeroporto*> ArvAeroporto(nullptr);

void Menu::print()
{
    cout << string(40,'\n');
    cout << "-------------------------------------" << endl;
    for(int i = 0; i < opcoes.size(); i++)
    {
        cout << i  << "  -  "<< opcoes.at(i) << endl;
    }

    cout << "-------------------------------------" << endl;
}

void Menu::wait()
{
    cout << "Pressione qualquer tecla para continuar...";
    cin.get();
}

void Menu::play() {
    print();
    getInput();
    CallMenu();
}

void Menu::getInput() {
    while (1)
    {
        cout << "Selecione uma opcao: ";
        cin >> input;
        if (!cin.fail() && input < opcoes.size()) {
            break;
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "Entrada invalida" << endl;
    }
}

void Menu::save()
{
    ofstream file;
    file.open("Airport.dt", ofstream::out);
    int aeroporto_it = 0;
    for(Aeroporto* aeroporto: aeroportos)
    {
        //Localizacao
        file << aeroporto->getLocalizacao().getCidade() << endl;
        file << aeroporto->getLocalizacao().getPais() << endl;
        file << aeroporto->getLocalizacao().getCordenadas().getLatitude() << endl;
        file << aeroporto->getLocalizacao().getCordenadas().getLongitude() << endl;
        file << "--localizacao--" << endl;

        vector<Voo*> voos;
        vector<Informacao*> infos;
        vector<Funcionario*> funcionarios;
       //Voos
       for(Aviao* aviao: aeroporto->getAvioes())
       {
           for(Voo* voo: aviao->getVoos())
           {
               //Voo
               voos.push_back(voo);
               infos.push_back(voo->getInfo());
               file << voo->getData() << endl;
               file << voo->getHora() << endl;
               file << voo->getDestino() << endl;
               file << voo->getTempoPista() << endl;
               file << voo->getInfo()->getHoraPrevista() << endl;
               file << voo->getInfo()->getHoraReal() << endl;
               file << voo->getInfo()->isCancelado() << endl;
           }
       }
       file << "--voos--" << endl;

       //Membros tripulacao
       for(Membro_tripulacao* membroTripulacao: aeroporto->getMembros())
       {
           file << membroTripulacao->getSalario() << endl;
           funcionarios.push_back(membroTripulacao);
           for(Voo* voo: membroTripulacao->getVoos())
           {
               for(int i = 0; i < voos.size(); i++)
               {
                   if(voo == voos.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--voos membro--" << endl;
           for(Informacao* info: membroTripulacao->getInfos())
           {
               for(int i = 0; i < infos.size(); i++)
               {
                   if(info == infos.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--infos membro--" << endl;
       }
        file << "--membros--" << endl;

       //Avioes
       for(Aviao* aviao: aeroporto->getAvioes())
       {
           file << aviao->getTipo() << endl;
           file << aviao->getCustoOperacao() << endl;
           file << aviao->getCapacidade() << endl;
           for(Funcionario* funcionario: aviao->getTripulacao())
           {
               for(int i = 0; i < funcionarios.size(); i++)
               {
                   if(funcionario == funcionarios.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--funcionarios aviao--" << endl;
           for(Voo* voo: aviao->getVoos())
           {
               for(int i = 0; i < voos.size(); i++)
               {
                   if(voo == voos.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--voos aviao--" << endl;
       }
        file << "--avioes--" << endl;

       //Pilotos
       for(Piloto* piloto: aeroporto->getPilotos())
       {
           funcionarios.push_back(piloto);
           file << piloto->getSalario() << endl;
           file << piloto->getNome() << endl;
           file << piloto->getDataNascimento() << endl;
           file << piloto->getCategoria() << endl;
           for(Aviao* aviao: piloto->getAvioes())
           {
               for (int i = 0; i < aeroporto->getAvioes().size(); ++i)
               {
                    if(aeroporto->getAvioes().at(i) == aviao)
                    {
                        file << i << endl;
                        break;
                    }
               }
           }
           file << "--avioes piloto--" << endl;
           for(Voo* voo: piloto->getVoos())
           {
               for(int i = 0; i < voos.size(); i++)
               {
                   if(voo == voos.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--voos piloto--" << endl;
       }
       file << "--pilotos--" << endl;

       //Funcionario Administrativo
       for(Funcionario_administrativos* funcionarioAdministrativos: aeroporto->getFuncionariosAdministrativos())
       {
           funcionarios.push_back(funcionarioAdministrativos);
           file << funcionarioAdministrativos->getSalario() << endl;
           file << funcionarioAdministrativos->getNome() << endl;
           file << funcionarioAdministrativos->getDataNascimento() << endl;
           file << funcionarioAdministrativos->getCategoria() << endl;
           file << funcionarioAdministrativos->gethorario_de_trabalho().first << endl;
           file << funcionarioAdministrativos->gethorario_de_trabalho().second << endl;
           file << funcionarioAdministrativos->getFuncao() << endl;
           file << funcionarioAdministrativos->getDepartamento() << endl;
       }
       file << "--funcionarios administrativos--" << endl;
       int i = 0;
       for(Funcionario* funcionario1 : funcionarios)
       {
           if(funcionario1 == aeroporto->getGerente())
           {
               file << i << endl;
               file << "----Gerente----" << endl;
               break;
           }
           i++;
       }
       if(funcionarios.empty())
       {
           file << "-1" << endl;
           file << "----Gerente----" << endl;
       }
       aeroporto_it++;
        if(aeroporto_it == aeroportos.size())
            file << "--ultimoAeroporto--";
        else
            file << "--aeroporto--" << endl;
    }
    vector<Empresa> temp;
    while(!empresas.empty())
    {
        Empresa em = empresas.top();
        empresas.pop();
        file << endl;
        file << em.getId() << endl;
        file << em.getDisponibilidade() << endl;
        file << em.getManutencao() << endl;
        temp.push_back(em);
        file << "--empresa--";
    }
    for (unsigned i=0; i<temp.size(); i++)
        empresas.push(temp[i]);
    file.close();
}

void Menu::load() {
    ifstream file("Airport.dt");
    if (!file.is_open()) {
        throw runtime_error("Could not open file Airport.dt");
    }
    string line;
    vector<Aeroporto *> aeroportosLoad;
    while (!file.eof()) {
        string cidade, pais;
        float lat, lng;
        getline(file, cidade);
        getline(file, pais);
        getline(file, line);
        lat = stof(line);
        getline(file, line);
        lng = stof(line);
        Localizacao localizacao = Localizacao(pais, cidade, GPS(lat, lng));
        getline(file, line);
        //-----Localizacao-------

        vector<Voo *> voos;
        vector<Informacao *> informacoes;
        vector<string> splitted;
        while (1) {
            getline(file, line);
            if (line == "--voos--")
                break;
            splitted = split(line, "/");
            Data data(stoi(splitted[0]), stoi(splitted[1]), stoi(splitted[2]));
            getline(file, line);
            splitted = split(line, ":");
            Hora hora(stoi(splitted[0]), stoi(splitted[1]), stoi(splitted[2]));
            string destino;
            getline(file, destino);
            string temp;
            getline(file, temp);
            int tempPista = stoi(temp);
            getline(file, line);
            splitted = split(line, ":");
            Hora hora_prevista(stoi(splitted[0]), stoi(splitted[1]), stoi(splitted[2]));
            getline(file, line);
            splitted = split(line, ":");
            Hora hora_real(stoi(splitted[0]), stoi(splitted[1]), stoi(splitted[2]));
            getline(file, line);
            bool canceled = (line == "0");

            Voo *voo = new Voo(data, hora, destino, tempPista);
            Informacao *informacao = new Informacao(voo, hora_prevista, hora_real, canceled);
            voo->setInfo(informacao);
            voos.push_back(voo);
            informacoes.push_back(informacao);
        }
        //---------Voos--------

        vector<Funcionario *> funcionarios;
        vector<Membro_tripulacao *> membros_tripulacao;
        while (1) {
            getline(file, line);
            if (line == "--membros--")
                break;
            int salario = stoi(line);
            vector<Voo *> voos_membro;
            vector<Informacao *> infos_membro;
            while (1) {
                getline(file, line);
                if (line == "--voos membro--")
                    break;
                int i = stoi(line);
                voos_membro.push_back(voos.at(i));
            }
            while (1) {
                getline(file, line);
                if (line == "--infos membro--")
                    break;
                int i = stoi(line);
                infos_membro.push_back(informacoes.at(i));
            }
            Membro_tripulacao *membro = new Membro_tripulacao(voos_membro, infos_membro);
            membros_tripulacao.push_back(membro);
            funcionarios.push_back(membro);
        }
        //---------Membros--------

        vector<Aviao *> avioes;
        map<Aviao *, vector<int>> aviao_pos_func;
        while (1) {
            string tipo;
            getline(file, tipo);
            if (tipo == "--avioes--")
                break;
            int custo_de_operacao;
            getline(file, line);
            custo_de_operacao = stoi(line);
            int capacidade;
            getline(file, line);
            capacidade = stoi(line);
            vector<int> pos_funcionarios_aviao;
            while (1) {
                getline(file, line);
                if (line == "--funcionarios aviao--")
                    break;
                int i = stoi(line);
                pos_funcionarios_aviao.push_back(i);
            }
            vector<Voo *> voos_aviao;
            while (1) {
                getline(file, line);
                if (line == "--voos aviao--")
                    break;
                int i = stoi(line);
                voos_aviao.push_back(voos.at(i));
            }
            Aviao *aviao = new Aviao(tipo, capacidade, voos_aviao, {}, custo_de_operacao);
            avioes.push_back(aviao);
            aviao_pos_func.insert(pair<Aviao *, vector<int>>(aviao, pos_funcionarios_aviao));
        }
        //Avioes

        vector<Piloto *> pilotos;
        while (1) {
            getline(file, line);
            if (line == "--pilotos--")
                break;
            int salario = stoi(line);
            string nome;
            getline(file, nome);
            getline(file, line);
            splitted = split(line, "/");
            Data nascimento(stoi(splitted[0]), stoi(splitted[1]), stoi(splitted[2]));
            string categoria;
            getline(file, categoria);
            vector<Aviao *> avioes_piloto;
            while (1) {
                getline(file, line);
                if (line == "--avioes piloto--")
                    break;
                int i = stoi(line);
                avioes_piloto.push_back(avioes.at(i));
            }
            vector<Voo *> voos_piloto;
            while (1) {
                getline(file, line);
                if (line == "--voos piloto--")
                    break;
                int i = stoi(line);
                voos_piloto.push_back(voos.at(i));
            }
            Piloto *piloto = new Piloto(nome, nascimento, categoria, avioes_piloto, voos_piloto);
            pilotos.push_back(piloto);
            funcionarios.push_back(piloto);
        }

        vector<Funcionario_administrativos *> funcionarios_administrativos;
        while (1) {
            getline(file, line);
            if (line == "--funcionarios administrativos--")
                break;
            int salario = stoi(line);
            string nome;
            getline(file, nome);
            getline(file, line);
            splitted = split(line, "/");
            Data nascimento(stoi(splitted[0]), stoi(splitted[1]), stoi(splitted[2]));
            string categoria;
            getline(file, categoria);
            getline(file, line);
            splitted = split(line, ":");
            Hora hora_entrada(stoi(splitted[0]), stoi(splitted[1]), stoi(splitted[2]));
            getline(file, line);
            splitted = split(line, ":");
            Hora hora_saida(stoi(splitted[0]), stoi(splitted[1]), stoi(splitted[2]));
            pair<Hora, Hora> hora_trabalho(hora_entrada, hora_saida);
            string funcao;
            getline(file, funcao);
            string departamento;
            getline(file, departamento);
            Funcionario_administrativos *funcionarioAdministrativo = new Funcionario_administrativos(nome, nascimento,
                                                                                                     categoria,
                                                                                                     hora_trabalho,
                                                                                                     funcao,
                                                                                                     departamento);
            funcionarios_administrativos.push_back(funcionarioAdministrativo);
            funcionarios.push_back(funcionarioAdministrativo);
        }

        getline(file, line);
        int gerenteIndex = stoi(line);
        getline(file, line);

        getline(file, line);

        for (auto aviao_vec: aviao_pos_func) {
            for (int i : aviao_vec.second) {
                aviao_vec.first->adicionarTripulacao(funcionarios.at(i));
            }
        }
        for (Funcionario *f : funcionarios) {
            tab_funcionarios.insert(f);
        }

        Aeroporto* a = new Aeroporto(funcionarios.empty() ? nullptr : funcionarios[gerenteIndex], localizacao, funcionarios,
        avioes, pilotos, membros_tripulacao, funcionarios_administrativos);

        aeroportosLoad.push_back(a);

        ArvAeroporto.insert(a);

        if (line == "--ultimoAeroporto--") {
            while (getline(file, line)) {
                int id, disp, manut;
                id = stoi(line);
                getline(file, line);
                disp = stoi(line);
                getline(file, line);
                manut = stoi(line);
                Empresa e(id, disp, manut);
                empresas.push(e);
                getline(file, line); //"--empresa--"
            }
        }
    }
    aeroportos = aeroportosLoad;
}