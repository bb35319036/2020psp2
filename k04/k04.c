
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human_data                 //�\���̂��w�肵�����Ƀt�@�C���̐��l��z��Ƃ��Ċi�[//
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
        sscanf(buf,"%d,%lf",&data1[i].gender,&data1[i].height);//�\����human_data�Ƀf�[�^���󗓂ɂȂ�܂Ŋi�[//
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



    for(i=0;i<14;i++){                     //�\���̂�1����14�Ԗڂ��Q�Ƃ����͂��ꂽ�����������ID�A���ʁA�g�����o��//
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
    if(j==0){                                  //����ID����v���f�[�^������΂��́{�P�����̂Ńv���X����Ȃ��ꍇNodata���o�͂����//
     printf("No data");
    }
return 0;
}
   
    

    