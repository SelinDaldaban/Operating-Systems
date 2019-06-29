#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>   
int main(int argc, char *argv[],char ** envp)
{
while(1){
  
    int parametre1,parametre2;
   
  printf("\nmyshell >>");
 

char *buf=(char*) malloc(50*sizeof(char));

  
    gets(buf);
    int j=0;
    int i = 0;
    char *p = strtok (buf, " &"); //bosluk ve & isaretine gore ayirdim

     char * islem=(char*) malloc(5*sizeof(char)); //yer ayirdim
     char * par1=(char*) malloc(5*sizeof(char));
     char * par2=(char*) malloc(5*sizeof(char));
     char * islem2=(char*) malloc(5*sizeof(char)); 
     char * par3=(char*) malloc(5*sizeof(char));
     char * par4=(char*) malloc(5*sizeof(char));
     char *newargv[7];
     
     newargv[0]=(char*) malloc(5*sizeof(char));
     newargv[1]=(char*) malloc(5*sizeof(char));
     newargv[2]=(char*) malloc(5*sizeof(char));
     newargv[3]=(char*) malloc(5*sizeof(char));
     newargv[4]=(char*) malloc(5*sizeof(char));
     newargv[5]=(char*) malloc(5*sizeof(char));
     newargv[6] = NULL;   
    while (p != NULL)
    {
        newargv[i++] = p;
        newargv[j++] = p;
        p = strtok (NULL, " &");
        
    }

     char *args[]={newargv[0],newargv[1],newargv[2],newargv[3],newargv[4],newargv[5]}; 

  
    if (!(strcmp(newargv[0],"exit"))){ exit(0); }  //exit girilirse sistemden cikis
     else if(!(strcmp(newargv[0],"clear")))  {system("clear");}  // clear ile ekran temizlenir
     else if(!(strcmp(newargv[0],"cat")))  {printf(newargv[1]);} // cat ile ikinci parametre ne ise aynisini yazdim

      else if (!strcmp(newargv[3],"rakam") || !strcmp(newargv[3],"div") || !strcmp(newargv[3],"mul")) //ikinci islem icin kosullar
                                                        {  
                                                          int fv = fork(); 
                                                         
                                                             if(fv==0)  {
               
                                                          i= execv(newargv[3],newargv+3,envp);  //ikinci islemin elemanlarini gönderebilmek icin
                              																													
                                                                          }
                                                            
                                                            else if(fv>0){wait(&fv); }  

																																																								
                                                        }        
        if (!strcmp(newargv[0],"rakam") || !strcmp(newargv[0],"div") || !strcmp(newargv[0],"mul")) //ilk islem icin kosullar
                        {

                         int fv = fork(); 
                         
                         if(fv==0)  {
                 
                         i= execv(newargv[0],newargv,envp);  //ilk islemi gondermek icin
                              
                                    }
                 
                           
                            else if(fv>0 && strcmp(newargv[0],"rakam") && strcmp(newargv[3],"rakam")){wait(&fv); } //rakam icin wait olmamasi icin 
                     
                        }

               else if (strcmp(newargv[0],"rakam") && strcmp(newargv[0],"div") && strcmp(newargv[0],"mul") && strcmp(newargv[0],"cat") &&
strcmp(newargv[0],"clear") && strcmp(newargv[0],"exit")){   //bunlar disinda ise yanlis komuttur
              
printf("yanlis komut girdiniz\n ");
						             		} 
           
   }     
    return 0;






}
