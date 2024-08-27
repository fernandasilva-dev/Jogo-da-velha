#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  \n

typedef struct {
	   char	nome[100];
	   char letra;
	   int vitoria;
}Jogador;

void tabuleiroInicial(char tabuleiro[3][3]);
void mostrarTabuleiro(char tabuleiro[3][3]);
void modificarTabuleiro(char *posicao_tabuleiro);

void main(){
	
	char tabuleiro[3][3];
	tabuleiroInicial(tabuleiro);
	Jogador jogador[2];
	
	while(1){
		system("cls");
		fflush(stdin);
		char op;
		printf("----- JODO DA VELHA -----\n");
		printf("1 - Jogar\n");
		printf("0 - Sair\n");
		printf(">> ");
		scanf("%c",&op);
		switch(op)
		{
		case '1':
			system("cls");
			fflush(stdin);
			
			printf("Enderero jogador 1: %p\n", jogador[0]);
			printf("Enderero jogador 1: %p\n", jogador[1]);
			
			Jogador *p;
			p = &jogador[0];
			p->nome = "Bruno";
			
			
			printf("Enderero jogador 1: %s\n", p);
			//printf("Enderero jogador 1: %p\n", jogador[1]);
			
			
			system("pause");
			
			/*printf("Informe o nome do jogador 1: ");
			gets(jogadores[0].nome);
			printf("Informe o nome do jogador 2: ");
			gets(jogadores[1].nome);
			printf("%s voce vai querer X ou O?: ",jogadores[0].nome);
			scanf("%c", &jogadores[0].x_O);
			jogadores[0].x_O = toupper(jogadores[0].x_O);
			
			if(jogadores[0].x_O =='X'){
				jogadores[1].x_O = 'O';
			}else{
				jogadores[1].x_O = 'X';
			}
			mostrarTabuleiro(tabuleiro);
			system("pause");*/
			break;
		case '0':
			if(op=='0'){
				break;
			}
			break;
		default:
			system("cls");
			printf("Opcao invalida!\nInforme outra posicao\n\n");
			system("pause");
			break;
		}
	}	
}//fim main

void tabuleiroInicial(char tabuleiro[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			tabuleiro[i][j] = ' ';	
		}
	}
}//fim tabuleiroInicial

void mostrarTabuleiro(char tabuleiro[3][3]){
	system("cls");
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j==2){
				printf(" %c ",tabuleiro[i][j]);
				printf("\n");
				if(i!=2){
					printf("-----------");
					printf("\n");
				}
			}else{
				printf(" %c |",tabuleiro[i][j]);
			}//fim else
		}//fim for do J
	}//fim do for do I
}//fim mostrarMatriz



void modificarTabuleiro(char *posicao_tabuleiro){
	char *p = posicao_tabuleiro;
	*p = 'X';
}//fim modificarMatriz
