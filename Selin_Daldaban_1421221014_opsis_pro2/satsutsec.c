#include<stdio.h>
 
int main(int argc, char *argv[])
{     
   int i;
  int pipefd[2];
  srand(time(NULL)); //random deger icin
//random degerleri dizide tutup tek tek okuttum 
  char ch_arr[6][10] = {
                             "sat1",
                             "sat2",
                             "sat3", "sut1","sut2","sut3"
                         };
    
    char random_char[10];
    int random_index = rand() % 6; //dizinin icinden random deger aldim

    int s;
    printf  ("\n" );
    write(4, &ch_arr[random_index], sizeof(char)*4);  //gelen degeri determinanta gonderdim
     

}
