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

A seguinte funcao compara pares de elementos adjacentes e os troca de lugar
se necessário. Este procedimento é realizado até que mais nenhuma troca seja necessária
Wendel Marques */
void bubble (int vetor[], int n) {

    int i, fim, aux;

    for(fim = n - 1; fim > 0; fim--) {

        //enquanto fim /= de 0, a cada iteração um element maior é deslocado
            //para o fim do vetor
        for(i = 0; i < fim; i++) {
            //Realização da troca
            if(vetor[i] > vetor[i + 1]) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
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

    bubble(vetor, TAM); //Chama a função do metodo Bubble Sort

    fclose (fptr); //Fecha o arquivo
    free(vetor); //Libera a memórica alocada

    return 0;
}
