#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo (país)
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para calcular densidade demográfica (população / área)
void calcularDensidade(struct Carta *carta) {
    carta->densidadeDemografica = carta->populacao / carta->area;
}

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta) {
    printf("País: %s\n", carta.nomePais);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n\n", carta.densidadeDemografica);
}

int main() {
    // Cartas cadastradas (exemplo com Brasil e Argentina)
    struct Carta carta1 = {"Brasil", 215000000, 8515767.0, 1868.0, 25, 0};
    struct Carta carta2 = {"Argentina", 45380000, 2780400.0, 640.0, 15, 0};

    // Calcula densidade para ambas
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int opcao;

    // Exibir as cartas
    printf("===== CARTA 1 =====\n");
    exibirCarta(carta1);
    printf("===== CARTA 2 =====\n");
    exibirCarta(carta2);

    // Menu de atributos
    printf("===== MENU DE COMPARAÇÃO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);

    // Switch com lógica de comparação
    switch(opcao) {
        case 1: // População
            printf("\nComparação: População\n");
            printf("%s: %d habitantes\n", carta1.nomePais, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nomePais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("\nComparação: Área\n");
            printf("%s: %.2f km²\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomePais, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("\nComparação: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.nomePais, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nomePais, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("\nComparação: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomePais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade demográfica (menor vence!)
            printf("\nComparação: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("\nOpção inválida! Por favor, selecione uma opção de 1 a 5.\n");
            break;
    }

    return 0;
}
