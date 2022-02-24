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

void multiRow(int Row[MAX_LEN], int multiplicador)
{
  for (int i = 0; i < MAX_LEN; ++i)
  {
    Row[i] *= multiplicador;
  }
}

void multiColumn(int matrix[MAX_LEN][MAX_LEN], int column, int multiplicador)
{
  for (int i = 0; i < MAX_LEN; ++i)
  {
      matrix[i][column] *= multiplicador;
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
    printf("Deseja multiplicar os elementos de uma linha ou coluna?:\n");
    printf("1 - Linha:\n");
    printf("2 - Coluna:\n");
    printf("0 - Encerrar:\n");
    scanf("%d", &input);

    if(input == 1) 
    {
      int lin, mult;
      printf("Informe a linha e o multiplicador:\n");
      scanf("%d%d", &lin, &mult);
      multiRow(matriz[lin], mult);

      printf("\nMatriz Resultante: \n");
      print(matriz, column, row);
    }
    else if (input == 2)
    {
      int col, mult;
      printf("Informe a coluna e o multiplicador:\n");
      scanf("%d%d", &col, &mult);
      multiColumn(matriz[col - 1], col, mult);

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
