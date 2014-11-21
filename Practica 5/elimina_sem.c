#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>

int main (int argc, char * argv[]) {
	if(argc != 2)
		printf("Error, argumentos incorrectos\n");
	else {
		if(sem_unlink(argv[1]) == -1)
			printf("error al eliminar semaforo\n");
		else
			printf("semaforo eliminado con exito\n");
	}
	return 0;
}