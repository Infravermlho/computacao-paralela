#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float CalcTaylor()
{
  int n;


  float soma = 0;
  float div;
  int count = 1;

  for (int d = 1; d < 10; d++)
    {
      n = 1;
      
      div = pow(n,d)/d;
      
      soma = soma + div;

      printf("Iteração %d\n", count);
      printf("Valor de N: %d\n", n);
      printf("Valor de D: %d\n", d);
      printf("Valor da Divisão: %.2f\n", div);
      printf("Soma: %.2f\n", soma);
      printf("\n");
      
      count++;

    }

  
  return soma;
}

int main(void) 


{

  float func = CalcTaylor();
  
  printf("Série de Taylor(valor sem aproximação de casas decimais): \n %f", func);
  
  
  
  return 0;
}
