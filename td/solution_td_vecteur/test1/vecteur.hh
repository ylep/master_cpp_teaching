#ifndef VECTEUR_HH_INCLUDED
#define VECTEUR_HH_INCLUDED

#include <cassert>

class Vecteur
{
public:
  Vecteur(unsigned int size);
  ~Vecteur();

  unsigned int size() const { return m_size; };

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

private:
  // disallow copy-constructing and assignment
  Vecteur(const Vecteur&);
  Vecteur& operator = (const Vecteur&);

  unsigned int m_size;
  double* m_elems;
};

#endif // !defined(VECTEUR_HH_INCLUDED)
