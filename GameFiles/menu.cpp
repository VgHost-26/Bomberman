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



//biblioteki swoje
#include "globals.h"
#include "functions_system.h"
#include "functions_menu.h"

int main(){

    setConsoleSize();
    hideCursor();

    //pobieranie wielko�ci konsoli (centrowanie)
    CONSOLE_SCREEN_BUFFER_INFO csbi;    
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int winWidth = csbi.dwMaximumWindowSize.X;
    int winHeight = csbi.dwMaximumWindowSize.Y;

    string menuList[3]={
        "    Graj",
        "  Jak grac",
        "   Wyjdz!"
    };

    int selected{};
    int key_num{};

    printLogo(defCol, middleCalc(winWidth, 119)); // Wyswietlanie tytulu gry w menu glownym
    printBomob();
    helpButtons(winWidth-30, winHeight-1);

    select(menuList, 3, selected, defCol, 9, middleCalc(winWidth, 5));

    while (1) {

        key_num=getKey();

        if(key_num==72) {   //Strzalka w gore
                        
            if(selected>0) {

                selected--;
                select(menuList, 3, selected, defCol, 9, middleCalc(winWidth, 5));
            }

        } else if(key_num==80) {  //Strzalka w dol
                  
            if(selected<2) {

                selected++;
                select(menuList, 3, selected, defCol, 9, middleCalc(winWidth, 5));
            }
        }
    }

    return 0;
}