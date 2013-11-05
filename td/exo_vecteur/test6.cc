#include "vecteur.hh"

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

bool tests(const Vecteur& u, const Vecteur& v)
{
  const double s = 2.0;
  {
    Vecteur w = u + v;
    Vecteur wref(u);
    wref[0] = u[0] + v[0];
    wref[1] = u[1] + v[1];
    wref[2] = u[2] + v[2];
    if(w != wref)
    {
      cout << "u + v a retourné " << w << " au lieu de " << wref << endl;
      return false;
    }

    w = u;
    w += v;
    if(w != wref)
    {
      cout << "w += v a retourné " << w << " au lieu de " << wref << endl;
      return false;
    }
  }

  {
    Vecteur w = u - v;
    Vecteur wref(u);
    wref[0] = u[0] - v[0];
    wref[1] = u[1] - v[1];
    wref[2] = u[2] - v[2];
    if(w != wref)
    {
      cout << "u - v a retourné " << w << " au lieu de " << wref << endl;
      return false;
    }

    w = u;
    w -= v;
    if(w != wref)
    {
      cout << "w -= v a retourné " << w << " au lieu de " << wref << endl;
      return false;
    }
  }

  {
    Vecteur w = u * s;
    Vecteur wref(u);
    wref[0] = u[0] * s;
    wref[1] = u[1] * s;
    wref[2] = u[2] * s;
    if(w != wref)
    {
      cout << "u * " << s << " a retourné " << w << " au lieu de " << wref
           << endl;
      return false;
    }

    w = s * u;
    if(w != wref)
    {
      cout << s << " * u a retourné " << w << " au lieu de " << wref
           << endl;
      return false;
    }

    w = u;
    w *= s;
    if(w != wref)
    {
      cout << "w *= " << s << " a retourné " << w << " au lieu de " << wref
           << endl;
      return false;
    }
  }

  {
    Vecteur w = u / s;
    Vecteur wref(u);
    wref[0] = u[0] / s;
    wref[1] = u[1] / s;
    wref[2] = u[2] / s;
    if(w != wref)
    {
      cout << "u / " << s << " a retourné " << w << " au lieu de " << wref
           << endl;
      return false;
    }

    w = u;
    w /= s;
    if(w != wref)
    {
      cout << "w /= " << s << " a retourné " << w << " au lieu de " << wref
           << endl;
      return false;
    }
  }

  return true;
}

int main()
{
  Vecteur u(3);
  u[0] = 3.0;
  u[1] = 2.0;
  u[2] = 1.0;

  Vecteur v(3);
  v[0] = 7.0;
  v[1] = 8.0;
  v[2] = 9.0;

  Vecteur u2(2);
  u2[0] = u[0];
  u2[1] = u[1];

  if(u == u2) {
    cout << "u == u2 a retourné true pour des vecteurs de taille différente"
         << endl;
    return EXIT_FAILURE;
  }

  if(!(u != u2)) {
    cout << "u != u2 a retourné false pour des vecteurs de taille différente"
         << endl;
    return EXIT_FAILURE;
  }

  if(!(u == u)) {
    cout << "u == u a retourné false" << endl;
    return EXIT_FAILURE;
  }

  if(u == v) {
    cout << "u == v a retourné true" << endl;
    return EXIT_FAILURE;
  }

  if(u != u) {
    cout << "u != u a retourné true" << endl;
    return EXIT_FAILURE;
  }

  if(!(u != v)) {
    cout << "u != v a retourné false" << endl;
    return EXIT_FAILURE;
  }

  bool succes = tests(u, v);

  if(succes) {
    cout << "Test 6 réussi !" << endl;
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
