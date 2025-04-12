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

void mostrarMenu() // Fun��o para exibir o menu principal
{
    system("cls");
    printf("=== Menu Principal ===\n\n");
    printf("1. Cadastrar Carta\n");
    printf("2. Mostrar Cartas\n");
    printf("3. Comparar Individualmente\n");
    printf("4. Comparar M�ltiplos Atributos\n");
    printf("5. Sair\n\n");
    printf("Escolha uma op��o: ");
}

void gerarCarta(CartaCidade *cartacidade) // Fun��o para gerar uma nova carta
{
    int numeroCarta;
    printf("Digite uma letra de A a H para representar o estado: ");
    scanf(" %c", &cartacidade->estado);
    system("cls");

    printf("Escolha um n�mero de 01 a 04: ");
    scanf("%d", &numeroCarta);
    switch (numeroCarta)
    {
    case 1:
        sprintf(cartacidade->codigoCarta, "%c01", cartacidade->estado); // Formata o c�digo da carta com o estado e o n�mero
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
    scanf(" %49[^\n]", cartacidade->nomeCidade); // L� at� 49 caracteres e ignora o '\n'
    system("cls");

    printf("Digite a popula��o: ");
    scanf("%ld", &cartacidade->populacao); // L� a popula��o como um n�mero inteiro longo
    system("cls");

    printf("Digite a �rea: ");
    scanf("%f", &cartacidade->area); // L� a �rea como um n�mero de ponto flutuante
    system("cls");

    printf("Digite o PIB em milh�es: ");
    scanf("%f", &cartacidade->pib);
    system("cls");

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &cartacidade->nPontosTuristicos);
    system("cls");

    printf("Carta gerada com sucesso\n\n\n"); // Armazenando os dados na estrutura
}

float calcularDensidade(CartaCidade *cartacidade) // Fun��o para calcular a densidade populacional
{
    if (cartacidade->area == 0) // Evita divis�o por zero
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
        printf("Popula��o: %ld\n", cartacidade[i].populacao);
        printf("�rea: %.2f km�\n", cartacidade[i].area);
        printf("PIB: R$%.2f\n", cartacidade[i].pib);
        printf("Pontos Tur�sticos: %d\n", cartacidade[i].nPontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km�\n", calcularDensidade(&cartacidade[i]));
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

    printf("Compara��o de Cartas\n");
    //Itera a estrutura para comparar as cartas

    int maiorIndicePopulacao = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].populacao > cartacidade[maiorIndicePopulacao].populacao) 
        {
            maiorIndicePopulacao = i;
        }
    }
    printf("Popula��o: A Carta %d venceu\n", maiorIndicePopulacao + 1);

    int maiorIndiceArea = 0;
    for (int i = 1; i < qtdCartas; i++)
    {
        if (cartacidade[i].area > cartacidade[maiorIndiceArea].area)
        {
            maiorIndiceArea = i;
        }
    }
    printf("�rea: A Carta %d venceu\n", maiorIndiceArea + 1);

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
    printf("Pontos Tur�sticos: A Carta %d venceu\n", maiorIndicePontosTuristicos + 1);

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

    printf("\nCompara��o de Popula��o\n");
    for (int i = 0; i < qtdCartas; i++)
    {
        printf("Carta %d (%s - %s): %ld habitantes\n",
               i + 1, cartacidade[i].codigoCarta, cartacidade[i].nomeCidade, cartacidade[i].populacao); // Exibe os dados da carta 
    }

    int maiorIndicePopulacao = 0;
    int empates = 0;
    for (int i = 1; i < qtdCartas; i++) // Itera a estrutura para comparar as cartas salvando tamb�m os empates
    // e o maior �ndice de popula��o
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

    printf("\nCompara��o de �rea\n");
    for (int i = 0; i < qtdCartas; i++)
    {
        printf("Carta %d (%s - %s): %.2f km�\n",
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

    printf("\nCompara��o de PIB\n");
    for (int i = 0; i < qtdCartas; i++)
    {
        printf("Carta %d (%s - %s): R$%.2f milh�es\n",
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

    printf("\nCompara��o de Densidade Populacional\n");
    for (int i = 0; i < qtdCartas; i++)
    {
        calcularDensidade(&cartacidade[i]);
        printf("Carta %d (%s - %s): %.2f hab/km�\n",
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

    printf("\nCompara��o de PIB per Capita\n");
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
    printf("=== Menu de Compara��o Individual ===\n");
    printf("1. Comparar Popula��o\n");
    printf("2. Comparar �rea\n");
    printf("3. Comparar PIB\n");
    printf("4. Comparar Densidade Populacional\n");
    printf("5. Comparar PIB per Capita\n");
    printf("Digite a op��o: ");
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
        printf("Op��o inv�lida!\n");
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
    float somaCarta1; // Vari�vel para armazenar a soma dos atributos da carta 1
    float somaCarta2; // Vari�vel para armazenar a soma dos atributos da carta 2
    char resultadoCompararacao1[50]; // Vari�vel para armazenar o resultado da compara��o do primeiro atributo
    char resultadoCompararacao2[50]; // Vari�vel para armazenar o resultado da compara��o do segundo atributo
    char resultadoSoma[50]; // Vari�vel para armazenar o resultado da soma dos atributos

    int opc1;
    int opc2;

    system("cls");
    printf("Escolha o primeiro atributo");
    printf("1. Comparar Popula��o\n");
    printf("2. Comparar �rea\n");
    printf("3. Comparar PIB\n");
    printf("4. Comparar Densidade Populacional\n");
    printf("5. Comparar PIB per Capita\n");
    printf("Digite a op��o: ");
    scanf("%d", &opc1);

    do
    {
        switch (opc1)
        {
        case 1:
            strcpy(nome[0], cartacidade[0].nomeCidade); // Copia o nome da cidade para o array
            // A fun��o strcpy copia a string de origem para o destino
            strcpy(nome[1], cartacidade[1].nomeCidade);
            atributos[0][0] = (float)cartacidade[0].populacao; // Atribui o valor da popula��o da carta 1
            atributos[0][1] = (float)cartacidade[1].populacao; // Atribui o valor da popula��o da carta 2

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
            printf("Op��o inv�lida!\n");
            break;
        }
    } while (opc1 < 1 || opc1 > 5);

    system("cls");
    printf("Escolha o segundo atributo"); // Exibe o menu para escolher o segundo atributo
    if (opc1 != 1) // evita repetir o primeiro atributo e assim por diante
        printf("1. Popula��o\n");
    if (opc1 != 2)
        printf("2. �rea\n");
    if (opc1 != 3)
        printf("3. PIB\n");
    if (opc1 != 4)
        printf("4. Densidade Populacional\n");
    if (opc1 != 5)
        printf("5. PIB per Capita\n");
    printf("Digite a op��o: ");
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
            printf("Op��o inv�lida!\n");
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
    printf("\nResultado da Compara��o:\n");
    printf("Carta 1: %s\nCarta 2: %s\n", nome[0], nome[1]);
    printf("Atributo 1: %.2f vs %.2f - %s\n", atributos[0][0], atributos[0][1], resultadoCompararacao1);
    printf("Atributo 2: %.2f vs %.2f - %s\n", atributos[1][0], atributos[1][1], resultadoCompararacao2);
    printf("Soma: %.2f vs %.2f - %s\n", somaCarta1, somaCarta2, resultadoSoma);
}

int main()
{
    system("cls");
    setlocale(LC_ALL, "portuguese_brazil"); // Definindo o locale para portugu�s do Brasil
    printf("=== Jogo Super Trunfo ===\n\n");

    CartaCidade cartacidade[5]; // Array para armazenar at� 5 cartas
    // Inicializando as cartas com valores padr�o
    int qtdcartas = 0; // Contador de cartas cadastradas
    int opcao; // Vari�vel para armazenar a op��o do menu
    // Definindo valores padr�o para as cartas

    do // Loop principal do menu
    {
        mostrarMenu(); // Exibindo o menu de op��es
        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada inv�lida!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (opcao) // Verificando a op��o escolhida pelo usu�rio
        {
        case 1:
            if (qtdcartas < 5) // Verificando se ainda h� espa�o para cadastrar mais cartas
            {
                system("cls");
                gerarCarta(&cartacidade[qtdcartas]);
                qtdcartas++;
            }
            else
            {
                printf("N�mero m�ximo de cartas atingido!\n");
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
                printf("\nN�o h� cartas\n\n");
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
            printf("Op��o inv�lida!\n\n");
            while (getchar() != '\n')
                ;
            break;
        }
    } while (opcao != 5);

    return 0;
}