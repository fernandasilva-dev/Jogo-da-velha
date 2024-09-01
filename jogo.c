#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
	   char	nome[100];
	   char letra;
	   int vitoria;
}Jogador;

void jogoDesempate(char tabuleiro[3][3], Jogador *jogador, Jogador *jogadorAtual, int *resultado, int *empate);
void jogo(char tabuleiro[3][3], Jogador *jogador, Jogador *jogadorAtual, int *resultado, int *empate);
void relatorio(Jogador *jogador, int *empate);
int verificarEmpate(char tabuleiro[3][3]);
int verificarVencedor(char tabuleiro[3][3], Jogador *jogador);
void jogar(Jogador *jogador, char tabuleiro[3][3]);
void nomeLetraJogador(Jogador *jogador);
void tabuleiroInicial(char tabuleiro[3][3]);
void mostrarTabuleiro(char tabuleiro[3][3]);

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
		int t;
		printf("%c",201);
		for(t = 0; t < 43; t++){
			printf("%c",205);
		}
		printf("%c",187);
		printf("\n%c\t\tJOGO DA VELHA\t\t    %c\n",186,186);
		printf("%c",204);
		for(t = 0; t < 43; t++){
			printf("%c",205);
		}
		printf("%c",185);
		printf("\n%c         \t\t\t\t    %c",186,186);
		printf("\n%c1 - Jogar\t\t\t\t    %c\n",186,186);
		printf("%c0 - Sair\t\t\t\t    %c",186,186);
		printf("\n%c         \t\t\t\t    %c\n",186,186);
		printf("%c",200);

		for(t = 0; t < 43; t++){
			printf("%c",205);
		}
		printf("%c",188);
		printf("\n>> ");
		scanf("%c",&op);
		printf("\n");
		if(op == '0'){
			break;
		}
		switch(op){
			case '1':
				system("cls");
				fflush(stdin);
				nomeLetraJogador(jogador);
				jogo(tabuleiro, jogador, jogadorAtual, &resultado, &empate);
				if(jogador[0].vitoria == jogador[1].vitoria || empate == 4){
					jogoDesempate(tabuleiro,jogador, jogadorAtual, &resultado, &empate);
				}
				relatorio(jogador, &empate);
				system("pause");
				break;
			case '0':
				break;
			default:
				system("cls");
				printf("Opcao invalida!\nInforme outra Opicao\n\n");
				system("pause");
				break;
		}
	}// fim while

}//fim main

void jogoDesempate(char tabuleiro[3][3], Jogador *jogador, Jogador *jogadorAtual, int *resultado, int *empate){
	int partidaDesempate = 0;
	while(partidaDesempate < 1){
		int qtdJogadas = 0;
		while(qtdJogadas < 9){
			system("cls");
			fflush(stdin);
			int t;
			printf("%c",201);
			for(t = 0; t < 43; t++){
				printf("%c",205);
			}
			printf("%c",187);
			printf("\n%c\t     PARTIDA DE DESEMPATE\t    %c\n",186,186);
			printf("%c",204);
			for(t = 0; t < 43; t++){
				printf("%c",205);
			}
			printf("%c",185);
			printf("\n%cJogador 1: %s, Letra: %c\t\t    %c\n",186, jogador[0].nome, jogador[0].letra, 186);
			printf("%cJogador 2: %s, Letra: %c\t\t    %c\n",186, jogador[1].nome, jogador[1].letra, 186);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);

			mostrarTabuleiro(tabuleiro);
			jogar(jogadorAtual, tabuleiro);
			resultado = verificarVencedor(tabuleiro,jogador);
			if(resultado == 1){
				system("cls");
				int t;
				printf("%c",201);
				for(t = 0; t < 43; t++){
					printf("%c",205);
				}
				printf("%c",187);
				printf("\n%c\t     PARTIDA DE DESEMPATE\t    %c\n",186,186);
				printf("%c",204);
				for(t = 0; t < 43; t++){
					printf("%c",205);
				}
				printf("%c",185);
				printf("\n%cJogador 1: %s, Letra: %c\t\t    %c\n",186, jogador[0].nome, jogador[0].letra, 186);
				printf("%cJogador 2: %s, Letra: %c\t\t    %c\n",186, jogador[1].nome, jogador[1].letra, 186);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);

				mostrarTabuleiro(tabuleiro);
	            printf("\n%s e o vencedor da partida de desempate\n", jogador[0].nome);
	            jogador[0].vitoria +=1;
	            partidaDesempate = 0;
	            printf("Vitoria: %d\n\n",jogador[0].vitoria);
	            system("pause");
	            partidaDesempate++;
	            break;
	        }else if(resultado == 2){
	        	system("cls");
				int t;
				printf("%c",201);
				for(t = 0; t < 43; t++){
					printf("%c",205);
				}
				printf("%c",187);
				printf("\n%c\t     PARTIDA DE DESEMPATE\t    %c\n",186,186);
				printf("%c",204);
				for(t = 0; t < 43; t++){
					printf("%c",205);
				}
				printf("%c",185);
				printf("\n%cJogador 1: %s, Letra: %c\t\t    %c\n",186, jogador[0].nome, jogador[0].letra, 186);
				printf("%cJogador 2: %s, Letra: %c\t\t    %c\n",186, jogador[1].nome, jogador[1].letra, 186);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);

				mostrarTabuleiro(tabuleiro);
	            printf("\n%s e o vencedor da partida desempate\n", jogador[1].nome);
	            jogador[1].vitoria +=1;
	            partidaDesempate = 0;
	            printf("Vitoria: %d\n\n",jogador[1].vitoria);
	            system("pause");
	            partidaDesempate++;
	            break;
	        }//vitoria jogador 2

	        resultado = verificarEmpate(tabuleiro);
			if(resultado == 3){
				system("cls");
	        	int t;
				printf("%c",201);
				for(t = 0; t < 43; t++){
					printf("%c",205);
				}
				printf("%c",187);
				printf("\n%c\t     PARTIDA DE DESEMPATE\t    %c\n",186,186);
				printf("%c",204);
				for(t = 0; t < 43; t++){
					printf("%c",205);
				}
				printf("%c",185);
				printf("\n%cJogador 1: %s, Letra: %c\t\t    %c\n",186, jogador[0].nome, jogador[0].letra, 186);
				printf("%cJogador 2: %s, Letra: %c\t\t    %c\n",186, jogador[1].nome, jogador[1].letra, 186);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	        	mostrarTabuleiro(tabuleiro);
                printf("A partida de desempate deu empate!\n");
                *empate += 1;
                partidaDesempate++;
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
			int o;
			system("cls");
			printf("\n\n\t\tCARREGANDO...\t\t\n");
			for(o = 0; o < 45; o++){
				Sleep(15);
				printf("%c",178);
			}
			Sleep(20);
			while(qtdPartidas<4){
				int qtdJogadas = 0;
				while(qtdJogadas < 9){
					system("cls");
					fflush(stdin);
					int t;
					printf("%c",201);
					for(t = 0; t < 43; t++){
						printf("%c",205);
					}
					printf("%c",187);
					printf("\n%c\t\tJOGO DA VELHA\t\t    %c\n",186,186);
					printf("%c",204);
					for(t = 0; t < 43; t++){
						printf("%c",205);
					}
					printf("%c",185);
					printf("\n%cJogador 1: %s, Letra: %c\t\t    %c\n",186, jogador[0].nome, jogador[0].letra, 186);
					printf("%cJogador 2: %s, Letra: %c\t\t    %c\n",186, jogador[1].nome, jogador[1].letra, 186);
					printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
					printf("%c\t\tPartida %d/4\t\t    %c\n",186,qtdPartidas+1,186);

					mostrarTabuleiro(tabuleiro);
					jogar(jogadorAtual, tabuleiro);
					resultado = verificarVencedor(tabuleiro,jogador);
					if(resultado == 1){
						system("cls");
						int t;
						printf("%c",201);
						for(t = 0; t < 43; t++){
							printf("%c",205);
						}
						printf("%c",187);
						printf("\n%c\t\tJOGO DA VELHA\t\t    %c\n",186,186);
						printf("%c",204);
						for(t = 0; t < 43; t++){
							printf("%c",205);
						}
						printf("%c",185);
						printf("\n%cJogador 1: %s, Letra: %c\t\t    %c\n",186, jogador[0].nome, jogador[0].letra, 186);
						printf("%cJogador 2: %s, Letra: %c\t\t    %c\n",186, jogador[1].nome, jogador[1].letra, 186);
						printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
						printf("%c\t\tPartida %d/4\t\t    %c\n",186,qtdPartidas+1,186);

						mostrarTabuleiro(tabuleiro);
			            printf("\n%s e o vencedor da partida %d/4!\n", jogador[0].nome,qtdPartidas+1);
			            jogador[0].vitoria +=1;
			            printf("Vitoria: %d\n\n",jogador[0].vitoria);
			            system("pause");
			            break;
			        }else if(resultado == 2){
			        	system("cls");
						int t;
						printf("%c",201);
						for(t = 0; t < 43; t++){
							printf("%c",205);
						}
						printf("%c",187);
						printf("\n%c\t\tJOGO DA VELHA\t\t    %c\n",186,186);
						printf("%c",204);
						for(t = 0; t < 43; t++){
							printf("%c",205);
						}
						printf("%c",185);
						printf("\n%cJogador 1: %s, Letra: %c\t\t    %c\n",186, jogador[0].nome, jogador[0].letra, 186);
						printf("%cJogador 2: %s, Letra: %c\t\t    %c\n",186, jogador[1].nome, jogador[1].letra, 186);
						printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
						printf("%c\t\tPartida %d/4\t\t    %c\n",186,qtdPartidas+1,186);

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
							int t;
							printf("%c",201);
							for(t = 0; t < 43; t++){
								printf("%c",205);
							}
							printf("%c",187);
							printf("\n%c\t\tJOGO DA VELHA\t\t    %c\n",186,186);
							printf("%c",204);
							for(t = 0; t < 43; t++){
								printf("%c",205);
							}
							printf("%c",185);
							printf("\n%cJogador 1: %s, Letra: %c\t\t    %c\n",186, jogador[0].nome, jogador[0].letra, 186);
							printf("%cJogador 2: %s, Letra: %c\t\t    %c\n",186, jogador[1].nome, jogador[1].letra, 186);
							printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
							printf("%c\t\tPartida %d/4\t\t    %c\n",186,qtdPartidas+1,186);
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
	int t;
	for(t = 0; t < 45; t++){
		printf("%c",205);
	}
	printf("\n\t\t  RELATORIO\t\t    \n");
	for(t = 0; t < 45; t++){
		printf("%c",205);
	}
	printf("\n");
	int i;
	for(i=0;i<2;i++){
		printf("Vitoria(s) de %s: %d\n",jogador[i].nome,jogador[i].vitoria);
	}
	printf("Empate(s): %d\n\n", *empate);
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
		printf("Jogador %d: ", i+1);
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
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("%c",186);
	printf("\t\t   1   2   3\t\t    %c\n",186);
	for(i=0;i<3;i++){
        printf("%c",186);
		printf("\t\t%d ", i+1);
		for(j=0;j<3;j++){
			if(j==2){
				printf(" %c \t\t    %c",tabuleiro[i][j],186);
				printf("\n");
				if(i!=2){
					printf("%c\t\t  -----------               %c",186,186);
                    printf("\n");
				}
			}else{
				printf(" %c |",tabuleiro[i][j]);
			}//fim else
		}//fim for do J
	}//fim do for do I
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}//fim mostrarMatriz
