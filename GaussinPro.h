#ifndef GAUSSINPRO_H__
#define GAUSSINPRO_H__
#include <armadillo>

using namespace arma;

extern int M; //the dimension of point we need to handle

mat zminushx(mat &a); 
mat Kernal(mat &arr_sample);
mat FindMaxu(mat &se,mat &sam);
mat Acqui(mat &arr,mat &maxu,int N);
mat Nextu(mat &NextP,mat &se,mat &SamTraPoi,mat &arr_sample);

#endif
