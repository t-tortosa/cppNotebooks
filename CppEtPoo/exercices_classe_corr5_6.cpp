#include <iostream>
using namespace std;

class Vect {
public:
  Vect(float a, float b, float c);
  Vect();

  friend istream &operator>>(istream &flot, Vect &v);
  friend ostream &operator<<(ostream &flot, const Vect &v);

  Vect operator+(const Vect &v2) const;

  // "un scalaire" * "un vecteur"
  // nécessairement friend car le 1er opérande n'est pas un objet Vect
  friend Vect operator*(float a, const Vect &v);

  // "un vecteur" * "un scalaire"
  Vect operator*(float a);

  // produit scalaire de 2 vecteurs
  float operator*(const Vect &v2) const;

  bool operator==(const Vect &v2) const;
  bool operator!=(const Vect &v2) const;

private:
  float x, y, z;
};

Vect::Vect(float a, float b, float c) {
  x = a;
  y = b;
  z = c;
}

Vect::Vect() {
  x = 0;
  y = 0;
  z = 0;
}

istream &operator>>(istream &flot, Vect &v) {
  flot >> v.x >> v.y >> v.z;
  return flot;
}

ostream &operator<<(ostream &flot, const Vect &v) {
  flot << "(" << v.x << ", " << v.y << ", " << v.z << ")";
  return flot;
}

Vect Vect::operator+(const Vect &v2) const {
  Vect vecSomme(x + v2.x, y + v2.y, z + v2.z);
  return vecSomme;
}

Vect operator*(float a, const Vect &v) {
  Vect vecProduit(a * v.x, a * v.y, a * v.z);
  return vecProduit;
}

Vect Vect::operator*(float a) {
  Vect vecProduit(a * x, a * y, a * z);
  return vecProduit;
}

float Vect::operator*(const Vect &v2) const {
  return x * v2.x + y * v2.y + z * v2.z;
}

bool Vect::operator==(const Vect &v2) const {
  return x == v2.x && y == v2.y && z == v2.z;
}

bool Vect::operator!=(const Vect &v2) const {
  return x != v2.x || y != v2.y || z != v2.z;
}

int main() {
  Vect v1, v2;

  cout << "entrer 2 vecteurs : ";
  cin >> v1 >> v2;

  cout << "somme = " << v1 + v2 << endl;
  cout << "produit scalaire = " << v1 * v2 << endl;

  float s;
  cout << "entrer un reel : ";
  cin >> s;
  cout << "produit du reel et de v1 = " << s * v1 << endl;
  cout << "produit de v1 et du reel = " << v1 * s << endl;

  cout << "pour les vecteurs saisis," << endl;

  cout << "resultat du test par == : ";
  if (v1 == v2)
    cout << "egaux" << endl;
  else
    cout << "differents" << endl;

  cout << "resultat du test par != : ";
  if (v1 != v2)
    cout << "differents" << endl;
  else
    cout << "egaux" << endl;

  return 0;
}
