#include <stdio.h>
#define r 3
#define c 2
int i, j;
//Funcao que cria a transposta da matriz e printa o resultado
void transpor(int matriz[][c], int transposta[][r])
{
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

int main()
{
    int matriz[r][c], transposta[r][c];
    printf("Digite os valore \n");
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
    transpor(matriz, transposta);
    return 0;
}