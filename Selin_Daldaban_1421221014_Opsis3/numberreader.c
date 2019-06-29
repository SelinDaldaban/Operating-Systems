#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//int str cevrim
char *intstr(int number)
{
    int count=0;
    int numbertmp=number;
    while(numbertmp>0)
    {
        int digit= numbertmp%10;
        numbertmp/=10;
        count++;
    }
    char * value= (char * ) calloc (count,sizeof(unsigned char)  );
    numbertmp=number;
    count--;
    while(numbertmp>0)
    {
        int digit= numbertmp%10;
        numbertmp/=10;
        char x=(char) 48+digit;
        *(value+count)=x;
        count--;
    }

    return value;
}
//str int cevrim
int strint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("\nGecersiz islem");
            break;
         }
 }
 return number;
}
int main(int argc,char *argv[])
{   
  

    int npipefd;
    //named pipe adresi
    char * myfifo = "/tmp/myfifo";
    //adresi pipe yapıyoruz 0666 rwx-rwx-rwx >0-110-110-110
    mkfifo(myfifo, 0666);

     int x;
        int i;
     char *is=(char*)calloc(10, sizeof(char));
     FILE *fp;
    char *str[8];
    char* filename = "numbers.txt";
 
    fp = fopen(filename, "r");  //dosya okuma
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }   
   
    while (fgets(str, 8, fp) != NULL){
        char *arr=(char*)calloc(10, sizeof(char));
        char *arr2=(char*)calloc(10, sizeof(char));
        npipefd = open(myfifo, O_RDONLY);  //x y z karakterini okur
        read(npipefd, arr, sizeof(arr));
        close(npipefd);
   
        printf("%s = %s\n",arr,str);
     
        
        npipefd = open(myfifo, O_WRONLY);  //dosyadaki degeri xyztotalizera gönderir.
     
        write(npipefd, str, sizeof(str));
        close(npipefd);
        sleep(2);
        }  
     fclose(fp);
    return 0;

   

}
