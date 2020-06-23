// Define cores das letras e fundo.
HANDLE hConsole;
WORD corNormal;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
// Define cores das letras e fundo.

void telaAbertura(void) {
	// Define cores das letras e fundo./ Define cores das letras e fundo.
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	corNormal = consoleInfo.wAttributes;
	// Define cores das letras e fundo.
	int linhaInicial = 3, colunaInicial = 23, recuperaLinhaInicial = linhaInicial, mudaLinha, imprimeLinhas, imprimeLetras, i, j;
	char nome[35] = {"Desenvolvido por: Gabriel Henrique"};
	int letras[11][7]= {
		{126, 32, 32, 32, 33, 18, 12},  // letra J
		{ 28, 34, 65, 65, 65, 34, 28},  // letra O
		{ 60, 66,  1,  1,113, 98, 92},  // letra G
		{ 28, 34, 65, 65, 65, 34, 28},  // letra O
		{ 31, 33, 65, 65, 65, 33, 31},  // letra D
		{ 28, 34, 65, 65,127, 65, 65},  // letra A
		{126,  1,  1,126,  1,  1,  1},  // letra F
		{ 28, 34, 65, 65, 65, 34, 28},  // letra O
		{ 30, 33, 33, 25, 17, 33, 65},  // letra R
		{126,  1,  1,  1,  1,  1,126},  // letra C
		{ 28, 34, 65, 65,127, 65, 65}   // letra A
	};
	imprimeCreditos();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	for(i = 2; i < 23; i++) { // Imprime as bordas laterais.
		Sleep(1); // Cria um efeito de desenho.
		gotoxy( 5,i);
		printf("%c",186);
		gotoxy(72,i);
		printf("%c",186);
		if (i == 7) {
			gotoxy(72,1);
			printf("%c",187);
		}
		if (i == 7) {
			gotoxy( 5,1);
			printf("%c",201);
		}
	}
	for(i = 6; i < 72; i++) { // Imprime as bordas superiores e inferiores.
		Sleep(1);
		gotoxy(i, 1);
		printf("%c",205);
		gotoxy(i,23);
		printf("%c",205);
		gotoxy(i,19);
		printf("%c",205);
		if (i == 7) {
			gotoxy(72,23);
			printf("%c",188);
		}
		if (i == 7) {
			gotoxy( 5,23);
			printf("%c",200);
		}
	}
	SetConsoleTextAttribute(hConsole, corNormal);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	for (i = 0; i < 11; i++) { // Conta até 11 para acessar todas as letras do array.
		Sleep(1);
		if(i == 4) {	// Muda 'Da' para baixo.
			linhaInicial = 11;
			colunaInicial = 10;
			recuperaLinhaInicial = linhaInicial;
		}
		if(i == 6) {	// Faz um espaço entre 'Da' e 'Forca'.
			linhaInicial = 11;
			colunaInicial = 30;
			recuperaLinhaInicial = linhaInicial;
		}
		for(imprimeLinhas = 0; imprimeLinhas < 7; imprimeLinhas++) { // Cada letra possui 7 linhas para ser desenhada.
			gotoxy(colunaInicial,linhaInicial); // Posiciona o cursor na posição da tela para 'pintar'.
			imprimeLetras = letras[i][imprimeLinhas]; // Pega o numero da primeira linha do caractere.
			for(j = 0; j < 7; j++) {
				Sleep(1);
				if(imprimeLetras % 2 != 0) { // Se o número for igual a 1, coloca espaço invertido, senão, coloca espaço normal.
					printf("%c",219);
				} else {
					printf(" ");
				}
				imprimeLetras /= 2; // Desloca as letras para direita.
			}
			mudaLinha = linhaInicial++;
		}
		colunaInicial += 8; // Avança 8 colunas.
		linhaInicial = recuperaLinhaInicial;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
	gotoxy(69,17);
	printf(" %c",169); // Imprime "marca registrada" > ®.
	SetConsoleTextAttribute(hConsole, corNormal);

	SetConsoleTextAttribute(hConsole, corNormal);
	for (i = 0; i < strlen(nome); i++) {
		gotoxy(10+i,21);
		printf("%c", nome[i]);
		Sleep(50);
	}
	Sleep(200);
	gotoxy(55,21);
	printf("version 1.0");
	int tecla;
	gotoxy(30,25);
	printf("COME%CAR (ENTER)", 128);
	do {
		if(kbhit) {
			tecla = getch();
		}
	} while (tecla != 13);
}
