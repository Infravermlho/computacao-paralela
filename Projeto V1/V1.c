#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

long double x = 1.0;
long double aux = 0;


long double *sum()
{
  
  for (int i = 1; i < 100; i++)
  {
    aux = aux + (x/i);
      
  }
  aux = aux + 1;

  return &aux;
}

int main(void) 
{
  clock_t begin = clock();

  pthread_t thread1;
  

  pthread_create(&thread1, NULL, sum, NULL);
  pthread_join(thread1, NULL);
  
  printf("valor de X é : %Lf", aux);
  
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("\n");

  printf("Tempo de execução %f segundos", time_spent);


  return 0;
}
