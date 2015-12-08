#include <iostream>
#include <cmath>

using namespace std;
//--------------------------------------
void f(double* ys,const double* const y, const double eta );
//--------------------------------------
int main(void){
  const double T = 100;
  double t=0;
  double y[2],k1[2],k2[2],k3[2],ytemp[2];
  const double eta = 0.4;
  const double dt = 0.01;
  const int N = T/dt;

  y[0] = 1e-5;
  y[1] = sqrt(eta)*y[0];


  for(int i=0; i<N; i++){
     t += dt;

     f(k1, y, eta);

     ytemp[0] = y[0] + 0.5 * dt * k1[0];
     ytemp[1] = y[1] + 0.5 * dt * k1[1];
     f(k2, ytemp, eta);

     ytemp[0] = y[0]- dt * k1[0] + 2.0 * dt * k2[0];
     ytemp[1] = y[1]- dt * k1[1] + 2.0 * dt * k2[1];
     f(k3, ytemp, eta);

     y[0] += dt/6.0 * (k1[0]+ 4 * k2[0] + k3[0]);
     y[1] += dt/6.0 * (k1[1]+ 4 * k2[1] + k3[1]);

     cout << t << "\t" << y[0] << "\t" << y[1] << endl;
  }


  return 0;
}
//-------------------------------------------------
void f(double* ys,const double* const y, const double eta ){
   ys[0] = y[1];
   ys[1] = y[0]*(eta - y[0]*y[0]);
}
