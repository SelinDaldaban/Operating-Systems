
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 #include <math.h>
 
int main()
{

int x[2][2];  // determinanttan gelen diziler icin yer ayirdim
int y[2][2];
int z[2][2];
int xkonum; int ykonum; int zkonum; // us degerlerini tuttum
int xtop,ytop,ztop;
int sonucx, sonucy , sonucz; //determinanta gonderecegim degerler
int i=0, j=0 ; 
int sonuc = 1; 
read(3, &x, sizeof(int)*4); // determinanttan okudum
read(3, &y, sizeof(int)*4);
read(3, &z, sizeof(int)*4);
read(3, &xkonum, sizeof(int)); // us degerlerini okudum
read(3, &ykonum, sizeof(int));
read(3, &zkonum, sizeof(int));
         sonucx = (x[0][0] * x[1][1]) - (x[1][0] * x[0][1]);   //kofaktor icin hesaplama
         sonucy = (y[0][0] * y[2][2]) - (y[1][0] * y[0][1]);
         sonucz= (z[0][0] * z[2][2]) - (z[1][0] * z[0][1]);
       //  printf("x sonuc : %d \n " ,sonucx);  printf("y sonuc : %d \n " ,sonucy);  printf("z sonuc : %d \n " ,sonucz);
         for (i=0; i<xkonum; i++){sonuc  =sonuc*(-1);} sonucx=sonucx*sonuc; //us degerlerini hesapladim
         for (i=0; i<ykonum; i++){sonuc  =sonuc*(-1);} sonucy=sonucy*sonuc;
         for (i=0; i<zkonum; i++){sonuc  =sonuc*(-1);} sonucz=sonucz*sonuc;
     
      //   printf("x sonuc : %d \n " ,sonucx);  printf("y sonuc : %d \n " ,sonucy);  printf("z sonuc : %d \n " ,sonucz); 
         write(4, &sonucx, sizeof(int)); //determinanta sonuclari yolladim
         write(4, &sonucy, sizeof(int));
         write(4, &sonucz, sizeof(int));




      return 0;


      

}
