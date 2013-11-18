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

  cout << "Test 3 réussi !" << endl;
  return EXIT_SUCCESS;
}
