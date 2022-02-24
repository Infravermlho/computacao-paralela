#include <stdio.h>
#define MAX_SIZE 100


void add_ch(char s[], int index, char addee)
{
  char balde;
  char balde2;

  balde = addee;
  for (int i = index; i < MAX_SIZE; i++)
  {
    balde2 = s[i];
    s[i] = balde;

    balde = balde2;
  }

}


int main() 
{
  char str[MAX_SIZE];
  int pos;
  char addee;

  printf("Insira uma palavra: ");
  scanf("%s", str);

  printf("Insira o char que deseja colocar: ");
  scanf(" %c", &addee);
  
  printf("Insira o index onde deseja colocar o char: ");
  scanf("%d", &pos);

  add_ch(str, pos, addee);
  
  printf("%s", str);


  
  return 0;
}
