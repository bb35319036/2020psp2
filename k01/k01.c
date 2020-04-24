#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double ave,double val ,int i)
{return ((i-1)*ave)/i + val/i;}//平均を求める式を入力


extern double var_online(double val, double ave, double square_ave ,int i)
{
    return(((i-1)*square_ave/i)+pow(val,2)/i)-pow((((i-1)*ave/i)+(val/i)),2);}//分散を求める式を入力
int main(void)
{
    double ave,val,var,square_ave;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double Fx;
    int i;
    i=0;


    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");//fileを開いてる　ここでは読み取り専用
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%lf",&val);
        i++;//i=0と宣言しているのでi++を前に置く
        var=var_online(val,ave,square_ave,i);//自作した分散を求める関数を繰り返すようにここに置く
        ave=ave_online(ave,val,i);

        square_ave=ave_online(square_ave,pow(val,2),i);//（平均,値、n)　分散の式で利用する2乗の平均を求めたいので平均を求める関数をここでも使用する


    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    Fx=i*var/(i-1);

    printf("ave=%lf\n",ave);
    printf("var=%lf\n",var);

    printf("est var=%lf\n",Fx);
    printf("est ave=%lf\n",ave);//READ ME の「平均の推定値は，標本の平均が最良である」より平均をもう一度出力
    return 0;
    
}
