#include "main.h"
#include "math.h"

using namespace std;

class CVector {
public:
  double x, y;
  CVector (){}
  CVector (double a, double b) : x(a), y(b) {}
  CVector operator + (const CVector&);
  CVector operator * (const double&);
  double getLength() {
    return sqrt(pow(x, 2) + pow(y, 2));
  }
  double getAngle() {
    return tan(y / x);
  }
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

CVector CVector::operator* (const double& param) {
  CVector temp;
  temp.x = x * param;
  temp.y = y * param;
  return temp;
}
