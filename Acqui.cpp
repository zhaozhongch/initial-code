#include "GaussinPro.h"
#include <stdio.h>
#include <armadillo>

using namespace arma;

mat Acqui(mat &arr,mat &maxu,int N)
  {
    mat nextP;
    int ra;
    ra=rand()%N;
    if (ra%2==0) ra+=1;
    nextP=arr.row(ra);//The next point to sample should comes from DIRECT. I didn't do it yet but will be soon. So I just use an random number that not belong to training point. As I use the 2*i as sample point, so 2*+1 won't be one of them
    return nextP;
  }
