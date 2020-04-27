/* github.com/wendelmarques
--------------------------------------------------- TRABALHO PRÁTICO 1 - AED1 (2018.1) ---------------------------------------------------
Universidade Federal de Goiás
Instituto de Informática
Aluno: Wendel Marques de Jesus Souza
Prof. Nádia Félix
*/

 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* CÓPIA: https://www.youtube.com/watch?v=RZbg5oT5Fgw */
void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;

    p1 = inicio;
    p2 = meio + 1;

    temp = (int *) malloc(tamanho * sizeof(int));

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {

            //combina ordenando
            if (!fim1 && !fim2) {
                if (V[p1] < V[p2])
                    temp[i] = V[p1++];

                else
                    temp[i] = V[p2++];

                //verifica se o vetor acabou
                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 2;
            }

            //copia o que sobrar
             else {
                if (!fim1)
                    temp[i] = V[p1++];

                else
                    temp[i] = V[p2++];
             }

        }

        //copiar do auxiliar para o original
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            V[k] = temp[j];
    }
    free(temp);
}

/*

A funcao recursiva mergeSort recebe um vetor com tanahamo TAM. Ela divide o conj.
de dados até que cada subconjunto possua apenas 1 elemento em sua composição.
O processo termina quando essa última condicao eh satisfeita

CÓPIA: https://www.youtube.com/watch?v=RZbg5oT5Fgw */
void mergeSort(int *V, int inicio, int fim){

    if(inicio < fim){
        int meio = floor(inicio + fim) / 2;

        mergeSort(V, inicio, meio); //chama a funcao para uma das metades
        mergeSort(V, meio + 1, fim); //chama a funcao para a outra metade
        merge(V, inicio, meio, fim); //combina as 2 metades de forma ordenad
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
    int inicio, fim;
    FILE *fptr;
    int TAM; //Este é o tamanho do experimento, ou seja, do vetor que sera ordenado

    scanf("%i", &TAM); //Lê o tamanho do vetor

    fptr = fopen ("seq.txt", "r"); /*Abre, em modo texto, o arquivo que contem a
                                    sequencia a ser ordenada (gravação a partir
                                    so seu inicio)*/

    vetor = malloc(TAM * sizeof(int)); //Alocação dinâmica do vetor com base em TAM


    /*O seguinte While lê o arquivo e logo em seguida armazena o numero i
        da seq de numeros do arquivo na i-esima posição do vetor*/
    j = 0;
    while (fscanf(fptr, "%i", &regnum) != EOF) {
        vetor[j] = regnum;
        j++;
    }

    inicio = 0;
    fim = TAM;

    mergeSort(vetor, inicio, fim);//Chama a função do metodo Merge Sort

    //imprime os dados (para verificaçao de corretude)
    // for(i = 0; i < TAM; i++)
    //    printf("%i\n", vetor[i] + 1);

    fclose (fptr); //Fecha o arquivo
    free(vetor); //Libera a memórica alocada

    return 0;
}
