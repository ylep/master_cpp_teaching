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

Vecteur::Vecteur(const Vecteur& other)
  : m_size(other.size()), m_elems(new double[m_size])
{
  for(unsigned int i = 0 ; i < size() ; ++i)
    m_elems[i] = other.get(i);
}

Vecteur::~Vecteur()
{
  delete [] m_elems;
}

Vecteur& Vecteur::operator = (const Vecteur& other)
{
  if(this != &other)
  {
    m_size = other.size();
    delete [] m_elems;
    m_elems = new double[m_size];
    for(unsigned int i = 0 ; i < m_size ; ++i)
      m_elems[i] = other.get(i);
  }
  return *this;
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

bool operator == (const Vecteur& u, const Vecteur& v)
{
  const unsigned int usize = u.size();
  if(usize != v.size())
    return false;

  for(unsigned int i = 0 ; i < usize ; ++i)
    if(u[i] != v[i])
      return false;

  return true;
}

bool operator != (const Vecteur& u, const Vecteur& v)
{
  const unsigned int usize = u.size();
  if(usize != v.size())
    return true;

  for(unsigned int i = 0 ; i < usize ; ++i)
    if(u[i] != v[i])
      return true;

  return false;
}

Vecteur operator + (const Vecteur& u, const Vecteur& v)
{
  Vecteur ret = u;
  ret += v;
  return ret;
}

Vecteur operator - (const Vecteur& u, const Vecteur& v)
{
  Vecteur ret = u;
  ret -= v;
  return ret;
}

Vecteur operator * (const Vecteur& u, double s)
{
  Vecteur ret = u;
  ret *= s;
  return ret;
}

Vecteur operator * (double s, const Vecteur& u)
{
  Vecteur ret = u;
  ret *= s;
  return ret;
}

Vecteur operator / (const Vecteur& u, double s)
{
  Vecteur ret = u;
  ret /= s;
  return ret;
}

Vecteur& Vecteur::operator += (const Vecteur& v)
{
  assert(v.size() == size());
  for(unsigned int i = 0 ; i < m_size ; ++i)
    m_elems[i] += v[i];
  return *this;
}

Vecteur& Vecteur::operator -= (const Vecteur& v)
{
  assert(v.size() == size());
  for(unsigned int i = 0 ; i < m_size ; ++i)
    m_elems[i] -= v[i];
  return *this;
}

Vecteur& Vecteur::operator *= (double s)
{
  for(unsigned int i = 0 ; i < m_size ; ++i)
    m_elems[i] *= s;
  return *this;
}

Vecteur& Vecteur::operator /= (double s)
{
  const double inv_s = 1. / s;
  for(unsigned int i = 0 ; i < m_size ; ++i)
    m_elems[i] *= inv_s;
  return *this;
}
