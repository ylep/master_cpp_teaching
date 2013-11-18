#include <vecteur_euclidien.hh>

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;


int main()
{
  VecteurEuclidien v2(2);
  v2[0] = 3.0;
  v2[1] = 4.0;

  const VecteurEuclidien& v2ref = v2;
  const double norm = v2ref.norm();
  if(!(std::abs(norm - 5.0) < 1e-3))
  {
    cout << "La norme du vecteur (3, 4) a retourné " << norm
         << " au lieu de 5" << endl;
    return EXIT_FAILURE;
  }

  VecteurEuclidien u2(2);
  u2[0] = 4.0;
  u2[1] = 3.0;

  const VecteurEuclidien& u2ref = u2;

  const double result = dot(u2ref, v2ref);
  if(!(std::abs(result - 24.0) < 1e-3))
  {
    cout << "Le produit scalaire du vecteur (3, 4) par le vecteur (4, 3) a retourné "
         << result << " au lieu de 24" << endl;
    return EXIT_FAILURE;
  }

  cout << "Test 7 réussi !" << endl;
  return EXIT_SUCCESS;
}
