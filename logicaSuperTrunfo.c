#include <stdio.h>

int main() {
    // Declaração de variáveis
    short int pontosturisticos1, pontosturisticos2;
    long unsigned int populacao1, populacao2;
    float pib1, pib2, area1, area2;
    char codigo1[4], codigo2[4], cidade1[50], cidade2[50], estado1, estado2;
    float densidade1, densidade2, pibcapita1, pibcapita2;
    float superpoder1, superpoder2;
    short int pontuacao1, pontuacao2;
    short int opcao = 0;

    // Entrada de dados da primeira carta
    printf("Vamos começar com o registro da primeira carta!\n");

    printf("Insira o estado (A-H) da primeira carta: ");
    scanf(" %c", &estado1);

    printf("Insira o código de identificação dessa carta: ");
    scanf("%s", codigo1);

    printf("De qual cidade estamos falando?: ");
    getchar();
    scanf("%[^\n]", cidade1);

    printf("População de %s: ", cidade1);
    scanf("%lu", &populacao1);

    printf("Área em km²: ");
    scanf("%f", &area1);

    printf("PIB em bilhões: ");
    scanf("%f", &pib1);

    printf("Quantidade de pontos turísticos: ");
    scanf("%hd", &pontosturisticos1);

    // Entrada de dados da segunda carta
    printf("\nAgora, vamos registrar a segunda carta!\n");

    printf("Insira o estado (A-H) da segunda carta: ");
    scanf(" %c", &estado2);

    printf("Insira o código de identificação dessa carta: ");
    scanf("%s", codigo2);

    printf("De qual cidade estamos falando?: ");
    getchar();
    scanf("%[^\n]", cidade2);

    printf("População de %s: ", cidade2);
    scanf("%lu", &populacao2);

    printf("Área em km²: ");
    scanf("%f", &area2);

    printf("PIB em bilhões: ");
    scanf("%f", &pib2);

    printf("Quantidade de pontos turísticos: ");
    scanf("%hd", &pontosturisticos2);

    // Cálculo dos atributos derivados
    densidade1 = (float) populacao1 / area1;
    densidade2 = (float) populacao2 / area2;

    pibcapita1 = (pib1 * 1000000000) / populacao1;
    pibcapita2 = (pib2 * 1000000000) / populacao2;

    superpoder1 = (float) populacao1 + area1 + pib1 + (float) pontosturisticos1 + pibcapita1 + (area1 / (float) populacao1);
    superpoder2 = (float) populacao2 + area2 + pib2 + (float) pontosturisticos2 + pibcapita2 + (area2 / (float) populacao2);

    // Loop de comparação
    do {
        printf("\n--- PRIMEIRA CARTA ---\n");
        printf("Estado: %c | Código: %s | Cidade: %s\n", estado1, codigo1, cidade1);

        printf("--- SEGUNDA CARTA ---\n");
        printf("Estado: %c | Código: %s | Cidade: %s\n", estado2, codigo2, cidade2);

        printf("\n--- MENU DE COMPARAÇÃO ---\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Demográfica\n");
        printf("6. PIB Per Capita\n");
        printf("7. Super Poder\n");
        printf("8. Desafio Final (Comparar Tudo)\n");
        printf("0. Encerrar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("\nEncerrando o programa...\n");
                return 0;

            case 1:
                printf("\nPopulação: %s (%lu) vs %s (%lu)\n", cidade1, populacao1, cidade2, populacao2);
                if (populacao1 == populacao2) printf("Empate!\n");
                else if (populacao1 > populacao2) printf("%s venceu!\n", cidade1);
                else printf("%s venceu!\n", cidade2);
                break;

            case 2:
                printf("\nÁrea: %s (%.2f km²) vs %s (%.2f km²)\n", cidade1, area1, cidade2, area2);
                if (area1 == area2) printf("Empate!\n");
                else if (area1 > area2) printf("%s venceu!\n", cidade1);
                else printf("%s venceu!\n", cidade2);
                break;

            case 3:
                printf("\nPIB: %s (%.2f bilhões) vs %s (%.2f bilhões)\n", cidade1, pib1, cidade2, pib2);
                if (pib1 == pib2) printf("Empate!\n");
                else if (pib1 > pib2) printf("%s venceu!\n", cidade1);
                else printf("%s venceu!\n", cidade2);
                break;

            case 4:
                printf("\nPontos Turísticos: %s (%hd) vs %s (%hd)\n", cidade1, pontosturisticos1, cidade2, pontosturisticos2);
                if (pontosturisticos1 == pontosturisticos2) printf("Empate!\n");
                else if (pontosturisticos1 > pontosturisticos2) printf("%s venceu!\n", cidade1);
                else printf("%s venceu!\n", cidade2);
                break;

            case 5:
                printf("\nDensidade Demográfica: %s (%.2f hab/km²) vs %s (%.2f hab/km²)\n", cidade1, densidade1, cidade2, densidade2);
                if (densidade1 == densidade2) printf("Empate!\n");
                else if (densidade1 < densidade2) printf("%s venceu! (Menor densidade)\n", cidade1);
                else printf("%s venceu! (Menor densidade)\n", cidade2);
                break;

            case 6:
                printf("\nPIB Per Capita: %s (R$%.2f) vs %s (R$%.2f)\n", cidade1, pibcapita1, cidade2, pibcapita2);
                if (pibcapita1 == pibcapita2) printf("Empate!\n");
                else if (pibcapita1 > pibcapita2) printf("%s venceu!\n", cidade1);
                else printf("%s venceu!\n", cidade2);
                break;

            case 7:
                printf("\nSuper Poder: %s (%.4f) vs %s (%.4f)\n", cidade1, superpoder1, cidade2, superpoder2);
                if (superpoder1 == superpoder2) printf("Empate!\n");
                else if (superpoder1 > superpoder2) printf("%s venceu!\n", cidade1);
                else printf("%s venceu!\n", cidade2);
                break;

            case 8:
                pontuacao1 = 0;
                pontuacao2 = 0;

                // Comparações
                pontuacao1 += (populacao1 > populacao2);
                pontuacao2 += (populacao2 > populacao1);

                pontuacao1 += (area1 > area2);
                pontuacao2 += (area2 > area1);

                pontuacao1 += (pib1 > pib2);
                pontuacao2 += (pib2 > pib1);

                pontuacao1 += (pontosturisticos1 > pontosturisticos2);
                pontuacao2 += (pontosturisticos2 > pontosturisticos1);

                pontuacao1 += (densidade1 < densidade2);
                pontuacao2 += (densidade2 < densidade1);

                pontuacao1 += (pibcapita1 > pibcapita2);
                pontuacao2 += (pibcapita2 > pibcapita1);

                pontuacao1 += (superpoder1 > superpoder2);
                pontuacao2 += (superpoder2 > superpoder1);

                // Resultado
                printf("\nPlacar Final: %s (%hd) vs %s (%hd)\n", cidade1, pontuacao1, cidade2, pontuacao2);
                if (pontuacao1 == pontuacao2) {
                    printf("Empate geral!\n");
                } else if (pontuacao1 > pontuacao2) {
                    printf("%s venceu com mais atributos!\n", cidade1);
                } else {
                    printf("%s venceu com mais atributos!\n", cidade2);
                }
                break;

            default:
                printf("\nOpção inválida, tente novamente...\n");
        }

    } while (opcao != 0);

    return 0;
}