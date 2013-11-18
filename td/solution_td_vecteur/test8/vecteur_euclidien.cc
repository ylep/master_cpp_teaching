#include "vecteur_euclidien.hh"

#include <cmath>

namespace
{

template <typename T>
inline T square(const T& x)
{
  return x * x;
}

} // end of anonymous namespace

VecteurEuclidien::VecteurEuclidien(unsigned int size)
  : Vecteur(size)
{
}

VecteurEuclidien::VecteurEuclidien(const VecteurEuclidien& other)
  : Vecteur(other)
{
}

double VecteurEuclidien::norm() const
{
  double sum = 0.0;

  for(unsigned int i = 0 ; i < size() ; ++i)
    sum += square(get(i));

  return std::sqrt(sum);
}

double dot(const VecteurEuclidien& u, const VecteurEuclidien& v)
{
  const unsigned int usize = u.size();
  assert(usize == v.size());

  double sum = 0.0;

  for(unsigned int i = 0 ; i < usize ; ++i)
    sum += u.get(i) * v.get(i);

  return sum;

}
