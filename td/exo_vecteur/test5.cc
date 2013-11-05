#include "vecteur.hh"

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
  Vecteur v3(3);
  v3[0] = 7.0;
  v3[1] = 8.0;
  v3[2] = 9.0;

  const Vecteur& v3_ref = v3;

  if(v3_ref[0] != 7.0
     || v3_ref[1] != 8.0
     || v3_ref[2] != 9.0)
  {
    cout << "Les valeurs obtenues par l'opérateur [] sont fausses" << endl;
    return EXIT_FAILURE;
  }

  cout << "Test 5 réussi !" << endl;
  return EXIT_SUCCESS;
}
