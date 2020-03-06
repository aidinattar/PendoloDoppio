// runge_kutta.cc
//
// Aidin Attar. 2020

#include <cmath>
#include "definitions.h"

void       deriv( double xin, double yin[], double dydx[]           );

void runge_kutta( double xin, double yin[], double yout[], double h ){
  // fourth order Runge-Kutta

  int i;
  double hh,             xh,
         dydx[ N ], yt[ N ],
         k1  [ N ], k2[ N ],
         k3  [ N ], k4[ N ];

  hh = 0.5 * h;
  xh = xin + hh; // ti + delta / 2

  // first step
  deriv( xin, yin, dydx ); 
  for( i = 0; i < N; ++i ){
    k1[ i ] = h              * dydx[ i ]; // f( Y1, ti ) * delta/2
    yt[ i ] = yin[ i ] + 0.5 *   k1[ i ]; // Y2
  }

  // second step
  deriv( xh, yt, dydx );
  for( i = 0; i < N; ++i ){
    k2[ i ] = h              * dydx[ i ]; // f( Y2, ti + delta/2 ) * delta
    yt[ i ] = yin[ i ] + 0.5 *    k2[ i ]; // Y3
  }

  // third step
  deriv( xh, yt, dydx );
  for( i = 0; i < N; ++i ){
    k3[ i ] = h        * dydx[ i ];
    yt[ i ] = yin[ i ] +    k3[ i ];
  }

  // fourth step
  deriv( xin, yt, dydx ); 
  for( i = 0; i < N; ++i ){
    k4  [ i ] = h * dydx[ i ];
    yout[ i ] = yin[ i ] 
              + k1 [ i ] / 6.
              + k2 [ i ] / 3.
              + k3 [ i ] / 3.
              + k4 [ i ] / 6.;
  }

  return;
}



void deriv( double xin, double yin[], double dydx[] ){

  // function to fill array of derivatives dydx at xin

  double den1, den2, del; // denominatore 1, 2 e delta theta

  dydx[ 0 ] =                                               yin[ 1 ]; // theta1 = w1
  
  del       =                                    yin[ 2 ] - yin[ 0 ]; // delta theta
  den1      = (   M1 + M2 ) * L1 - M2 * L1 * cos( del ) * cos( del );
  
  dydx[ 1 ] = ( M2 * L1   * yin[ 1 ] * yin[ 1 ] * sin( del ) * cos( del )
            +   M2 *  G   * sin(       yin[ 2 ]            ) * cos( del ) 
            +   M2 * L2   * yin[ 3 ] * yin[ 3 ]              * sin( del )
            - ( M1 + M2 ) * G   * sin( yin[ 0 ] ) )               / den1;

  dydx[ 2 ] = yin[ 3 ];

  den2      = (   L2 / L1 ) * den1;
  dydx[ 3 ] = ( - M2 * L2   * yin[ 3 ] * yin[ 3 ] * sin( del ) * cos( del )
            + (   M1 + M2 ) *  G  * sin( yin[ 0 ] )            * cos( del ) 
            - (   M1 + M2 ) * L1  *      yin[ 1 ] * yin[ 1 ]   * sin( del )
            - (   M1 + M2 ) *  G  * sin( yin[ 2 ] ) )          /      den2;

  return;
}
