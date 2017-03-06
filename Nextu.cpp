#include "GaussinPro.h"
#include <stdio.h>
#include <armadillo>

using namespace arma;

mat Nextu(mat &NextP,mat &se,mat &SamTraPoi,mat &arr_sample)
  {
    int j,k;
    int num=se.n_rows;
    double e=2.718;
    double sum_temp,b;
    mat nextu,next_var,knew(1,num),invse;
    mat A(1,1); A.fill(1.0);//(k(t+1),k(t+1))=1;
    mat B(1,1); //B is used to give a value to scalar b, B should be knew*invse*knew.t(), and b =B(0,0); b is used to calculate the variance of t+1 point
    invse=inv(se);
    for(k=0;k<num;k++)
       {
         for(j=0;j<M;j++)
           {
             sum_temp=sum_temp+(NextP(0,j)-arr_sample(k,j))* (NextP(0,j)-arr_sample(k,j));
           }
         knew(0,k)=pow(e,-12.5*sum_temp);
         sum_temp=0;
       } 
    //knew.print("knew is \n");
    nextu=knew*invse*SamTraPoi;//expect of t+1 sample point
    B=knew*invse*knew.t();b=B(0,0); //we need get the variance to put it into PI.
    //next_var=knew-b;//if we use knew-B , matrix doen't match. convert B to a scalar so that every element of knew can subtract b 
    se.insert_rows(num,knew);
    knew.insert_cols(num,A);
    se.insert_cols(num,knew.t()); //Now we have new se which has 1 column and 1 row more
    return nextu;
  }
