#include <stdio.h>
#include <math.h>

#define MAX 100

// Estrutura para representar um polinômio
typedef struct {
    int grau;
    float coef[MAX];
} Polinomio;

// Função para ler um polinômio
Polinomio lerPolinomio() {
    Polinomio p;
    printf("Digite o grau do polinômio: ");
    scanf("%d", &p.grau);
    
    for (int i = p.grau; i >= 0; i--) {
        printf("Digite o coeficiente de x^%d: ", i);
        scanf("%f", &p.coef[i]);
    }
    
    return p;
}

// Função para exibir um polinômio
void exibirPolinomio(Polinomio p) {
    for (int i = p.grau; i >= 0; i--) {
        if (p.coef[i] != 0) {
            if (i != p.grau && p.coef[i] > 0) {
                printf("+");
            }
            printf("%.1fx^%d ", p.coef[i], i);
        }
    }
    printf("\n");
}

// Função para adicionar dois polinômios
Polinomio adicionar(Polinomio p1, Polinomio p2) {
    Polinomio resultado;
    resultado.grau = (p1.grau > p2.grau) ? p1.grau : p2.grau;
    
    for (int i = 0; i <= resultado.grau; i++) {
        resultado.coef[i] = p1.coef[i] + p2.coef[i];
    }
    
    return resultado;
}

// Função para subtrair dois polinômios
Polinomio subtrair(Polinomio p1, Polinomio p2) {
    Polinomio resultado;
    resultado.grau = (p1.grau > p2.grau) ? p1.grau : p2.grau;
    
    for (int i = 0; i <= resultado.grau; i++) {
        resultado.coef[i] = p1.coef[i] - p2.coef[i];
    }
    
    return resultado;
}

// Função para multiplicar dois polinômios
Polinomio multiplicar(Polinomio p1, Polinomio p2) {
    Polinomio resultado;
    resultado.grau = p1.grau + p2.grau;
    
    for (int i = 0; i <= resultado.grau; i++) {
        resultado.coef[i] = 0;
    }
    
    for (int i = 0; i <= p1.grau; i++) {
        for (int j = 0; j <= p2.grau; j++) {
            resultado.coef[i + j] += p1.coef[i] * p2.coef[j];
        }
    }
    
    return resultado;
}

// Função para avaliar um polinômio em um dado valor de x
float avaliar(Polinomio p, float x) {
    float resultado = 0;
    
    for (int i = 0; i <= p.grau; i++) {
        resultado += p.coef[i] * pow(x, i);
    }
    
    return resultado;
}

int main() {
    Polinomio p1, p2, resultado;
    int opcao;
    float x;
    
    printf("Calculadora de Polinômios\n");
    printf("1. Adicionar polinômios\n");
    printf("2. Subtrair polinômios\n");
    printf("3. Multiplicar polinômios\n");
    printf("4. Avaliar polinômio\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1:
            printf("Polinômio 1:\n");
            p1 = lerPolinomio();
            printf("Polinômio 2:\n");
            p2 = lerPolinomio();
            resultado = adicionar(p1, p2);
            printf("Resultado: ");
            exibirPolinomio(resultado);
            break;
            
        case 2:
            printf("Polinômio 1:\n");
            p1 = lerPolinomio();
            printf("Polinômio 2:\n");
            p2 = lerPolinomio();
            resultado = subtrair(p1, p2);
            printf("Resultado: ");
            exibirPolinomio(resultado);
            break;
            
        case 3:
            printf("Polinômio 1:\n");
            p1 = lerPolinomio();
            printf("Polinômio 2:\n");
            p2 = lerPolinomio();
            resultado = multiplicar(p1, p2);
            printf("Resultado: ");
            exibirPolinomio(resultado);
            break;
            
        case 4:
            printf("Polinômio:\n");
            p1 = lerPolinomio();
            printf("Digite o valor de x: ");
            scanf("%f", &x);
            printf("Resultado: %.2f\n", avaliar(p1, x));
            break;
            
        default:
            printf("Opção inválida!\n");
    }
    
    return 0;
}
