void loopMais(char letra, int posicao) { // Cria o efeito das letras percorrerem de baixo até o centro da tela.
	int i;
	for(i=0; i<9; i++) {
		gotoxy(posicao,3+i);
		printf("%c", letra);
		Sleep(50);
		gotoxy(posicao,3+i);
		printf(" ");
	}
	gotoxy(posicao,12);
	printf("%c", letra);
}
void loopMenos(char letra, int posicao) { // Cria o efeito das letras percorrerem de baixo até o centro da tela.
	int i;
	for(i=0; i<9; i++) {
		gotoxy(posicao,20-i);
		printf("%c", letra);
		Sleep(30);
		gotoxy(posicao,20-i);
		printf(" ");
	}
	gotoxy(posicao,12);
	printf("%c", letra);
}
void bordaVitoria() {  // Desenha e cria um efeito da borda.
	int i;
	for (i=0; i<43; i++) {
		gotoxy(25+i,10);
		printf("%c",205);
		Sleep(30);
		gotoxy(25+i,14);
		printf("%c",205);
	}
}
void desenharVitoria(void) { // A cada letra da há um loop que traz a letra de cima para o meio ou de baixo para o meio.
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	loopMais(86,30);  // V
	loopMenos(79,33); // O
	loopMais(67,36);  // C
	loopMenos(69,39); // E
	
	loopMais(86,45);  // V
	loopMenos(69,48); // E
	loopMais(78,51);  // N
	loopMenos(67,54); // C
	loopMais(69,57);  // E
	loopMenos(85,60); // U
	loopMais(33,63);  // !
	bordaVitoria();
	SetConsoleTextAttribute(hConsole, corNormal);
}
void desenharDerrota(void) {
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	loopMais(86,30);  // V
	loopMenos(79,33); // O
	loopMais(67,36);  // C
	loopMenos(69,39); // E
	loopMais(80,45);  // P
	
	loopMenos(69,48); // E
	loopMais(82,51);  // R
	loopMenos(68,54); // D
	loopMais(69,57);  // E
	loopMenos(85,60); // U
	loopMais(33,63);  // !
	bordaVitoria();
	SetConsoleTextAttribute(hConsole, corNormal);
}
void lerStringSeguramente(char* palavra, int tamanho) { // Remove o \n da palavra.
	fflush(stdin);
	if(fgets(palavra, tamanho, stdin) != NULL) {
		/* Remove a nova linha (\n), caso ela tenha sido lida pelo fgets */
		int indiceUltimoCaractere = strlen(palavra) - 1;
		if(palavra[indiceUltimoCaractere] == '\n') {
			palavra[indiceUltimoCaractere] = '\0';
		}
		fflush(stdin);
	}
}
int contarLetras(char* palavra) { //Conta quantas letras com a função isalpha existem na palavra e retorna a quantidade de letras.
	int i, quantidadeLetras=0;
	for(i=0; i<strlen(palavra); i++) {
		if(isalpha(palavra[i])) {
			quantidadeLetras++;
		}
	}
	return quantidadeLetras;
}
int ehLetraOuEspaco(char* palavra) { // Verifica se a palavra possui espaço ou letras (isalpha) e retorna 0 caso tenha outro tipo de caractere.
	int i;
	for(i=0; i<strlen(palavra); i++) {
		if(palavra[i] != ' ' && !isalpha(palavra[i])) {
			return 0;
		}
	}
	return 1;
}
void bordaJogoPrincipal(void) { // Cria as bordas laterais, superiores e inferiores.
	int contador;
	SetConsoleTextAttribute(hConsole, 0x08);
	for(contador = 2; contador < 23; contador++) { 
		gotoxy(16,contador);
		printf("%c",186);
		gotoxy(72,contador);
		printf("%c",186);
		gotoxy(72,1);
		printf("%c",187);
		gotoxy(16,1);
		printf("%c",201);
	}
	for(contador = 17; contador < 72; contador++) {
		gotoxy(contador, 1);
		printf("%c",205);
		gotoxy(contador,23);
		printf("%c",205);
		gotoxy(72,23);
		printf("%c",188);
		gotoxy(16,23);
		printf("%c",200);
	}
	SetConsoleTextAttribute(hConsole, corNormal);
}
void imprimirCoracoes(int coracoes) { // Cria um espaçamento e os corações.
	int i;
	for(i=0; i<6*2; i+=2) { // Cria um espaçamento entre os corações para que não fiquem agrupados.
		gotoxy(59 + i,3);
		printf(" ");
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	for (i = 0; i < coracoes * 2; i+=2) {
		gotoxy(59 + i,3);
		printf("%c",3);
	}
	SetConsoleTextAttribute(hConsole, corNormal);
}
void desenharCabeca() {
	gotoxy(27,11);
	printf("%c",2);
}
void desenharCorpo() {
	gotoxy(27,12);
	printf("%c",178);	
}
void desenharBracoEsquerdo() {
	gotoxy(26,12);
	printf("%c",47);
}
void desenharBracoDireito() {
	gotoxy(28,12);
	printf("%c",92);
}
void desenharPernaEsquerda() {
	gotoxy(26,13);
	printf("%c",47);
}
void desenharPernaDireita() {
	gotoxy(28,13);
	printf("%c",92);
}
void vida(int vidasRestantes) { // Chama a função de criar corações e desenha partes do boneco de acordo com a quantidade de vidas restantes.
	imprimirCoracoes(vidasRestantes);
	gotoxy(53,3);
	printf("VIDAS");
	switch (vidasRestantes) {
		case 5: {
			desenharCabeca();
			break;
		}
		case 4: {
			desenharCabeca();
			desenharCorpo();
			break;
		}
		case 3: {
			desenharCabeca();
			desenharCorpo();
			desenharBracoEsquerdo();
			break;
		}
		case 2: {
			desenharCabeca();
			desenharCorpo();
			desenharBracoEsquerdo();
			desenharBracoDireito();
			break;
		}
		case 1: {
			desenharCabeca();
			desenharCorpo();
			desenharBracoEsquerdo();
			desenharBracoDireito();
			desenharPernaEsquerda();
			break;
		}
		case 0: {
			desenharCabeca();
			desenharCorpo();
			desenharBracoEsquerdo();
			desenharBracoDireito();
			desenharPernaEsquerda();
			desenharPernaDireita();
			break;
		}
	}
}
void desenharForca(void) {
	int i;
	for (i=0; i<8; i++) {		// Desenha a base da forca.
		gotoxy(20 + i,18);
		printf("%c",205);
	}
	gotoxy(22,18);
	printf("%c",202);			// Desenha o centro da base.
	for (i=0; i<8; i++) {		// Desenha corpo da forca.
		gotoxy(22,17-i);
		printf("%c",186);
	}
	gotoxy(22, 9);
	printf("%c",201);			// Desenha quina de cima.
	for (i=0; i<4; i++) {		// Desenha base de cima.
		gotoxy(23+i, 9);
		printf("%c",205);
	}
	gotoxy(27, 9);
	printf("%c",187);			// Desenha quina da forca.
	gotoxy(27, 10);
	printf("%c",179);			// Desenha o laço da forca.
}
void desenharGrama(void) {
	int contador;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	for (contador = 0; contador < 55; contador++) {
		gotoxy(17+contador, 18);
		printf("%c",176);
		gotoxy(17+contador, 19);
		printf("%c",176);
		gotoxy(17+contador, 20);
		printf("%c",176);
		gotoxy(17+contador, 21);
		printf("%c",176);
		gotoxy(17+contador, 22);
		printf("%c",176);
	}
	SetConsoleTextAttribute(hConsole, corNormal);
}
void desenharLacuna(char* palavra) { // Desenha uma lacuna ou espaço, caso a palavra tenha espaço, de acordo com o tamanho da palavra.
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		gotoxy(29+i*2,16);
		printf("%c", palavra[i] == ' ' ? 255 : 95); // Caso a letra na posição [i] da palavra seja espaço, desenha espaço, senão, desenha uma lacuna.
	}
}
void revelarLetraLacuna(char* palavra, char letraAcertada) {
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		if (letraAcertada == palavra[i]) {
			gotoxy(29+i*2,16);
			printf("%c", letraAcertada);
		}
	}
}
void revelarPalavraLacuna(char* palavra) {
	int i;
	for (i = 0; i < strlen(palavra); i++) {
			gotoxy(29+i*2,16);
			printf("%c", palavra[i]);
			Sleep(30);
		}
	}
int verificarAcertos(char* palavra, char* acertos) {
	int i, j;
	for (i=0; i<strlen(palavra); i++) {  // Cria um loop para varrer cada letra de palavra.
		int encontrou = 0;
		for(j=0; j<strlen(acertos); j++) { // Cria um loop para varrer cada letra de acertos.
			if(palavra[i] == acertos[j]) { // Verifica se a letra em palavra é igual à letra em acertos.
				encontrou = 1; // Retorna 1 caso tenha alguma letra igual, e recomeça o loop até verificar todas as letras.
			}
		}
		if(encontrou == 0 && palavra[i] != ' ') { // Caso não exista uma letra ou ela não seja um espaço, retorna 0.
			return 0;
		}
	}
	return 1; // Retorna 1 quando todas as letras em acertos compõem palavra (o jogador venceu).
}
void paraMaiusculo(char* palavraParaMudar) { // Passa a palavra para maiúsculo.
	int i;
	for(i = 0; i < strlen(palavraParaMudar); i++) {
		palavraParaMudar[i] = toupper(palavraParaMudar[i]);
	}
}
void desenharDicaNome(char* dica, char* nome) {
	gotoxy(40,6);
	printf("DICA:");
	gotoxy(46,6);
	printf("%s", dica);
	gotoxy(20,3);
	printf("%s", nome);
}
void desenharGrafico(char* palavra,char* dica,char* nome) { // Desenha creditos, borda, grama, forca, lacuna, nome e dica.
	limpaTela();
	imprimeCreditos();
	bordaJogoPrincipal();
	desenharGrama();
	desenharForca();
	desenharLacuna(palavra);
	desenharDicaNome(dica, nome);
	vida(VIDA_TOTAL);
}
int palavraTemLetra(char letra, char* palavra) { // Verifica se a palavra tem a letra coletada dentro do jogo e inicia a função de verificação.
	int i;
	for (i = 0 ; i < strlen(palavra); i++) {
		if (letra == palavra[i]) {
			return 1;
		}
	}
	return 0;
}
void tentativas(char* palavra) { /**************************** O processamento do jogo está localizado aqui***********************************/
	char historicoErros[6], acertos[15];
	int quantidadeErros = 0, quantidadeAcertos = 0;
	do {
		gotoxy(40,10);
		printf("Pressione uma letra:");
		gotoxy(61,10);
		letraColetada = getch();
		if (isalpha(letraColetada)) { // Verificar se o caracter é uma letra do alfabeto.
			gotoxy(40,12);
			printf("                           "); // Limpa a mensagem de informação para o usuário.
			letraColetada = toupper(letraColetada);
			gotoxy(61,10);
			printf("%c", letraColetada);
			if(palavraTemLetra(letraColetada, historicoErros)) { //Verifica se a letra digitada ja foi errada/acertada.
				gotoxy(40,12);
				printf("Esta letra j%c foi tentanda!", 160);
			} else if (palavraTemLetra(letraColetada, acertos)) {
				gotoxy(40,12);
				printf("Esta letra j%c foi tentanda!", 160);
			} else { //Verifica se a letra digitada é correta e revela a letra na lacuna.
				if(palavraTemLetra(letraColetada, palavra)) { // Verifica se a palavra contém letra ou caracter inválido.
					acertos[quantidadeAcertos] = letraColetada;
					quantidadeAcertos++;
					gotoxy(40,12);
					printf("                             "); // Limpa a mensagem de informação para o usuário.
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					gotoxy(40,12);
					printf("Voc%c acertou!", 136);
					SetConsoleTextAttribute(hConsole, corNormal);
					revelarLetraLacuna(palavra, letraColetada);
				} else { //Salva letra errada em historicoErros e tira uma vida.
					historicoErros[quantidadeErros] = letraColetada;
					quantidadeErros++;
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					gotoxy(40,12);
					printf("Voc%c errou!", 136);
					gotoxy(39+ (quantidadeErros > 0 ? quantidadeErros * 2 : 1), 14); // Desenha a letra errada nada tela do usuário e da um espaço entre as letras.
					printf("%c", toupper(letraColetada));
					SetConsoleTextAttribute(hConsole, corNormal);
					VIDA_TOTAL -= 1; // Retira uma vida do usuário.
					vida(VIDA_TOTAL); // Desenha a vida atual do usuário.
				}
			}
		} else { // Caso seja um caracter inválido, retorna uma mensagem de erro.
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			gotoxy(40,12);
			printf("Pressione somente letras!");
			SetConsoleTextAttribute(hConsole, corNormal);
		}
	} while(verificarAcertos(palavra, acertos) == 0 && VIDA_TOTAL > 0); // Condição para terminar o jogo caso o usuário ganhar ou perder.
	// Caso o usuário ganhar, será desenhado o gráfico de vitória, senão, gráfico de derrota.
	if(verificarAcertos(palavra, acertos) == 1) { 
		gotoxy(40,12);
		printf("                "); // Limpa as letras que o usuário errou para desenhar o efeito de vitória/derrota.
		desenharVitoria();			  
		vida(VIDA_TOTAL); // Arruma a destruição que o effeito de vitória/derrota causo ao jogo. 
		desenharGrama();  // Arruma a destruição que o effeito de vitória/derrota causo ao jogo. 
		desenharForca();  // Arruma a destruição que o effeito de vitória/derrota causo ao jogo.                                	
		revelarPalavraLacuna(palavra); // Arruma a destruição que o effeito de vitória/derrota causo ao jogo. 
	} else if(!VIDA_TOTAL > 0) {
		gotoxy(40,12);
		printf("                "); // Limpa as letras que o usuário errou para desenhar o efeito de vitória/derrota.
		desenharDerrota();
		vida(VIDA_TOTAL); // Arruma a destruição que o effeito de vitória/derrota causo ao jogo. 
		desenharGrama(); // Arruma a destruição que o effeito de vitória/derrota causo ao jogo. 
		desenharForca(); // Arruma a destruição que o effeito de vitória/derrota causo ao jogo.    
		revelarPalavraLacuna(palavra); // Arruma a destruição que o effeito de vitória/derrota causo ao jogo. 
	}
}
void coletarPalavraSecreta(char* palavra) {
	int palavraSecretaValida;
	gotoxy(30,10);
	printf("Escreva uma palavra:");
	do {
		gotoxy(51,10);
		lerStringSeguramente(palavra, 17);
		if(ehLetraOuEspaco(palavra)) { //Verifica se a palavra tem espaço e letra, senão informa o erro.
			if (contarLetras(palavra) > 15) { // Limita a quantidade máxima de letras que a palavra pode ter.
				gotoxy(51,10);
				printf("                     "); // Limpa a informação da palavra anterior.
				gotoxy(30,12);
				printf("                              "); // Limpa a informação de aviso anterior.
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				gotoxy(30,12);
				printf("Nao ultrapasse 15 letras!");
				SetConsoleTextAttribute(hConsole, corNormal);
				palavraSecretaValida = 0;
			} else if(contarLetras(palavra) < 2) { // Limita a quantidade mínima de letras que a palavra pode ter.
				gotoxy(51,10);
				printf("                     "); // Limpa a informação da palavra anterior.
				gotoxy(30,12);
				printf("                              "); // Limpa a informação de aviso anterior.
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				gotoxy(30,12);
				printf("No m%cnimo duas letras!", 161);
				SetConsoleTextAttribute(hConsole, corNormal);
				palavraSecretaValida = 0;
			} else { // Informa que a palavra foi salva com sucesso.
				gotoxy(51,10); 
				printf("                     "); // Limpa a informação da palavra anterior.
				gotoxy(30,12);
				printf("                              "); // Limpa a informação de aviso anterior.
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				gotoxy(30,12);
				printf("Nome salvo com sucesso!");
				SetConsoleTextAttribute(hConsole, corNormal);
				palavraSecretaValida = 1;
			}
		} else { // Informa que a palavra não pode ter caracteres especiais.
			gotoxy(51,10);
			printf("                     "); // Limpa a informação da palavra anterior.
			gotoxy(30,12);
			printf("                              "); // Limpa a informação de aviso anterior.
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			gotoxy(30,12);
			printf("Digite somente letras sem acento!");
			SetConsoleTextAttribute(hConsole, corNormal);
			palavraSecretaValida = 0;
		}
	} while(!palavraSecretaValida);
	paraMaiusculo(palavra);
}
char coletarDicaPalavraSecreta(char* dica) { // Mesma função para palavraSecreta.
	int palavraSecretaValida;
	gotoxy(30,14);
	printf("Escreva uma dica:");
	do {
		gotoxy(48,14);
		lerStringSeguramente(dica, 12);
		if(ehLetraOuEspaco(dica)) {
			if (contarLetras(dica) > 10) {
				gotoxy(48,14);
				printf("                       ");
				gotoxy(30,16);
				printf("                              ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				gotoxy(30,16);
				printf("Nao ultrapasse 10 digitos!");
				SetConsoleTextAttribute(hConsole, corNormal);
				palavraSecretaValida = 0;
			} else if(contarLetras(dica) < 2) {
				gotoxy(48,14);
				printf("                       ");
				gotoxy(30,16);
				printf("                              ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				gotoxy(30,16);
				printf("No m%cnimo duas letras!", 161);
				SetConsoleTextAttribute(hConsole, corNormal);
				palavraSecretaValida = 0;
			} else {
				gotoxy(48,14);
				printf("                       ");
				gotoxy(30,16);
				printf("                              ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				gotoxy(30,16);
				printf("Nome salvo com sucesso!");
				SetConsoleTextAttribute(hConsole, corNormal);
				palavraSecretaValida = 1;
			}
		} else {
			gotoxy(48,14);
			printf("                       ");
			gotoxy(30,16);
			printf("                              ");
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			gotoxy(30,16);
			printf("Digite somente letras!");
			SetConsoleTextAttribute(hConsole, corNormal);
			palavraSecretaValida = 0;
		}
	} while(!palavraSecretaValida);
	paraMaiusculo(dica);
}
char coletarNomeJogador(char* nome) { // Mesma função para palavraSecreta.
	int palavraSecretaValida;
	gotoxy(30,6);
	printf("Digite o seu nome:");
	do {
		gotoxy(49,6);
		lerStringSeguramente(nome, 13);
		if(ehLetraOuEspaco(nome)) {
			if (contarLetras(nome) > 10) {
				gotoxy(49,6);
				printf("                       ");
				gotoxy(30,8);
				printf("                              ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				gotoxy(30,8);
				printf("Nao ultrapasse 10 digitos!");
				SetConsoleTextAttribute(hConsole, corNormal);
				palavraSecretaValida = 0;
			} else if(contarLetras(nome) < 2) {
				gotoxy(49,6);
				printf("                       ");
				gotoxy(30,8);
				printf("                              ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				gotoxy(30,8);
				printf("No m%cnimo duas letras!", 161);
				SetConsoleTextAttribute(hConsole, corNormal);
				palavraSecretaValida = 0;
			} else {
				gotoxy(49,6);
				printf("                       ");
				gotoxy(30,8);
				printf("                              ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				gotoxy(30,8);
				printf("Nome salvo com sucesso!");
				SetConsoleTextAttribute(hConsole, corNormal);
				palavraSecretaValida = 1;
			}
		} else {
			gotoxy(49,6);
			printf("                       ");
			gotoxy(30,8);
			printf("                              ");
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			gotoxy(30,8);
			printf("Digite somente letras!");
			SetConsoleTextAttribute(hConsole, corNormal);
			palavraSecretaValida = 0;
		}
	} while(!palavraSecretaValida);
	paraMaiusculo(nome);
}
void sairOuContinuar(){ // Fornece ao usuário a opção de continuar ou sair usando um menu padrão.
	Sleep(4000);
	imprimeCreditos();
	limpaTela();
	bordaJogoPrincipal();
	int  opcao = 0;
	do {
		opcao = 0;
		int posicaoDaLinha = 10, posicaoDaColuna = 10, posicaoDaSeta = 10, teclaPressionada;
		inicio:
		bordaJogoPrincipal();
		SetConsoleTextAttribute(hConsole, 0x05);
		gotoxy(33,3);
		printf("F I M   D O   J O G O");
		gotoxy(35,7);
		printf("Deseja Continuar");
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		gotoxy(40,10);
		printf("Sim");
		SetConsoleTextAttribute(hConsole, corNormal);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		gotoxy(40,13);
		printf("Nao");
		SetConsoleTextAttribute(hConsole, corNormal);
		SetConsoleTextAttribute(hConsole, corNormal);
		imprimeCreditos();
		do {
			opcao = 0;
			gotoxy(35,posicaoDaColuna);
			printf("  -%c",16); // Desenha uma seta para selecionar as opções do menu.
			gotoxy(1,22);
			teclaPressionada = getch();
			if(teclaPressionada == TECLA_SETA_BAIXO) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha += 3 ;
				posicaoDaSeta += 3;
				if(posicaoDaSeta > 13) {// Se posição da seta para baixo ultrapassar "Sim" (posição 13), retorna para a posição 7 (Jogar).
					posicaoDaSeta = 10;
					posicaoDaLinha = 10;
				}
			}
			if(teclaPressionada == TECLA_SETA_CIMA) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha -= 3;
				posicaoDaSeta -= 3;
				if(posicaoDaSeta < 10) {// Se a posição da seta para cima ultrapassar "Nao" (posição 10), retorna para a posição 16 (Sair).
					posicaoDaSeta = 13;
					posicaoDaLinha = 13;
				}
			}
			if(posicaoDaLinha != posicaoDaColuna) {// Limpa as setas (quando movimentadas).
				gotoxy(35,posicaoDaColuna);
				printf("     ");
				posicaoDaColuna = posicaoDaLinha;
			}
			if(teclaPressionada == TECLA_ENTER) {
				opcao = posicaoDaSeta;
			}
		} while(opcao == 0);
		switch (opcao) {
			case 10: {
				VIDA_TOTAL = 6;
				menuSelecionavel();
				break;
			}
			case 13: {
				gotoxy(0,24);
				exit(0);				
				break;
			}
			default: {
				printf("Você deve escolher uma opção válida\n");
				printf("Precione qualquer tecla para voltar ao menu.\n");
				getch();
				goto inicio;
				break;
			}
		}
	}while(opcao != 4);
}
void jogoForca() { // Banco de Dados do jogo da forca e gráficos.
	char nome[10], palavra[15], dica[15];
	limpaTela();
	imprimeCreditos();
	bordaJogoPrincipal();
	gotoxy(35,3);
	printf("B E M - V I N D O");
	coletarNomeJogador(nome);
	coletarPalavraSecreta(palavra);
	coletarDicaPalavraSecreta(dica);
	Sleep(500);
	desenharGrafico(palavra, dica, nome);
	tentativas(palavra);
}
void menuSelecionavel(void) { // Menu padrão explicado em outra parte do programa.
	int  opcao = 0;
	limpaTela();
	imprimeCreditos();
	do {
		opcao = 0;
		int posicaoDaLinha = 7, posicaoDaColuna = 7, posicaoDaSeta = 7, teclaPressionada;
		inicio:
		bordaJogoPrincipal();
		SetConsoleTextAttribute(hConsole, 0x05);
		gotoxy(32,3);
		printf("M E N U   D O  J O G O ");
		gotoxy(33,7);
		printf("JOGAR CONTRA MAQUINA");
		gotoxy(33,10);
		printf("JOGAR CONTRA AMIGO");
		gotoxy(33,13);
		printf("VOLTAR");
		SetConsoleTextAttribute(hConsole, corNormal);
		imprimeCreditos();
		do {
			opcao = 0;
			gotoxy(28,posicaoDaLinha);
			printf("  -%c",16); 
			gotoxy(1,22);
			teclaPressionada = getch();
			if(teclaPressionada == TECLA_SETA_BAIXO) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha += 3 ;
				posicaoDaSeta += 3;
				if(posicaoDaSeta > 13) {
					posicaoDaSeta = 7;
					posicaoDaLinha = 7;
				}
			}
			if(teclaPressionada == TECLA_SETA_CIMA) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha -= 3;
				posicaoDaSeta -= 3;
				if(posicaoDaSeta < 7) {	
					posicaoDaSeta = 13;
					posicaoDaLinha = 13;
				}
			}
			if(posicaoDaLinha != posicaoDaColuna) { 
				gotoxy(27,posicaoDaColuna);
				printf("     ");
				posicaoDaColuna = posicaoDaLinha;
			}
			if(teclaPressionada == TECLA_ENTER) {
				opcao = posicaoDaSeta;
			}
		} while(opcao == 0);
		switch (opcao) {
			case 7: {
				gotoxy(33,7);
				limpaTela();
				imprimeCreditos();
				bordaJogoPrincipal();
				gotoxy(30,3);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				printf("V e r s u s   M a c h i n e");
				SetConsoleTextAttribute(hConsole, corNormal);
				gotoxy(40,7);
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				printf("Aguarde!!");
				gotoxy(25,12);
				printf("Esta modalidade ficara disponivel em breve!");
				SetConsoleTextAttribute(hConsole, corNormal);
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				limpaTela();
				break;
			}
			case 10: {
				jogoForca();
				sairOuContinuar();
				break;
			}
			case 13: {
				menuPrincipal();
				break;
			}
			default: {
				printf("Você deve escolher uma opção válida\n");
				printf("Precione qualquer tecla para voltar ao menu.\n");
				getch();
				goto inicio;
				break;
			}
		}
	}while(opcao != 4);
}
void jogoPrincipal(void) { // Função principal do jogo.
	menuSelecionavel();
}
