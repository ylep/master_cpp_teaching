#include <vecteur.hh>

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
  // Test du constructeur
  Vecteur v3(3);
  const Vecteur v100000(100000);

  // Tests de la méthode size()
  unsigned int size = v3.size();
  if(size != 3)
  {
    cout << "La méthode size() a retourné " << size << " au lieu de 3" << endl;
    return EXIT_FAILURE;
  }

  // Test de la méthode size() sur un objet constant
  if(v100000.size() != 100000)
  {
    cout << "La méthode size() a retourné " << size << " au lieu de 100000" << endl;
    return EXIT_FAILURE;
  }

  // Test des méthodes set() et get()
  v3.set(0, 7.0);
  v3.set(1, 8.0);
  v3.set(2, 9.0);
  if(v3.get(0) != 7.0 || v3.get(1) != 8.0 || v3.get(2) != 9.0)
  {
    cout << "La méthode get() n'a pas retourné la bonne valeur" << endl;
    return EXIT_FAILURE;
  }

  // Test de la méthode get() sur un objet constant
  v100000.get(99999);

  cout << "Test 1 réussi !" << endl;
  return EXIT_SUCCESS;
}
