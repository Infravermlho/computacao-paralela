#include <stdio.h>


void remove_ch(char s[], int index, int length)
{

  for (int i = index; i < length; i++)
  {
    s[i] = s[i + 1];
  }

}


int main() 
{

  int size = 100;

  char str[size];
  int pos;


  printf("Insira uma palavra:");
  scanf("%s", str);




  printf("Insira o index que deseja remover:");
  scanf("%d", &pos);

 
  remove_ch(str, pos, size);
  
  printf("%s", str);


  
  return 0;
 
}
