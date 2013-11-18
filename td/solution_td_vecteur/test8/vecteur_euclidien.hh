#ifndef VECTEUR_EUCLIDIEN_HH
#define VECTEUR_EUCLIDIEN_HH

#include "vecteur.hh"

class VecteurEuclidien : public Vecteur
{
public:
  VecteurEuclidien(unsigned int size);
  VecteurEuclidien(const VecteurEuclidien&);

  double norm() const;
};

double dot(const VecteurEuclidien& u, const VecteurEuclidien& v);

#endif // !defined(VECTEUR_EUCLIDIEN_HH)
