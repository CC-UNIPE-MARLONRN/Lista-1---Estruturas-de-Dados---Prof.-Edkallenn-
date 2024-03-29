/*
**    Função : Escrever uma função em C chamada 'verificar_numero_automorfico' que verifica se um dado número inteiro 'n' é automórfico ou não. 
**             Usando a função mostrar todos os números automórficos entre '2 e 1000'. 
**             Guardar-los em um array usando alocação dinâmica.
**    Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
**    Data  : 23/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...
*/

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

//Protótipo das Funções
int eh_numero_automorfico (int);
void verificar_numero_automorfico (int, int);

//Função main
int main(){
    setlocale(LC_ALL, "Portuguese");

    verificar_numero_automorfico(2,1000); //verifica quaisos números automorficos no intervalo de 2-1000

    return 0;
}

//Função que verifica se o número é automorfico ou não (verifica por unidade, entra o número dentro do valor n, e verfica se ele é automorfico ou não);
int eh_numero_automorfico(int n){
    int quadrado = n * n;
    while(n > 0){
        if(n % 10 != quadrado % 10){
            return 0;
        }
        n /= 10;
        quadrado /= 10;
    }
    return 1;
}

//Função que verifica se o número é automorfico dentro de um intervalo utilizando a função anterior
void verificar_numero_automorfico(int inicio, int fim) {
    int count = 0;
    int *automorficos = NULL;

    for (int i = inicio; i <= fim; i++) {
        if (eh_numero_automorfico(i)) {
            automorficos = (int *)realloc(automorficos, (count + 1) * sizeof(int));
            if (automorficos == NULL) {
                printf("Erro de alocação de memória.\n");
                exit(1);
            }
            automorficos[count] = i;
            count++;
        }
    }

    printf("Números automórficos entre %d e %d:\n", inicio, fim);
    for (int i = 0; i < count; i++) {
        printf("%d\n", automorficos[i]);
    }

    free(automorficos);
}