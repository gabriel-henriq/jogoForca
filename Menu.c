int TECLA_SETA_CIMA = 72, TECLA_SETA_BAIXO = 80, TECLA_ENTER = 13;
void limpaTela(void) {
	system("cls");
}
void imprimeCreditos(void) {
	SetConsoleTextAttribute(hConsole, 0x03);
	gotoxy(75,3);
	printf("Faculdades Integradas Camoes.");
	gotoxy(75,5);
	printf("An%clise e Desenvolvimento de Sistemas.", 160);
	gotoxy(75,7);
	printf("Disciplina %c Algoritmos e Programacao.", 196);
	gotoxy(75,9);
	printf("Professora: Rosemari Rattmann.");
	SetConsoleTextAttribute(hConsole, corNormal);
}
void apertaESC() {
	int pressionaTecla;
	do {
		if(kbhit) {
			pressionaTecla = getch();
		}
	} while(pressionaTecla != 27);
}
void bordasMenu(void) {
	int i;
	for(i = 2; i < 23; i++) { // Imprime as bordas laterais.
		SetConsoleTextAttribute(hConsole, 0x08);
		gotoxy(16,i);
		printf("%c",186);
		gotoxy(72,i);
		printf("%c",186);
		gotoxy(72,1);
		printf("%c",187);
		gotoxy(16,1);
		printf("%c",201);
	}
	for(i = 17; i < 72; i++) { // Imprime as bordas superiores e inferiores.
		gotoxy(i, 1);
		printf("%c",205);
		gotoxy(i,23);
		printf("%c",205);
		gotoxy(72,23);
		printf("%c",188);
		gotoxy(16,23);
		printf("%c",200);
	}
	SetConsoleTextAttribute(hConsole, corNormal);
}
void menuPrincipal(void) {
	int opcao = 0;
	do {
		int opcao = 0, pressionaTecla;
		int posicaoDaLinha = 7, posicaoDaColuna = 7, posicaoDaSeta = 7; 				// Manipula a localização do ponteiro na tela.
inicio: 																	// Saída do comando 'goto', para voltar ao início do menu.
		system("cls");
		bordasMenu();
		SetConsoleTextAttribute(hConsole, 0x05);
		gotoxy(32,3);
		printf("M E N U   P R I N C I P A L ");
		gotoxy(40,7);
		printf("JOGAR");
		gotoxy(40,10);
		printf("RANKING");
		gotoxy(40,13);
		printf("CREDITOS");
		gotoxy(40,16);
		printf("SAIR");
		SetConsoleTextAttribute(hConsole, corNormal);
		imprimeCreditos();
		gotoxy(15, 27);
		do {
			gotoxy(35,posicaoDaLinha);
			printf("  -%c",16); 													// Desenha uma seta para selecionar as opções do menu.
			gotoxy(1,22);
			if(kbhit) { 	   														// Kbhit pega a tecla que o usurário pressionar e retorna o seu valor em código (ASCII).
				pressionaTecla = getch();
			}
			if(pressionaTecla == TECLA_SETA_BAIXO) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha += 3 ;
				posicaoDaSeta += 3;
				if(posicaoDaSeta > 16) {												// Se posição da seta para baixo ultrapassar "Sair" (posição 16), retorna para a posição 7 (Jogar).
					posicaoDaSeta = 7;
					posicaoDaLinha = 7;
				}
			}
			if(pressionaTecla == TECLA_SETA_CIMA) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha -= 3;
				posicaoDaSeta -= 3;
				if(posicaoDaSeta < 7) {												// Se a posição da seta para cima ultrapassar "Jogar" (posição 7), retorna para a posição 16 (Sair).
					posicaoDaSeta = 16;
					posicaoDaLinha = 16;
				}
			}
			if(posicaoDaLinha != posicaoDaColuna) {    								// Limpa as setas (quando movimentadas).
				gotoxy(35,posicaoDaColuna);
				printf("     ");
				posicaoDaColuna = posicaoDaLinha;
			}
			if(pressionaTecla == TECLA_ENTER) {
				opcao = posicaoDaSeta;
			}
		} while(opcao == 0);
		switch(opcao) {
			case 7:
				jogoPrincipal();
				break;
			case 10:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(40,3);
				printf("RANKING");
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertaESC();
				break;
			case 13:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(40,3);
				printf("CREDITOS");
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertaESC();
				break;
			case 16:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(39,12);
				printf("Saindo");
				for(pressionaTecla = 0; pressionaTecla < 3; pressionaTecla++) {
					printf(".");
					Sleep(300);
				}
				gotoxy(36,12);
				printf("Ate a proxima!");
				gotoxy(0,24);
				exit(0);
			default:
				printf("Você deve escolher uma opção válida\n");
				printf("Precione qualquer tecla para voltar ao menu.\n");
				getch();
				goto inicio;
		}
	} while(opcao != 4);
}
