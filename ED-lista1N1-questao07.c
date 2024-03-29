/*
**    Função : Escrever uma função em C chamada 'eh_numero_feliz' que recebe um número inteiro positivo n como entrada e retorna verdadeiro se n for um número feliz, e falso caso contrário. 
**    Use um array para checar se o número já foi “visitado” em um “percurso feliz”. 
**    Se determinado número já foi visitado, então é um ciclo infinito e o número não é feliz.
**    Autor : Marlon Rufino do Nascimento 2º período turma A 2024.1
**    Data  : 24/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da língua portuguesa, tais como ´, ^, `, ª ...
**                 Tomei a liberdade de colocar um loop ao trabalho para deixar o processo mais interessante de se trabalhar e buscar os números que deseja saber se são felizes ou não.
*/

#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

// Protótipo da função
bool eh_numero_feliz(int n);

//Função main
int main() {
    setlocale(LC_ALL, "Portuguese");

    int play_now = 1;
    char resposta[4];
    int n;

    do {
        printf("\nDigite um número inteiro positivo para verificar se é um número feliz:");
        scanf("%d", &n);

        if (eh_numero_feliz(n)) {
            printf("\n %d é um número feliz.\n\n", n);
        } else {
            printf("\n %d não é um número feliz.\n\n", n);
        }
 
        do {
            printf("Deseja digitar outro número novamente? \nSim ou não?\n");
            scanf("%s", resposta);

            if (strcmp(resposta, "sim") == 0) {
                play_now = 1;
                break;
            } else if (strcmp(resposta, "não") == 0) {
                play_now = 0;
                break;
            } else {
                printf("\nResposta inválida! Por favor, digite 'sim' ou 'não'.\n");
            }

        } while (1);

    } while (play_now == 1);

    printf("\nAplicação finalizada!\n");
    return 0;
}

// Implementação da função eh_numero_feliz
bool eh_numero_feliz(int n) {
    int visitados[1000] = {0}; // Array para verificar números visitados
    int soma_quadrados;

    while (1) {
        soma_quadrados = 0;
        
        // Calcula a soma dos quadrados dos dígitos de n
        while (n) {
            soma_quadrados += (n % 10) * (n % 10);
            n /= 10;
        }

        // Verifica se a soma é 1 (número feliz)
        if (soma_quadrados == 1) {
            return true;
        }

        // Verifica se a soma já foi visitada (evita ciclo infinito)
        if (visitados[soma_quadrados] == 1) {
            return false;
        }

        // Marca a soma como visitada
        visitados[soma_quadrados] = 1;

        // Atualiza n com a soma dos quadrados
        n = soma_quadrados;
    }
}
