// pendolo.cc
//
//
// Aidin Attar, 2020

#include <iostream>
#include  <fstream>
#include    <cmath>

#include "definitions.h"

void   runge_kutta( double , double*, double*, double                );
double      energy( double , double , double , double                );
void     cartesout( double*, double*, double*, double*, double*, int );
void     energyout( double*, double*,                            int );

int main( int argc, char *argv[] ){

  std::cout << std::endl
            << "************************************************"
            << std::endl
            << "---------------DOUBLE PENDULUM------------------"
            << std::endl
            << "************************************************"
            << std::endl << std::endl << std::endl;

  int i = 0, NSTEP;
  double h, TMIN, TMAX, TH10, W10, TH20, W20;
  double yin[ N ], yout[ N ];
  double  *t, *th1, *th2, *w1, *w2;
  double                        *H;

  // input of the initial values
  std::cout <<                  "istante iniziale: ";
  std::cin  >>                                  TMIN;
  std::cout <<                  "istante finale:   ";
  std::cin  >>                                  TMAX;
  std::cout <<     "angolo iniziale primo pendolo: ";
  std::cin  >>                                  TH10;
  std::cout <<   "angolo iniziale secondo pendolo: ";
  std::cin  >>                                  TH20;
  std::cout <<   "velocità iniziale primo pendolo: ";
  std::cin  >>                                   W10;
  std::cout << "velocità iniziale secondo pendolo: ";
  std::cin  >>                                   W20;
  std::cout <<                       "numero step: ";
  std::cin  >>                                 NSTEP;

  // allocate memory for arrays of values of time, angles 1 and 2,
  // and angular velocities 1 and 2 respectively 
  t   = new double[ NSTEP ];
  th1 = new double[ NSTEP ];
  w1  = new double[ NSTEP ];
  th2 = new double[ NSTEP ];
  w2  = new double[ NSTEP ];

  H   = new double[ NSTEP ];


  h = ( TMAX - TMIN ) / ( NSTEP - 1.0 );
 
  // Define array of t values
  for( i = 0; i < NSTEP; ++i )
    t[ i ] = TMIN + h * i;

  // convert all angles to radians
  th1[ 0 ] = TH10 * M_PI / 180.0;
  w1 [ 0 ] =  W10 * M_PI / 180.0;
  th2[ 0 ] = TH20 * M_PI / 180.0;
  w2 [ 0 ] =  W20 * M_PI / 180.0; 

  // integration
  std::string  output;
  std::cout << "nome file di output: ";
  std::cin  >> output;

  std::ofstream file( output.c_str() );

  // initial data
  file <<   t[ 0 ] << ' '
       << th1[ 0 ] << ' '
       <<  w1[ 0 ] << ' '
       << th2[ 0 ] << ' '
       <<  w2[ 0 ] << std::endl;

  for( i = 0; i < NSTEP - 1; ++i ){ 

    yin[ 0 ] = th1[ i ];
    yin[ 1 ] =  w1[ i ];
    yin[ 2 ] = th2[ i ];
    yin[ 3 ] =  w2[ i ];

    runge_kutta( t[ i ], yin, yout, h );

    th1[ i + 1 ] = yout[ 0 ];
    w1 [ i + 1 ] = yout[ 1 ];
    th2[ i + 1 ] = yout[ 2 ];
    w2 [ i + 1 ] = yout[ 3 ];

  /*
    while( th1[ i + 1 ] > + 2 * M_PI || th1[ i + 1 ] < - 2 * M_PI ){
      if( th1[ i + 1 ] > + 2 * M_PI ) th1[ i + 1 ] -= 2 * M_PI;
      if( th1[ i + 1 ] < - 2 * M_PI ) th1[ i + 1 ] += 2 * M_PI;
      }      

    while( th2[ i + 1 ] > + 2 * M_PI || th2[ i + 1 ] < - 2 * M_PI ){
      if( th2[ i + 1 ] > + 2 * M_PI ) th2[ i + 1 ] -= 2 * M_PI;
      if( th2[ i + 1 ] < - 2 * M_PI ) th2[ i + 1 ] += 2 * M_PI;
      }      
  */

    file <<   t[ i + 1 ] << ' '
         << th1[ i + 1 ] << ' '
         <<  w1[ i + 1 ] << ' '
         << th2[ i + 1 ] << ' '
         <<  w2[ i + 1 ] << std::endl;

  // energy computation
    H[ i ] = energy( th1[ i ], th2[ i ], w1[ i ], w2[ i ] ); 

  }

  // cartesian coordinates
  cartesout( t, th1,th2, w1, w2, NSTEP );

  // energy output
  energyout( t, H, NSTEP );

  std::cout << std::endl << std::endl
            << "----------------by Aidin Attar-------------------"
            << std::endl << std::endl;

  return 0;
}