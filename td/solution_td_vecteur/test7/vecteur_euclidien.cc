#include "vecteur_euclidien.hh"

VecteurEuclidien::VecteurEuclidien(unsigned int size)
  : Vecteur(size)
{
}

VecteurEuclidien::VecteurEuclidien(const VecteurEuclidien& other)
  : Vecteur(other)
{
}
