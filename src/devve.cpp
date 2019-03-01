#include "devve.h"

Devve::Devve(int id)
    : m_Id(id)
{
}


int Devve::getId()
{
    return this->m_Id;
}

void Devve::setId(int newId)
{
    this->m_Id = newId;
}
