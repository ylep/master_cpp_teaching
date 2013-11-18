#include <vecteur_euclidien.hh>

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;


int main()
{
  VecteurEuclidien u(3);
  const Vecteur& uref = u;

  Vecteur v = u;

  cout << "Test 7 réussi !" << endl;
  return EXIT_SUCCESS;
}
