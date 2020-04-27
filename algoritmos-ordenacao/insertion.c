/* github.com/wendelmarques
--------------------------------------------------- TRABALHO PRÁTICO 1 - AED1 (2018.1) ---------------------------------------------------
Universidade Federal de Goiás
Instituto de Informática
Aluno: Wendel Marques de Jesus Souza
Prof. Nádia Félix
*/

 
#include <stdio.h>
#include <stdlib.h>

/*
Pega um elemento de cada vez (nesse caso, key) e o coloca em seu devido lugar através de comparações.

//Wendel Marques
*/
void insertion (int vetor [], int n) {

    int i, key, j, cont = 0;

    for (i = 1; i < n; i++) {
       key = vetor[i];
       j = i - 1;

       //deslocamento dos menores elementos para frente
       while ((j >= 0) && (vetor[j] > key)) {
           vetor[j + 1] = vetor[j];
           j = j - 1;
       }

       vetor[j + 1] = key;
   }

   //imprime os dados (para verificaçao de corretude)
   // for(i = 0; i < n; i++)
   //    printf("%i\n", vetor[i]);
}

/*No seguinte bloco, inicialmente o arquivo que contem as sequencias é aberto.
    Em le o tamanho do vetor e faz a alocacao dinamica do mesmo. Após isso, lê cada
    elemento presente no arquivo e add cada um deles no vetor. Por fim, chama
    a função para ordenar.
*/
//Wendel Marques
int main ( ) {

    int *vetor, j;
    int i, regnum;
    FILE *fptr;
    int TAM; //Este é o tamanho do experimento, ou seja, do vetor que sera ordenado

    fptr = fopen ("seq.txt", "r"); /*Abre, em modo texto, o arquivo que contem a
                                    sequencia a ser ordenada (gravação a partir
                                    so seu inicio)*/

    scanf("%i", &TAM); //Lê o tamanho do vetor

    vetor = malloc(TAM * sizeof(int)); //Alocação dinâmica do vetor com base em TAM


    /*O seguinte While lê o arquivo e logo em seguida armazena o numero i
        da seq de numeros do arquivo na i-esima posição do vetor*/
    j = 0;
    while (fscanf(fptr, "%i", &regnum) != EOF) {
        vetor[j] = regnum;
        j++;
    }

    insertion (vetor, TAM); //Chama a função do metodo INsertion Sort

    fclose (fptr); //Fecha o arquivo
    free(vetor); //Libera a memórica alocada

    return 0;
}
