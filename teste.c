#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  \n ||

typedef struct {
	   char	nome[100];
	   char letra;
	   int vitoria;
}Jogador;

void tabuleiroInicial(char tabuleiro[3][3]); // Coloca espacos em branco no tabuleiro
void mostrarTabuleiro(char tabuleiro[3][3]); //Mostra o tabuleiro

void nomeLetraJogador(Jogador *jogador); //Pega o nome dos jogagores e qual letra o jogador 1 vai quer
void jogar(Jogador *jogador, char tabuleiro[3][3]); // Adiciona a letra do jogador no tabuleiro
int verificarVencedor(char tabuleiro[3][3], Jogador *jogador);
int verificarEmpate(char tabuleiro[3][3]);
void relatorio(Jogador *jogador, int *empate);
void jogo(char tabuleiro[3][3], Jogador *jogador, Jogador *jogadorAtual, int *resultado, int *empate);
void jogoDesempate(char tabuleiro[3][3], Jogador *jogador, Jogador *jogadorAtual, int *resultado);

void main(){
	char tabuleiro[3][3];
	tabuleiroInicial(tabuleiro); // Tabuleiro com ' '.
	Jogador jogador[2]; 
	Jogador *jogadorAtual; //Ponteiro vai apontar para o jogador atual.
	int resultado, empate = 0; // resultado pega o retorno na funcao verifica vencedor
	
	jogadorAtual = &jogador[0]; // Definindo o jogador atual como sendo o jogador da posicao 0.
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
			jogo(tabuleiro, jogador, jogadorAtual, &resultado, &empate);
			empate = 4;
			if(jogador[0].vitoria == 2 && jogador[1].vitoria == 2 || empate == 4){
				jogoDesempate(tabuleiro,jogador, jogadorAtual, &resultado);
			}
			
			relatorio(jogador, &empate);
			printf("era para ser o relatorio");
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

void jogoDesempate(char tabuleiro[3][3], Jogador *jogador, Jogador *jogadorAtual, int *resultado){
	int partidaDesempate = 1;
	while(partidaDesempate == 1){
		int qtdJogadas = 0;
		while(qtdJogadas < 9){
			system("cls");
			fflush(stdin);
			printf("--------- JOGO DA VELHA --------\n");
			printf("----- PARTIDA DE DESEMPATE -----\n\n");
			printf("Jogador 1: %s, Letra: %c\n", jogador[0].nome, jogador[0].letra);
			printf("Jogador 2: %s, Letra: %c\n\n", jogador[1].nome, jogador[1].letra);
			
			mostrarTabuleiro(tabuleiro);
			jogar(jogadorAtual, tabuleiro);
			resultado = verificarVencedor(tabuleiro,jogador);
			if(resultado == 1){
				system("cls");
				printf("--------- JOGO DA VELHA --------\n");
				printf("----- PARTIDA DE DESEMPATE -----\n\n");
				mostrarTabuleiro(tabuleiro);
	            printf("\n%s e o vencedor da partida de desempate\n", jogador[0].nome);
	            jogador[0].vitoria +=1;
	            partidaDesempate = 0;
	            printf("Vitoria: %d\n\n",jogador[0].vitoria);
	            system("pause");
	            break;
	        }else if(resultado == 2){
	        	system("cls");
				printf("--------- JOGO DA VELHA --------\n");
				printf("----- PARTIDA DE DESEMPATE -----\n\n");
				mostrarTabuleiro(tabuleiro);
	            printf("\n%s e o vencedor da partida desempate\n", jogador[1].nome);
	            jogador[1].vitoria +=1;
	            partidaDesempate = 0;
	            printf("Vitoria: %d\n\n",jogador[1].vitoria);
	            system("pause");
	            break;
	        }//vitoria jogador 2
	        
	        resultado = verificarEmpate(tabuleiro);
			if(resultado == 3){
				system("cls");
	        	printf("--------- JOGO DA VELHA ------------\n");
				printf("----- PARTIDA DE DESEMPATE -----\n\n");
	        	mostrarTabuleiro(tabuleiro);
                printf("\nA partida de desempate deu empate!\n");
                printf("\nUma nova partira sera iniciada ate que haja um vencedor!\n");
                system("pause");
                break;
    
			}//empate
			
	        //troca de jogador
			if(jogadorAtual == &jogador[0]){
				jogadorAtual = &jogador[1];
			}else{
				jogadorAtual = &jogador[0];
			}
			qtdJogadas++;
		}//fim while jogadas
		
		//Coloca o jogador 1 para iniciar as partidas
		if(jogadorAtual == &jogador[1]){
			jogadorAtual = &jogador[0];
		}
		//Limpa o tabuleiro
		tabuleiroInicial(tabuleiro);
	}//fim while partidas	
	
}//fim funcao jogoDesempate

void jogo(char tabuleiro[3][3], Jogador *jogador, Jogador *jogadorAtual, int *resultado, int *empate){
			int qtdPartidas = 0;
			while(qtdPartidas<4){
				int qtdJogadas = 0;
				while(qtdJogadas < 9){
					system("cls");
					fflush(stdin);
					printf("----- JOGO DA VELHA -----\n\n");
					printf("Jogador 1: %s, Letra: %c\n", jogador[0].nome, jogador[0].letra);
					printf("Jogador 2: %s, Letra: %c\n\n", jogador[1].nome, jogador[1].letra);
					printf("Partida %d/4\n\n",qtdPartidas+1);
					
					mostrarTabuleiro(tabuleiro);
					jogar(jogadorAtual, tabuleiro);
					resultado = verificarVencedor(tabuleiro,jogador);
					if(resultado == 1){
						system("cls");
						printf("----- JOGO DA VELHA -----\n\n");
						printf("Jogador 1: %s, Letra: %c\n", jogador[0].nome, jogador[0].letra);
						printf("Jogador 2: %s, Letra: %c\n\n", jogador[1].nome, jogador[1].letra);
						printf("Partida %d/4\n\n",qtdPartidas+1);
						mostrarTabuleiro(tabuleiro);
			            printf("\n%s e o vencedor da partida %d/4!\n", jogador[0].nome,qtdPartidas+1);
			            jogador[0].vitoria +=1;
			            printf("Vitoria: %d\n\n",jogador[0].vitoria);
			            system("pause");
			            break;
			        }else if(resultado == 2){
			        	system("cls");
						printf("----- JOGO DA VELHA -----\n\n");
						printf("Jogador 1: %s, Letra: %c\n", jogador[0].nome, jogador[0].letra);
						printf("Jogador 2: %s, Letra: %c\n\n", jogador[1].nome, jogador[1].letra);
						printf("Partida %d/4\n\n",qtdPartidas+1);
						mostrarTabuleiro(tabuleiro);
			            printf("\n%s e o vencedor da partida %d/4!\n", jogador[1].nome,qtdPartidas+1);
			            jogador[1].vitoria +=1;
			            printf("Vitoria: %d\n\n",jogador[1].vitoria);
			            system("pause");
			            break;
			        }else{
			        	resultado = verificarEmpate(tabuleiro);
			        	if(resultado == 3){
			        		system("cls");
							printf("----- JOGO DA VELHA -----\n\n");
							printf("Jogador 1: %s, Letra: %c\n", jogador[0].nome, jogador[0].letra);
							printf("Jogador 2: %s, Letra: %c\n\n", jogador[1].nome, jogador[1].letra);
							printf("Partida %d/4\n\n",qtdPartidas+1);
							mostrarTabuleiro(tabuleiro);
			                printf("\nA partida %d/4 deu empate!\n",qtdPartidas+1);
			                *empate +=1;
			                system("pause");
			                break;
			            }
					}
					
			        //troca de jogador
					if(jogadorAtual == &jogador[0]){
						jogadorAtual = &jogador[1];
					}else{
						jogadorAtual = &jogador[0];
					}
					qtdJogadas++;
				}//fim while jogadas
				
				//Coloca o jogador 1 para iniciar as partidas
				if(jogadorAtual == &jogador[1]){
					jogadorAtual = &jogador[0];
				}
				//Limpa o tabuleiro
				tabuleiroInicial(tabuleiro);
				qtdPartidas++;	
			}//fim while partidas
}//fim funcao jogo
	
void relatorio(Jogador *jogador, int *empate){
	system("cls");
	printf("----- JOGO DA VELHA - RELATORIO -----\n\n");
	int i;
	for(i=0;i<2;i++){
		printf("Vitoria do %s: %d\n",jogador[i].nome,jogador[i].vitoria);
	}
	printf("Empate: %d\n", *empate);
	system("pause");
}
	
int verificarEmpate(char tabuleiro[3][3]){
    int i;
    for(i = 0; i < 3; i++){
        if(tabuleiro[i][0] == ' ' || tabuleiro[i][1] == ' ' || tabuleiro[i][2] == ' '){
            return 0;
        }
    }
    return 3;
}//verifica empate


/*
int verificarVencedor(char tabuleiro[3][3], Jogador *jogador) {
    int i;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            if(tabuleiro[i][0] == jogador[0].letra){
                return 1;
            }
        }else if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            if(tabuleiro[i][0] == jogador[1].letra){
                return 2;
            }
        }

        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            if(tabuleiro[i][0] == jogador[0].letra){
                return 1;
            }
        }else if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            if(tabuleiro[i][0] == jogador[1].letra){
                return 2;
            }
        }

        if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
            if(tabuleiro[i][0] == jogador[0].letra){
                return 1;
            }
        }else if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            if(tabuleiro[i][0] == jogador[1].letra){
                return 2;
            }
        }

        if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
            if(tabuleiro[i][0] == jogador[0].letra){
                return 1;
            }
        }else if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            if(tabuleiro[i][0] == jogador[1].letra){
                return 2;
            }
        }
    }//fim for

}//fim verificarVencedor
*/

int verificarVencedor(char tabuleiro[3][3], Jogador *jogador){
	int i;
	for(i=0;i<3;i++){
		//verifica linhas
		if(tabuleiro[i][0] == jogador[0].letra && tabuleiro[i][1] == jogador[0].letra && tabuleiro[i][2] == jogador[0].letra){
			return 1;
		}else if(tabuleiro[i][0] == jogador[1].letra && tabuleiro[i][1] == jogador[1].letra && tabuleiro[i][2] == jogador[1].letra){
			return 2;
		}
	}// fim for linhas
	
	for(i=0;i<3;i++){
		//verifica as colunas
		if(tabuleiro[0][i] == jogador[0].letra && tabuleiro[1][i] == jogador[0].letra && tabuleiro[2][i] == jogador[0].letra){
			return 1;
		}else if(tabuleiro[0][i] == jogador[1].letra && tabuleiro[1][i] == jogador[1].letra && tabuleiro[2][i] == jogador[1].letra){
			return 2;
		}	
	}//fim for colunas
	
	//verifica diagonal principal
		if(tabuleiro[0][0] == jogador[0].letra && tabuleiro[1][1] == jogador[0].letra && tabuleiro[2][2] == jogador[0].letra){
			return 1;
		}else if(tabuleiro[0][0] == jogador[1].letra && tabuleiro[1][1] == jogador[1].letra && tabuleiro[2][2] == jogador[1].letra){
			return 2;
		}
		
		//verifica diagonal secundaria
		if(tabuleiro[0][2] == jogador[0].letra && tabuleiro[1][1] == jogador[0].letra && tabuleiro[2][0] == jogador[0].letra){
			return 1;
		}else if(tabuleiro[0][2] == jogador[1].letra && tabuleiro[1][1] == jogador[1].letra && tabuleiro[2][0] == jogador[1].letra){
			return 2;
		}
	
	
}// fim verificarVencedor

	
void jogar(Jogador *jogador, char tabuleiro[3][3]) {
    int linha;
    int coluna;
    int linhaColuna;
    do {
        printf("\n%s digite a linha e coluna: ", jogador->nome);
        linhaColuna = scanf("%d %d", &linha, &coluna);
        if (linhaColuna !=2 || linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha-1][coluna-1] != ' ') {
            printf("\nMovimento invalido!\n");
            while(getchar() != '\n');
        } else {
            break;
        }
    } while(1);
        tabuleiro[linha-1][coluna-1] = jogador->letra;
}//fim jogar

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
		jogador[i].vitoria = 0;
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
	int i,j;
	printf("   1   2   3\n\n");
	for(i=0;i<3;i++){
		printf("%d ", i+1);
		for(j=0;j<3;j++){
			if(j==2){
				printf(" %c ",tabuleiro[i][j]);
				printf("\n");
				if(i!=2){
					printf("  -----------");
					printf("\n");
				}
			}else{
				printf(" %c |",tabuleiro[i][j]);
			}//fim else
		}//fim for do J
	}//fim do for do I
}//fim mostrarMatriz