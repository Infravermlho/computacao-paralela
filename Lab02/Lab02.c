#include  <stdio.h>
#include  <sys/types.h>


void factorial(int n)
{
   int i;
   
   pid_t pid = fork();
   
   if (pid == 0) // processo filho
   {
   
       for (i=1; n > 1; n = n -1) 
       {
       
         i=i*n;
   
   }
   printf(" é = %d", i);

   }
   
   if (pid > 0) // processo pai
   {
   	printf("O fatorial de %d", n);
   }
}


void  main()
{
   int num;
   printf ("Digite um numero inteiro: ");
   scanf ("%d", &num);
   factorial(num);
     
}
