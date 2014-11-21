/*
*	eliminaMC.c
*	Alberto Rodriguez de la Cruz
*/

#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <ctype.h> 

#define TAM_BUFFER 		10

int main() {

	key_t 	clave; 
	int 	shmid;
	int	  * seg 	= NULL;

	/*	
	*	ELIMINACION DE SEMAFOROS	
	*/

	if(sem_unlink("huecos") == -1)
		printf("Error al eliminar semaforo huecos\n");
	else
		printf("Semaforo huecos eliminado con exito\n");

	if(sem_unlink("elementos") == -1)
		printf("Error al eliminar semaforo elementos\n");
	else
		printf("Semaforo elementos eliminado con exito\n");

	if(sem_unlink("mutex") == -1)
		printf("Error al eliminar semaforo mutex\n");
	else
		printf("Semaforo mutex eliminado con exito\n");

	/*
	*	ELIMINACION DE MEMORIA COMPARTIDA
	*/

	clave=ftok(".",'S');

	if((shmid=shmget(clave,(TAM_BUFFER+2) * sizeof(int),0))==-1) 
         printf("Error al abrir el segmento\n");
    else if((seg=shmat(shmid,NULL,0))== (int *)-1) 
         printf("Error al mapear el segmento\n"); 
    else {
    	shmctl(shmid,IPC_RMID,NULL); 
        printf("Segmento de memoria marcado para borrar\n"); 
    	shmdt(seg); 
    } 
    return 0;
}