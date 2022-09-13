#include <stdio.h>
#include <string.h>

/* Função que recebe um caracter de um número romano válido e retorna o valor inteiro 
ou então retorna -1 caso tenha sido digitado um dígito inválido */
int digit(char c) {
    int valor;

    switch(c) {
        case 'I': valor = 1; break;
        case 'V': valor = 5; break;
        case 'X': valor = 10; break;
        case 'L': valor = 50; break;
        case 'C': valor = 100; break;
        case 'D': valor = 500; break;
        case 'M': valor = 1000; break;
        case '\0': valor = 0; break;
        default: valor = -1;
    }
    return valor;
}

/* Função que recebe uma string e testa para verificar se é um número romano válido, então
converte para inteiro */
int romanToInt(char s[])
{
    int i = 0, resultado = 0;

    while (s[i]) {
        // Testa e retorna 0 caso um digito inválido tenha sido digitado
        if (digit(s[i]) < 0)
            return 0;

        /* Verifica se ainda há pelo menos 3 dígitos na string e verifica se o número adiante
        duas posições é maior que o número atual e retorna o valor 0 indicando que o número 
        romano é inválido */
        if (strlen(s)-i > 2) {
            if (digit(s[i]) < digit(s[i+2]))
                return 0;
        }

        /* Caso o número digitado seja válido prossegue somando ao resultado os valores dos
        dígitos caso estejam em ordem crescente */
        if (digit(s[i]) >= digit(s[i+1]))
            resultado += digit(s[i]);
        /* Ou então subtrai caso os números estejam em ordem decrescente */
        else {
            resultado += digit(s[i+1]) - digit(s[i]);
            i++;
        }
        i++;
    }
    return resultado;    
}

int main() {
    char s[] = "MCMXCIV";
    printf("%d\n", romanToInt(s));
    return 0;
}
