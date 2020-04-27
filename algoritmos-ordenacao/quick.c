/* github.com/wendelmarques
--------------------------------------------------- TRABALHO PRÁTICO 1 - AED1 (2018.1) ---------------------------------------------------
Universidade Federal de Goiás
Instituto de Informática
Aluno: Wendel Marques de Jesus Souza
Prof. Nádia Félix
*/

 

#include <stdio.h>
#include <stdlib.h>

/* Funcao chamada pela funcao quick
Particiona vetor[] considerando os índices p e r como limites
(inferior e superior), retornando o índice onde ocorreu o particionamento
COPIA:  Slides das aulas*/
int partition(int vetor[], int p, int r) {
    int aux, pivo = vetor[r], i = p - 1, j;

 //recua posicao da direita para a esquerda
    for (j = p; j <= r - 1; j++) {

        //troca esquerda e direita
        if(vetor[j] <= pivo) {
            i = i + 1;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    aux = vetor[i + 1];
    vetor[i + 1] = vetor[r];
    vetor[r] = aux;

    return (i + 1);
}

/*Função recursiva que divide o vetor original em duas particoes

Os dados são rearranjados (valores menores
do que o pivo são colocados antes dele e os maiores, depois)

Wendel Marques
*/
void quick(int vetor[], int inicio, int fim) {

    int q;

    if (inicio < fim) {

        q = partition (vetor, inicio, fim); //separa os dados em particoes
        quick(vetor, inicio, q - 1); //chama a funcao para um das metades
        quick(vetor, q + 1, fim); //chama a funcao para a outra metade

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

    quick(vetor, 0, TAM); //Chama a função do metodo Quick Sort

    //imprime os dados (para verificaçao de corretude)
    // for(i = 0; i < TAM; i++)
    //    printf("%i\n", vetor[i] + 1);

    fclose (fptr); //Fecha o arquivo
    free(vetor); //Libera a memórica alocada

    return 0;
}
