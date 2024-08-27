#include <stdio.h>
#include <locale.h>


typedef struct {
    char nome[100];
    char jogada;
} Jogador;

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
    int linha;
    int coluna;
    do {
        printf("%sDigite a linha e coluna: ", jogador->nome);
        scanf("%d %d", &linha, &coluna);
       
        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha-1][coluna-1] != ' ') {
            printf("Movimento inválido!\n");
        } else {
            break;
        }
    } while (1);
        tabuleiro[linha-1][coluna-1] = jogador->jogada;
    system("cls");
}//fim turno

int verificarVencedor(char tabuleiro[3][3]) {
    int i;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            if(tabuleiro[i][0] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }

        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            if(tabuleiro[i][0] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }

        if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
            if(tabuleiro[i][0] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }

        if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
            if(tabuleiro[i][0] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }
    }//fim for

}//fim verificarVencedor

int verificarEmpate(char tabuleiro[3][3]){
    int i;
    for(i = 0; i < 3; i++){
        if(tabuleiro[i][0] == ' ' || tabuleiro[i][1] == ' ' || tabuleiro[i][2] == ' '){
            return 0;
        }
    }
    return 3;
}

void main() {
    setlocale(LC_ALL, "Portuguese");
   
    char tabuleiro[3][3];
    Jogador jogador1;
    Jogador jogador2;
    Jogador *jogadorAtual;
   
    printf("========JOGO DA VELHA========\n\n");
   
    printf("Nome do Jogador 1: ");
    fgets(jogador1.nome, sizeof(jogador1.nome), stdin);
    jogador1.jogada = 'X';
   
    printf("\nNome doa Jogador 2: ");
    fgets(jogador2.nome, sizeof(jogador2.nome), stdin);
    jogador2.jogada = 'O';


    tabuleiroInicial(tabuleiro);
    mostrarTabuleiro(tabuleiro);
    
    jogadorAtual = &jogador1;
    while (1) {
        system('cls');
        jogar(jogadorAtual, tabuleiro);
        mostrarTabuleiro(tabuleiro);
        if (jogadorAtual == &jogador1) {
            jogadorAtual = &jogador2;
        } else {
            jogadorAtual = &jogador1;
        }

        int ganhador;
        
        ganhador = verificarVencedor(tabuleiro);
        if(ganhador == 1){
            printf("%s é o vencedor!", jogador1.nome);
            break;
        }
        if(ganhador == 2){
            printf("%s é o vencedor!", jogador2.nome);
            break;
        }
        ganhador = verificarEmpate(tabuleiro);
            if(ganhador == 3){
                printf("Empate");
                break;
            }
    }
}//fim main

