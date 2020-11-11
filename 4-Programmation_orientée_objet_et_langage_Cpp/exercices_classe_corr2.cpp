#include <iostream>

const int TAILLE = 100; // nb max d'élements dans un ensemble

class Ensemble {
public:
  Ensemble();
  void ajouter(int x);
  void retirer(int x);
  bool contient(int x) const;
  bool estEgal(const Ensemble &ens2) const;
  void afficher() const;

private:
  int elem[TAILLE]; // tableau dans lequel on range les élements de
                    // l'ensemble
  int nbElem;       // nb d'élements de l'ensemble

  int chercher(int x) const; // cherche x dans l'ensemble, retourne son
                             // indice dans elem ou -1 si non trouvé
};

Ensemble::Ensemble() { nbElem = 0; }

void Ensemble::ajouter(int x) {
  // on vérifie qu'il y a de la place dans l'ensemble
  if (nbElem < TAILLE) {
    // x est ajouté seulement s'il n'est pas déjà dans l'ensemble
    if (!contient(x)) {
      elem[nbElem] = x;
      nbElem++;
    }
  }
}

void Ensemble::retirer(int x) {
  int indice_x;

  indice_x = chercher(x);

  // si x a été trouvé dans l'ensemble
  if (indice_x >= 0) {
    // pour retirer x on peut décaler les élements suivants ou le remplacer
    // par le dernier élement (solution retenue)
    elem[indice_x] = elem[nbElem - 1];
    nbElem--;
  }
}

bool Ensemble::contient(int x) const {
  bool contenance;

  if (chercher(x) >= 0)
    contenance = true;
  else
    contenance = false;

  return contenance;
}

bool Ensemble::estEgal(const Ensemble &ens2) const {
  // les ensembles sont égaux s'ils ont même nb d'élements et si l'un des 2
  // contient chaque élement de l'autre

  bool egaux;

  if (nbElem != ens2.nbElem)
    egaux = false;
  else {
    // test pour savoir si ens2 contient chaque élement de l'ensemble
    // courant

    int i = 0;
    while (i < nbElem && ens2.contient(elem[i]))
      i++;

    if (i < nbElem)
      egaux = false;
    else
      egaux = true;
  }

  return egaux;
}

void Ensemble::afficher() const {
  std::cout << "(";

  for (int i = 0; i < nbElem; i++)
    std::cout << " " << elem[i];

  std::cout << " )" << std::endl;
}

int Ensemble::chercher(int x) const {
  int indice;

  int i = 0;
  while (i < nbElem && x != elem[i])
    i++;

  if (i < nbElem)
    indice = i;
  else
    indice = -1;

  return indice;
}

int main() {
  Ensemble e1;

  e1.ajouter(2);
  e1.ajouter(8);
  e1.ajouter(6);
  e1.ajouter(5);
  e1.ajouter(2);
  e1.afficher();

  e1.retirer(8);
  e1.retirer(5);
  e1.afficher();

  Ensemble e2, e3;
  e2.ajouter(2);
  e2.ajouter(6);
  e3.ajouter(6);
  e3.ajouter(2);

  if (e1.contient(6) || !e1.contient(5))
    std::cout << "contient ok" << std::endl;

  e3.ajouter(7);

  if (e1.estEgal(e2) && !e1.estEgal(e3))
    std::cout << "estEgal ok" << std::endl;

  return 0;
}
