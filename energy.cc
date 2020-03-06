// energy.cc
//
// Aidin Attar. 2020

#include <cmath>
#include "definitions.h"

double energy( double th1, double th2, double w1, double w2 ){
  double T, U;
  
  T = + M1 / 2 * w1 * w1 * L1 * L1 
      + M2 / 2 * w1 * w1 * L1 * L1
      + M2 / 2 * w2 * w2 * L2 * L2
      + M2     * w1 * w2 * L1 * L2
      * cos( th1 - th2 );

  U = - M1 * G * L1 * cos( th1 )
      - M2 * G * L1 * cos( th1 )
      - M2 * G * L2 * cos( th2 );
  
  return T + U;
}