#include "heat_difusion.h"

void heat_difusion(){
  
  const int N = 1000000; // mm
  double *T_n = new double[N];
  double *T_n1 = new double[N];
  double alpha_gold =  127; // mm^2/s, coeficiente de difusão térmica
  double t_f = 10.0; // tempo final em segundos
  double t = 0.0; // time in seconds
  
  // time representation of each iteration
  double dt=0.001; //seconds
  
  //initial temperatures
  for(int k=0; k < N-2; k++){
    T_n[k] = 25.0;
  }

  T_n[ 0 ] = 100.0; // one edge
  T_n[N - 1] = 100.0; //the other edge of the stick of gold

  while(t < t_f){
    //TODO - T_n1[k] has some error
    for(int k=0; k<N-2; k++){
      T_n1[k] = T_n[k] + (T_n[k+2] - 2.0 * T_n[k+1] + T_n[k]) * dt / alpha_gold;
    }
    std::cout << "t = " << t << "T(t) = " << T_n[int(N/2)] << std::endl;
    t += dt; 
  }

  delete [] T_n;
  delete [] T_n1;
}
