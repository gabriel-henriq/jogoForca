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
		int teclaPressionada;
		opcao = 0;
		int posicaoDaLinha = 7, posicaoDaColuna = 7, posicaoDaSeta = 7; // Manipula a localização do ponteiro na tela.
		inicio: // Saída do comando 'goto', para voltar ao início do menu.
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
			printf("  -%c",16); // Desenha uma seta para selecionar as opções do menu.
			gotoxy(1,22);
			teclaPressionada = getch();
			if(teclaPressionada == TECLA_SETA_BAIXO) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha += 3 ;
				posicaoDaSeta += 3;
				if(posicaoDaSeta > 16) {// Se posição da seta para baixo ultrapassar "Sair" (posição 16), retorna para a posição 7 (Jogar).
					posicaoDaSeta = 7;
					posicaoDaLinha = 7;
				}
			}
			if(teclaPressionada == TECLA_SETA_CIMA) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha -= 3;
				posicaoDaSeta -= 3;
				if(posicaoDaSeta < 7) {	// Se a posição da seta para cima ultrapassar "Jogar" (posição 7), retorna para a posição 16 (Sair).
					posicaoDaSeta = 16;
					posicaoDaLinha = 16;
				}
			}
			if(posicaoDaLinha != posicaoDaColuna) { // Limpa as setas (quando movimentadas).
				gotoxy(35,posicaoDaColuna);
				printf("     ");
				posicaoDaColuna = posicaoDaLinha;
			}
			if(teclaPressionada == TECLA_ENTER) {
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
				gotoxy(40,7);
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				printf("Aguarde!!");
				gotoxy(25,12);
				printf("Esta funcao ficara disponivel em breve!");
				SetConsoleTextAttribute(hConsole, corNormal);
				
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 13:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(40,3);
				printf("CREDITOS");
				
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 16:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(39,12);
				printf("Saindo");
				for(teclaPressionada = 0; teclaPressionada < 3; teclaPressionada++) {
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
