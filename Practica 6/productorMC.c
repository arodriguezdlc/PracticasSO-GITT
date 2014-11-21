/*
	ProductorMC.c
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

	if ((sem_huecos = sem_open("huecos", 0)) == SEM_FAILED)
		printf("Error al abrir semaforo huecos\n");
	else {
		printf("Semaforo huecos abierto con exito\n");		
	}		

	if ((sem_elementos = sem_open("elementos", 0)) == SEM_FAILED)
		printf("Error al abrir semaforo elementos\n");
	else {
		printf("Semaforo elementos abierto con exito\n");		
	}

	if ((sem_mutex = sem_open("mutex", 0)) == SEM_FAILED)
		printf("Error al abrir semaforo mutex\n");
	else {
		printf("Semaforo mutex abierto con exito\n");		
	}
	

}
