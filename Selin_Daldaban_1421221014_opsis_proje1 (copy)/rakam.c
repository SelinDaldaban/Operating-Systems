#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[],char ** envp)
{

int sayi1=atoi(argv[1]);   //  rakam ile yazilacak olan char elemanini int e cevirdim
int sayi4=atoi(argv[4]); 
 if (sayi1==1){                 //karsilastirmalar yapilir
printf("%d >> bir\n", sayi1);
}
else if(sayi1==2){
printf("%d >> iki\n", sayi1);
}
else if(sayi1==3){
printf("%d >> uc\n", sayi1);
}
else if(sayi1==4){
printf("%d >> dort\n", sayi1);
}
else if(sayi1==5){
printf("%d >> bes\n", sayi1);
}
else if(sayi1==6){
printf("%d >> alti\n", sayi1);
}
else if(sayi1==7){
printf("%d >> yedi\n", sayi1);
}
else if(sayi1==8){
printf("%d >> sekiz\n", sayi1);
}
else if(sayi1==9){
printf("%d >> dokuz\n", sayi1);
}
else if(sayi1==0){
printf("%d >> sifir\n", sayi1);
}

    return 0;
}
