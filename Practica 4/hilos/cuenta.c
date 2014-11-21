#include <stdio.h>

#define TAMBUF 4096

int contar_lineas(FILE *f)
{
   char texto[TAMBUF];
   int i=0;
   int bytesleidos=0;
   int lineas=0;
   
   /* lee parte del fichero */
   bytesleidos=fread(texto,sizeof(char),TAMBUF,f);
  
   while(bytesleidos)
   {
   
       
      /* Cuenta lineas del texto leido */
      for(i=0;i<bytesleidos;i++)
      {
         if(texto[i]=='\n')
            lineas++;
      }
      
      bytesleidos=fread(texto,sizeof(char),TAMBUF,f);
   }  

   return lineas;
}

int main(int argc, char *argv[])
{
   FILE *f=NULL;
   int i=0;
   int lineas=0;
   
   if(argc>1)
   {
       /* Para cada argumento */
       for(i=1;i<argc;i++)
       {
          f=fopen(argv[i],"r");
          if(f!=NULL)
          {
             lineas=contar_lineas(f);
             printf("El fichero %s tiene %d lineas \n",argv[i],lineas);
             fclose(f);
          }
       }       
   
   }
   
   return(0);
}
