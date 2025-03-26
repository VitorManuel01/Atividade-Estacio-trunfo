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
    printf("Digite 1 para cadastrar uma carta\nDigite 2 para mostrar cartas\nDigite 3 para comparar individualmente\nDigite 4 para sair\n\n\nDigitar: ");
}

void gerarCarta(CartaCidade *cartacidade)
{
    int numeroCarta;
    printf("Digite uma letra de A a H para representar o estado: ");
    scanf(" %c", &cartacidade->estado);
    system("cls");

    printf("Escolha um número de 01 a 04: ");
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
    scanf(" %49[^\n]", cartacidade->nomeCidade);
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

float calcularPIBPercapita(CartaCidade *cartacidade)
{
    cartacidade->pib_percapita = (cartacidade->pib * 1000) / cartacidade->populacao;
    return cartacidade->pib_percapita;
}

float calcularSuperPoder(CartaCidade *cartacidade)
{
    cartacidade->superPoder = cartacidade->populacao + cartacidade->area + cartacidade->pib + cartacidade->nPontosTuristicos + cartacidade->densidade + cartacidade->pib_percapita;
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
        printf("Pontos Turísticos: %d\n", cartacidade[i].nPontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", calcularDensidade(&cartacidade[i]));
        printf("PIB per Capita: R$%.2f\n", calcularPIBPercapita(&cartacidade[i]));
        printf("Super Poder: %.2f\n\n\n", calcularSuperPoder(&cartacidade[i]));
    }
}

void compararCartas(CartaCidade *cartacidade, int qtdCartas)
{
    if (qtdCartas <= 0)
    {
        printf("Nenhuma carta para comparar.\n");
        return;
    }

    printf("Comparação de Cartas\n");

    int maiorIndicePopulacao = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].populacao > cartacidade[maiorIndicePopulacao].populacao)
        {
            maiorIndicePopulacao = i;
        }
    }
    printf("População: A Carta %d venceu\n", maiorIndicePopulacao + 1);

    int maiorIndiceArea = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].area > cartacidade[maiorIndiceArea].area)
        {
            maiorIndiceArea = i;
        }
    }
    printf("Área: A Carta %d venceu\n", maiorIndiceArea + 1);

    int maiorIndicePIB = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].pib > cartacidade[maiorIndicePIB].pib)
        {
            maiorIndicePIB = i;
        }
    }
    printf("PIB: A Carta %d venceu\n", maiorIndicePIB + 1);

    int maiorIndicePontosTuristicos = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].nPontosTuristicos > cartacidade[maiorIndicePontosTuristicos].nPontosTuristicos)
        {
            maiorIndicePontosTuristicos = i;
        }
    }
    printf("Pontos Turísticos: A Carta %d venceu\n", maiorIndicePontosTuristicos + 1);

    int menorIndiceDensidade = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        calcularDensidade(&cartacidade[i]);
        if (cartacidade[i].densidade < cartacidade[menorIndiceDensidade].densidade)
        {
            menorIndiceDensidade = i;
        }
    }
    printf("Densidade Populacional: A Carta %d venceu\n", menorIndiceDensidade + 1);

    int maiorIndicePibPerCapita = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        calcularPIBPercapita(&cartacidade[i]);
        if (cartacidade[i].pib_percapita > cartacidade[maiorIndicePibPerCapita].pib_percapita)
        {
            maiorIndicePibPerCapita = i;
        }
    }
    printf("PIB per Capita: A Carta %d venceu\n", maiorIndicePibPerCapita + 1);

    int maiorIndiceSuperPoder = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        calcularSuperPoder(&cartacidade[i]);
        if (cartacidade[i].superPoder > cartacidade[maiorIndiceSuperPoder].superPoder)
        {
            maiorIndiceSuperPoder = i;
        }
    }
    printf("Super Poder: A Carta %d venceu\n\n\n", maiorIndiceSuperPoder + 1);
}

void compararPopulacao(CartaCidade *cartacidade, int qtdCartas)
{
    if (qtdCartas <= 0)
    {
        printf("Nenhuma carta para comparar.\n");
        return;
    }

    printf("\nComparação de População\n");
    for (int i = 0; i < qtdCartas; i++)
    {
        printf("Carta %d (%s - %s): %ld habitantes\n", 
               i + 1, cartacidade[i].codigoCarta, cartacidade[i].nomeCidade, cartacidade[i].populacao);
    }

    int maiorIndicePopulacao = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].populacao > cartacidade[maiorIndicePopulacao].populacao)
        {
            maiorIndicePopulacao = i;
        }
    }
    printf("Resultado: A Carta %d venceu!\n\n", maiorIndicePopulacao + 1);
}

void compararArea(CartaCidade *cartacidade, int qtdCartas)
{
    if (qtdCartas <= 0)
    {
        printf("Nenhuma carta para comparar.\n");
        return;
    }

    printf("\nComparação de Área\n");
    for (int i = 0; i < qtdCartas; i++)
    {
        printf("Carta %d (%s - %s): %.2f km²\n", 
               i + 1, cartacidade[i].codigoCarta, cartacidade[i].nomeCidade, cartacidade[i].area);
    }

    int maiorIndiceArea = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].area > cartacidade[maiorIndiceArea].area)
        {
            maiorIndiceArea = i;
        }
    }
    printf("Resultado: A Carta %d venceu!\n\n", maiorIndiceArea + 1);
}

void compararPIB(CartaCidade *cartacidade, int qtdCartas)
{
    if (qtdCartas <= 0)
    {
        printf("Nenhuma carta para comparar.\n");
        return;
    }

    printf("\nComparação de PIB\n");
    for (int i = 0; i < qtdCartas; i++)
    {
        printf("Carta %d (%s - %s): R$%.2f milhões\n", 
               i + 1, cartacidade[i].codigoCarta, cartacidade[i].nomeCidade, cartacidade[i].pib);
    }

    int maiorIndicePIB = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].pib > cartacidade[maiorIndicePIB].pib)
        {
            maiorIndicePIB = i;
        }
    }
    printf("Resultado: A Carta %d venceu!\n\n", maiorIndicePIB + 1);
}

void compararDensidade(CartaCidade *cartacidade, int qtdCartas)
{
    if (qtdCartas <= 0)
    {
        printf("Nenhuma carta para comparar.\n");
        return;
    }

    printf("\nComparação de Densidade Populacional\n");
    for (int i = 0; i < qtdCartas; i++)
    {
        calcularDensidade(&cartacidade[i]);
        printf("Carta %d (%s - %s): %.2f hab/km²\n", 
               i + 1, cartacidade[i].codigoCarta, cartacidade[i].nomeCidade, cartacidade[i].densidade);
    }

    int menorIndiceDensidade = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].densidade < cartacidade[menorIndiceDensidade].densidade)
        {
            menorIndiceDensidade = i;
        }
    }
    printf("Resultado: A Carta %d venceu!\n\n", menorIndiceDensidade + 1);
}

void compararPIBPerCapita(CartaCidade *cartacidade, int qtdCartas)
{
    if (qtdCartas <= 0)
    {
        printf("Nenhuma carta para comparar.\n");
        return;
    }

    printf("\nComparação de PIB per Capita\n");
    for (int i = 0; i < qtdCartas; i++)
    {
        calcularPIBPercapita(&cartacidade[i]);
        printf("Carta %d (%s - %s): R$%.2f\n", 
               i + 1, cartacidade[i].codigoCarta, cartacidade[i].nomeCidade, cartacidade[i].pib_percapita);
    }

    int maiorIndicePibPerCapita = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].pib_percapita > cartacidade[maiorIndicePibPerCapita].pib_percapita)
        {
            maiorIndicePibPerCapita = i;
        }
    }
    printf("Resultado: A Carta %d venceu!\n\n", maiorIndicePibPerCapita + 1);
}

void menuCompararIndividualmente(CartaCidade *cartacidade, int qtdCartas)
{
    int opc;
    system("cls");
    printf("=== Comparação Individual ===\n");
    printf("1. Comparar População\n");
    printf("2. Comparar Área\n");
    printf("3. Comparar PIB\n");
    printf("4. Comparar Densidade Populacional\n");
    printf("5. Comparar PIB per Capita\n");
    printf("Digite a opção: ");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        compararPopulacao(cartacidade, qtdCartas);
        break;
    case 2:
        compararArea(cartacidade, qtdCartas);
        break;
    case 3:
        compararPIB(cartacidade, qtdCartas);
        break;
    case 4:
        compararDensidade(cartacidade, qtdCartas);
        break;
    case 5:
        compararPIBPerCapita(cartacidade, qtdCartas);
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
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
        {
            printf("Entrada inválida!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao)
        {
        case 1:
            if (qtdcartas < 5)
            {
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
                mostrarCartas(cartacidade, qtdcartas);
                compararCartas(cartacidade, qtdcartas);
            }
            else
            {
                printf("\nNão há cartas\n\n");
            }
            break;

        case 3:
            menuCompararIndividualmente(cartacidade, qtdcartas);
            break;

        case 4:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n\n");
            while (getchar() != '\n');
            break;
        }
    } while (opcao != 4);

    return 0;
}