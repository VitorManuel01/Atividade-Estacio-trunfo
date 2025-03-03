#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    char estado;

    char codigoCarta[5];
    char nomeCidade[50];
    long int populacao;
    float area;
    float pib;
    int nPontosTuristicos;
    float densidade;
    float pib_percapita;

    float superPoder;

} CartaCidade;

void mostrarMenu()
{
    printf("Digite 1 para cadastrar uma carta\nDigite 2 para mostrar cartas \nDigite 3 para sair\n\n\nDigitar: ");
}

void gerarCarta(CartaCidade *cartacidade)
{
    int numeroCarta;
    printf("Digite uma letra de A a H para representar o estado: ");
    scanf(" %c", &cartacidade->estado);
    system("cls");

    printf("Escolha um numéro de 01 a 04: ");
    scanf("%d", &numeroCarta);
    switch (numeroCarta)
    {
    case 1:
        sprintf(cartacidade->codigoCarta, "%c01", cartacidade->estado);
        break;
    case 2:
        sprintf(cartacidade->codigoCarta, "%c02", cartacidade->estado);
        break;
    case 3:
        sprintf(cartacidade->codigoCarta, "%c03", cartacidade->estado);
        break;
    case 4:
        sprintf(cartacidade->codigoCarta, "%c04", cartacidade->estado);
        break;
    }

    printf("Digite a cidade: ");
    scanf(" %49[^\n]", cartacidade->nomeCidade); // Reads up to 49 chars, leaving room for \0
    system("cls");

    printf("Digite a população: ");
    scanf("%ld", &cartacidade->populacao);
    system("cls");

    printf("Digite a área: ");
    scanf("%f", &cartacidade->area);
    system("cls");

    printf("Digite o PIB em milhões: ");
    scanf("%f", &cartacidade->pib);
    system("cls");

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &cartacidade->nPontosTuristicos);
    system("cls");

    printf("Carta gerada com sucesso\n\n\n");
}

float calcularDensidade(CartaCidade *cartacidade)
{

    if (cartacidade->area == 0)
    {
        return 0;
    }

    cartacidade->densidade = cartacidade->populacao / cartacidade->area;

    return cartacidade->densidade;
}

float calcularPIBPercapita(CartaCidade *cartacidade){

    cartacidade->pib_percapita = (cartacidade->pib * 1000) / cartacidade->populacao;
    return cartacidade->pib_percapita;
}

float calcularSuperPoder(CartaCidade *cartacidade){

    cartacidade->superPoder =cartacidade->populacao + cartacidade->area + cartacidade->pib + cartacidade->nPontosTuristicos + cartacidade->densidade + cartacidade->pib_percapita;
    return cartacidade->superPoder;
}

void mostrarCartas(CartaCidade *cartacidade, int qtdCartas)
{

    for (int i = 0; i < qtdCartas; i++)
    {
        printf("\nCarta: %s\n\n", cartacidade[i].codigoCarta);

        printf("Estado: %c\n", cartacidade[i].estado);

        printf("Cidade: %s\n", cartacidade[i].nomeCidade);

        printf("População: %ld\n", cartacidade[i].populacao);

        printf("Área: %.2f km²\n", cartacidade[i].area);

        printf("PIB: R$%.2f\n", cartacidade[i].pib);

        printf("Pontos Turisticos: %d\n", cartacidade[i].nPontosTuristicos);
        
        printf("Densidade Populacional: %.2f hab/km²\n", calcularDensidade(&cartacidade[i]));

        printf("PIB per Capita: R$%.2f\n", calcularPIBPercapita(&cartacidade[i]));

        printf("Super Poder: %.2f\n\n\n", calcularSuperPoder(&cartacidade[i]));
    }

}

void compararCartas(CartaCidade *cartacidade, int qtdCartas) {
    if (qtdCartas <= 0) {
        printf("Nenhuma carta para comparar.\n");
        return;
    }

    printf("Comparação de Cartas");

    int maiorIndicePopulacao = 0;
    for (int i = 1; i < qtdCartas; i++) {
        if (cartacidade[i].populacao > cartacidade[maiorIndicePopulacao].populacao) {
            maiorIndicePopulacao = i;
        }
    }
    printf("População: A Carta %d venceu\n", maiorIndicePopulacao + 1);

    int maiorIndiceArea = 0;
    for (int i = 1; i < qtdCartas; i++) {
        if (cartacidade[i].area > cartacidade[maiorIndiceArea].area) {
            maiorIndiceArea = i;
        }
    }
    printf("Área: A Carta %d venceu\n", maiorIndiceArea + 1);

    int maiorIndicePIB = 0;
    for (int i = 1; i < qtdCartas; i++) {
        if (cartacidade[i].pib > cartacidade[maiorIndicePIB].pib) {
            maiorIndicePIB = i;
        }
    }
    printf("PIB: A Carta %d venceu\n", maiorIndicePIB + 1);

    int maiorIndicePontosTuristicos = 0;
    for (int i = 1; i < qtdCartas; i++) {
        if (cartacidade[i].nPontosTuristicos > cartacidade[maiorIndicePontosTuristicos].nPontosTuristicos) {
            maiorIndicePontosTuristicos = i;
        }
    }
    printf("Pontos Turísticos: A Carta %d venceu\n", maiorIndicePontosTuristicos + 1);

    int maiorIndiceDensidade = 0;
    for (int i = 1; i < qtdCartas; i++) {
        if (cartacidade[i].densidade > cartacidade[maiorIndiceDensidade].densidade) {
            maiorIndiceDensidade = i;
        }
    }
    printf("Densidade Populacional: A Carta %d venceu\n", maiorIndiceDensidade + 1);

    int maiorIndicePibPerCapita = 0;
    for (int i = 1; i < qtdCartas; i++) {
        if (cartacidade[i].pib_percapita > cartacidade[maiorIndicePibPerCapita].pib_percapita) {
            maiorIndicePibPerCapita = i;
        }
    }
    printf("PIB per Capita: A Carta %d venceu\n", maiorIndicePibPerCapita + 1);

    int maiorIndiceSuperPoder = 0;
    for (int i = 1; i < qtdCartas; i++) {
        if (cartacidade[i].superPoder > cartacidade[maiorIndiceSuperPoder].superPoder) {
            maiorIndiceSuperPoder = i;
        }
    }
    printf("Super Poder: A Carta %d venceu\n\n\n", maiorIndiceSuperPoder + 1);
}

int main()
{
    system("cls");
    setlocale(LC_ALL, "portuguese_brazil");

    CartaCidade cartacidade[5];

    int qtdcartas = 0;

    int opcao;
    do
    {
        mostrarMenu();
        if (scanf("%d", &opcao) != 1)
        { // Verifica entrada inválida
            printf("Entrada inválida!\n");
            while (getchar() != '\n')
                ; // Limpa buffer de entrada
            continue;
        }

        switch (opcao)
        {
        case 1:
            if (qtdcartas < 3 )
            { // Evita ultrapassar o tamanho do array
                system("cls");
                gerarCarta(&cartacidade[qtdcartas]);
                qtdcartas++;
            }
            else
            {
                printf("Número máximo de cartas atingido!\n");
            }
            break;

        case 2:
            system("cls");
            if (qtdcartas > 0)
            {
                system("cls");
                mostrarCartas(cartacidade, qtdcartas);
                compararCartas(cartacidade,qtdcartas);
            }
            else
            {
                printf("\nNão há cartas\n\n");
            }
            break;

        case 3:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n\n");
            while (getchar() != '\n')
                ; // Espera o usuário ler a mensagem
            break;
        }

    } while (opcao != 3);

    return 0;
}