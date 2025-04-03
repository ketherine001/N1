#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    int numerador;
    int denominador;
} Fracao;

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fracao simplificar(Fracao f) {
    int divisor = mdc(f.numerador, f.denominador);
    f.numerador /= divisor;
    f.denominador /= divisor;
    return f;
}

Fracao somar(Fracao f1, Fracao f2) {
    Fracao resultado;
    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return simplificar(resultado);
}
Fracao subtrair(Fracao f1, Fracao f2) {
    Fracao resultado;
    resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return simplificar(resultado);
}
Fracao multiplicar(Fracao f1, Fracao f2) {
    Fracao resultado;
    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;
    return simplificar(resultado);
}
Fracao dividir(Fracao f1, Fracao f2) {
    Fracao resultado;
    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f1.denominador * f2.numerador;
    return simplificar(resultado);
}
void exibirFracao(Fracao f) {
    printf("%d/%d\n", f.numerador, f.denominador);
}
int main() {
    Fracao f1, f2, resultado;
    char operador;
    printf("Digite a primeira fração (numerador denominador): ");
    scanf("%d %d", &f1.numerador, &f1.denominador);
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operador);
    printf("Digite a segunda fração (numerador denominador): ");
    scanf("%d %d", &f2.numerador, &f2.denominador);
    switch (operador) {
        case '+':
            resultado = somar(f1, f2);
            break;
        case '-':
            resultado = subtrair(f1, f2);
            break;
        case '*':
            resultado = multiplicar(f1, f2);
            break;
        case '/':
            if (f2.numerador == 0) {
                printf("Erro: divisão por zero!\n");
                return 1;
            }
            resultado = dividir(f1, f2);
            break;
        default:
            printf("Operador inválido!\n");
            return 1;
    }
    printf("Resultado: ");
    exibirFracao(resultado);
    getch();
    return 0;
}
