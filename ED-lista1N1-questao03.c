/*
**    Função : Escrever  uma função em C que verifica se dois números são amigáveis. Esta função deve exibir na tela os divisores de ambos os números, assim como a soma desses divisores.
**             Além disso, escrever outra função que verifica todos os pares de números amigáveis até um determinado valor `n` que será fornecido pelo usuário.
**    Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
**    Data  : 23/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...
*/

#include <stdio.h>
#include <stdbool.h>

//prototipos das funções
int somaDivisores(int);
void verificaAmigaveis(int);

//Função main
int main(){
    int valor;

    printf("Digite um valor limite para encontrar pares de números amigáveis: ");
    scanf("%d", &valor);

    verificaAmigaveis(valor);

    return 0;
}

//Função que retorna a soma de divisores de cado número do intervalo
int somaDivisores(int n){
    int soma = 1;
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0){
            soma += i;
        }
    }
    return soma;
}

//Função que verifica que os números são amigaveis entre o intervalo fornecido pelo usuário
void verificaAmigaveis(int n){
    for(int a = 2; a <= n; a++){
        int b = somaDivisores(a);
        if(b > a && b <= n && somaDivisores(b) == a){
            printf("Os divisores próprios de %d são: 1", a);
            for(int i = 2; i <= a/2; i++){
                if(a % i == 0){
                    printf(", %d", i);
                }
            }
            printf(". \nA soma desses divisores é %d.\n", b);

            printf("Os divisores próprios de %d são: 1", b);
            for(int i = 2; i <= b/2; i++){
                if(b % i == 0){
                    printf(", %d", i);
                }
            }
            printf(". A soma desses divisores é %d.\n", a);

            printf("Portanto, %d e %d são um par de números amigáveis.\n", a, b);
        }
    }
}