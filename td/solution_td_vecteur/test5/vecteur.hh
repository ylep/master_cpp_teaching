#ifndef VECTEUR_HH_INCLUDED
#define VECTEUR_HH_INCLUDED

#include <cassert>
#include <iosfwd>

class Vecteur
{
public:
  Vecteur(unsigned int size);
  Vecteur(const Vecteur&);
  ~Vecteur();

  Vecteur& operator = (const Vecteur&);

  unsigned int size() const { return m_size; };
  void resize(unsigned int);

  double operator [] (unsigned int i) const
  {
    assert(i < m_size);
    return m_elems[i];
  };
  double& operator [] (unsigned int i)
  {
    assert(i < m_size);
    return m_elems[i];
  };

  double get(unsigned int i) const
  {
    assert(i < m_size);
    return m_elems[i];
  };

  void set(unsigned int i, double value)
  {
    assert(i < m_size);
    m_elems[i] = value;
  };

  double norm() const;

private:

  unsigned int m_size;
  double* m_elems;
};

std::ostream& operator << (std::ostream& os, const Vecteur& v);

#endif // !defined(VECTEUR_HH_INCLUDED)
