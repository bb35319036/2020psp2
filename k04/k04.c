
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human_data                 //構造体を指定しそこにファイルの数値を配列として格納//
{
    int ID;
    int gender;
    double height;
};


int main(void)
{   
    int ID,i,j=0;
    char fname[FILENAME_MAX];
    char buf[256],buf2[256];
    FILE* fp;
    FILE* fp2;
    
    struct human_data data1 [14];

    
    printf("input the filename of sample height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
     
     fp = fopen(fname,"r");
    if(fp==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);

    }




     printf("input the filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    

    fp2 = fopen(fname,"r");
    if(fp2==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i=0;
    fgets(buf,sizeof(buf),fp);
     while(fgets(buf,sizeof(buf),fp)!= NULL){
        sscanf(buf,"%d,%lf",&data1[i].gender,&data1[i].height);//構造体human_dataにデータが空欄になるまで格納//
         i++;
     }
    i=0;
    while(fgets(buf2,sizeof(buf2),fp2) != NULL ){
        sscanf(buf2,"%d",&data1 [i].ID);
        i++;
     }
    

 if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);}
 if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);}

    printf("Which ID's data do you want? : ");
    scanf("%d",&ID);



    for(i=0;i<14;i++){                     //構造体の1から14番目を参照し入力された数字があればID、性別、身長を出力//
        if(ID==data1 [i].ID){
            printf("%d\n" ,data1[i].ID);
        if(data1[i].gender==1){
            printf("Male\n");
        }
        else
        {
            printf("Female\n");
        }
            printf("%.1lf\n" ,data1[i].height);
            j++;
       
        }

    }
    if(j==0){                                  //もしIDが一致しデータがあればｊは＋１されるのでプラスされない場合Nodataが出力される//
     printf("No data");
    }
return 0;
}
   
    

    