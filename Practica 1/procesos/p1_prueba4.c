// #include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h> 

int main(void) 
{ 
   pid_t pid; 

   pid = fork(); 
   switch(pid) 
   { 
      case -1:     /* error del fork() */
         perror("fork");
         break;

      case 0:    /* proceso hijo */ 
         execlp("ls","ls","-l",NULL); 
         perror("exec"); 
         break; 
      default:   /* padre */ 
         printf("Proceso padre\n"); 
    } 
    
    // getchar();
    
    return 0;
} 

