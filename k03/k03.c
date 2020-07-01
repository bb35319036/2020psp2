#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

extern double r_unif(void);
extern double r_stdnorm(void);

int main(void)
{
    
    double val, mu,S,S2,Tall;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

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

    mu=(mu+val)/8;

     }
     S=0;
     S2=0;
     while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
    S=pow((val-mu),2);
    S2=(S2+S)/8;
    }


    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

printf("%f\n",S2);
printf("%f",mu);
Tall=r_stdnorm*
 
 
    return 0;


}


double r_unif(void)
{
    return (double)(rand()+1)/(RAND_MAX+2);
}
  
double r_stdnorm(void)
{  
    return sqrt( -2.0*log(r_unif()) ) * sin( 2.0*M_PI*r_unif() );
} 

