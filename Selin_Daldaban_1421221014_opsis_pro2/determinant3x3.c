#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>   

int main(void)
{   

 
   int pipefd[2];
   int fv;
   int x[2][2]; int y[2][2]; int z[2][2];  
  if (pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
      }
   int dizi[3][3];
   printf("9 eleman giriniz\n");
   int j=0;
   int i = 0;
  int c;
   for(i=0;i<3;i++) //Burada ise döngü yardımıyla matrisimizin tüm elemanlarını dışarıdan giriyoruz.
   {
      for(j=0;j<3;j++)
      {
   scanf("%d",&dizi[i][j]);
      }
   }
     printf("matris\n");
 fflush(stdin); 
    for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
     {
      printf("%d\t",dizi[i][j]);   //matrisi yazdirdim
     }
    printf("\n");
    }    

 int pid = fork();
 char  ch_arr[6][10];
int random_index=4;
      if (pid == 0) {
          
          c = execv("satsutsec", NULL);
           // hata olusursa
          perror("");
        close(pipefd[0]);
      } else if(pid>0){
          
         wait(&c);//mod5 programinin cagirildigi prosesi bekle 
       
         read(pipefd[0], &ch_arr[random_index], sizeof(char)*4); //sonucu pipe oku
         printf("random deger : %s\n",&ch_arr[random_index]); //ekrana yazdır
       
        }
     
    
                              if (!strcmp(ch_arr[random_index],"sat1")){   
      // eger satsutsecten gelen deger sat1 se degerleri 3 alt diziye yerlestirir                              
                                 for(i=0;i<3;i++)
                                     {
                                     for(j=0;j<3;j++)
                                            {   //0-0
                                            if(dizi[i][j]==dizi[1][1]){ //x dizisine yerlestirir
                                                  x[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][2]){
                                                  x[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][1]){
                                                  x[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][2]){
                                                  x[1][1]=dizi[i][j];
                                                  
                                                      }  //0-1
                                            if(dizi[i][j]==dizi[1][0]){  //y dizisine yerlestirir
                                                  y[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][0]){
                                                  y[1][0]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[1][2]){
                                                 y[0][1]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][2]){
                                                  y[1][1]=dizi[i][j];
                                                  
                                                      }//0-2
                                            if(dizi[i][j]==dizi[1][0]){ //z dizisine yerlestirir
                                                  z[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][1]){
                                                  z[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][0]){
                                                 z[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][1]){
                                                  z[1][1]=dizi[i][j];
                                                  
                                                      }
   }  }   int xkonum=2; int ykonum=3; int zkonum=4;  
         int fv = fork(); if (fv == 0 ) { 
            write(pipefd[1], &x, sizeof(int)*20) ; //3 dizinin elemanlarini yolladim
            write(pipefd[1], &y, sizeof(int)*20) ;
            write(pipefd[1], &z, sizeof(int)*20) ;
            write(pipefd[1], &xkonum, sizeof(int)) ;//us degerlerini yolladim
            write(pipefd[1], &ykonum, sizeof(int)) ;
            write(pipefd[1], &zkonum, sizeof(int)) ;
           c = execv("kofakhesap2x2", NULL); //kofaktor programina yollar
            perror("");
           close(pipefd[0]);
            }
            else if(fv>0){
                
             wait(&c);//kofaktor programinin cagirildigi prosesi bekle 
            
             int sonucx; int sonucy; int sonucz;
             read(pipefd[0], &sonucx, sizeof(int)); //sonucu pipe oku
             read(pipefd[0], &sonucy, sizeof(int));
             read(pipefd[0], &sonucz, sizeof(int));
           
             printf(" sat 1 icin determinant sonuc : %d \n : " , sonucx+sonucy+sonucz ); //toplamda determinant sonucu cikar
                           }
              }

                         // AYNI ISLEMLER SAT2, SAT3, SUT1 , SUT2, SUT3 ICIN YAPILIR


                              if (!strcmp(ch_arr[random_index],"sat2")){   
                                  
                                 for(i=0;i<3;i++)
                                     {
                                     for(j=0;j<3;j++)
                                            {   //0-0
                                            if(dizi[i][j]==dizi[0][1]){
                                                  x[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][2]){
                                                  x[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][1]){
                                                  x[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][2]){
                                                  x[1][1]=dizi[i][j];
                                                  
                                                      }  //0-1
                                            if(dizi[i][j]==dizi[0][0]){
                                                  y[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][2]){
                                                  y[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][0]){
                                                 y[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][2]){
                                                  y[1][1]=dizi[i][j];
                                                  
                                                      }//0-2
                                            if(dizi[i][j]==dizi[0][0]){
                                                  z[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][1]){
                                                  z[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][0]){
                                                 z[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][1]){
                                                  z[1][1]=dizi[i][j];
                                                  
                                                      }
   }  }   int xkonum=3; int ykonum=4; int zkonum=5;
         int fv = fork(); if (fv == 0 ) { 
            write(pipefd[1], &x, sizeof(int)*20) ;
            write(pipefd[1], &y, sizeof(int)*20) ;
            write(pipefd[1], &z, sizeof(int)*20) ;
            write(pipefd[1], &xkonum, sizeof(int)) ;
            write(pipefd[1], &ykonum, sizeof(int)) ;
            write(pipefd[1], &zkonum, sizeof(int)) ;
           c = execv("kofakhesap2x2", NULL);
            perror("");
           close(pipefd[0]);
            }
            else if(fv>0){
                
             wait(&c);//kofaktor programinin cagirildigi prosesi bekle 
             
             int sonucx; int sonucy; int sonucz;
             read(pipefd[0], &sonucx, sizeof(int)); //sonucu pipe oku
             read(pipefd[0], &sonucy, sizeof(int));
             read(pipefd[0], &sonucz, sizeof(int));
             printf("sat2 sonuc:  %d \n", sonucx);  printf("sat2 sonuc:  %d \n", sonucy); printf("sat2 sonuc:  %d \n", sonucz);
             printf(" sat 2 icin determinant sonuc : %d \n : " , sonucx+sonucy+sonucz );
                           }
              }


   if (!strcmp(ch_arr[random_index],"sat3")){   
                                  
                                 for(i=0;i<3;i++)
                                     {
                                     for(j=0;j<3;j++)
                                            {   //0-0
                                            if(dizi[i][j]==dizi[0][1]){
                                                  x[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][2]){
                                                  x[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[1][1]){
                                                  x[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][2]){
                                                  x[1][1]=dizi[i][j];
                                                  
                                                      }  //0-1
                                            if(dizi[i][j]==dizi[0][0]){
                                                  y[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][0]){
                                                  y[1][0]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[0][2]){
                                                 y[0][1]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][2]){
                                                  y[1][1]=dizi[i][j];
                                                  
                                                      }//0-2
                                            if(dizi[i][j]==dizi[0][0]){
                                                  z[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][1]){
                                                  z[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[1][0]){
                                                 z[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][1]){
                                                  z[1][1]=dizi[i][j];
                                                  
                                                      }
   }  }   int xkonum=4; int ykonum=5; int zkonum=6;
         int fv = fork(); if (fv == 0 ) { 
            write(pipefd[1], &x, sizeof(int)*20) ;
            write(pipefd[1], &y, sizeof(int)*20) ;
            write(pipefd[1], &z, sizeof(int)*20) ;
            write(pipefd[1], &xkonum, sizeof(int)) ;
            write(pipefd[1], &ykonum, sizeof(int)) ;
            write(pipefd[1], &zkonum, sizeof(int)) ;
           c = execv("kofakhesap2x2", NULL);
            perror("");
           close(pipefd[0]);
            }
            else if(fv>0){
                
             wait(&c);//kofaktor programinin cagirildigi prosesi bekle 
          
             int sonucx; int sonucy; int sonucz;
             read(pipefd[0], &sonucx, sizeof(int)); //sonucu pipe oku
             read(pipefd[0], &sonucy, sizeof(int));
             read(pipefd[0], &sonucz, sizeof(int));
             printf("sat3 sonuc:  %d \n", sonucx);  printf("sat3 sonuc:  %d \n", sonucy); printf("sat3 sonuc:  %d \n", sonucz);
             printf(" sat 3 icin determinant sonuc : %d \n : " , sonucx+sonucy+sonucz );
                           }
              }


   if (!strcmp(ch_arr[random_index],"sut1")){   
                                  
                                 for(i=0;i<3;i++)
                                     {
                                     for(j=0;j<3;j++)
                                            {   //0-0
                                            if(dizi[i][j]==dizi[1][1]){
                                                  x[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][2]){
                                                  x[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][1]){
                                                  x[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][2]){
                                                  x[1][1]=dizi[i][j];
                                                  
                                                      }  //0-1
                                            if(dizi[i][j]==dizi[0][1]){
                                                  y[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][2]){
                                                  y[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][1]){
                                                 y[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][2]){
                                                  y[1][1]=dizi[i][j];
                                                  
                                                      }//0-2
                                            if(dizi[i][j]==dizi[0][1]){
                                                  z[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][2]){
                                                  z[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[1][1]){
                                                 z[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][2]){
                                                  z[1][1]=dizi[i][j];
                                                  
                                                      }
   }  }   int xkonum=2; int ykonum=3; int zkonum=4;
         int fv = fork(); if (fv == 0 ) { 
            write(pipefd[1], &x, sizeof(int)*20) ;
            write(pipefd[1], &y, sizeof(int)*20) ;
            write(pipefd[1], &z, sizeof(int)*20) ;
            write(pipefd[1], &xkonum, sizeof(int)) ;
            write(pipefd[1], &ykonum, sizeof(int)) ;
            write(pipefd[1], &zkonum, sizeof(int)) ;
           c = execv("kofakhesap2x2", NULL);
            perror("");
           close(pipefd[0]);
            }
            else if(fv>0){
                
             wait(&c);//kofaktor programinin cagirildigi prosesi bekle 
   
             int sonucx; int sonucy; int sonucz;
             read(pipefd[0], &sonucx, sizeof(int)); //sonucu pipe oku
             read(pipefd[0], &sonucy, sizeof(int));
             read(pipefd[0], &sonucz, sizeof(int));
             printf("sut1 sonuc:  %d \n", sonucx);  printf("sut1 sonuc:  %d \n", sonucy); printf("sut1 sonuc:  %d \n", sonucz);
             printf(" sut1 icin determinant sonuc : %d \n : " , sonucx+sonucy+sonucz );
                           }
              }



if (!strcmp(ch_arr[random_index],"sut2")){   
                                  
                                 for(i=0;i<3;i++)
                                     {
                                     for(j=0;j<3;j++)
                                            {   //0-0
                                            if(dizi[i][j]==dizi[1][0]){
                                                  x[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][2]){
                                                  x[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][0]){
                                                  x[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][2]){
                                                  x[1][1]=dizi[i][j];
                                                  
                                                      }  //0-1
                                            if(dizi[i][j]==dizi[0][0]){
                                                  y[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][2]){
                                                  y[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][0]){
                                                 y[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][2]){
                                                  y[1][1]=dizi[i][j];
                                                  
                                                      }//0-2
                                            if(dizi[i][j]==dizi[0][0]){
                                                  z[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][2]){
                                                  z[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[1][2]){
                                                 z[0][1]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][2]){
                                                  z[1][1]=dizi[i][j];
                                                  
                                                      }
   }  }   int xkonum=3; int ykonum=4; int zkonum=5;
         int fv = fork(); if (fv == 0 ) { 
            write(pipefd[1], &x, sizeof(int)*20) ;
            write(pipefd[1], &y, sizeof(int)*20) ;
            write(pipefd[1], &z, sizeof(int)*20) ;
            write(pipefd[1], &xkonum, sizeof(int)) ;
            write(pipefd[1], &ykonum, sizeof(int)) ;
            write(pipefd[1], &zkonum, sizeof(int)) ;
           c = execv("kofakhesap2x2", NULL);
            perror("");
           close(pipefd[0]);
            }
            else if(fv>0){
                
             wait(&c);//kofaktor programinin cagirildigi prosesi bekle 
   
             int sonucx; int sonucy; int sonucz;
             read(pipefd[0], &sonucx, sizeof(int)); //sonucu pipe oku
             read(pipefd[0], &sonucy, sizeof(int));
             read(pipefd[0], &sonucz, sizeof(int));
             printf("sut2 sonuc:  %d \n", sonucx);  printf("sut2 sonuc:  %d \n", sonucy); printf("sut2 sonuc:  %d \n", sonucz);
             printf(" sut2 icin determinant sonuc : %d \n : " , sonucx+sonucy+sonucz );
                           }
              }




if (!strcmp(ch_arr[random_index],"sut3")){   
                                  
                                 for(i=0;i<3;i++)
                                     {
                                     for(j=0;j<3;j++)
                                            {   //0-0
                                            if(dizi[i][j]==dizi[1][0]){
                                                  x[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][0]){
                                                  x[1][0]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[1][1]){
                                                  x[0][1]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][1]){
                                                  x[1][1]=dizi[i][j];
                                                  
                                                      }  //0-1
                                            if(dizi[i][j]==dizi[0][0]){
                                                  y[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[0][1]){
                                                  y[0][1]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[2][0]){
                                                 y[1][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[2][1]){
                                                  y[1][1]=dizi[i][j];
                                                  
                                                      }//0-2
                                            if(dizi[i][j]==dizi[0][0]){
                                                  z[0][0]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][0]){
                                                  z[1][0]=dizi[i][j];
                                                 
                                                      }
                                            if(dizi[i][j]==dizi[0][1]){
                                                 z[0][1]=dizi[i][j];
                                                  
                                                      }
                                            if(dizi[i][j]==dizi[1][1]){
                                                  z[1][1]=dizi[i][j];
                                                  
                                                      }
   }  }   int xkonum=4; int ykonum=5; int zkonum=6;
         int fv = fork(); if (fv == 0 ) { 
            write(pipefd[1], &x, sizeof(int)*20) ;
            write(pipefd[1], &y, sizeof(int)*20) ;
            write(pipefd[1], &z, sizeof(int)*20) ;
            write(pipefd[1], &xkonum, sizeof(int)) ;
            write(pipefd[1], &ykonum, sizeof(int)) ;
            write(pipefd[1], &zkonum, sizeof(int)) ;
           c = execv("kofakhesap2x2", NULL);
            perror("");
           close(pipefd[0]);
            }
            else if(fv>0){
                
             wait(&c);//kofaktor programinin cagirildigi prosesi bekle 
   
             int sonucx; int sonucy; int sonucz;
             read(pipefd[0], &sonucx, sizeof(int)); //sonucu pipe oku
             read(pipefd[0], &sonucy, sizeof(int));
             read(pipefd[0], &sonucz, sizeof(int));
             printf("sut3 sonuc:  %d \n", sonucx);  printf("sut3 sonuc:  %d \n", sonucy); printf("sut3 sonuc:  %d \n", sonucz);
             printf(" sut3 icin determinant sonuc : %d \n : " , sonucx+sonucy+sonucz );
                           }
              }

         
         
    return 0;
}   
    


