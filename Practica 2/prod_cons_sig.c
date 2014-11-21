#include <signal.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <wait.h> 

pid_t pid; 
void consumidor();
void productor();
void imprime(int sig);

int main() 
{ 
  int status;    
   
  /* Se crea el proceso hijo */ 
  pid = fork(); 

  switch(pid) { 
    case -1:   /* error del fork() */ 
       perror("fork"); 
    break; 
    case 0:    /* proceso hijo */ 
       consumidor();          
    break; 
    default:   /* padre */ 
       productor();        
       /* Espera al proceso hijo */ 
       wait(&status); 
  } 
  return 0;
}

void consumidor() {
  int i;
  struct sigaction act;
  act.sa_handler = imprime; /*función a ejecutar*/ 
  act.sa_flags = 0;   /* ninguna acción especifica */ 
  sigemptyset(&act.sa_mask); 
  
  for(i=1; i<=5; i++) {  
    sigaction(i, &act, NULL);     
  }
  while(1);
}

void productor() {
  int i;
  for(i=1; i<=5; i++) {
    sleep(5);
    kill(pid, i);    
  }
  sleep(5);
  kill(pid, SIGKILL);  
}

void imprime(int sig) {
  printf("Recibida %d\n", sig);
}
