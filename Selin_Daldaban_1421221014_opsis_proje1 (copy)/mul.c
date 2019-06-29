#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

float sayi1=atof(argv[1]);  // char float donusumu icin
float sayi2=atof(argv[2]);
 printf("%.2f * %.2f = %.2f \n", sayi1, sayi2,sayi1*sayi2);

    return 0;
}



