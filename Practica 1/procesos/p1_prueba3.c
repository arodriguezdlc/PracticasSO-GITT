// #include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
int main(void) 
{ 
   int estado;
  
   pid_t pid; 
   pid = fork(); 
   
   switch(pid) 
   {
      case -1:    /* error del fork() */ 
         perror("fork"); 
         break; 
      case 0:    /* proceso hijo */ 
         printf("Proceso %d; padre = %d \n", getpid(), getppid()); 
         break; 
      default:   /* padre */ 
         printf("Proceso %d; padre = %d \n", getpid(), getppid()); 
         wait(&estado);
         
   } 
         
   return 0;
} 
