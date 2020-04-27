/* github.com/wendelmarques
--------------------------------------------------- TRABALHO PRÁTICO 1 - AED1 (2018.1) ---------------------------------------------------
Universidade Federal de Goiás
Instituto de Informática
Aluno: Wendel Marques de Jesus Souza
Prof. Nádia Félix
*/

 
#include <stdio.h>
#include <stdlib.h>

void counting (int[], int);

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

                                    /*
                                    --------------------------------------------------- TRABALHO PRÁTICO 1 - AED1 (2018.1) ---------------------------------------------------

                                    Aluno: Wendel Marques de Jesus Souza
                                    Prof. Nádia Félix

                                    */

                                       scanf("%i", &TAM); //Lê o tamanho do vetor

    vetor = malloc(TAM * sizeof(int)); //Alocação dinâmica do vetor com base em TAM


    /*O seguinte While lê o arquivo e logo em seguida armazena o numero i
        da seq de numeros do arquivo na i-esima posição do vetor*/
    j = 0;
    while (fscanf(fptr, "%i", &regnum) != EOF) {
        vetor[j] = regnum;
        j++;
    }

    counting(vetor, TAM); //Chama a função do metodo Counting Sort

    fclose (fptr); //Fecha o arquivo
    free(vetor); //Libera a memórica alocada

    return 0;
}


/*Recebe um vetor de tamanho n. Determina, inicialmente, quantos elementos
são menores que n. Dessa forma, ao fim desse processo, n está na sua posição correta
Esse processo é feito para todos os indices 0 .. n.
*/
//Wendel Marques
void counting (int vetor[], int n) {

    int i, j, k;
    int baldes[n];

    //inicializa todas as posições do vetor balde com o valor 0
	for (i = 0; i < n; i++)
        baldes[i] = 0;

    //vare o vetor principal e contabiliza
        //a ocorrencia dos elementos no vetor baldes
	for (i = 0; i < n; i++)
        baldes[vetor[i]] = baldes[vetor[i]] + 1;

    //vare o vetor baldes verificando a ocorrencia dos elementos
        //e add na posição correta em vetor
	for(i = 0, j = 0; j < n; j++) {
        for (k = baldes[j]; k > 0; k--)
            vetor[i++] = j;
    }

    //imprime os dados (para verificaçao de corretude)
    // for(i = 0; i < n; i++)
    //    printf("%i\n", vetor[i]);
}
