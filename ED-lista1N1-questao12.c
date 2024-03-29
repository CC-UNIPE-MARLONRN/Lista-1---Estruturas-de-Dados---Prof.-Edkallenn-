/*
**    Função : Construir um programa que apresente o tempo em anos para cada caso de teste.
**             Porém, se o tempo for muito grande, informar a mensagem "Mais de 1 século.".
**    Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
**    Data  : 27/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...
*/

#include <stdio.h>
#include <locale.h>

//Função main
int main() {
    int t, anos;
    int pa, pb;
    double g1, g2;
    
    printf("Insira o número de casos de teste: ");
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        printf("Caso nº %d: \n", i + 1);
        printf("Digite a quantidade de habitantes da cidade A: ");
        scanf("%d", &pa); 
        printf("Digite a quantidade de habitantes da cidade B: ");
        scanf("%d", &pb);
        printf("Digite o valor do crescimento populacional da cidade A: ");
        scanf("%lf", &g1);
        printf("Digite o valor do crescimento populacional da cidade B: ");
        scanf("%lf", &g2);

        anos = 0;
        while (pa <= pb) {
            pa += pa * (g1 / 100);
            pb += pb * (g2 / 100);
            anos++;

            if (anos > 100) {
                printf("Levará mais de 1 século para a ultrapassagem da cidade B!\n");
                break;
            }
        }

        if (anos <= 100) {
            printf("\n");
            printf("Levará %d anos para a ultrapassagem da cidade B!\n\n", anos);
        }
    }

    return 0;
}
