#include <vecteur.hh>

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
  Vecteur v(3);
  v.set(0, 7.0);
  v.set(1, 8.0);

  v.resize(2);

  const unsigned int size = v.size();
  if(size != 2)
  {
    cout << "La taille après resize() est " << size << " au lieu de 2" << endl;
    return EXIT_FAILURE;
  }

  if(v.get(0) != 7.0 || v.get(1) != 8.0)
  {
    cout << "Les valeurs retournées après resize() sont fausses." << endl;
    return EXIT_FAILURE;
  }

  Vecteur v2(2);
  v2.set(0, 3.0);
  v2.set(1, 4.0);

  const Vecteur& v2ref = v2;
  const double norm = v2ref.norm();
  if(!(std::abs(norm - 5.0) < 1e-3))
  {
    cout << "La norme du vecteur (3, 4) a retourné " << norm
         << " au lieu de 5" << endl;
    return EXIT_FAILURE;
  }

  cout << "Test 3 réussi !" << endl;
  return EXIT_SUCCESS;
}
