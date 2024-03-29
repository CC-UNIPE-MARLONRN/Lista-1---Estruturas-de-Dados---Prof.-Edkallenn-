/*
**    Função : Escrever uma função em C chamada 'potencia_fatorial_crescente' que recebe dois parâmetros, 'x' e 'n', que retorna o resultado da potência fatorial crescente de 'x' elevado a 'n'.
**             Após o procedimento, escrever outra função chamada potencia_fatorial_decrescente que realiza o mesmo cálculo, mas para a potência fatorial decrescente. 
**             Em seguida, montar uma tabela usando um 'x' fixo e variando o 'n' de 2 até 10 executando ambas as operações. 
**             Logo após, fazer o 'x' variar de 2 até 10. E exibir todos os resultados em um arquivo de texto. 
**    Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
**    Data  : 23/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...
                   Havia a necessidade de parar no momento que o valor 'n' na função decrescente chegasse a um inferior igual ou inferior zero, porque sempre o produto seria multiplicado por zero, então tomei a ideia de colocar um valor fixo para que ao multiplicar o fatoriais por valores negativos ele não se tornasse negativo, como estava dando, por conta da saída de dados, por isso colocando o valor igual a zero, caso o n fosse 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Prototipos das Funções
double potencia_fatorial_crescente(int, int);
double potencia_fatorial_decrescente(int, int);

//Função main
int main(){
    setlocale(LC_ALL, "portuguese");

    FILE *arquivo;
    arquivo = fopen("resultados_1.txt", "w"); // Abrindo o arquivo para escrita

    if(arquivo == NULL){
        printf("Erro! Arquivo não encontrado.\n"); //Erro caso não exista o arquivo
        return 1;
    }

    // Tabela com x fixo e n variando de 2 até 10
    
    int x = 3; //valor fixo = 3 para x

    fprintf(arquivo, "Tabela para x = %d:\n", x);
    fprintf(arquivo, "n \t  Potência Fatorial Crescente   \t   Potência Fatorial Decrescente\n");
    for (int n = 2; n <= 10; n++) {
        fprintf(arquivo, "%d           \t    %.0lf        \t   \t  \t  \t    %.0lf   \n", n, potencia_fatorial_crescente(x, n), potencia_fatorial_decrescente(x, n));
    }

     fprintf(arquivo, "n \t  ------------------------------------------------------------------------\n");

    // Tabela com x variando de 2 até 10
    for (x = 2; x <= 10; x++) {
        fprintf(arquivo, "\nTabela para x = %d:\n", x);
        fprintf(arquivo, "n \t  Potência Fatorial Crescente   \t   Potência Fatorial Decrescente\n");
        for (int n = 2; n <= 10; n++) {
            fprintf(arquivo, "%d           \t    %.0lf        \t   \t  \t  \t    %.0lf   \n", n, potencia_fatorial_crescente(x, n), potencia_fatorial_decrescente(x, n));
        }
    }

    fclose(arquivo); 

    printf("Resultados salvos em 'resultados.txt'.\n");

    return 0;
}

//Função potencia_fatorial_crescente
double potencia_fatorial_crescente(int x, int n){
    double resultado = x;
    for (int i = 1; i < n; i++) {
        resultado *= (x + i);
    }
    return resultado;
}

//Função potencia_fatorial_decrescente
double potencia_fatorial_decrescente(int x, int n){
   double resultado = x;
    for (int i = 1; i < n; i++) {
        resultado *= (x - i);
    }

    if (resultado <= 0) {
        return 0.0;  
    } else {
        return resultado;
    }
}