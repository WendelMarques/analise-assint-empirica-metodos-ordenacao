/* github.com/wendelmarques
--------------------------------------------------- TRABALHO PRÁTICO 1 - AED1 (2018.1) ---------------------------------------------------
Universidade Federal de Goiás
Instituto de Informática
Aluno: Wendel Marques de Jesus Souza
Prof. Nádia Félix
*/

 

#include <stdio.h>
#include <stdlib.h>


/*A cada passo procura o menor valor do vetor e o coloca na primeira possição.
Descarta-se a primeira posição do vetor e repete-se o processo para a segunda
posição. E assim por diante
*/

//Wendel Marques
void selection (int vetor[], int TAM) {

    int min, aux, i, j;

    for (i = 0; i < (TAM - 1); i++) {

        min = i; //fixa a posição corrente e compara o elemento dessa posição
                    //com os demais elementos do array

        //Procura o menor elemento do conjunto de num desodernados
        for (j = (i + 1); j < TAM; j++) {
            if(vetor[j] < vetor[min]) {
              min = j;
            }
        }

        //Realiza a troca
        if (vetor[i] != vetor[min]) {
            aux = vetor[i]; //aux recebe o maior elemento
            vetor[i] = vetor[min]; //o menor elemento eh deslocado para frente
            vetor[min] = aux; //o maior elemento é deslocado para trás
        }
    }
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

    selection(vetor, TAM); //Chama a função do metodo Selection Sort

    //imprime os dados (para verificaçao de corretude)
    for(i = 0; i < TAM; i++)
       printf("%i\n", vetor[i]);

    fclose (fptr); //Fecha o arquivo
    free(vetor); //Libera a memórica alocada

    return 0;
}
