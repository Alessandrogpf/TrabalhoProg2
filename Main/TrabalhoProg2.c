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


// Função para preencher o vetor com números aleatórios

void gerar_vetor_aleatorio(int* vetor, int tamanho_vetor) {
    srand(time(NULL));
    for (int i = 0; i < tamanho_vetor; i++) {
        vetor[i] = rand() % tamanho_vetor;
    }
}

void gerar_vetor_quase_ordenado(int* vetor, int tamanho, float percentual_ordenado) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
    int elementos_ordenados = (int)(tamanho * percentual_ordenado / 100);
    for (int i = 0; i < elementos_ordenados; i++) {
        int j = i + rand() % (tamanho - i);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void gerar_vetor_ordem_crescente(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
}

void gerar_vetor_ordem_decrescente(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

// Função para imprimir um vetor
void imprime_vetor(int* vetor, int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("%d", vetor[i]);
        if (i == tamanho_vetor -1) {
            printf(".");
        } else {
            printf(", ");
        }
    }
    printf("\n");
}

// Função auxiliar para realizar a troca de elementos no vetor
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição para o Quick Sort
int particiona(int* vetor, int p, int r) {
    int pivot = vetor[r];
    int i = p;
    for (int j = p; j < r; j++) {
        if (vetor[j] <= pivot) {
            troca(&vetor[i], &vetor[j]);
            i++;
        }
    }
    troca(&vetor[i], &vetor[r]);
    return i;
}

// Função recursiva do Quick Sort
void quick_sort(int* vetor, int p, int r) {
    if (p < r) {
        int q = particiona(vetor, p, r - 1);
        quick_sort(vetor, p, q - 1);
        quick_sort(vetor, q + 1, r);
    }
}

// Função para calcular o tempo de execução do Quick Sort
double tempo_quick(int* vetor, int tamanho_vetor) {
    clock_t inicio = clock();
    quick_sort(vetor, 0, tamanho_vetor - 1);
    clock_t fim = clock();
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Função de merge para o Merge Sort
void merge(int* vetor, int inicio, int meio, int fim) {
    int tamanho1 = meio - inicio + 1;
    int tamanho2 = fim - meio;

    int vetorEsquerdo[tamanho1], vetorDireito[tamanho2];

    for (int i = 0; i < tamanho1; i++)
        vetorEsquerdo[i] = vetor[inicio + i];
    for (int j = 0; j < tamanho2; j++)
        vetorDireito[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < tamanho1 && j < tamanho2) {
        if (vetorEsquerdo[i] <= vetorDireito[j]) {
            vetor[k] = vetorEsquerdo[i];
            i++;
        } else {
            vetor[k] = vetorDireito[j];
            j++;
        }
        k++;
    }

    while (i < tamanho1) {
        vetor[k] = vetorEsquerdo[i];
        i++;
        k++;
    }

    while (j < tamanho2) {
        vetor[k] = vetorDireito[j];
        j++;
        k++;
    }
}

// Função recursiva do Merge Sort
void merge_sort(int* vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

// Função para calcular o tempo de execução do Merge Sort
double tempo_merge(int* vetor, int tamanho_vetor) {
    clock_t inicio = clock();
    merge_sort(vetor, 0, tamanho_vetor - 1);
    clock_t fim = clock();
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Função do Selection Sort
void selection_sort(int* vetor, int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor - 1; i++) {
        int indice_menor = i;
        for (int j = i + 1; j < tamanho_vetor; j++) {
            if (vetor[j] < vetor[indice_menor]) {
                indice_menor = j;
            }
        }
        troca(&vetor[i], &vetor[indice_menor]);
    }
}

// Função para calcular o tempo de execução do Selection Sort
double tempo_selection(int* vetor, int tamanho_vetor) {
    clock_t inicio = clock();
    selection_sort(vetor, tamanho_vetor);
    clock_t fim = clock();
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Função do Insertion Sort
void insertion_sort(int* vetor, int tamanho_vetor) {
    for (int i = 1; i < tamanho_vetor; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

// Função para calcular o tempo de execução do Insertion Sort
double tempo_insertion(int* vetor, int tamanho_vetor) {
    clock_t inicio = clock();
    insertion_sort(vetor, tamanho_vetor);
    clock_t fim = clock();
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Função para rodar os algoritmos de ordenação 10 vezes
void rodar_10x(int* vetor, int tamanho_vetor) {
    double tempos_quick[10];
    double tempos_merge[10];
    double tempos_selection[10];
    double tempos_insertion[10];

    for (int i = 0; i < 10; i++) {
        int* copia_vetor1 = (int*)malloc(tamanho_vetor * sizeof(int));
        int* copia_vetor2 = (int*)malloc(tamanho_vetor * sizeof(int));
        int* copia_vetor3 = (int*)malloc(tamanho_vetor * sizeof(int));

        for (int j = 0; j < tamanho_vetor; j++) {
            copia_vetor1[j] = vetor[j];
            copia_vetor2[j] = vetor[j];
            copia_vetor3[j] = vetor[j];
        }

        tempos_quick[i] = tempo_quick(copia_vetor1, tamanho_vetor);
        tempos_merge[i] = tempo_merge(copia_vetor2, tamanho_vetor);
        tempos_selection[i] = tempo_selection(copia_vetor3, tamanho_vetor);
        tempos_insertion[i] = tempo_insertion(copia_vetor3, tamanho_vetor);

        free(copia_vetor1);
        free(copia_vetor2);
        free(copia_vetor3);
    }

    double media_quick = 0.0;
    double media_merge = 0.0;
    double media_selection = 0.0;
    double media_insertion = 0.0;

    for (int i = 0; i < 10; i++) {
        media_quick += tempos_quick[i];
        media_merge += tempos_merge[i];
        media_selection += tempos_selection[i];
        media_insertion += tempos_insertion[i];
    }

    media_quick /= 10;
    media_merge /= 10;
    media_selection /= 10;
    media_insertion /= 10;

    double desvio_padrao_quick = 0.0;
    double desvio_padrao_merge = 0.0;
    double desvio_padrao_selection = 0.0;
    double desvio_padrao_insertion = 0.0;

    for (int i = 0; i < 10; i++) {
        desvio_padrao_quick += pow(tempos_quick[i] - media_quick, 2);
        desvio_padrao_merge += pow(tempos_merge[i] - media_merge, 2);
        desvio_padrao_selection += pow(tempos_selection[i] - media_selection, 2);
        desvio_padrao_insertion += pow(tempos_insertion[i] - media_insertion, 2);
    }

    desvio_padrao_quick = sqrt(desvio_padrao_quick / 10);
    desvio_padrao_merge = sqrt(desvio_padrao_merge / 10);
    desvio_padrao_selection = sqrt(desvio_padrao_selection / 10);
    desvio_padrao_insertion = sqrt(desvio_padrao_insertion / 10);

    printf("\nMedia e desvio padrao dos tempos de execucao:\n");
    printf("Quick Sort - Media: %.6f segundos, Desvio Padrao: %.6f segundos\n", media_quick, desvio_padrao_quick);
    printf("Merge Sort - Media: %.6f segundos, Desvio Padrao: %.6f segundos\n", media_merge, desvio_padrao_merge);
    printf("Selection Sort - Media: %.6f segundos, Desvio Padrao: %.6f segundos\n", media_selection, desvio_padrao_selection);
    printf("Insertion Sort - Media: %.6f segundos, Desvio Padrao: %.6f segundos\n", media_insertion, desvio_padrao_insertion);
}

int main() {
    int tamanho_vetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);

    int* vetor = (int*)malloc(tamanho_vetor * sizeof(int));

    int opcao;
    printf("\nSelecione como o vetor sera construído:\n");
    printf("1. Aleatorio\n");
    printf("2. Quase ordenado\n");
    printf("3. Porcentagem ordenada\n");
    printf("4. Ordem crescente\n");
    printf("5. Ordem decrescente\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            gerar_vetor_aleatorio(vetor, tamanho_vetor);
            break;
        case 2:
            gerar_vetor_quase_ordenado(vetor, tamanho_vetor, 90.0);
            break;
        case 3:
            float percentual;
            printf("Digite a porcentagem de elementos ordenados: ");
            scanf("%f", &percentual);
            gerar_vetor_quase_ordenado(vetor, tamanho_vetor, percentual);
            break;
        case 4:
            gerar_vetor_ordem_crescente(vetor, tamanho_vetor);
            break;
        case 5:
            gerar_vetor_ordem_decrescente(vetor, tamanho_vetor);
            break;
        default:
            printf("Opcao invalida\n");
            free(vetor);
            return 0;
    }

    int visualizar_vetor;
    printf("\nDeseja visualizar o vetor construído?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    printf("Digite uma opção: ");
    scanf("%d", &visualizar_vetor);
    if (visualizar_vetor == 1) {
        printf("Vetor gerado: ");
        imprime_vetor(vetor, tamanho_vetor);
        printf("\n");
    }

    int* copia_vetor1 = (int*)malloc(tamanho_vetor * sizeof(int));
    int* copia_vetor2 = (int*)malloc(tamanho_vetor * sizeof(int));
    int* copia_vetor3 = (int*)malloc(tamanho_vetor * sizeof(int));
    for (int i = 0; i < tamanho_vetor; i++) {
        copia_vetor1[i] = vetor[i];
        copia_vetor2[i] = vetor[i];
        copia_vetor3[i] = vetor[i];
    }

    double tempo_quick_sort = tempo_quick(vetor, tamanho_vetor);
    printf("\nTempo de execucao do Quick Sort: %.6f segundos\n", tempo_quick_sort);

    double tempo_merge_sort = tempo_merge(copia_vetor1, tamanho_vetor);
    printf("Tempo de execucao do Merge Sort: %.6f segundos\n", tempo_merge_sort);

    double tempo_selection_sort = tempo_selection(copia_vetor2, tamanho_vetor);
    printf("Tempo de execucao do Selection Sort: %.6f segundos\n", tempo_selection_sort);

    double tempo_insertion_sort = tempo_insertion(copia_vetor3, tamanho_vetor);
    printf("Tempo de execucao do Insertion Sort: %.6f segundos\n", tempo_insertion_sort);

    rodar_10x(vetor, tamanho_vetor);

    int visualiza_ordenado;
    printf("\nDeseja visualizar o vetor ordenado?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    printf("Digite uma opção: ");
    scanf("%d", &visualiza_ordenado);
    if (visualiza_ordenado == 1) {
        printf("Vetor ordenado: ");
        imprime_vetor(copia_vetor1, tamanho_vetor);
    }   else {
        printf("Programa encerrado!");
    }

    free(vetor);
    free(copia_vetor1);
    free(copia_vetor2);
    free(copia_vetor3);

    return 0;
}
