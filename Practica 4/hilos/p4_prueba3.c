#include <pthread.h>
#include <stdio.h>

void *imprimir(void *n)
{
   printf("Thread %lu %d \n", pthread_self(),*((int *)n));
   pthread_exit(NULL);
}

int main(void)
{
   pthread_attr_t attr;
   pthread_t thid;
   int num=1;

   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

   while(num)
   {
      printf("Escribir numero entero :\n");
      scanf("%d", &num); /* espera */
      pthread_create(&thid, &attr, imprimir, &num);
   }

   pthread_attr_destroy(&attr);

   return 0;

}

