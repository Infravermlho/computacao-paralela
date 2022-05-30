## RESULTADO FINAL:
![resultados](https://user-images.githubusercontent.com/66850003/170902947-56be40c9-c419-4dd9-aeb9-d05c6cac59b5.png)
TEMPO TOTAL DE EXECUÇÃO: ``68 HRS``
 
VALORS **S** ATINGIDO: ``34.11699883617231``

### Como resolveram o problema:  descrição simples do algoritmo e estratégia de paralelismo adotada
O programa calcula a série de Taylor infinitamente em incrementos de 5000000000, o crate Rayon é usado para criar dinamicamente threads que separadamente
calculam 1/n ... 1/(n + 100000) que após isso são somados serialmente.

### Qual foi o speedup da última versão  e como eles fizeram para melhorar
Tempo de execução de cada incremento serial: ``8.58454582``

Tempo de execução de cada incremento paralelo: ``3.35``

Speedup: ``2.56``

Foi testado a implementação de SIMD para acelerar nos calculos, porem devido a simplicidade do problema o overhead de criar 3 vetores (vetor de `[1]*n`, vetor de `[1..n]`
e vetor para resultados) tornou o processo de SIMD mais lento que a divisão individual 1/n. Então como alternativa foi implementado um sistema de chunks no
calculo paralelo, o qual trouxe um grande ganho de performance que foi levado a o projeto final.

### Considerações sobre a estratégia de paralelismo adotada e como isso auxiliou na escala do problema.
Como o problema proposto era simples o foco principal foi aumentar a quantidade de trabalho executada por cada thread para compensar o overhead na criação,
para realizar isso foi implementado o sistema de chunks o qual foi manualmente ajustado para o valor que proporcionaria o melhor ganho de performance. após isso
deixamos o progama rodando em uma VM da azure
