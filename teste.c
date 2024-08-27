#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  \n ||

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
void mostrarTabuleiro(char tabuleiro[3][3]);
void modificarTabuleiro(char *posicao_tabuleiro);
void nomeLetraJogador(Jogador *jogador);

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
			
			nomeLetraJogador(jogador);
			mostrarTabuleiro(tabuleiro);
			
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

void nomeLetraJogador(Jogador *jogador){
	char letra;
	int i;
	for(i=0;i<2;i++){
		fflush(stdin);
		system("cls");
		printf("Informe o nome do jogador %d: ", i+1);
		gets(jogador[i].nome);
		
		while(jogador[0].letra != 'X' && jogador[0].letra != 'O'){
			fflush(stdin);
			printf("%s voce vai querer X ou O? ", jogador[0].nome);
			scanf("%c", &letra);
			jogador[0].letra = toupper(letra);
			
			if(jogador[0].letra != 'X' && jogador[0].letra != 'O'){
				system("cls");
				printf("Letra invalida, informe X ou O\n");	
			}
		}//fim while
		if(jogador[0].letra == 'X'){
			jogador[1].letra = 'O';
		}else{
			jogador[1].letra = 'X';
		}
	}//fim for
}//fim nomeLetraJogador

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
	printf(" 1   2   3\n");
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
