/* github.com/wendelmarques
--------------------------------------------------- TRABALHO PRÁTICO 1 - AED1 (2018.1) ---------------------------------------------------
Universidade Federal de Goiás
Instituto de Informática
Aluno: Wendel Marques de Jesus Souza
Prof. Nádia Félix
*/


#include <stdio.h>
#include <stdlib.h>// para rand() e srand()
#include <time.h> //referente a função time()

int main(void) {
     int i, regnum;
     FILE *fptr;
     int TAM; //qtd de numeros que serao gerados

     /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
        com o valor da função time(NULL). Este por sua vez, é calculado
        como sendo o total  de segundos passados desde 1 de janeiro de 1970
        até a data atual.
        Desta forma, a cada execução o valor da "semente" será diferente.
     */

     scanf("%i", &TAM);

     srand(time(NULL));

     fptr = fopen("seq.txt", "w"); //abre o arquivo para gravacao em modo texto

     for (i = 0; i < TAM; i++) {
           // gerando valores aleatórios na faixa de 0 a %x
           regnum = rand() % TAM;

           fprintf(fptr, "%i\n", regnum); //armazena no arquivo
     }

     fclose(fptr);

     /*O seguinte trecho pode ser utilizado para a realizacao de teste */

     // fptr = fopen("seq.txt", "r");
     //
     // while(fscanf(fptr, "%i\n", &regnum) != EOF)
     //    printf("%i\n", regnum);
     //
     //
     // fclose(fptr);

      return 0;
}
