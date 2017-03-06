#include "GaussinPro.h"
#include <stdio.h>
#include <armadillo>

using namespace arma;

mat FindMaxu(mat &se,mat &sam)
  {
    int i=0;
    double sum=0,tempsum=0;
    mat tempinv,tempu,finalu;
    for(i=0;i<se.n_rows;i++)
        {
           se.swap_rows(0,i);se.swap_cols(0,i);sam.swap_rows(0,i);//swap rows to make se(i,i) and always be se(0,0) to simplify the computation. swap returns void so cannot let A=B.swap.
           tempinv=inv(se(span(1,se.n_rows-1),span(1,se.n_cols-1)));
           tempu=se(span(0,0),span(1,se.n_rows-1))*tempinv*sam(span(1,sam.n_rows-1),span(0,1));//Use conditional distri of multivariable normal distri.
           tempsum=tempu(0,0)*tempu(0,0)+tempu(0,1)*tempu(0,1);
             if (tempsum>sum)
                 {
                  sum=tempsum;
                  finalu=tempu;
                 }
           se.swap_rows(0,i);se.swap_cols(0,i);sam.swap_rows(0,i);//swap back to let we get the original matrix for next time's computation.
        }
    
     return finalu;
  };
