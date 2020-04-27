/* github.com/wendelmarques
--------------------------------------------------- TRABALHO PRÁTICO 1 - AED1 (2018.1) ---------------------------------------------------
Universidade Federal de Goiás
Instituto de Informática
Aluno: Wendel Marques de Jesus Souza
Prof. Nádia Félix
*/

 
#include <stdio.h>
#include <stdlib.h>
#define tam_bucket 150 //DEVE SER IGUAL A TAM

//CÓPIA https://pt.wikipedia.org/wiki/Bucket_sort
struct balde {
    int topo;
    int balde[tam_bucket];
};


/*

A seguinte funcao compara pares de elementos adjacentes e os troca de lugar
se necessário. Este procedimento é realizado até que mais nenhuma troca seja necessária
*/
//Wendel Marques
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
}

/*Distribui os valores em um conj de baldes. Cada balde guarda uma faixa de valores.
Ordena os valores de cada baldes (utilizando a funcao bubble). Por fim, pecorre os baldes
e coloca os valores de cada baldes no vetor ordenado.*/
//CÓPIA https://pt.wikipedia.org/wiki/Bucket_sort
void bucketSort(int v[],int tam){

        int num_bucket;
        num_bucket = tam / 10;


         struct balde b[num_bucket];
         int i, j, k;
 /* 1 */ for (i=0; i < num_bucket;i++)  //inicializa todos os "topo"
                 b[i].topo=0;

 /* 2 */ for(i=0;i<tam;i++){  //verifica em que balde o elemento deve ficar
                 j=(num_bucket)-1;
                 while(1){
                         if(j<0)
                                 break;
                         if(v[i]>=j*10){
                                 b[j].balde[b[j].topo]=v[i];
                                 (b[j].topo)++;
                                 break;
                         }
                         j--;
                 }
         }

 /* 3 */ for(i=0;i<num_bucket;i++)  //ordena os baldes
                 if(b[i].topo)
                         bubble(b[i].balde, b[i].topo);

         i=0;
 /* 4 */ for(j=0;j<num_bucket;j++){ //põe os elementos dos baldes de volta no vetor
                 for(k=0;k<b[j].topo;k++){
                         v[i]=b[j].balde[k];
                         i++;
                 }
         }

         bubble(v, tam);
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

    bucketSort(vetor, TAM); //Chama a função do metodo Bucket Sort

    // imprime os dados (para verificaçao de corretude)
    // for(i = 0; i < TAM; i++)
    //    printf("%i\n", vetor[i]);

    fclose (fptr); //Fecha o arquivo
    free(vetor); //Libera a memórica alocada

    return 0;
}
