# Como funciona o Rayon?
Rayon é uma biblioteca que converte um algoritmo iterativo sequêncial em um paralelo, é dada uma função e por qual valores ela deve iterar e a bilioteca vai criar
criar e definir dinamicamente as threads para cada execução da função.

# Como é feita a definição da area critica?
O algoritmo atualmente esta gerando um vetor com todos os numeros 1/n e retornando a soma no final, a unica parte não paralelizada no processo é a soma

![image](https://user-images.githubusercontent.com/66850003/168514445-fc5395df-168b-4b37-8907-749c3804579d.png)

Isso é feito pois ter inumeras threads escrevendo no mesmo endereço de memoria na hora da soma pode ocasionar em varios bugs, como por exemplo duas threads fazendo a soma no
mesmo instante e a mudança de uma sobrepondo a da outra
