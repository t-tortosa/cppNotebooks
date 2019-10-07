#include <iostream>
using namespace std;

class Point {
public:
  Point(float x0, float y0) {
    x = x0;
    y = y0;
  }

  float getX() const { return x; }
  float getY() const { return y; }

  void setX(float nx) { x = nx; }
  void setY(float ny) { y = ny; }

private:
  float x, y;
};

class Segment {
public:
  Segment(const Point &a, const Point &b);
  void translation(const Point &nouvOrg);
  void afficher() const;

private:
  Point org, ext;
};

/* dans la liste d'initialisation, appel des constructeurs des objets membres
org et ext
1ere version : pour org et ext, appel du constructeur Point(int,int)
2eme version : pour org et ext, appel du constructeur par copie de Point
*/
Segment::Segment(const Point &a, const Point &b)
    : org(a.getX(), a.getY()), ext(b.getX(), b.getY())
//: org(a), ext(b)    // 2eme version
{}

void Segment::translation(const Point &nouvOrg) {
  // calcul des déplacements sur x et sur y
  float dx = nouvOrg.getX() - org.getX();
  float dy = nouvOrg.getY() - org.getY();

  org.setX(nouvOrg.getX());
  org.setY(nouvOrg.getY());

  ext.setX(ext.getX() + dx);
  ext.setY(ext.getY() + dy);

  /* si setX et setY n'existaient pas, on aurait pu modifier org et ext
   * ainsi :
  org = nouvOrg;
  Point nouvExt (ext.getX() + dx, ext.getY() + dy);
  ext = nouvExt;
  */
}

void Segment::afficher() const {
  cout << "origine(" << org.getX() << "," << org.getY() << ")"
       << ", extremite(" << ext.getX() << "," << ext.getY() << ")" << endl;
}

int main() {
  Point A(1, 2), B(8, 5), C(15, 20);
  A.setX(3);
  A.setY(4);
  cout << A.getX() << "," << A.getY() << endl;

  Segment S1(A, B);
  S1.afficher();

  cout << "apres translation en (" << C.getX() << "," << C.getY()
       << ") :" << endl;
  S1.translation(C);
  S1.afficher();

  return 0;
}
