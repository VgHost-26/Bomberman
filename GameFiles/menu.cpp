/* plik z menu gry */

//biblioteki systemowe
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//biblioteki swoje
#include "functions_system.h"
#include "functions_menu.h"
#include "globals.h"

int main(){

    setConsoleSize();
    hideCursor();

    //pobieranie wielkości konsoli (centrowanie)
    CONSOLE_SCREEN_BUFFER_INFO csbi;    
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int winWidth = csbi.dwMaximumWindowSize.X;
    int winHeight = csbi.dwMaximumWindowSize.Y;

    int defCol = 7; //Domyślny kolor tekstu;

    printLogo(defCol, middleCalc(winWidth, 119));

    cout.width(middleCalc(winWidth, 7)); cout<<"Boomboom"<<endl;
    system("pause");
    system("start game.exe");

    return 0;
}