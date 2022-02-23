#include <stdio.h>

int main() 


{

  int maxnum; //Size do array
  int GN; //Maior número
  int LN = 0; //Menor número
  



  int arr[100];

  printf("Digite o número máximo:");
  scanf("%d", &maxnum);
  for (int i = 0; i < maxnum; i++)
  {
    arr[i] = maxnum-i;
  }

  for (int i = 0; i < maxnum; i++)
  {
    printf("%d", arr[i]);
  }

  printf("\n");

  GN = maxnum;

  while(maxnum != 1)
  {

  

    for (int i = GN-1; i < maxnum; i++)
    {
      arr[i]= arr[i+1];
    }

    maxnum--;



    for (int i = LN-1; i < maxnum; i++)
    {
      arr[i]= arr[i+1];
    }

    maxnum--;


    for (int i = 0; i < maxnum; i++)
    {
      printf("%d", arr[i]);
    }
  
    printf("\n");

  }

  




  return 0;
  
  
}
