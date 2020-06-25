void limpaTela(void) {
	system("cls");
}
void gotoxy(int X,int Y) { // Declaração do comando gotoxy.
	COORD c;
	c.X = X;
	c.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
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
void apertarESC() {
	do {
	} while(getch() != 27);
}
