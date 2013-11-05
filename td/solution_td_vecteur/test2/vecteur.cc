#include "vecteur.hh"

#include <ostream>

Vecteur::Vecteur(unsigned int size)
  : m_size(size), m_elems(new double[size])
{
}

Vecteur::~Vecteur()
{
  delete [] m_elems;
}

std::ostream& operator << (std::ostream& os, const Vecteur& v)
{
  const unsigned int size = v.size();
  os << "Vecteur(" << size << "){";
  if(size > 0)
  {
    for(unsigned int i = 0; i < size - 1 ; ++i)
      os << v.get(i) << ", ";
    os << v.get(size - 1);
  }
  os << '}';
  return os;
}
