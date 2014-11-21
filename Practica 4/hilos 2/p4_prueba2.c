#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_THREADS 10

void *func(void *arg)
{
   printf("Thread %lu \n", pthread_self());
   pthread_exit(NULL);
}

int main(void)
{
   int j;
   pthread_attr_t attr;
   pthread_t thid[MAX_THREADS];

   /* Se inician los atributos y se marcan como independientes */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

   for(j = 0; j < MAX_THREADS; j ++)
      pthread_create(&thid[j], &attr,func, NULL);
   pthread_attr_destroy(&attr);

   /* El proceso ligero principal no puede esperar la finalizacion */
   /* de los procesos ligeros que ha creado y se suspende durante un */
   /* cierto tiempo esperando su finalizacion */
   sleep(5);

   return (0);
}

