#include <stdio.h>
#include <stdlib.h>
//#include <math.h>//don't need math.h for pow(a,b);
#include <armadillo>
#include "GaussinPro.h"

using namespace std;
using namespace arma;


int M=10;

int main()
{ 
  int i=0,j=0,k=0,N=60;
  printf("Please enter how many 10 dimension data you want to have for test, should be at least 60 \n");
  std::cin>>N;
  mat sample(1,M*3);//use 3 times of the dimension as sample
  mat arr_sample(M*3,M);
  //use square exponential kernal with cita=0.2(use this as a test, matern later). we sample 10*3 points as training set
  mat nextSam;
  mat SamTraPoi;
  mat Maxu;
  mat arr(N,M);
  mat NextP;
  mat nextu;
  mat se;
 
  
  srand((unsigned)time(NULL));
 
  
  for(i=0;i<N;i++)
   {
      for(j=0;j<M;j++)
         {
          arr(i,j)=(double)rand()/10000000000;//must use double, or we'll get 1,2.... int. reason to deduct 10^10 can be seen 'kernal'
         }
   } //generate 10 dimension N row for test


 
   for (i=0;i<M*3;i++) //rearrange the 10 dimension points needed to be sampled
     {
        for(j=0;j<M;j++)
          {
           arr_sample(i,j)=arr(i*2,j);
          }
     }
///This way can avoid two same index number comparing to rand(). I sample every 2 elements below. In fact if I have abunch of data, I can sample every 100, that can laso be looked as 'randam'

//The following steps should have iteration like 30 times or Nextu we find is smaller than a threshold, now I just the following as a test for just one iteration
//arr_sample.print("arr_sample is:\n");
SamTraPoi=zminushx(arr_sample); //Get the z-h(x) from sample points
//SamTraPoi.print("SamTraPoi is \n");
se=Kernal(arr_sample);
//se.print("se: \n");
Maxu=FindMaxu(se,SamTraPoi);
//Maxu.print("maxu is \n");
NextP=Acqui(arr,Maxu,N);
//NextP.print("Next point to sample is \n");
nextu=Nextu(NextP,se,SamTraPoi,arr_sample);
//printf("num of se row and col is %d and %d",se.n_rows,se.n_cols);
  return 0;
  
};




