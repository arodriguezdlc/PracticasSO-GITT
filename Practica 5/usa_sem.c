#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_IMP 5
#define VECES_RC 5

int main (int argc, char * argv[]) {
	int i;
	int j;
	sem_t * sem = NULL;
	if(argc != 2)
		printf("Error, argumentos incorrectos\n");
	else {
		if((sem = sem_open(argv[1], 0)) == SEM_FAILED)
			printf("Error al abrir semaforo\n");
		else {		
			for(i = 1; i <= VECES_RC; i++ ) {
				if(sem_wait(sem) == -1) {
					printf("Error al bajar el semaforo\n");
				}
				else { 	
					for(j= 1; j <= NUM_IMP; j++){
						printf("RC: %d IMP: %d \n", i, j);
						sleep(1);
					}
					if(sem_post(sem) == -1) {
						printf("Error al subir el semaforo\n");
					}
				}
			}
		}			
		sem_post(sem);		
	}
	return 0;
}