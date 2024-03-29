/*
**    Função : Escrever uma função em C chamada fatorial_duplo que recebe o parâmetro, 'n', e retorna o resultado do fatorial duplo de 'n'. 
**    Em seguida montar uma tabela usando  2 até 20 de forma tabulada, exibindo o resultado do fatorial duplo para cada número. 
**    Seguindo a isso, na mesma tabela mostrar o resultado do fatorial normal. 
**    Em seguida o programa uma nova tabela com uma quarta coluna mostrando a diferença entre o fatorial normal e o fatorial duplo. 
**    Exibir todos os resultados em um arquivo texto. 
**    Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
**    Data  : 23/03/2024
**    Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Prototipos das funções 
double fatorial(int n);
double fatorial_duplo(int n);

//Função main
int main(){
    setlocale(LC_ALL, "portuguese");

    FILE *arquivo;
    arquivo = fopen("resultados_2.txt", "w"); // Abrindo o arquivo para escrita

    if(arquivo == NULL){
        printf("Erro! Arquivo não encontrado.\n"); //Erro caso não exista o arquivo
        return 1;
    }

    double fatoriais[19];  // Array para armazenar fatoriais normais
    double fatoriais_duplos[19];  // Array para armazenar fatoriais duplos
    double diferencas[19];  // Array para armazenar diferenças entre fatoriais normais e duplos

    fprintf(arquivo, "Tabela de Fatoriais\n");
    fprintf(arquivo, "n \t  Fatorial Normal   \t   Fatorial Duplo    \t Diferença  \n");

    for(int n = 2; n <= 20; n++){
        fatoriais[n-2] = fatorial(n);
        fatoriais_duplos[n-2] = fatorial_duplo(n);
        diferencas[n-2] = fatoriais[n-2] - fatoriais_duplos[n-2];

        fprintf(arquivo, "%d       \t %.0lf      \t  \t      %.0lf    \t  \t           %.0lf\n", n, fatoriais[n-2], fatoriais_duplos[n-2], diferencas[n-2]);
    }

    fclose(arquivo); // Fechando o arquivo

    printf("\nResultados salvos em 'resultados.txt'.\n");

    return 0;
}

//Função fatorial
double fatorial(int n){
    double resultado = 1;
    for(int i = 2; i <= n; i++){
        resultado *= i;
    }
    return resultado;
}

//Função fatorial Duplo
double fatorial_duplo(int n){
    double resultado = 1;
    for(int i = n; i > 0; i -= 2){
        resultado *= i;
    }
    return resultado;
}
