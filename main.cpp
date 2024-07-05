#include <iostream>
#include "gui.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	resizeConsole(1920,920);
	SetScreenBufferSize(160,1000);
	Intro();
	MainMenuLogin();
	
	return 0;
}
