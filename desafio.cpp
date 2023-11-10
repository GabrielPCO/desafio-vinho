// -------------------------------
// |         Criado por          |
// |        Gabriel Paez         |
// | gabrielpcoliveira@gmail.com |
// -------------------------------

// Bibliotecas
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include "desafio.h"
using namespace std;

// Função para impressão dos textos no console
void printText(int x,int y, bool fline, string message){
	if(x>0){
		while(x>0){
			cout << endl;
			x--;
		}
	}

	if(message != ""){
		cout << message;
	}

	if(y>0){
		while(y>0){
			cout << endl;
			y--;
		}
	}

	if(fline){
		cout << flush;
	}
}

// Função de classifica a cobaia como viva (X) ou morta (O)
char classCob(std::vector<int> cob, int randNum){
	for(int i=0; i<=cob.size(); i++){
			if(cob[i] == randNum){
				return 'X';
			}
		}
	return 'O';
}

// Função do jogo
void rodarJogo(){

	int pontos = 0;

	// Inicio do jogo
	while(1){

		// Limpando o terminal
		system("clear");

		if(pontos<=2){

			// Título inicial
			printText(3,0, false, "");
			printText(0,1, false, titulo_01);
			printText(0,1, false, titulo_02);
			printText(0,1, false, titulo_03);
			printText(0,1, false, titulo_04);
			printText(0,1, false, titulo_05);
			printText(3,0, false, "");

		} else {

			// Título secreto
		    	printText(0,1, false, titulo_06);
			printText(0,1, false, titulo_07);
			printText(0,1, false, titulo_08);
			printText(0,1, false, titulo_09);
			printText(0,1, false, titulo_10);
			printText(0,1, false, titulo_11);
			printText(0,1, false, titulo_12);
			printText(0,1, false, titulo_13);
			printText(0,1, false, titulo_14);
			printText(0,1, false, titulo_15);
			printText(0,1, false, titulo_16);

		}

		// Aguarda o jogador pressionar [ENTER]
		printText(1,0, true, sistema_01);
		system("read continue");
		system("clear");

		// Valor de Seed
		srand((unsigned) time(NULL));

		// Criando um número randômico entre 1 e 8
		int randomNumber = 1 + (rand() % 8);

		// Imprimindo as regras do desafio
		printText(0,2, false, inst_01);
		printText(0,1, false, inst_02);
		printText(0,1, false, inst_03);
		printText(0,1, false, inst_04);
		printText(0,2, false, inst_05);
		printText(0,1, false, inst_06);
		printText(0,1, false, inst_07);
		printText(0,1, false, inst_08);
		printText(0,2, false, inst_09);
		printText(0,1, false, inst_10);

		// Aguarda o jogador pressionar [ENTER]
		printText(1,0, true, sistema_01);
                system("read continue");
                system("clear");

		// Variáveis do programa
		const int MAXVINHO = 8, MAXCOBAIA = 3;
		int count = 0, TOTAL = MAXVINHO*MAXCOBAIA;
		int respostaUsuario;
		bool invalido = true;
		bool pVez = true;
		bool error = false;
		char jogarDeNovo;
		char cob1, cob2, cob3;

		std::vector<int> cob1Vec;
		std::vector<int> cob2Vec;
		std::vector<int> cob3Vec;

		// Escolhendo quais garrafas cada cobaia irá beber
		for(int x=0; x<MAXCOBAIA; x++){
			while(invalido){

				char numGarrafa[100] = {'\n'};
				while(numGarrafa[0] == '\n'){
					system("clear");

					printText(0,1, false, garrafa_01);
					printText(0,1, false, garrafa_02);
					printText(0,1, false, garrafa_03);
					printText(0,1, false, garrafa_04);
					printText(0,1, false, garrafa_05);
					printText(0,2, false, garrafa_06);
					printText(0,0, false, jogo_01);
					cout << x+1;
					printText(0,1, false, jogo_02);
					printText(0,1, false, sistema_04);

					if(error && !pVez){
                                                printText(1,1, false, sistema_03);
                                        }

					fgets(numGarrafa,100,stdin);

				}

				// separa o input do jogador na presença de espaço na string
				char * token = strtok(numGarrafa, " ");

				invalido=false;
				pVez=false;

				// Verifica se os inputs do jogador são validos e os adiciona ao vetor das cobaias, respectivamente
				switch(x){
					case 0:
						while(token != NULL){
							try {
								if(stoi(token) >= 1 && stoi(token) <= 8){
									cob1Vec.push_back(stoi(token));
									error=false;
								}else{
									cob1Vec.empty();
									invalido=true;
									error=true;
									break;
								}
							}catch(...){
								cob1Vec.empty();
								invalido=true;
								error=true;
								break;
							}
							token = strtok(NULL, " ");
						}
						break;
					case 1:
						while(token != NULL){
							try {
								if(stoi(token) >= 1 && stoi(token) <= 8){
									cob2Vec.push_back(stoi(token));
									error=false;
								}else{
									cob2Vec.empty();
									invalido=true;
									error=true;
									break;
								}
							}catch(...){
								cob2Vec.empty();
								invalido=true;
								error=true;
								break;
							}
							token = strtok(NULL, " ");
						}
						break;
					case 2:
						while(token != NULL){
							try {
								if(stoi(token) >= 1 && stoi(token) <= 8){
									cob3Vec.push_back(stoi(token));
									error=false;
								}else{
									cob3Vec.empty();
									invalido=true;
									error=true;
									break;
								}
							}catch(...){
								cob3Vec.empty();
								invalido=true;
								error=true;
								break;
							}
							token = strtok(NULL, " ");
						}
						break;
					default:
						printText(0,0, true, sistema_02);
				}
			}

			invalido=true;

		}

		// Verifica se a cobaia 1 bebeu o vinho envenenado
		cob1 = classCob(cob1Vec, randomNumber);

		// Verifica se a cobaia 2 bebeu o vinho envenenado
		cob2 = classCob(cob2Vec, randomNumber);

		// Verifica se a cobaia 3 bebeu o vinho envenenado
		cob3 = classCob(cob3Vec, randomNumber);

		// Apresenta as cobaias ao jogador
		while(1){

			system("clear");
			printText(0,1, false, resposta_01);
			printText(0,2, false, resposta_02);
			cout << "	   " << cob1 << "  " << cob2 << "  " << cob3 << endl;
			printText(0,0, true, resposta_03);
			printText(0,2, true, resposta_04);
			printText(0,0, true, resposta_05);
			if(error){
				printText(2,1, false, sistema_05);
			}
			char input[2];
			fgets(input, 2, stdin);
			try{
				respostaUsuario = stoi(input);
			} catch(...) {
				respostaUsuario=-1;
			}

			if(respostaUsuario >= 1 && respostaUsuario <= 8){
				error=false;
				break;
			}

			error=true;

		}

		// Exibe o resultado do jogo
		system("clear");

		if(respostaUsuario==randomNumber){

			// Imprimindo a garrafa envenenada
			cout << " __" << endl;
			cout << " ||" << endl;
			cout << "/  \\" << endl;
			cout << "|" << randomNumber << "ª|" << endl;
			cout << "|  |" << endl;
			cout << "|__|" << endl << endl;

			printText(0,0, false, resultado_01);
			cout << randomNumber;
			printText(0,2, false, resultado_02);

			if(pontos>=2){

				if(pontos==2){
					pontos+=1;
				}

				//Mensagem de vitória total
				printText(0,1, false, resultado_03);
				printText(0,1, false, resultado_04);
				printText(0,1, false, resultado_05);
				printText(0,1, false, resultado_06);
				printText(0,1, false, resultado_03);

			} else {

				pontos+=1;

				// Mensagem de vitória parcial
				printText(0,1, false, resultado_07);
				printText(0,1, false, resultado_08);
				printText(0,1, false, resultado_09);
				printText(0,0, false, resultado_10);
				cout << pontos;
				printText(0,1, false, resultado_11);
				printText(0,1, false, resultado_07);
			}

		}else {

			if(pontos>0 && pontos<=2){
				pontos=0;
			}

			// Mensagem de fracasso
			printText(0,2, false, resultado_12);
			printText(0,1, false, resultado_13);
			printText(0,1, false, resultado_14);
			printText(0,1, false, resultado_15);
			printText(0,1, false, resultado_16);
			printText(0,0, false, resultado_10);
			cout << pontos;
			printText(0,1, false, resultado_17);
			printText(0,1, false, resultado_13);
		}

		// Pergunta se o jogador quer realizar uma nova partida
		printText(1,1, false, sistema_06);
		getchar();
		scanf("%c", &jogarDeNovo);

		// Se não, o jogo encerra
		if(jogarDeNovo == 's' || jogarDeNovo == 'S'){
                	continue;
		} else {
			system("clear");
                        break;
		}

	}

	// Créditos e mensagem de agradecimento
	system("clear");

	printText(0,1, false, sistema_08);
        printText(0,1, false, sistema_07);
        printText(0,1, false, sistema_08);
	printText(0,1, false, creditos_01);
	printText(0,1, false, creditos_02);
	printText(0,1, false, creditos_03);
	printText(0,1, false, creditos_04);
	printText(0,2, false, creditos_01);
	exit(EXIT_SUCCESS);

}

// Função principal
int main(){
	#ifdef  __linux__
		rodarJogo();
	#elif __APPLE__
		#include "TargetConditionals.h"
		#ifdef TARGET_OS_MAC
			rodarJogo();
		#else
			printText(0,2, false, sistema_09);
                	exit(EXIT_FAILURE);
		#endif
	#else
		printText(0,2, false, sistema_09);
		exit(EXIT_FAILURE);
	#endif
}
