#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
pthread_mutex_t lockx;
pthread_mutex_t locky;
pthread_mutex_t lockz;
int linenum=0;
int toplam=0;
int degerli;

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
    char * value= (char * ) calloc (count,sizeof(unsigned char) );
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


 int readnumber(char karakter, int linenum){    
    int npipefd;
    //named pipe adresi
    char * myfifo = "/tmp/myfifo";
 
    mkfifo(myfifo, 0666);
 
    char *is=(char*)calloc(10, sizeof(char));

     int i;

    char arr[3];char arr2[3];
    arr[0]=karakter;
    arr2[0]=linenum;
    char *iss=(char*)calloc(10, sizeof(char));
    for (i=0; i<1; i++)
    {   
        
        npipefd = open(myfifo, O_WRONLY);      //x y z degerlerini gondermek icin kullanılır.
       // is=intstr(i);
        write(npipefd, arr, strlen(arr)+1);
        close(npipefd);
       // printf("ben karakterim gittim.");

        //i degerini pipedan oku
        npipefd = open(myfifo,O_RDONLY);    //textteki degeri okumak icin kullanilir.
        read(npipefd, is, 10);
        printf("%s = %s\n", arr, is);
        degerli= atoi(is); //degerli=degerli+2;
       // iss=intstr(degerli);
        
        close(npipefd);
        
    }  
 linenum++;

 return degerli;
}



void *xmetot()   //x threadi icin
{
	while(1)
	{
		pthread_mutex_lock(&lockx);  //x i kitle
        int xman=readnumber('x', linenum);   //degeri toplama icin al
	    
        toplam+=xman;  //x degerini 
	//		sleep(5);

		pthread_mutex_unlock(&locky);  // y nin kilidini ac
	}
}

void *ymetot()  //y threadi icin
{
	while(1)
	{
		pthread_mutex_lock(&locky);  //y i kitle
		int yikik=readnumber('y', linenum);  //degeri toplama icin al
        
        toplam+=yikik;

       
        
		pthread_mutex_unlock(&lockz);  // z nin kilidini ac
	}
}

void *zmetot() // z threadi icin
{
	while(1)
	{   char *t=(char*)calloc(10, sizeof(char));
		pthread_mutex_lock(&lockz);   //z i kitle
	    int zeytin=readnumber('z' , linenum);  //degeri toplama icin al
        toplam+=zeytin;
        t=intstr(toplam);
        printf("x+y+z = %s \n", t);
        toplam=0;   // sifirlayarak üstü üste toplamasi engellenir
     
		pthread_mutex_unlock(&lockx);  // x nin kilidini ac
	}
}



int main(int argc,char *argv[]){
 char *a=(char*)calloc(10, sizeof(char));
 a=argv[1];
 int readcount =atoi(a);  //kac kere yapilacagina dair inte cevrilir
//printf("%s : " , a);
//printf("%d : " , &readcount);
    int i;
    
    pthread_t xthread;
	pthread_t ythread;
	pthread_t zthread;
    pthread_mutex_init(&lockx, NULL);
	pthread_mutex_init(&locky, NULL);
	pthread_mutex_init(&lockz, NULL);
    for (i =0 ; i< (readcount/3) ; i++){
    void* status;
    pthread_mutex_lock(&locky); // y kilitle
	pthread_mutex_lock(&lockz); //z kilitle
    pthread_create(&xthread,NULL,xmetot,NULL);  
    pthread_create(&ythread,NULL,ymetot,NULL);
    pthread_create(&zthread,NULL,zmetot,NULL);
	pthread_join(xthread,&status);
	pthread_join(ythread,&status);
	pthread_join(zthread,&status);
    pthread_mutex_destroy(&lockx); //olmasa olabilir
	pthread_mutex_destroy(&locky); // olmasa olabilir
	pthread_mutex_destroy(&lockz); // olmasa olabilir   
       }
	return 0;
}
