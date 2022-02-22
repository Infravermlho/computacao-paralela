#include <stdio.h>


int main()
{
    int i, j, m, n, linha, coluna;
    int matriz[10][10], menorValor;
    printf("Digite o valor de coluna e linha:\n");
    scanf("%d%d", &m, &n);
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    menorValor = matriz[0][0];
    linha = 0;
    coluna = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matriz[i][j] < menorValor)
            {
                menorValor = matriz[i][j];
                linha = i;
                coluna = j;
            }
        }
    }
    printf("O menor numero esta localizado na linha:  %d e coluna %d\n", linha+1, coluna+1);

}