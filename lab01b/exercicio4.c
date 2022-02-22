#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char name1[20], name2[20];
	printf("Digite o primeiro nome: ");
	scanf("%s", name1);
	printf("Digite o segundo nome: ");
	scanf("%s", name2);
	if (name1 > name2)
	{
		printf(name1);
		printf("\n");
		printf(name2);
	}
	else {
		printf(name2);
		printf("\n");
		printf(name1);
	}
}