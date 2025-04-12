#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct // Definindo a estrutura da carta
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

void mostrarMenu() // Função para exibir o menu principal
{
    system("cls");
    printf("=== Menu Principal ===\n\n");
    printf("1. Cadastrar Carta\n");
    printf("2. Mostrar Cartas\n");
    printf("3. Comparar Individualmente\n");
    printf("4. Comparar Múltiplos Atributos\n");
    printf("5. Sair\n\n");
    printf("Escolha uma opção: ");
}

void gerarCarta(CartaCidade *cartacidade) // Função para gerar uma nova carta
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
        sprintf(cartacidade->codigoCarta, "%c01", cartacidade->estado); // Formata o código da carta com o estado e o número
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
    scanf(" %49[^\n]", cartacidade->nomeCidade); // Lê até 49 caracteres e ignora o '\n'
    system("cls");

    printf("Digite a população: ");
    scanf("%ld", &cartacidade->populacao); // Lê a população como um número inteiro longo
    system("cls");

    printf("Digite a área: ");
    scanf("%f", &cartacidade->area); // Lê a área como um número de ponto flutuante
    system("cls");

    printf("Digite o PIB em milhões: ");
    scanf("%f", &cartacidade->pib);
    system("cls");

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &cartacidade->nPontosTuristicos);
    system("cls");

    printf("Carta gerada com sucesso\n\n\n"); // Armazenando os dados na estrutura
}

float calcularDensidade(CartaCidade *cartacidade) // Função para calcular a densidade populacional
{
    if (cartacidade->area == 0) // Evita divisão por zero
    {
        return 0;
    }
    cartacidade->densidade = cartacidade->populacao / cartacidade->area; // Calcula a densidade
    return cartacidade->densidade; // Retorna a densidade calculada armazenada na estrutura
}

float calcularPIBPercapita(CartaCidade *cartacidade)
{
    cartacidade->pib_percapita = (cartacidade->pib * 1000) / cartacidade->populacao; // Calcula o PIB per capita com os dados salvos na estrutura
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
    //Itera a estrutura para comparar as cartas

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
        calcularSuperPoder(&cartacidade[i]); // Itera a estrutura com para calcular o super poder das cartas e comparar
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
               i + 1, cartacidade[i].codigoCarta, cartacidade[i].nomeCidade, cartacidade[i].populacao); // Exibe os dados da carta 
    }

    int maiorIndicePopulacao = 0;
    int empates = 0;
    for (int i = 1; i < qtdCartas; i++) // Itera a estrutura para comparar as cartas salvando também os empates
    // e o maior índice de população
    {
        if (cartacidade[i].populacao > cartacidade[maiorIndicePopulacao].populacao)
        {
            maiorIndicePopulacao = i;
            empates = 0;
        }
        else if (cartacidade[i].populacao == cartacidade[maiorIndicePopulacao].populacao)
        {
            empates++;
        }
    }
    if (empates > 0)
    {
        printf("Resultado: Empate!\n\n");
    }
    else
    {
        printf("Resultado: A Carta %d venceu!\n\n", maiorIndicePopulacao + 1);
    }
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
    int empates = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].area > cartacidade[maiorIndiceArea].area)
        {
            maiorIndiceArea = i;
            empates = 0;
        }
        else if (cartacidade[i].area == cartacidade[maiorIndiceArea].area)
        {
            empates++;
        }
    }
    if (empates > 0)
    {
        printf("Resultado: Empate!\n\n");
    }
    else
    {
        printf("Resultado: A Carta %d venceu!\n\n", maiorIndiceArea + 1);
    }
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
    int empates = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].pib > cartacidade[maiorIndicePIB].pib)
        {
            maiorIndicePIB = i;
            empates = 0;
        }
        else if (cartacidade[i].pib == cartacidade[maiorIndicePIB].pib)
        {
            empates++;
        }
    }
    if (empates > 0)
    {
        printf("Resultado: Empate!\n\n");
    }
    else
    {
        printf("Resultado: A Carta %d venceu!\n\n", maiorIndicePIB + 1);
    }
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
    int empates = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].densidade < cartacidade[menorIndiceDensidade].densidade)
        {
            menorIndiceDensidade = i;
            empates = 0;
        }
        else if (cartacidade[i].densidade == cartacidade[menorIndiceDensidade].densidade)
        {
            empates++;
        }
    }
    if (empates > 0)
    {
        printf("Resultado: Empate!\n\n");
    }
    else
    {
        printf("Resultado: A Carta %d venceu!\n\n", menorIndiceDensidade + 1);
    }
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
    int empates = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].pib_percapita > cartacidade[maiorIndicePibPerCapita].pib_percapita)
        {
            maiorIndicePibPerCapita = i;
            empates = 0;
        }
        else if (cartacidade[i].pib_percapita == cartacidade[maiorIndicePibPerCapita].pib_percapita)
        {
            empates++;
        }
    }
    if (empates > 0)
    {
        printf("Resultado: Empate!\n\n");
    }
    else
    {
        printf("Resultado: A Carta %d venceu!\n\n", maiorIndicePibPerCapita + 1);
    }
}

void menuCompararIndividualmente(CartaCidade *cartacidade, int qtdCartas)
{
    int opc;
    system("cls");
    printf("=== Menu de Comparação Individual ===\n");
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

void compararMultiplosAtt(CartaCidade *cartacidade, int qtdCartas)
{
    float atributos[2][2]; // Array para armazenar os atributos das cartas
    // Atributos: 0 - Carta 1, 1 - Carta 2        
    char nome[2][50];
    // Array para armazenar os nomes das cartas
    // Atributos: 0 - Carta 1, 1 - Carta 2
    float somaCarta1; // Variável para armazenar a soma dos atributos da carta 1
    float somaCarta2; // Variável para armazenar a soma dos atributos da carta 2
    char resultadoCompararacao1[50]; // Variável para armazenar o resultado da comparação do primeiro atributo
    char resultadoCompararacao2[50]; // Variável para armazenar o resultado da comparação do segundo atributo
    char resultadoSoma[50]; // Variável para armazenar o resultado da soma dos atributos

    int opc1;
    int opc2;

    system("cls");
    printf("Escolha o primeiro atributo");
    printf("1. Comparar População\n");
    printf("2. Comparar Área\n");
    printf("3. Comparar PIB\n");
    printf("4. Comparar Densidade Populacional\n");
    printf("5. Comparar PIB per Capita\n");
    printf("Digite a opção: ");
    scanf("%d", &opc1);

    do
    {
        switch (opc1)
        {
        case 1:
            strcpy(nome[0], cartacidade[0].nomeCidade); // Copia o nome da cidade para o array
            // A função strcpy copia a string de origem para o destino
            strcpy(nome[1], cartacidade[1].nomeCidade);
            atributos[0][0] = (float)cartacidade[0].populacao; // Atribui o valor da população da carta 1
            atributos[0][1] = (float)cartacidade[1].populacao; // Atribui o valor da população da carta 2

            if (atributos[0][0] > atributos[0][1]) 
            {
                strcpy(resultadoCompararacao1, "Carta 1 venceu");
            }
            else if (atributos[0][0] < atributos[0][1])
            {
                strcpy(resultadoCompararacao1, "Carta 2 venceu");
            }
            else
            {
                strcpy(resultadoCompararacao1, "Empate!");
            }
            break;
        case 2:
            strcpy(nome[0], cartacidade[0].nomeCidade); 
            strcpy(nome[1], cartacidade[1].nomeCidade);
            atributos[0][0] = cartacidade[0].area;
            atributos[0][1] = cartacidade[1].area;
            if (atributos[0][0] > atributos[0][1])
            {
                strcpy(resultadoCompararacao1, "Carta 1 venceu");
            }
            else if (atributos[0][0] < atributos[0][1])
            {
                strcpy(resultadoCompararacao1, "Carta 2 venceu");
            }
            else
            {
                strcpy(resultadoCompararacao1, "Empate!");
            }
            break;
        case 3:
            strcpy(nome[0], cartacidade[0].nomeCidade);
            strcpy(nome[1], cartacidade[1].nomeCidade);
            atributos[0][0] = cartacidade[0].pib;
            atributos[0][1] = cartacidade[1].pib;
            if (atributos[0][0] > atributos[0][1])
            {
                strcpy(resultadoCompararacao1, "Carta 1 venceu");
            }
            else if (atributos[0][0] < atributos[0][1])
            {
                strcpy(resultadoCompararacao1, "Carta 2 venceu");
            }
            else
            {
                strcpy(resultadoCompararacao1, "Empate!");
            }
            break;
        case 4:
            strcpy(nome[0], cartacidade[0].nomeCidade);
            strcpy(nome[1], cartacidade[1].nomeCidade);
            atributos[0][0] = cartacidade[0].densidade;
            atributos[0][1] = cartacidade[1].densidade;
            if (atributos[0][0] < atributos[0][1])
            {
                strcpy(resultadoCompararacao1, "Carta 1 venceu");
            }
            else if (atributos[0][0] > atributos[0][1])
            {
                strcpy(resultadoCompararacao1, "Carta 2 venceu");
            }
            else
            {
                strcpy(resultadoCompararacao1, "Empate!");
            }
            break;
        case 5:
            strcpy(nome[0], cartacidade[0].nomeCidade);
            strcpy(nome[1], cartacidade[1].nomeCidade);
            atributos[0][0] = cartacidade[0].pib_percapita;
            atributos[0][1] = cartacidade[1].pib_percapita;
            if (atributos[0][0] > atributos[0][1])
            {
                strcpy(resultadoCompararacao1, "Carta 1 venceu");
            }
            else if (atributos[0][0] < atributos[0][1])
            {
                strcpy(resultadoCompararacao1, "Carta 2 venceu");
            }
            else
            {
                strcpy(resultadoCompararacao1, "Empate!");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opc1 < 1 || opc1 > 5);

    system("cls");
    printf("Escolha o segundo atributo"); // Exibe o menu para escolher o segundo atributo
    if (opc1 != 1) // evita repetir o primeiro atributo e assim por diante
        printf("1. População\n");
    if (opc1 != 2)
        printf("2. Área\n");
    if (opc1 != 3)
        printf("3. PIB\n");
    if (opc1 != 4)
        printf("4. Densidade Populacional\n");
    if (opc1 != 5)
        printf("5. PIB per Capita\n");
    printf("Digite a opção: ");
    scanf("%d", &opc2);

    do
    {
        switch (opc2)
        {
        case 1:
            atributos[1][0] = (float)cartacidade[0].populacao;
            atributos[1][1] = (float)cartacidade[1].populacao;
            if (atributos[1][0] > atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 1 venceu!");
            }
            else if (atributos[1][0] < atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 2 venceu!");
            }
            else
            {
                strcpy(resultadoCompararacao2, "Empate!");
            }

            break;
        case 2:
            atributos[1][0] = cartacidade[0].area;
            atributos[1][1] = cartacidade[1].area;
            if (atributos[1][0] > atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 1 venceu!");
            }
            else if (atributos[1][0] < atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 2 venceu!");
            }
            else
            {
                strcpy(resultadoCompararacao2, "Empate!");
            }
            break;
        case 3:
            atributos[1][0] = cartacidade[0].pib;
            atributos[1][1] = cartacidade[1].pib;
            if (atributos[1][0] > atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 1 venceu!");
            }
            else if (atributos[1][0] < atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 2 venceu!");
            }
            else
            {
                strcpy(resultadoCompararacao2, "Empate!");
            }
            break;
        case 4:
            atributos[1][0] = cartacidade[0].densidade;
            atributos[1][1] = cartacidade[1].densidade;
            if (atributos[1][0] < atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 1 venceu!");
            }
            else if (atributos[1][0] > atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 2 venceu!");
            }
            else
            {
                strcpy(resultadoCompararacao2, "Empate!");
            }
            break;
        case 5:
            atributos[1][0] = cartacidade[0].pib_percapita;
            atributos[1][1] = cartacidade[1].pib_percapita;
            if (atributos[1][0] > atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 1 venceu!");
            }
            else if (atributos[1][0] < atributos[1][1])
            {
                strcpy(resultadoCompararacao2, "Carta 2 venceu!");
            }
            else
            {
                strcpy(resultadoCompararacao2, "Empate!");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opc2 != opc1 && (opc2 < 1 || opc2 > 5));

    somaCarta1 = atributos[0][0] + atributos[1][0]; // Soma os atributos da carta 1
    somaCarta2 = atributos[0][1] + atributos[1][1]; // Soma os atributos da carta 2

    if (somaCarta1 > somaCarta2)
    {
        strcpy(resultadoSoma, "Carta 1 venceu a rodada");
    }
    else if (somaCarta1 < somaCarta2)
    {
        strcpy(resultadoSoma, "Carta 2 venceu a rodada");
    }
    else
    {
        strcpy(resultadoSoma, "Empate!");
    }

    system("cls");
    // mostra tudo que foi comparado
    printf("\nResultado da Comparação:\n");
    printf("Carta 1: %s\nCarta 2: %s\n", nome[0], nome[1]);
    printf("Atributo 1: %.2f vs %.2f - %s\n", atributos[0][0], atributos[0][1], resultadoCompararacao1);
    printf("Atributo 2: %.2f vs %.2f - %s\n", atributos[1][0], atributos[1][1], resultadoCompararacao2);
    printf("Soma: %.2f vs %.2f - %s\n", somaCarta1, somaCarta2, resultadoSoma);
}

int main()
{
    system("cls");
    setlocale(LC_ALL, "portuguese_brazil"); // Definindo o locale para português do Brasil
    printf("=== Jogo Super Trunfo ===\n\n");

    CartaCidade cartacidade[5]; // Array para armazenar até 5 cartas
    // Inicializando as cartas com valores padrão
    int qtdcartas = 0; // Contador de cartas cadastradas
    int opcao; // Variável para armazenar a opção do menu
    // Definindo valores padrão para as cartas

    do // Loop principal do menu
    {
        mostrarMenu(); // Exibindo o menu de opções
        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada inválida!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (opcao) // Verificando a opção escolhida pelo usuário
        {
        case 1:
            if (qtdcartas < 5) // Verificando se ainda há espaço para cadastrar mais cartas
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
            compararMultiplosAtt(cartacidade, qtdcartas);
            break;
        case 5:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n\n");
            while (getchar() != '\n')
                ;
            break;
        }
    } while (opcao != 5);

    return 0;
}