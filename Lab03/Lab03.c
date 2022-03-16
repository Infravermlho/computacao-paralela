#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PESSOA
{
  char nome[20];
  int idade;
  float altura;

}PESSOA;

char cmpnome (const void * a, const void * b) 
{ 
    struct PESSOA *ia = (struct PESSOA *)a;
    struct PESSOA *ib = (struct PESSOA *)b;
    return strcmp(ia->nome, ib->nome);
}

int cmpidade (const void * a, const void * b) 
{ 
    struct PESSOA *ia = (struct PESSOA *)a;
    struct PESSOA *ib = (struct PESSOA *)b;
    return (int)(ia->idade - ib->idade);
}

float cmpaltura (const void * a, const void * b) 
{ 
    struct PESSOA *ia = (struct PESSOA *)a;
    struct PESSOA *ib = (struct PESSOA *)b;
    return (int)(ia->altura - ib->altura);
}

void imprimeVetor(struct PESSOA* arr, size_t len)
{
  for(int i=0; i<len; i++) 
        printf("nome: %s idade: %d altura: %f \n", arr[i].nome, arr[i].idade, arr[i].altura);
}

int main()
{
    char S1[50];
    struct PESSOA Povo[4];
    FILE *Arq;
    int i;
  
    Arq = fopen("lab03.txt","r");

    char buffer[200];
    fgets(buffer, 200, Arq);

    while(!feof(Arq))
      {
       
        PESSOA* p = Povo + i;
        sscanf(buffer, "%s%d%f", p->nome, &p->idade, &p->altura);
        fgets(buffer, 200, Arq);
        i++;
        
      }
  
    int j = i;
  
    for(i = 0; i < j; i++)
      {
        printf("%s%d%f\n", Povo[i].nome, Povo[i].idade, Povo[i].altura); 
      }
  
    fclose(Arq);

    size_t structs_len = sizeof(Povo) / sizeof(struct PESSOA);


    printf("Ordenação por nome(Ordem crescente):");
    printf("\n");
    qsort(Povo, structs_len, sizeof(struct PESSOA), cmpnome);
    imprimeVetor(Povo, structs_len);

  
    return 0;

}
