#include "../Classes/Aeroporto.h"

bool compLocalizacao(Aeroporto* &a1, Aeroporto* &a2)
{
    if(a1->getLocalizacao().getPais() < a2->getLocalizacao().getPais())
        return true;
    if(a2->getLocalizacao().getPais() < a1->getLocalizacao().getPais())
        return false;
    if(a1->getLocalizacao().getCidade() < a2->getLocalizacao().getCidade())
        return true;
    return false;
}

bool compQuantidadeFuncionariosAdministrativos(Aeroporto* &a1, Aeroporto* &a2)
{
    if(a1->getFuncionariosAdministrativos().size() < a2->getFuncionariosAdministrativos().size())
        return true;
    return false;
}

bool compQuantidadefuncionarios(Aeroporto* &a1, Aeroporto* &a2)
{
    if(a1->getFuncionarios().size() < a2->getFuncionarios().size())
        return true;
    return false;
}

bool compQuantidadePilotos(Aeroporto* &a1, Aeroporto* &a2)
{
    if(a1->getPilotos().size() < a2->getPilotos().size())
        return true;
    return false;
}

bool compQuantidadeMembroTripulacao(Aeroporto* &a1, Aeroporto* &a2)
{
    if(a1->getMembros().size() < a2->getMembros().size())
        return true;
    return false;
}

bool compQuantidadeAvioes(Aeroporto* &a1, Aeroporto* &a2)
{
    if(a1->getAvioes().size() < a2->getAvioes().size())
        return true;
    return false;
}

