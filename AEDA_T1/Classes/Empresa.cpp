#include "Empresa.h"

Empresa::Empresa(int id, int disp, int m):id(id), disponibilidade(disp), manutencoes(m) {}

int Empresa::getId() const {return id;}

void Empresa::setId(int n) {id = n;}

int Empresa::getDisponibilidade() const {return disponibilidade;}

void Empresa::setDisponibilidade(int n) { disponibilidade = n;}

void Empresa::setManutencao(int n) {manutencoes = n;}

int Empresa::getManutencao() {return manutencoes;}

bool Empresa::operator< (Empresa e) const {return this->getDisponibilidade() > e.getDisponibilidade();}

ostream& operator<<(ostream& os, Empresa e) {
    os << "Id: " << e.getId() << endl;
    os << "Disponibilidade: " << e.getDisponibilidade() << endl;
    os << "Manutencao: " << e.getManutencao() << endl;
    return os;
}




