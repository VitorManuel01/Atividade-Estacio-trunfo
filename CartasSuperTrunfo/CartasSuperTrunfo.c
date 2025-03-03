#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    char estado;

    char codigoCarta[5];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int nPontosTuristicos;

} CartaCidade;

void mostrarMenu(){
    printf("Digite 1 para cadastrar uma carta\nDigite 2 para mostrar cartas cadastradas\nDigite 3 para sair\n\n\nDigitar: ");
}

void gerarCarta(CartaCidade* cartacidade)
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
    scanf("%d", &cartacidade->populacao);
    system("cls");
    
    printf("Digite a área: ");
    scanf("%f", &cartacidade->area);
    system("cls");
    
    printf("Digite o PIB: ");
    scanf("%f", &cartacidade->pib);
    system("cls");

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &cartacidade->nPontosTuristicos);
    system("cls");

    printf("Carta gerada com sucesso\n\n\n");
}

void mostrarCartas(CartaCidade* cartacidade, int qtdCartas){

    for(int i = 0; i < qtdCartas; i++){
        printf("\nCarta Encontrada\n\n");

        printf("Estado: %c\n", cartacidade[i].estado);
        
        printf("Código: %s\n", cartacidade[i].codigoCarta);
        
        printf("Cidade: %s\n", cartacidade[i].nomeCidade);
        
        printf("População: %d\n", cartacidade[i].populacao);
        
        printf("Área: %.2fm²\n", cartacidade[i].area);
        
        printf("PIB: R$%.2f\n", cartacidade[i].pib);
        
        printf("Pontos Turisticos: %d\n\n\n", cartacidade[i].nPontosTuristicos);
    }

}


int main()
{
    system("cls");
    setlocale(LC_ALL, "portuguese_brazil");

    CartaCidade cartacidade[5];
    
    int qtdcartas = 0;
    
    int opcao;
    do {
        mostrarMenu();
        if (scanf("%d", &opcao) != 1) { // Verifica entrada inválida
            printf("Entrada inválida!\n");
            while (getchar() != '\n'); // Limpa buffer de entrada
            continue;
        }

        switch (opcao) {
            case 1:
                if (qtdcartas < 5) { // Evita ultrapassar o tamanho do array
                    system("cls");
                    gerarCarta(&cartacidade[qtdcartas]);
                    qtdcartas++;
                } else {
                    printf("Número máximo de cartas atingido!\n");
                }
                break;

            case 2:
                system("cls");
                if (qtdcartas > 0) {
                    mostrarCartas(cartacidade, qtdcartas);
                } else {
                    printf("\nNão há cartas\n\n");
                }
                break;

            case 3:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n\n");
                while (getchar() != '\n'); // Espera o usuário ler a mensagem
                break;
        }

    } while (opcao != 3);

    
    

    return 0;
}