#include <stdio.h>

int main() {
	int x, y, z, media, resultado;
	printf("Digite as 3 notas dos alunos\n");
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	printf("Digite as media dos exercicios do alunos\n");
	scanf("%d", &media);
	resultado = (x + y * 2 + z * 3 + media) / 7;
	if (resultado >= 9) {
		printf("A nota final do aluno eh A\n");
	}
	if (resultado >= 7.5 && resultado < 9) {
		printf("A nota final do aluno eh B\n");
	}
	if (resultado >= 6 && resultado < 7.5) {
		printf("A nota final do aluno eh C\n");
	}
	if (resultado >= 4 && resultado < 5) {
		printf("A nota final do aluno eh D\n");
	}
	if (resultado < 4) {
		printf("A nota final do aluno eh E\n");
	}
}