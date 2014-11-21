#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
	if(argc != 3)
		printf("Error, argumentos incorrectos\n");
	else {
		sem_t * sem = NULL;
		if ((sem = sem_open(argv[1], O_CREAT, 0600, atoi(argv[2]))) == SEM_FAILED)
			printf("Error al crear semaforo\n");
		else {
			printf("Semaforo creado con exito\n");
			printf("ID semaforo creado: %d\n", (int) sem);
			printf("Valor del semaforo: %d\n", atoi(argv[2]));
		}		
	}
	return 0;
}