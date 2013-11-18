#ifndef VECTEUR_EUCLIDIEN_HH
#define VECTEUR_EUCLIDIEN_HH

#include "vecteur.hh"

class VecteurEuclidien : public Vecteur
{
public:
  VecteurEuclidien(unsigned int size);
  VecteurEuclidien(const VecteurEuclidien&);
};

#endif // !defined(VECTEUR_EUCLIDIEN_HH)
