#include <stdio.h>


char find_ch(char s[], char ch, int lenght)
{ 

  int index = 0;
  


  for(int i = 0; i < lenght; i++)
  {
    if (s[i]==ch)
    {
      index = i;
    }

  }
  
  return printf("A posição do caracter é: %d", index);

}

int main() 
{
  int size = 100;

  char str[size];
  char chr;

  printf("Insira uma palavra:");
  scanf("%s", str);

  printf("Digite o caracter que deseja retornar a posição:");
  scanf("%s", &chr);

  find_ch(str, chr, size);



  return 0;
 
}
