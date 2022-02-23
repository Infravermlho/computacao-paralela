#include <stdio.h>

int main() 

{

  struct student
  {
    char Name;
    int Age;
    int Weight;
    int Height;


  };

  struct student std[4];

  for (int i = 0; i < 4; i++)
  {
    printf("estudante %d\n",i+1);


    printf("Digite o nome:\n");
    scanf("%s", &std[i].Name);

    printf("Digite a idade:\n");
    scanf("%d", &std[i].Age);

    printf("Digite o peso:\n");
    scanf("%d", &std[i].Weight);

    printf("Digite a altura:\n");
    scanf("%d", &std[i].Height);

  }

  printf("");


  for (int i = 0; i < 4; i++)
  {
    printf("estudante %d\n",i+1);
    printf("");

    printf("Nome: %s\n", &std[i].Name);
    printf("");
    printf("Idade: %d\n", std[i].Age);
    printf("");
    printf("Peso: %d\n", std[i].Weight);
    printf("");
    printf("Altura: %d\n", std[i].Height);
    printf("");
    
  }




  return 0;
}
