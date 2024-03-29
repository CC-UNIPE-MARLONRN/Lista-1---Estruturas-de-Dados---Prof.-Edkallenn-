/*
 ** Função : Escrever uma função em C chamada 'fibonacci_max' que recebe um número inteiro 'max' como entrada e retorna um array contendo todos os números da série de Fibonacci que sejam menores ou iguais a max. 
 **          O array retornado deve terminar com um marcador de posição especial, como -1. Use alocação dinâmica.
 ** Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
 ** Data  : 24/03/2024
 ** Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...
 */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

double *fibonacci_max(int);
void add_element(double **, int *, double);

int main() {
    setlocale(LC_ALL, "portuguese");

    int max;

    // Solicita ao usuário que insira um número
    printf("Digite um número para gerar a sequência de Fibonacci até esse número: ");
    scanf("%d", &max);

    // Chama a função fibonacci_max para gerar os números de Fibonacci
    double *fibonacci = fibonacci_max(max);

    // Exibe os números de Fibonacci até o número inserido
    printf("Sequência de Fibonacci até %d:\n", max);
    int i = 0;

    while (fibonacci[i] <= max) {
        printf("%.0f ", fibonacci[i]);
        i++;
    }

    // Adiciona -1 ao final do array se o último número for maior que max
    if (fibonacci[i-1] != max)
    {
        printf("-1 ");
    }
    

    // Libera a memória alocada para o array de Fibonacci
    free(fibonacci);

    return 0;
}

double *fibonacci_max(int max) {
    // Aloca dinamicamente um array para armazenar os números de Fibonacci
    double *fibonacci = malloc(sizeof(double) * max);

    // Inicializa os dois primeiros números de Fibonacci
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // Calcula os números de Fibonacci restantes até que o último número seja maior que max
    int i = 2;
    while (fibonacci[i - 1] <= max) {
        // O próximo número de Fibonacci é a soma dos dois números anteriores
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        i++;
    }

    // Retorna o array de números de Fibonacci
    return fibonacci;
}
