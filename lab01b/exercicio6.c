#include <stdio.h>


int main()
{
    int i, j, r, c;
    int matriz[10][10], transposta[10][10];
    printf("Digite o valor de coluna e linha:\n");
    scanf("%d%d", &r, &c);
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    //Printando Matriz Original
    printf("\nMatriz Original: \n");
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            printf("%d  ", matriz[i][j]);
            if (j == c - 1)
                printf("\n");
        }

    // Transpondo a matriz
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            transposta[j][i] = matriz[i][j];
        }

    // Matriz transposta
    printf("\nMatriz Transposta:\n");
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < r; ++j) {
            printf("%d  ", transposta[i][j]);
            if (j == r - 1)
                printf("\n");
        }
    return 0;
}