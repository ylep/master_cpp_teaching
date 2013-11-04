#include "vecteur.hh"

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
  Vecteur v3(3);
  v3.set(0, 7.0);
  v3.set(1, 8.0);
  v3.set(2, 9.0);

  cout << "Affichage du vecteur 3D (7, 8, 9) : "
       << v3 << endl;

  Vecteur v1(1);
  v1.set(0, 5.0);
  cout << "Affichage du vecteur 1D (5) : "
       << v1 << endl;

  Vecteur v0(0);
  cout << "Affichage du vecteur vide (dimension zéro) : "
       << v0 << endl;

  cout << "Test 2 terminé, passez à la suite si les affichages sont corrects."
       << endl;
  return EXIT_SUCCESS;
}
