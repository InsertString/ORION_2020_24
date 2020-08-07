#include "main.h"
#include "odometry_stuff.hpp"

using namespace std;

// wheels are 200mm circumfrance
double LeftDistCM() {
  return LeftEncoder.get_value() * 45;
}

double RightDistCM() {
  return RightEncoder.get_value() * 45;
}

class CVector {
public:
  double x, y;
  CVector (){}
  CVector (double a, double b) : x(a), y(b) {}
  CVector operator + (const CVector&);
  double getLength() {
    return sqrt(pow(x, 2) + pow(y, 2));
  }
};
