#include "vecteur.hh"

Vecteur::Vecteur(unsigned int size)
  : m_size(size), m_elems(new double[size])
{
}

Vecteur::~Vecteur()
{
  delete [] m_elems;
}
