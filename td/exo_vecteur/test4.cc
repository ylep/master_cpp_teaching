#include "vecteur.hh"

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

bool test()
{
  Vecteur v3(3);
  v3.set(0, 7.0);
  v3.set(1, 8.0);
  v3.set(2, 9.0);

  Vecteur v_copie(v3);

  unsigned int size = v_copie.size();
  if(size != 3)
  {
    cout << "Le vecteur copié a la taille " << size << " au lieu de 3" << endl;
    return false;
  }
  if(v_copie.size() != v3.size() ||
     v_copie.get(0) != v3.get(0) ||
     v_copie.get(1) != v3.get(1) ||
     v_copie.get(2) != v3.get(2))
  {
    cout << "Le vecteur copié est " << v_copie << " au lieu de " << v3 << endl;
    return false;
  }

  Vecteur v(0);

  v = v3;
  if(size != 3)
  {
    cout << "Le vecteur affecté a la taille " << size << " au lieu de 3" << endl;
    return false;
  }
  if(v.size() != v3.size() ||
     v.get(0) != v3.get(0) ||
     v.get(1) != v3.get(1) ||
     v.get(2) != v3.get(2))
  {
    cout << "Le vecteur affecté est " << v << " au lieu de " << v3 << endl;
    return false;
  }

  return true;
}

int main()
{
  // Avec une fonction de test annexe les erreurs dans les destructeurs
  // apparaissent avant le message de succès
  bool succes = test();

  if(succes) {
    cout << "Test 4 réussi !" << endl;
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
