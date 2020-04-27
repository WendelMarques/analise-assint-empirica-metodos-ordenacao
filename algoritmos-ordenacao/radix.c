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
A seguinte funcao recebe um vetor vet  e o seu tamanho n. Em seguida, inicializa um segundo vetor
e o faz incrementos ddele e acordo com os digitos dos elementos do vetor original vet.

CÓPIA: (https://github.com/Fernando-Lafeta/Algoritmos-de-ordenacao/blob/master/radix-sort.c)
*/
void radix(int *vet, int n) {
	int i, exp = 1, m = 0, bucket[n], temp[n];

	//busca o maior elemento do vetor
	for(i = 0; i < n; i++) {
		if(vet[i] > m) {
			m = vet[i];
		}
	}

	while((m/exp) > 0) {

		//inicializa o vetor bucket com o valor 0
		for (i = 0; i < n; i++) {
			bucket[i] = 0;
		}

		for (i = 0; i < n; i++) {
			bucket[(vet[i] / exp) % 10]++;
		}

		for( i = 1; i < n; i++) {
			bucket[i] += bucket[i-1];
		}

		for (i = (n - 1); i >= 0; i--) {
			temp[--bucket[(vet[i] / exp) % 10]] = vet[i];
		}

		for (i = 0; i < n; i++) {
			vet[i] = temp[i];
		}

		exp *= 10;
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
    int i, regnum, num_digitos;
    int base;
    FILE *fptr;
	int TAM; //Este é o tamanho do experimento, ou seja, do vetor que sera ordenado

	fptr = fopen ("seq.txt", "r"); /*Abre, em modo texto, o arquivo que contem a
                                    sequencia a ser ordenada (gravação a partir
                                    so seu inicio)*/

	scanf("%i", &TAM); //Lê o tamanho do vetor
	num_digitos = TAM;

    vetor = malloc(TAM * sizeof(int)); //Alocação dinâmica do vetor com base em TAM


    /*O seguinte While lê o arquivo e logo em seguida armazena o numero i
        da seq de numeros do arquivo na i-esima posição do vetor*/
    j = 0;
    while (fscanf(fptr, "%i", &regnum) != EOF) {
        vetor[j] = regnum;
        j++;
    }

    radix(vetor, TAM); //Chama a função do metodo Radix Sort

	//imprime os dados (para verificaçao de corretude)
	// for(i = 0; i < TAM; i++)
	//    printf("%i\n", vetor[i]);

	fclose (fptr); //Fecha o arquivo
    free(vetor); //Libera a memórica alocada

    return 0;
}
