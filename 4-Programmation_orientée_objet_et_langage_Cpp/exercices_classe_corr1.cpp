#include <iostream>

class Complexe {
public:
  Complexe(float r, float i);
  Complexe(float r);

  void afficher() const;
  void ajouter(const Complexe &cx2);

private:
  float re, im;
};

Complexe::Complexe(float r, float i) : re(r), im(i) {}

Complexe::Complexe(float r) : re(r), im(0) {}

void Complexe::afficher() const {
  std::cout << re << " + " << im << "i" << std::endl;
}

void Complexe::ajouter(const Complexe &cx2) {
  re += cx2.re;
  im += cx2.im;
}

int main() {
  float a, b;
  std::cout << "Saisir un complexe : ";
  std::cin >> a >> b;

  Complexe c1(a, b);
  Complexe c2(3.1);
  Complexe c3(2, 5);

  c1.ajouter(c2);
  c1.ajouter(c3);
  std::cout << "Apres ajout de 3.1 et 2+5i : ";
  c1.afficher();

  return 0;
}
