/*
**    Função : Escrever uma função em C chamada 'eh_numero_armstrong' que recebe um número inteiro positivo n como entrada e retorna verdadeiro se n for um número de Armstrong, e falso caso contrário.
**             Usando esta função mostrar todos os números de Armstrong entre '1 e 100'.
**    Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
**    Data  : 24/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...
*/

#include <stdbool.h>
#include <stdio.h>
#include <locale.h>

// Protótipo da função eh_numero_armstrong
bool eh_numero_armstrong(int n);

//Função main
int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int inicio = 1;
    int fim = 100;

    printf("Números de Armstrong entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (eh_numero_armstrong(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

// Implementação da função eh_numero_armstrong
bool eh_numero_armstrong(int n) {
    int original = n;
    int soma = 0;
    int digitos = 0;

    int temp = n;

    // Conta o número de dígitos em n
    while (temp != 0) {
        temp /= 10;
        digitos++;
    }

    temp = original;

    // Calcula a soma dos cubos dos dígitos de n
    while (temp != 0) {
        int digito = temp % 10;
        int cubo = 1;
        for (int i = 0; i < digitos; i++) {
            cubo *= digito;
        }
        soma += cubo;
        temp /= 10;
    }

    return soma == original;
}

