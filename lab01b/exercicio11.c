#include <stdio.h>
#define MAX_LEN 10

void print(int matriz[MAX_LEN][MAX_LEN], int column, int row)
{
  for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j) {
            printf("%d  ", matriz[i][j]);
            if (j == column - 1)
                printf("\n");
        }
  printf("\n");
}

void addRow(int Matriz[MAX_LEN][MAX_LEN])
{
  for (int i = 0; i < MAX_LEN; ++i)
  {
    Matriz[1][i] += Matriz[0][i];
  }
}

void multRow(int Matriz[MAX_LEN][MAX_LEN])
{
  for (int i = 0; i < MAX_LEN; ++i)
  {
    Matriz[1][i] *= Matriz[0][i];
  }
}

int main()
{
  int column, row, input = -1;
  
  int matriz[MAX_LEN][MAX_LEN];
  printf("Digite o valor de coluna e linha (Limite é 10):\n");
    
  scanf("%d%d", &row, &column);
  while(row > 10 || row < 0 || column > 10 || column < 0)
  {
    printf("Um dos dados inseridos se encontra fora de padrão.\n");
    printf("Digite o valor de coluna e linha (Limite é 10):\n");
    scanf("%d%d", &row, &column);
  }

  printf("Digite os elementos da matriz:\n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      printf("a[%d][%d]= ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  //Printando Matriz Original
  printf("\nMatriz Original: \n");
  print(matriz, column, row);
  
  while( input != 0 )
  {
    printf("Deseja somar ou multiplicar L1 e L2?:\n");
    printf("1 - Somar:\n");
    printf("2 - Multiplicar:\n");
    printf("0 - Encerrar:\n");
    scanf("%d", &input);

    if(input == 1) 
    {
      addRow(matriz);

      printf("\nMatriz Resultante: \n");
      print(matriz, column, row);
    }
    else if (input == 2)
    {
      multRow(matriz);

      printf("\nMatriz Resultante: \n");
      print(matriz, column, row);
    }
    else if (input != 0)
    {
      printf("Input invalido.\n");
      input = -1;
    }
  }   

  //Printando matriz resultante
  printf("\nMatriz Resultante: \n");
  print(matriz, column, row);
  
  return;
}
