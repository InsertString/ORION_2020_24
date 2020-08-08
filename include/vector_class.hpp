#ifndef _VECTOR_CLAS_HPP_
#define _VECTOR_CLAS_HPP_

class CVector {
public:
  double x, y;
  CVector (){}
  CVector (double a, double b) : x(a), y(b) {}
  CVector operator + (const CVector&);
  CVector operator * (const double&);
  double getLength();
  double getAngle();
};

#endif
