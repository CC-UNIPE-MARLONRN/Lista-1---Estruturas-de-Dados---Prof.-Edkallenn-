/*
**    Função :Escrever uma função em C chamada 'soma_fatoriais_inversos' que recebe um número inteiro positivo 'n' como entrada e retorna a soma dos fatoriais inversos dos números de '1 a n' como um par de números inteiros representando o numerador e denominador.
**    Autor : Marlon Rufino do Nascimento 2º período turma A 2024.1
**    Data  : 23/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da língua portuguesa, tais como ´, ^, `, ª ...
**                 No exemplo fornecido eu verifiquei um erro que pensava ser erro do programa quando na verdade era do exercício, no exemplo dado para a entrada de dados 'n = 3', o resultado, segundo o enunciado do trabalho, é 11/6, sendo que ao fazer o calculo de 1 + 1/2 + 1/6, o MMC é o próprio 6, deixando-o como denominador, e o númerador nada mais é que a soma de 6 + 3 + 1 = 10, deixando o resultado na verdade igual a 10/6 a entrada descrita.
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//Prototipo da função
void soma_fatoriais_inversos(int);

//Função main
int main(){
    setlocale(LC_ALL, "portuguese");

    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    soma_fatoriais_inversos(n);

    return 0;

}

//Função void que resulta na soma dos fatoriais reversos deixando apenas o numerador e o denominador como o exemplo fornecido
void soma_fatoriais_inversos(int n){
    int numerador = 1;
    int denominador = 1;
    for(int i = 2; i <= n; i++){
        denominador *= i;
        numerador = numerador * i + 1;
    }
    printf("Soma dos fatoriais inversos é: %d/%d", numerador, denominador);
}
