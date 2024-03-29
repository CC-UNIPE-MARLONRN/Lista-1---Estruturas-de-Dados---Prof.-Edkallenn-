/*
 **  Função : Escrever uma função em C chamada 'permutacao_circular' que recebe dois arrays de inteiros e seu tamanho como entrada, e verifica se o primeiro é uma permutação circular do segundo.  
 **           A função deve retornar 1 se for uma permutação circular e 0 caso contrário.  Use alocação dinâmica.
 ** Autor : Marlon Rufino do Nascimento 
 ** Data  : 24/03/2023 
 ** Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da língua portuguesa, tais como ´, ^, `, ª ...
 **
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Prototipo da função
int permutacao_circular(int *, int * , int);

//Função main
int main() {
    int n;
    int *array1, *array2;

    // Solicita ao usuário o tamanho dos arrays
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &n);

    // Aloca dinamicamente os arrays
    array1 = (int *) malloc(sizeof(int) * n);
    array2 = (int *) malloc(sizeof(int) * n);

    // Solicita ao usuário os valores dos arrays
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº valor do primeiro array: ", i + 1);
        scanf("%d", &array1[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Digite o %dº valor do segundo array: ", i + 1);
        scanf("%d", &array2[i]);
    }

    // Verifica se os arrays são permutações circulares
    int resultado = permutacao_circular(array1, array2, n);

    // Exibe o resultado
    if (resultado == 1) {
        printf("Os arrays são permutações circulares.\n");
    } else {
        printf("Os arrays não são permutações circulares.\n");
    }

    // Libera a memória alocada para os arrays
    free(array1);
    free(array2);

    return 0;
}

//Função permutação_circular
int permutacao_circular(int *array1, int *array2, int n) {
    // Cria um novo array com os elementos do primeiro array concatenados com ele mesmo
    int *array_concatenado = (int *) malloc(sizeof(int) * n * 2);
    for (int i = 0; i < n; i++) {
        array_concatenado[i] = array1[i];
        array_concatenado[i + n] = array1[i];
    }

    // Verifica se o segundo array está contido no array concatenado
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) {
            if (array2[i] == array_concatenado[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            return 0;
        }
        encontrado = 0;
    }

    // Libera a memória alocada para o array concatenado
    free(array_concatenado);

    // Se o segundo array está contido no array concatenado, então os arrays são permutações circulares
    return 1;
}