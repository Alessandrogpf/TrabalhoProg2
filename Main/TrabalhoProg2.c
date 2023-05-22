#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Essa função ordena um vetor utilizando o método Selection Sort
void selection_sort(int* vetor, int tamanho_vetor){
    int i, j, menor, troca;

    for (i = 0; i < tamanho_vetor - 1; i++){
        menor = i;

        for(j = i+1; j < tamanho_vetor; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if (i != menor) {
        troca = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = troca;
        }
   }
    printf("\nVetor ordenado:\n");
    for (i = 0; i < tamanho_vetor; i++){
        printf("pos[%d] = %d\n", i, vetor[i]);
    }
}
// --------------------------------------------------------------------------------

int main(){
    int tamanho_vetor, i;
    int* vetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);
    vetor = (int *) calloc(tamanho_vetor, sizeof(int));

    // Gera número aleatórios e os adiciona dentro do vetor
    srand((unsigned) time(NULL));
    printf("\nVetor não ordenado:\n");
    for (i = 0; i < tamanho_vetor; i++){
        vetor[i] = rand() % 10;
        printf("pos[%d] = %d\n", i, vetor[i]);
    }
    // --------------------------------------------------------------------------------

    // Usado para medição de tempo de execução
    clock_t start, end;
    double cpu_time_used;

    start = clock();
     selection_sort(vetor, tamanho_vetor);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("O tempo gasto para ordenar foi: %f", cpu_time_used);
    // --------------------------------------------------------------------------------

    return 0;
}