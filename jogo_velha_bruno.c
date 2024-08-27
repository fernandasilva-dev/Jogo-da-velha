#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  \n

/*

printf("Endereco &jogador[2]: %p\n\n", &jogador[2]);
printf("Endereco &jogador: %p\n\n", &jogador);
printf("Endereco &jogador[0]: %p\n", &jogador[0]);
printf("Endereco &jogador[1]: %p\n\n", &jogador[1]);
printf("Endereco &jogador[0].nome: %p\n", &jogador[0].nome);
printf("Endereco &jogador[0].letra: %p\n\n", &jogador[0].letra);
printf("Endereco &jogador[1].nome: %p\n", &jogador[1].nome);
printf("Endereco &jogador[1].letra: %p\n", &jogador[1].letra);

*/

typedef struct {
	   char	nome[100];
	   char letra;
	   int vitoria;
}Jogador;

void tabuleiroInicial(char tabuleiro[3][3]);
void nomeLetraJogador(Jogador *jogador, Jogador *jogador2);
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
			nomeLetraJogador(&jogador[0], &jogador[1]);
			
			system("pause");
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
	}// fim while
		
}//fim main

void nomeLetraJogador(Jogador *jogador1, Jogador *jogador2){

	printf("Informe o nome do jogador 1: ");
	gets(jogador1->nome);
	jogador1->letra = 'X';
	
	printf("Informe o nome do jogador 2: ");
	gets(jogador2->nome);
	jogador2->letra = 'O';
}

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
