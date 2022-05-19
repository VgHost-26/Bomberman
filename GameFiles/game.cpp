/* Plik z czystą grą */

using namespace std;
//biblioteki systemowe
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>

//biblioteki swoje
#include "functions_system.h"
#include "functions_game.h"
#include "globals.h"

//klasy
#include "GameMap.h"
#include "Player.h"

int main() {
    
    setConsolSize();
    hideCursor();

    GameMap map1{};
    Player p1("PlayerOne", &map1);
    cout << p1.name <<endl;

   // map1.drawBorder();
    map1.loadMap(0);
    map1.drawMap();
    
    p1.show();


      
    while(1){
        
       // poruszanie(119, 97, 115, 100, p1.*ruchY, p1.*ruchX, getKey);
        //p1.ruchX(1);
        Sleep(100);
    }

    setCursorPosition(100,50);
    system("pause");

    return 0;

}

/*

W = 119
A = 97 
S = 115
D = 100

*/

