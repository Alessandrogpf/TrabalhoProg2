/* ============================ ATENÇÃO!!!!!! ============================
        Por favor, compile o código da seguinte forma:
        "gcc programa.c -lm"
        Caso contrário dará erro por conta da utilização da biblioteca math.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define MAX INT_MAX

// Protótipos de função
int* quick_sort(int* vetor, int p, int r);
void imprime_quick(int* vetor, int tamanho_vetor);
int* merge_sort(int* vetor, int p, int r);
int* insertion_sort(int* v, int tamanho_vetor);
double tempo_insertion(int* v, int tamanho_vetor);
void imprime_insertion(int* v, int tamanho_vetor);
int* selection_sort(int* v, int tamanho_vetor);
double tempo_selection(int* v, int tamanho_vetor);
void trocar(int* a, int* b);
int particiona(int* A, int inicio, int fim);
void imprime_selection(int* v, int tamanho_vetor);
double desvioPadrao(int* v, int tamanho_vetor);
void vetor_random(int* vetor, int tamanho_vetor, int i);
void menu(int* v, int tamanho_vetor, double tempoSelection, double tempoInsertion, double tempoMerge, double tempoQuick, double desvio_padrao);
// ===================================================================================

// ===================================================================================

// Função de partição do Quick Sort
int particiona(int* A, int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            trocar(&A[i], &A[j]);
        }
    }

    trocar(&A[i + 1], &A[r]);
    return i + 1;
}
// Funcao de auxilio ao particiona do Quick Sort
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// ===================================================================================

// Essa função ordena um vetor utilizando o método Quick Sort
int* quick_sort(int* vetor, int p, int r) {
    if (p < r) {
        int q = particiona(vetor, p, r);
        quick_sort(vetor, p, q - 1);
        quick_sort(vetor, q + 1, r);
    }
    return vetor;
}
// ===================================================================================

void imprime_quick(int* v, int tamanho_vetor) {
    int i; int* quick;
    quick = quick_sort(v, 0, tamanho_vetor - 1);

    printf("\nVetor ordenado pelo Quick Sort:\n");
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("%d", quick[i]);
        if (i == tamanho_vetor -1) {
            printf(".");
        } else {
            printf(", ");
        }
    }
}

double tempo_quick(int* v, int tamanho_vetor, int p, int r){
   double time_quick;

    clock_t start = clock();
    quick_sort(v, 0, tamanho_vetor - 1);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_quick = cpu_time_used;

    return time_quick;
}
// ===================================================================================

// Função de apoio para Merge Sort
void particionaMerge(int primeiro_elemento, int meio, int ultimo, int* v) {
    int tamanho1 = meio - primeiro_elemento + 1;
    int tamanho2 = ultimo - meio;
    int vetorEsquerdo[tamanho1], vetorDireito[tamanho2]; // Vetores Auxiliares
    int i, j, k;

    // Copia os elementos para os vetores auxiliares
    for (i = 0; i < tamanho1; i++) {
        vetorEsquerdo[i] = v[primeiro_elemento + i];
    }

    for (j = 0; j < tamanho2; j++) {
        vetorDireito[j] = v[meio + 1 + j];
    }

    i = 0; // Índice do vetor esquerdo
    j = 0; // Índice do vetor direito
    k = primeiro_elemento; // Índice do vetor original

    // Realiza a intercalação dos elementos ordenadamente
    while (i < tamanho1 && j < tamanho2) {
        if (vetorEsquerdo[i] <= vetorDireito[j]) {
            v[k] = vetorEsquerdo[i];
            i++;
        } else {
            v[k] = vetorDireito[j];
            j++;
        }
        k++;
    }

    // Copia elementos restantes do vetor esquerdo caso haja
    while (i < tamanho1) {
        v[k] = vetorEsquerdo[i];
        i++;
        k++;
    }

    // Copia elementos restantes do vetor direito caso haja
    while (j < tamanho2) {
        v[k] = vetorDireito[j];
        j++;
        k++;
    }
}
// ===================================================================================

// Essa função ordena um vetor utilizando o método Merge Sort
int* merge_sort(int* v, int primeiro_elemento, int ultimo){

   if (primeiro_elemento >= ultimo) return v; {                 
      int meio = (primeiro_elemento + ultimo)/2;

      merge_sort (v, primeiro_elemento, meio);        
      merge_sort (v, meio + 1, ultimo);        
      particionaMerge (primeiro_elemento, meio, ultimo, v); 

      return v;
    }
}
// ===================================================================================

// Printa o vetor ordenado por Merge Sort
void imprime_merge(int* v, int tamanho_vetor){
    int i; int* merge;
    merge = merge_sort(v, 0, tamanho_vetor - 1);

    printf("\nVetor ordenado pelo Merge Sort:\n");
    for (i = 0; i < tamanho_vetor; i++){
        printf("%d", merge[i]);
        if (i == tamanho_vetor -1) {
            printf(".");
        } else {
            printf(", ");
        }
    }
}
// ===================================================================================

// Calcula o tempo de execução do Merge Sort
double tempo_merge(int* v, int tamanho_vetor, int primeiro_elemento, int ultimo){
   double time_merge;

    clock_t start = clock();
    merge_sort(v, 0, tamanho_vetor - 1);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_merge = cpu_time_used;

    return time_merge;
}
// ===================================================================================

// Essa função ordena um vetor utilizando o método Insertion Sort
int* insertion_sort(int* v, int tamanho_vetor){
    int i, j, chave;
    for (i  = 1; i < tamanho_vetor; i++) {
        chave = v[i];
        j = i - 1;
        
        while (j >= 0 && v[j] > chave){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
    return v;
}
// ===================================================================================

// Printa o vetor ordenado por Insertion Sort
void imprime_insertion(int* v, int tamanho_vetor){
    int i; int* insertion;
    insertion = insertion_sort(v, tamanho_vetor);

    printf("\nVetor ordenado pelo Insertion Sort:\n");
    for (i = 0; i < tamanho_vetor; i++){
        printf("%d", insertion[i]);
        if (i == tamanho_vetor -1) {
            printf(".");
        } else {
            printf(", ");
        }
    }
}
// ===================================================================================

// Calcula o tempo de execução do Insertion Sort
double tempo_insertion(int* v, int tamanho_vetor){
   double time_insertion;

    clock_t start = clock();
    insertion_sort(v,tamanho_vetor);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_insertion = cpu_time_used;

    return time_insertion;
}
// ===================================================================================

// Essa função ordena um vetor utilizando o método Selection Sort
int* selection_sort(int* v, int tamanho_vetor){
    int i, j, menor, troca;

    for (i = 0; i < tamanho_vetor - 1; i++){
        menor = i;

        for(j = i+1; j < tamanho_vetor; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if (i != menor) {
        troca = v[i];
        v[i] = v[menor];
        v[menor] = troca;
        }
   }
    return v;
}
// ===================================================================================

// Calcula o tempo de execução do Selection Sort
double tempo_selection(int* v, int tamanho_vetor){
    double time_selection;

    clock_t start = clock();
    selection_sort(v,tamanho_vetor);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_selection = cpu_time_used;

    return time_selection;
}
// ===================================================================================

// Printa o vetor ordenado por Selection Sort
void imprime_selection(int* v, int tamanho_vetor){
    int i; int* selection;
    selection = selection_sort(v, tamanho_vetor);

    printf("\nVetor ordenado pelo Selection Sort:\n");
    for (i = 0; i < tamanho_vetor; i++){
        printf("%d", selection[i]);
        if (i == tamanho_vetor - 1) {
            printf(".");
        } else {
            printf(", ");
        }
    }
}
// ===================================================================================

// Calcula desvio padrão entre os tempos.
double desvioPadrao(int* v, int tamanho_vetor) {
    int i;
    double mediaS = 0, mediaI = 0, mediaM = 0, somaDesvios = 0, desvio;
    double valores_selection[10];
    double valores_insertion[10];
    double valores_merge[10];

    // Armazena o tempo de execução do Selection Sort
    for(i = 0; i < 10; i++){
        valores_selection[i] = tempo_selection(v, tamanho_vetor);
        mediaS += valores_selection[i];
    }
    mediaS /= 10;

    // Armazena o tempo de execução do Insertion Sort
    for(i = 0; i < 10; i++){
        valores_insertion[i] = tempo_insertion(v, tamanho_vetor);
        mediaI += valores_insertion[i];
    }
    mediaI /= 10;

    // Armazena o tempo de execução do Merge Sort
    for(i = 0; i < 10; i++){
        valores_merge[i] = tempo_merge(v, tamanho_vetor, 0, tamanho_vetor - 1);
        mediaM += valores_merge[i];
    }
    mediaM /= 10;


    // Calcula o desvio padrão entre os tempos de execução
    for(i = 0; i < 10; i++){
        somaDesvios += pow(valores_selection[i] - valores_insertion[i] - valores_merge[i], 2);
    }
    desvio = sqrt(somaDesvios / 10);

    return desvio;
}

// ===================================================================================

// Gera um vetor aleatório
void vetor_random(int* vetor, int tamanho_vetor, int i){
    // Gera número aleatórios e os adiciona dentro do vetor
    srand((unsigned) time(NULL));
    printf("\nVetor não ordenado:\n");
    for (i = 0; i < tamanho_vetor; i++){
        vetor[i] = rand() % 100;
        printf("%d", vetor[i]);
        if (i == tamanho_vetor - 1) {
            printf(".");
        } else {
            printf(", ");
        }
    }
}
// ===================================================================================

void menu(int* v, int tamanho_vetor, double tempoSelection, double tempoInsertion, double tempoMerge, double tempoQuick, double desvio_padrao) {
    int op, cond = 1;

    while (cond == 1) {
        printf("\n\n****************** Bem vindo ao menu! *******************\n");
        printf("\n1 - Ordenar vetor\n");
        printf("2 - Avaliar tempos de execução\n");
        printf("3 - Rodar 10x e calcular o desvio padrão\n");
        printf("4 - Alterar tamanho do vetor\n");
        printf("0 - Encerre o programa\n");
        printf("Escolha uma das opções acima: ");
        scanf("%d", &op);
         printf("=====================================================");

        switch (op) {
            case 1:
            {
                int op_ord;
                printf("\n1 - Selection Sort\n");
                printf("2 - Insertion Sort\n");
                printf("3 - Merge Sort\n");
                printf("4 - Quick Sort\n");
                printf("Escolha uma das ordenações acima: ");
                scanf("%d", &op_ord);
                // Switch interno
                switch (op_ord) {
                    case 1:
                        printf("=====================================================");
                        imprime_selection(v, tamanho_vetor);
                        break;
                    case 2:
                        printf("=====================================================");
                        imprime_insertion(v, tamanho_vetor);
                        break;
                    case 3:
                        printf("=====================================================");
                        imprime_merge(v, tamanho_vetor);
                        break;
                    case 4:
                        printf("=====================================================");
                        imprime_quick(v, tamanho_vetor);
                        break;
                }
                printf("\nDeseja fazer outra operação?\n1 - Sim\n0 - Encerrar\n");
                printf("Escolha uma das opções acima: ");
                scanf("%d", &cond);
                if (cond == 0){printf("\nPrograma encerrado!\n"); break;}
                break;
            }
            case 2:
            {
                int op_ord;
                printf("\n1 - Selection Sort\n");
                printf("2 - Insertion Sort\n");
                printf("3 - Merge Sort\n");
                printf("4 - Quick Sort\n");
                printf("Escolha uma das ordenações acima: ");
                scanf("%d", &op_ord);
                //Switch interno
                switch (op_ord){
                    case 1:
                        printf("=====================================================");
                        printf("\n\nO tempo gasto pelo Selection Sort foi: %f\n", tempoSelection);
                        break;

                    case 2:
                        printf("=====================================================");
                        printf("\n\nO tempo gasto pelo Insertion Sort foi: %f\n", tempoInsertion);
                        break;
                    
                    case 3:
                        printf("=====================================================");
                        printf("\n\nO tempo gasto pelo Merge Sort foi: %f\n", tempoMerge);
                        break;

                    case 4:
                        printf("=====================================================");
                        printf("\n\nO tempo gasto pelo Quick Sort foi: %f\n", tempoQuick);
                        break;
                }
                // -------------------------------------------------------
                printf("\nDeseja fazer outra operação?\n1 - Sim\n0 - Encerrar\n");
                printf("Escolha uma das opções acima: ");
                scanf("%d", &cond);
                if (cond == 0){printf("\nPrograma encerrado!\n"); break;}
                break;
            }
            // Rodar 10x e calcular o desvio padrão
            case 3:
                printf("=====================================================");
                printf("\nO desvio padrão é: %f\n", desvio_padrao);
                printf("\nDeseja fazer outra operação?\n1 - Sim\n0 - Encerrar\n");
                printf("Escolha uma das opções acima: ");
                scanf("%d", &cond);
                if (cond == 0){printf("\nPrograma encerrado!\n"); break;}
                break;

            case 4:
                printf("\nDigite o novo tamanho: ");
                scanf("%d", &tamanho_vetor);
                free(v);
                v = (int *)calloc(tamanho_vetor, sizeof(int));
                vetor_random(v, tamanho_vetor, 0);
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

    double desvio_padrao = desvioPadrao(v, tamanho_vetor);
    double tempoSelection = tempo_selection(v, tamanho_vetor);
    double tempoInsertion = tempo_insertion(v, tamanho_vetor);
    double tempoMerge = tempo_merge(v, tamanho_vetor, 0, tamanho_vetor - 1);
    double tempoQuick = tempo_quick(v, tamanho_vetor, 0, tamanho_vetor - 1);

    menu(v, tamanho_vetor, tempoSelection, tempoInsertion, tempoMerge, tempoQuick, desvio_padrao);
    
    free(vetor);
    return 0;
}