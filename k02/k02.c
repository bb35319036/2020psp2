#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

extern double p_stdnorm(double z);

int main(void)
{
    double val,z,aveA,sigmaA,aveB,sigmaB,L,max_val,min_val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;
    aveA=170.8;
    sigmaA=5.43;
    aveB=169.7;
    sigmaB=5.5;

    

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

    z=(val-aveA)/sigmaA;//標準化した値を出す
    L=p_stdnorm(z);//p_stdnormの関数に代入し、尤度を出す

    L1=L*L1;
     
     
     z=(val-aveB)/sigmaB;//Bの場合も同様
    L=p_stdnorm(z);

    L2=L*L2;



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

if(L1>L2){//if文で最大最小を比較

    max_val=L1;
    min_val=L2;}
else{ 
    min_val=L2;
    max_val=L1;}
 
  printf("L_A: %f\n",max_val);
  printf("L_B: %f\n",min_val);

    return 0;


}



double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

