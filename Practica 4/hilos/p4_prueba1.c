#include <pthread.h>
#include <stdio.h>

void *func(void *arg)
{
   printf("Thread %lu \n", pthread_self());
   pthread_exit(NULL);
}

int main(void)
{
   pthread_t th1, th2;

   /* se crean dos procesos ligeros con atributos por defecto */
   pthread_create(&th1, NULL, func, NULL);
   pthread_create(&th2, NULL, func, NULL);

   printf("El proceso ligero principal continua ejecutando\n");

   /* se espera su terminación */
   pthread_join(th1, NULL);
   pthread_join(th2, NULL);

   return(0);

}

