#include <iostream>
#include "Funcionario.h"
#include "../Classes/Aviao.h"
#include "../Classes/Informacao.h"
#include <string>

using namespace std;

int Funcionario::getSalario() const{
    return salario;
}

Funcionario::Funcionario(int salario,bool atual) : salario(salario), atual(atual) {}

string Funcionario_administrativos::getFuncao() const {
    return funcao;
}

void Funcionario_administrativos::setFuncao(const string &funcao) {
    Funcionario_administrativos::funcao = funcao;
}

string Funcionario_administrativos::getDepartamento() const {
    return departamento;
}

void Funcionario_administrativos::setDepartamento(const string &departamento) {
    Funcionario_administrativos::departamento = departamento;
}

void Funcionario_administrativos::print() {
    cout << "Nome: " << nome << endl;
    cout << "Salario: " << salario << "$" << endl;
    cout << "Nasimento: " << data_nascimento << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Horario de trabalho: de " << horario_de_trabalho.first << " as " << horario_de_trabalho.second << endl;
    cout << "Funcao: " << funcao << endl;
    cout << "Departamento: " << departamento << endl << endl;
}

Funcionario_administrativos::Funcionario_administrativos(const string& nome,const Data& data_nascimento,const string& categoria,const pair<Hora,Hora> horario_de_trabalho,const string &funcao, const string &departamento,
                                                         bool atual)
        :Funcionario(5000,atual),nome(nome),data_nascimento(data_nascimento),horario_de_trabalho(horario_de_trabalho),categoria(categoria), funcao(funcao), departamento(departamento) {}


const string &Funcionario_administrativos::getNome() const {
    return nome;
}

void Funcionario_administrativos::setNome(const string &nome) {
    Funcionario_administrativos::nome = nome;
}

const Data &Funcionario_administrativos::getDataNascimento() const {
    return data_nascimento;
}

void Funcionario_administrativos::setDataNascimento(const Data &dataNascimento) {
    data_nascimento = dataNascimento;
}

const string &Funcionario_administrativos::getCategoria() const {
    return categoria;
}

void Funcionario_administrativos::setCategoria(const string &categoria) {
    Funcionario_administrativos::categoria = categoria;
}

const pair<Hora, Hora> &Funcionario_administrativos::gethorario_de_trabalho() const {return horario_de_trabalho;}

void Funcionario_administrativos::setHorarioDeTrabalho(const pair<Hora, Hora> &horarioDeTrabalho) {horario_de_trabalho = horarioDeTrabalho;}

const string &Piloto::getNome() const {return nome;}

void Piloto::setNome(const string &nome) {Piloto::nome = nome;}

const Data &Piloto::getDataNascimento() const {return data_nascimento;}

void Piloto::setDataNascimento(const Data &dataNascimento) {data_nascimento = dataNascimento;}

const string &Piloto::getCategoria() const {return categoria;}

void Piloto::setCategoria(const string &categoria) {
    Piloto::categoria = categoria;
    Piloto::salario = 1000*categoria.size();
}

Piloto::Piloto(const string &nome, const Data &dataNascimento, const string &categoria,const vector<Aviao*> &tiposAviao, const vector<Voo*> & voosRealizados,bool atual):
        Funcionario(0,atual), nome(nome), data_nascimento(dataNascimento), categoria(categoria),tipos_aviao(tiposAviao), voos_realizados(voosRealizados)
{
    salario = 1000*categoria.size();
};

void Piloto::print() {
    cout << "Nome: " << nome << endl;
    cout << "Salario: " << salario << "$" << endl;
    cout << "Nascimento: " << data_nascimento << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Avioes pilotados: " << endl;
    for (Aviao* a: tipos_aviao)
         cout << *a << endl;
}

Membro_tripulacao::Membro_tripulacao(const vector<Voo*> & voosAlocados, const vector<Informacao*> &infoVoos,bool atual):Funcionario (0,atual), voos_alocados(voosAlocados), info_voos(infoVoos)
{
    salario = 250*voosAlocados.size();
}

vector<Voo*> Membro_tripulacao::getVoos()
{
    return voos_alocados;
}

vector<Informacao*> Membro_tripulacao::getInfos() {
    return info_voos;
}

void Membro_tripulacao::print() {
    cout << "Membro de tripulacao" << endl;
    cout << "Salario: " << salario << "$" << endl;
    cout << "Voos do membro: " << endl;
    for (Voo* voo : voos_alocados)
        cout << *voo;
    cout << "Informacoes dos voos: " << endl;
    for (Informacao* informacao : info_voos)
        cout << *informacao << endl;
}

ostream& operator<<(ostream& os, const Aviao& a)
{
    os << "Modelo: " << a.tipo << endl;
    os << "Capacidade: " << a.capacidade << endl;
    os << "Voos:" << endl;
    int i = 0;
    for(Voo* voo : a.voos)
    {
        cout << "Voo " << i << endl;
        cout << *voo;
        i++;
    }
    os <<  "Tripulacao: " << a.getTripulacao().size() << " membro(s)" << endl;
    os << "Custo de operacao: " << a.custo_operacao << endl;
    return os;
}