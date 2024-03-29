/*
**    Função : Escrever uma função em C chamada 'verificar_numero_carmichael' que verifica se um dado número inteiro n é um número de Carmichael ou não. 
**             Em seguida exibir todos os números de Carmichael de 2 até o número n digitado pelo usuário.
**    Autor : Marlon Rufino do Nascimento 2º período turma A 2024.1
**    Data  : 23/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da língua portuguesa, tais como ´, ^, `, ª ...
*/

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

//Prototipos
bool eh_primo(int);
int mod(int,int);
void numeros_carmichael(int num);
 
 //Função main
int main() {
   int n;

   printf("Digite o valor de n que deseja: ");
   scanf("%d", &n);


    for (int p = 2; p <= n; ++p) {
        if (eh_primo(p))
         numeros_carmichael(p);
    }
    return 0;
}

//verifica se um número é primo:
 bool eh_primo(int n) {
    if (n < 2)
        return false;
    if (n % 2 == 0)
        return n == 2;
    if (n % 3 == 0)
        return n == 3;
    for (int p = 5; p * p <= n; p += 4) {
        if (n % p == 0)
            return false;
        p += 2;
        if (n % p == 0)
            return false;
    }
    return true;
}

 // Função auxiliar para calcular o módulo de forma eficiente
int mod(int n, int d) {
    return (d + n % d) % d;
}

// Função que lista todos os números de Carmichael até o parametro
void numeros_carmichael(int num) {
    for (int i = 1; i < num; ++i) {
        for (int d = 1; d < i + num; ++d) {
            if (mod((i + num) * (num - 1), d) != 0
                || mod(-num * num, i) != mod(d, i))
                continue;
            int num2 = 1 + (num - 1) * (i + num) / d;
            if (!eh_primo(num2))
                continue;
            int num3 = 1 + num * num2 / i;
            if (!eh_primo(num3))
                continue;
            if (mod(num2 * num3, num - 1) != 1)
                continue;
            unsigned int carmichael = num * num2 * num3;
            printf("%2d x %4d x %5d = %10u\n", num, num2, num3, carmichael);
        }
    }
}
