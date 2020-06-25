#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
//================//
#include "Globais.c"
#include "Utils.c"
#include "TelaDeAbertura.c"
#include "JogoPrincipal.c"
#include "Menu.c"
int main() {
	// Manipula as variáveis para definir as cores.
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	corNormal = consoleInfo.wAttributes;
	
	// Chama o jogo principal.
	telaAbertura();
	menuPrincipal();
	return 0;
}
