#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<limits.h>
#define MAX INT_MAX


int particiona(int* A, int p, int r){
    int x = A[r];
    int i = p-1, j, temp;
    for(j = p; j<r; j++){
        if(A[j] <= x){
            i++;
            temp = A[i];
            A[j] = temp;

        }
    }
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i+1;
}


int* bubble_sort(int* vetor, int tamanho_vetor){
    int i, j, temp;
    for(i = n-1; i>=0; i--){
        for(j = 0; j<i; j++){
            if(vetor[j] > vetor[j+1]){
                temp = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = temp;

            }
        }
    } return vetor;
    }
int* quick_sort(int* vetor, int tamanho_vetor){
    if(p >= r) return;
    int q = particiona(A, p, q-1);
    quick_sort(A, p, q-1);
    quick_sort(A, q+1, r);


}
int* merge_sort(int* vetor, int p, int q, int r){
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L;
    int* R;
    L = (int*) malloc((n1 +1)*sizeof(int));
    R = (int*) malloc((n2 + 1)*sizeof(int));

    for(i =0; i<n1; i++){
        L[i] = vetor[p+i];
    }
    for(j = 0; j<n2; j++){
        R[j] = vetor[q+j+1];
    }
    L[n1] = R[n2] = MAX;
    i = j = 0;
    for(k=p; k<=r; k++){
        if(L[i] <= R[j]){
            vetor[k] = L[i];
            i++;
        } else{ 
            vetor[k] = R[j];
            j++;
        }
    }
    free(L);
    free(R);
    return vetor;
}

int* insertion_sort(int* vetor, int tamanho_vetor){
    int i, j, chave;
    for (i  = 1; i < tamanho_vetor; i++) {
        chave = vetor[i];
        j = i - 1;
        
        while (j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        vetor[j + 1] = chave;
    }
    return vetor;
}


// Essa função ordena um vetor utilizando o método Selection Sort
int* selection_sort(int* vetor, int tamanho_vetor){
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
    return vetor;
}
// --------------------------------------------------------------------------------

// Calcula desvio padrão
int dp(){}


void mede_tempo(int* vetor, int tamanho_vetor){
     clock_t start, end;
    double cpu_time_used;

    start = clock();
     selection_sort(vetor, tamanho_vetor);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("------------------------------------------------------");
    printf("\n\nO tempo gasto pelo Selection Sort foi: %f\n", cpu_time_used);
}

// Gera um vetor aleatório
void vetor_random(int* vetor, int tamanho_vetor, int i){
    // Gera número aleatórios e os adiciona dentro do vetor
    srand((unsigned) time(NULL));
    printf("\nVetor não ordenado:\n");
    for (i = 0; i < tamanho_vetor; i++){
        vetor[i] = rand() % 10;
        printf("pos[%d] = %d\n", i, vetor[i]);
    }
}
// --------------------------------------------------------------------------------

void menu(int* v, int tamanho_vetor) {
    int op, cond = 1;

    while (cond == 1) {
        printf("\n-------------- Bem vindo ao menu! --------------------\n");
        printf("Esse programa realiza a ordenação de um vetor e avalia o tempo de execução\n");
        printf("\n1 - Ordenar vetor\n");
        printf("2 - Avaliar tempos de execução\n");
        printf("3 - Rodar 10x e calcular o desvio padrão\n");
        printf("4 - Alterar tamanho do vetor\n");
        printf("5 - Gráfico de tamanho n x tempo\n");
        printf("0 - Encerre o programa\n");
        printf("Escolha uma das opções acima: ");
        scanf("%d", &op);
        printf("------------------------------------------------------");

        switch (op) {
            case 1:
                int op_ord;
                printf("\n1 - Selection Sort\n");
                printf("2 - Insertion Sort\n");
                printf("3 - Merge Sort\n");
                printf("4 - Quick Sort\n");
                printf("5 - Bubble Sort\n");
                printf("Escolha uma das ordenações acima: ");
                scanf("%d", &op_ord);
                switch (op_ord) {
                    case 1:
                        selection_sort(v, tamanho_vetor);
                        break;
                    // Adicionar as outras funções conforme forem implementadas;
                
                    case 2:
                        insertion_sort(v, tamanho_vetor);
                        break;
                    case 3:
                        merge_sort(v, 0, (tamanho_vetor/2)-1, tamanho_vetor-1);
                        break;
                    case 4:
                        quick_sort(v, tamanho_vetor);
                    case 5:
                        bubble_sort(v, tamanho_vetor);
                        break;
                
                }
                printf("\nDeseja fazer outra operação?\n1 - Sim\n0 - Encerrar\n");
                printf("Escolha uma das ordenações acima: ");
                scanf("%d", &cond);
                break;

            case 2:
                mede_tempo(v, tamanho_vetor);
                printf("Escolha uma das ordenações acima: ");
                break;

            // Rodar 10x e calcular o desvio padrão
            case 3:
                /* Código */
                printf("Escolha uma das ordenações acima: ");
                break;

            case 4:
                printf("\nDigite o novo tamanho: ");
                scanf("%d", &tamanho_vetor);
                free(v);
                v = (int *)calloc(tamanho_vetor, sizeof(int));
                vetor_random(v, tamanho_vetor, 0);
                break;

            // Gráfico
            case 5:
                /* Código */
               // printf("\nDeseja fazer outra operação?\n1 - Sim\n0 - Encerrar\n");
                printf("Escolha uma das ordenações acima: ");
                scanf("%d", &cond);
                break;

            case 0:
                printf("\nPrograma encerrado!\n");
                cond = 0;
                break;
        }
    }
}


int main(){
    int tamanho_vetor, i;
    int* vetor; int* v;

    printf("Por favor, digite um tamanho para o vetor: ");
    scanf("%d", &tamanho_vetor);
    vetor = (int *) calloc(tamanho_vetor, sizeof(int));

    vetor_random(vetor, tamanho_vetor, i);
    v = vetor;
    menu(v, tamanho_vetor);

    free(vetor);
    return 0;
}