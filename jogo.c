#include <stdio.h>
#include <locale.h>


typedef struct {
    char nome[100];
    char jogada;
} Jogador;


void tabuleiroInicial(char tabuleiro[3][3]);
void mostrarTabuleiro(char tabuleiro[3][3]);


void tabuleiroInicial(char tabuleiro[3][3]) {
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}//fim tabuleiroInicial


void mostrarTabuleiro(char tabuleiro[3][3]) {
    system("cls");
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 3 - 1) printf("|");
        }
        printf("\n");
        if (i < 3 - 1) printf("---|---|---\n");
    }
}//fim mostrarTabuleiro


void jogar(Jogador *jogador, char tabuleiro[3][3]) {
    int linha, coluna;
    do {
        printf("%s, digite a linha e coluna: ", jogador->nome);
        scanf("%d %d", &linha, &coluna);
       
        if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3 || tabuleiro[linha][coluna] != ' ') {
            printf("Movimento inválido!\n");
        } else {
            break;
        }
    } while (1);
    tabuleiro[linha][coluna] = jogador->jogada;
   
}//fim turno


void main() {
    setlocale(LC_ALL, "Portuguese");
   
    char tabuleiro[3][3];
    Jogador jogador1;
    Jogador jogador2;
   
    printf("========JOGO DA VELHA========\n\n");
   
    printf("Nome do Jogador 1: ");
    fgets(jogador1.nome, sizeof(jogador1.nome), stdin);
    jogador1.jogada = 'X';
   
    printf("\nNome doa Jogador 2: ");
    fgets(jogador2.nome, sizeof(jogador2.nome), stdin);
    jogador2.jogada = 'O';


    tabuleiroInicial(tabuleiro);
    mostrarTabuleiro(tabuleiro);
   
}//fim main

