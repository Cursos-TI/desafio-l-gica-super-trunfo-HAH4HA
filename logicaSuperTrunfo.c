#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular densidade populacional e PIB per capita
void calcularAtributos(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n\n", carta.pibPerCapita);
}

int main() {
    // Cadastro de duas cartas
    struct Carta carta1 = {
        "SP", "C001", "São Paulo", 12300000, 1521.11, 230.0, 15
    };

    struct Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro", 6748000, 1182.30, 140.5, 10
    };

    // Calcula densidade populacional e PIB per capita para ambas
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Exibe as duas cartas
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("Carta 2:\n");
    exibirCarta(carta2);

    // Atributo escolhido para comparação: População
    printf("Comparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    // Comparação utilizando if-else
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}