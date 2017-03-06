#include "GaussinPro.h"
#include <stdio.h>
#include <armadillo>

using namespace arma;

mat Kernal(mat &arr_sample)
   {
    int i,k,j;
    int len=arr_sample.n_rows;
    double sum_temp=0.0;
    float e=2.718;
    mat se(len,len);
    se.fill(0.0);
     //get kernal function
   for (i=0;i<len;i++) //we have the length of rows for the kernal
     {
        for(k=0;k<len;k++) //This is for getting the i th row of the kernal Matrix
        {
            if (i==k)
                 {
                   se(i,k)=1;//diagonal is all 1
                   continue;
                 }
            else if (se(i,k)!=0.0) continue ; //if it is not zero, then we have get its value with symmetry property. If we have give se[i][k] a certain value before with symmetry property, 
                                              //it won't be 0 because of exponential  
            else for(j=0;j<M;j++) sum_temp=sum_temp+(arr_sample(i,j)-arr_sample(k,j))* (arr_sample(i,j)-arr_sample(k,j));
            //printf("%f    ", sum_temp);
            se(i,k)=pow(e,-12.5*sum_temp);// be careful if sum_temp is like 10 *exp(-12.5*10), almost 0(computer will set it as 0). to avoid this, we need set the difference of each test point to be small.
                                          //  I do this by set the point to be small, so I use randu()/10^10 as randu is about 10^9
            se(k,i)=se(i,k);//kernal Matrix is a symmetry Matrix, so if we get se[2][3] we don't need compute se[3][2] again.
            sum_temp=0;
         }    
     }
    //se.print();
    return se;
   }
