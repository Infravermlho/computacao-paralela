#include <stdio.h>
#define N 3
void retornaModulo(int matriz[N][N]) {
    //Verificando valores negativos e trocando pelo seu modulo
    printf("\nMatriz com modulos: \n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matriz[i][j] < 0)
            {
                matriz[i][j] = matriz[i][j] * -1;

            }
            printf("%d  ", matriz[i][j]);
            if (j == N - 1)
                printf("\n");
        }
    }
}
int main()
{
    int matriz[N][N] = { { -9, 7, -8,},
                       { 5, -2, 4},
                       { -3, 6, -2} };
    //Printando Matriz Original
    printf("\nMatriz Original: \n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d  ", matriz[i][j]);
            if (j == 3 - 1)
                printf("\n");
        }
    }
    retornaModulo(matriz);
}