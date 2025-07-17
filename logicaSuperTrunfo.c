#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para calcular densidade demográfica
void calcularDensidade(struct Carta *carta) {
    carta->densidadeDemografica = carta->populacao / carta->area;
}

// Função para exibir menu de atributos
void exibirMenu(int atributosUsados[6]) {
    printf("Escolha um atributo para comparar:\n");
    if (!atributosUsados[1]) printf("1 - População\n");
    if (!atributosUsados[2]) printf("2 - Área\n");
    if (!atributosUsados[3]) printf("3 - PIB\n");
    if (!atributosUsados[4]) printf("4 - Pontos Turísticos\n");
    if (!atributosUsados[5]) printf("5 - Densidade Demográfica\n");
}

// Função para obter valor do atributo selecionado
float obterValor(struct Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return 0;
    }
}

// Função para exibir nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1 = {"Brasil", 215000000, 8515767.0, 1868.0, 25, 0};
    struct Carta carta2 = {"Argentina", 45380000, 2780400.0, 640.0, 15, 0};
    
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int atributo1 = 0, atributo2 = 0;
    int atributosUsados[6] = {0}; // índice 1 a 5 marca se o atributo foi escolhido

    printf("===== Super Trunfo: Comparação entre Países =====\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n\n", carta2.nomePais);

    // Escolha do primeiro atributo
    do {
        exibirMenu(atributosUsados);
        printf("Escolha o PRIMEIRO atributo (1 a 5): ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5 || atributosUsados[atributo1]) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 5 || atributosUsados[atributo1]);
    atributosUsados[atributo1] = 1;

    // Escolha do segundo atributo
    do {
        exibirMenu(atributosUsados);
        printf("Escolha o SEGUNDO atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributosUsados[atributo2]) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 5 || atributosUsados[atributo2]);

    // Obter valores dos atributos
    float valor1_attr1 = obterValor(carta1, atributo1);
    float valor2_attr1 = obterValor(carta2, atributo1);
    float valor1_attr2 = obterValor(carta1, atributo2);
    float valor2_attr2 = obterValor(carta2, atributo2);

    // Regras de comparação (menor vence apenas em densidade demográfica)
    int carta1_vencedora_attr1 = (atributo1 == 5) ? (valor1_attr1 < valor2_attr1) : (valor1_attr1 > valor2_attr1);
    int carta1_vencedora_attr2 = (atributo2 == 5) ? (valor1_attr2 < valor2_attr2) : (valor1_attr2 > valor2_attr2);

    // Soma dos atributos
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Resultado final com ternário
    const char* resultadoFinal = (soma1 > soma2) ? carta1.nomePais :
                                 (soma2 > soma1) ? carta2.nomePais : "Empate!";

    // Exibir resultado
    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf(" - %s: %.2f\n", carta1.nomePais, valor1_attr1);
    printf(" - %s: %.2f\n", carta2.nomePais, valor2_attr1);

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf(" - %s: %.2f\n", carta1.nomePais, valor1_attr2);
    printf(" - %s: %.2f\n", carta2.nomePais, valor2_attr2);

    printf("\nSoma dos atributos:\n");
    printf(" - %s: %.2f\n", carta1.nomePais, soma1);
    printf(" - %s: %.2f\n", carta2.nomePais, soma2);

    printf("\nResultado Final: %s\n", resultadoFinal);

    return 01;
}
