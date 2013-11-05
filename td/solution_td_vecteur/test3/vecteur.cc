#include "vecteur.hh"

#include <algorithm>
#include <cmath>
#include <ostream>


namespace
{

template <typename T>
inline T square(const T& x)
{
  return x * x;
}

} // end of anonymous namespace


Vecteur::Vecteur(unsigned int size)
  : m_size(size), m_elems(new double[size])
{
}

Vecteur::~Vecteur()
{
  delete [] m_elems;
}

void Vecteur::resize(unsigned int new_size)
{
  const unsigned int common_size = std::min(m_size, new_size);
  double * const new_elems = new double[new_size];
  for(unsigned int i = 0 ; i < common_size ; ++i)
    new_elems[i] = m_elems[i];
  delete [] m_elems;
  m_elems = new_elems;
  m_size = new_size;
}

double Vecteur::norm() const
{
  double sum = 0.0;

  for(unsigned int i = 0 ; i < size() ; ++i)
    sum += square(get(i));

  return std::sqrt(sum);
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
