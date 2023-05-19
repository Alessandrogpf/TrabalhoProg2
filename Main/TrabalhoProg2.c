#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int tamanho_vetor, i;
    int* vetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);
    vetor = (int*) calloc(tamanho_vetor, sizeof(int));

    // Usado para medição de tempo de execução ---------------------------------------
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    /* Código */
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // --------------------------------------------------------------------------------

    // Gera número aleatórios e os adiciona dentro do vetor ---------------------------
    srand((unsigned) time(NULL));
    for (i = 0; i < tamanho_vetor; i++){
        vetor[i] = rand() % 10;
        printf("pos[%d] = %d\n",i , vetor[i]);
    }
    // --------------------------------------------------------------------------------
    
    return 0;
}