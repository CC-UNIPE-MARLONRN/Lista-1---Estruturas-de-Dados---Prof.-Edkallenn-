/*
**    Função : Escrever uma função em C chamada 'eh_numero_perfeito' que recebe um número inteiro positivo n como entrada e retorna verdadeiro se n for um número perfeito, e falso caso contrário. 
**             Usando esta  função, exiba todos os números perfeitos entre 1 e 100000.
**    Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
**    Data  : 24/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...
*/

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

//Protótipo da função
bool eh_numero_perfeito(int);

//Função main
int main(){
    locale(LC_ALL, "portuguese");

int inicio = 1;
int fim = 100000;

printf("Números perfeitos entre %d e %d: \n", inicio, fim);
   for(int i = inicio; i <= fim; i++){
    if (eh_numero_perfeito(i)) {
            printf("%d\n", i);
        }
   }

 return 0;
}

bool eh_numero_perfeito(int n){
    int soma = 0;

    for(int i = 1; i < n; i++){
        if(n % i == 0){
            soma += i;
        }
    }
    if(soma == n){
      return true;
    }
    else{
        return false;
    }
}