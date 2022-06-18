/* plik z pomoca do gry */

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

int main(){

    setConsoleSize();
    hideCursor();
    setColors();
    hideScrollbars();

    cout<<"\n";
    changeColor(_LightGrey);
    setCenter(12); cout<<"Instruckja gry\n\n\n";

    changeColor(_DefGrey);
    writeFromFile("howtoplay.txt");

    changeColor(_LightGrey);
    coutGoBack();

    pauza();

    system("start menu.exe");   //powrot do menu
    return 0;
}