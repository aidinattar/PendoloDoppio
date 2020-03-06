// output.cc
//
// Aidin Attar. 2020

#include <iostream>
#include <fstream>
#include <cmath>

#include "definitions.h"


void cartesout( double *t, double *th1, double *th2, double *w1, double *w2, int NSTEP ){
  double *x1,  *x2,  *y1, *y2;

  x1  = new double[ NSTEP ];
  y1  = new double[ NSTEP ];
  x2  = new double[ NSTEP ];
  y2  = new double[ NSTEP ];

  std::string outputc; 
  std::cout << "file coordinate cartesiane: ";
  std::cin  >> outputc;

  std::ofstream cartesian( outputc.c_str() );

  for( int i = 0; i < NSTEP; ++i ){
    x1[ i ] =           L1 * sin( th1[ i ] );
    y1[ i ] =         - L1 * cos( th1[ i ] );
    x2[ i ] = x1[ i ] + L2 * sin( th2[ i ] );
    y2[ i ] = y1[ i ] - L2 * cos( th2[ i ] );

    cartesian <<  t[ i ] << ' '
              << x1[ i ] << ' '
              << y1[ i ] << ' '
              << x2[ i ] << ' '
              << y2[ i ] << std::endl;
  }

  return;
}


void energyout( double* t, double* H, int NSTEP ){

  std::string energyfile; 
  std::cout << "file energie: ";
  std::cin  >> energyfile;

  std::ofstream energy( energyfile.c_str() );

  for( int i = 0; i < NSTEP - 1; ++i )
    energy << t[ i ] << ' ' 
           << H[ i ] << std::endl;

  return;
}