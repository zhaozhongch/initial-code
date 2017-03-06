#include "GaussinPro.h"
#include <stdio.h>
#include <armadillo>

using namespace arma;


mat zminushx(mat &a)
  {
    int j,i;
    int len=a.n_rows;
    double temp1=0, temp2=0;
    mat temp(len,2);
    //a.print("a is \n");
    for(i=0;i<len;i++)
      { 
       temp1=0;temp2=0;
       for(j=0;j<M;j++)
           {
             if (j<4) temp1 += a(i,j);
             else temp2 += a(i,j); 
           }
       temp(i,0)=temp1/10;//there are two columns of a pixel (x,y) according to z-h(x), I believe in vicalib we should have some function to get z-h(x). So here I just use two sum to take the place of
//it temply...
       temp(i,1)=temp2/10;//Error is small, so I use temp over 10 to replace it.
      }
     //temp.print("temp is :\n");
     return temp;
  };

 
//number.This function is used to show z-h(x), the data we want to sample with a 10 dimension point. 
