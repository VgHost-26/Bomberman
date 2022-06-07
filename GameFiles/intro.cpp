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

    //pobieranie wielko�ci konsoli (centrowanie)
    CONSOLE_SCREEN_BUFFER_INFO csbi;    
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int winWidth = csbi.dwMaximumWindowSize.X;
    int winHeight = csbi.dwMaximumWindowSize.Y;

    printIntro(middleCalc(winWidth, 40),winWidth, winHeight);

    //system("start menu.exe");
}