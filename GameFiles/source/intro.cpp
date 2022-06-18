/* plik z intro gry */

//biblioteki systemowe
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

//biblioteki swoje
#include "globals.h"
#include "functions_system.h"
#include "functions_menu.h"

int main() {

    setConsoleSize();
    hideCursor();
    setColors();
    hideScrollbars();

    //pobieranie wielko�ci konsoli (centrowanie)
    CONSOLE_SCREEN_BUFFER_INFO csbi;    
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int winWidth = csbi.dwMaximumWindowSize.X;
    int winHeight = csbi.dwMaximumWindowSize.Y;

    printIntro(winWidth, winHeight, 50, 5);

    printBomob();
    Sleep(50*20);
    system("cls");
    printLogo(defCol, middleCalc(winWidth, 119));
    printBomob();
    Sleep(50*20);

    system("start menu.exe");
}