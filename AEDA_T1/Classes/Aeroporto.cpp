#include "Aeroporto.h"

Aeroporto::Aeroporto(Funcionario* ger, Localizacao loc, vector<Funcionario*> fu, vector<Aviao*> av, vector<Piloto*> pil, vector<Membro_tripulacao*> mem, vector<Funcionario_administrativos*> f_adm )
{
    gerente = ger;
    localizacao = loc;
    funcionarios = fu;
    avioes = av;
    pilotos = pil;
    membros = mem;
    funcionarios_administrativos = f_adm;
}

Funcionario* Aeroporto::getGerente() const{return gerente;}

Localizacao Aeroporto::getLocalizacao() const {return localizacao;}

void Aeroporto::setGerente(Funcionario* f){gerente = f;}

void Aeroporto::adicionarFuncionario(Funcionario* f){funcionarios.push_back(f);}

void  Aeroporto::adicionarPiloto(Piloto* p)
{
    pilotos.push_back(p);
    funcionarios.push_back(p);
}

void  Aeroporto::adicionarAviao(Aviao* a){avioes.push_back(a);}

void  Aeroporto::adicionarMembro(Membro_tripulacao* m)
{
    membros.push_back(m);
    funcionarios.push_back(m);
}

void  Aeroporto::adicionarFuncionarioAdministrativo(Funcionario_administrativos* f)
{
    funcionarios_administrativos.push_back(f);
    funcionarios.push_back(f);
}

void Aeroporto::removerFuncionario(Funcionario* f)
{
    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios.at(i) == f)
        {
            funcionarios.erase(funcionarios.begin()+i);
            break;
        }
    }
}

void  Aeroporto::removerPiloto(Piloto* p)
{
    Piloto* funcionario;
    for(int i = 0; i < pilotos.size(); i++)
    {
        if(pilotos.at(i) == p)
        {
            funcionario = pilotos.at(i);
            pilotos.erase(pilotos.begin()+i);
            break;
        }
    }
    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios.at(i) == p)
        {
            funcionarios.erase(funcionarios.begin()+i);
            delete funcionario;
            break;
        }
    }
}

void  Aeroporto::removerAviao(Aviao* a)
{
    for(int i = 0; i < avioes.size(); i++)
    {
        if(avioes.at(i) == a)
        {
            avioes.erase(avioes.begin()+i);
            break;
        }
    }
}

void  Aeroporto::removerMembro(Membro_tripulacao* m)
{
    for(int i = 0; i < membros.size(); i++)
    {
        if(membros.at(i) == m)
        {
            membros.erase(membros.begin()+i);
            break;
        }
    }
    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios.at(i) == m)
        {
            funcionarios.erase(funcionarios.begin()+i);
            break;
        }
    }
    delete m;
}

void  Aeroporto::removerFuncionarioAdministrativo(Funcionario_administrativos* f)
{
    Funcionario_administrativos* funcionario;
    for(int i = 0; i < funcionarios_administrativos.size(); i++)
    {
        if(funcionarios_administrativos.at(i) == f)
        {
            funcionario = funcionarios_administrativos.at(i);
            funcionarios_administrativos.erase(funcionarios_administrativos.begin()+i);
            break;
        }
    }
    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios.at(i) == f)
        {
            funcionarios.erase(funcionarios.begin()+i);
            delete funcionario;
            break;
        }
    }
}

ostream& operator<<(ostream& os, const Aeroporto& a)
{
    if(a.gerente == NULL)
        os << "Gerente: Nao alocado" << endl;
    else{
        os << "Gerente : " << endl;
        a.gerente->print();
    }
    os << "Localizacao : " << a.localizacao << endl;
    os << "Quantidade de funcionarios: " << a.funcionarios.size() << endl;
    os << "Quantidade de avioes: " << a.avioes.size() << endl;
    os << "Quantidade de pilotos: " << a.pilotos.size() << endl;
    os << "Quantidade de membros de tripulacao: " << a.membros.size() << endl;
    os << "Quantidade de funcionarios administrativos: " << a.funcionarios_administrativos.size() << endl;
    os << "Quantidade de voos: " << a.getParagens() << endl;
    return os;
}

vector<Funcionario_administrativos*> & Aeroporto::getFuncionariosAdministrativos(){return funcionarios_administrativos;}

vector<Funcionario*> & Aeroporto::getFuncionarios(){return funcionarios;}

vector<Aviao*> & Aeroporto::getAvioes(){return avioes;}

vector<Piloto*> & Aeroporto::getPilotos(){return pilotos;}

vector<Membro_tripulacao*> & Aeroporto::getMembros(){return membros;}

void Aeroporto::setLocalizacao(string p, string c, GPS g)
{
    localizacao.setPais(p);
    localizacao.setCidade(c);
    localizacao.setCordenadas(g);
}

int Aeroporto::getParagens() const
{
    int n = 0;
    for(int i=0; i < avioes.size(); i++)
    {
        n += avioes.at(i)->getVoos().size();
    }
    return n;
}

bool Aeroporto::operator< (Aeroporto &a1)
{
    if(this->getParagens() == a1.getParagens())
        return this->getTempoMedio() < a1.getTempoMedio();
    return this->getParagens() < a1.getParagens();
}
bool Aeroporto:: operator == ( Aeroporto &a1)
{
    return this==&a1;
}

int Aeroporto::getTempoMedio()
{
    int n = 0, tempMedioPista = 0;
    for (int i = 0; i < avioes.size(); i++) {
        n += avioes.at(i)->getTempoMedio();
    }
    if (getParagens() == 0)
        return 0;
    tempMedioPista = n / getParagens();
    return tempMedioPista;
}