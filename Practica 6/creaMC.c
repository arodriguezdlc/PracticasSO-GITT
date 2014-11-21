/*
	creaMC.c
	Alberto Rodriguez de la Cruz
*/

#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <ctype.h> 

#define TAM_BUFFER 		10
#define POS_LECTURA		seg[TAM_BUFFER]	
#define POS_ESCRITURA	seg[TAM_BUFFER+1]

int main () {

	sem_t * sem_huecos 		= NULL;
	sem_t * sem_elementos 	= NULL;
	sem_t * sem_mutex 		= NULL;
	key_t 	clave; 
	int 	shmid;
	int	  * seg 			= NULL;

	/*
	*	CREACION DE SEMAFOROS
	*/
	if ((sem_huecos = sem_open("huecos", O_CREAT, 0600, TAM_BUFFER)) == SEM_FAILED)
		printf("Error al crear semaforo huecos\n");
	else {
		printf("Semaforo huecos creado con exito\n");		
	}		

	if ((sem_elementos = sem_open("elementos", O_CREAT, 0600, 0)) == SEM_FAILED)
		printf("Error al crear semaforo elementos\n");
	else {
		printf("Semaforo elementos creado con exito\n");		
	}

	if ((sem_mutex = sem_open("mutex", O_CREAT, 0600, 1)) == SEM_FAILED)
		printf("Error al crear semaforo mutex\n");
	else {
		printf("Semaforo mutex creado con exito\n");		
	}

	/*
	*	MEMORIA COMPARTIDA
	*/
	clave=ftok(".",'S');
	if((shmid=shmget(clave,(TAM_BUFFER+2) * sizeof(int),IPC_CREAT|IPC_EXCL|0660))==-1) { 
    	printf("El segmento de memoria compartida ya existe\n"); 
    	printf("    Abriendo como cliente\n"); 
    	if((shmid=shmget(clave,(TAM_BUFFER+2) * sizeof(int),0))==-1) {
        	printf("Error al abrir el segmento\n");
        } 
	} 
  	else {
      	printf("Nuevo segmento creado\n"); 
    }

    if (shmid != -1) 
   	{ 
    	if((seg=shmat(shmid,NULL,0))== (int *)-1) 
         	printf("Error al mapear el segmento\n"); 
      	else {
      		POS_LECTURA = 0;	//Posicion de lectura
      		POS_ESCRITURA = 0;	//Posicion de escritura
      	}
	}
	return 0;
}