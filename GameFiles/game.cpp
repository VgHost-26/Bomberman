/* Plik z czystą grą */

//biblioteki systemowe
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>


using namespace std;
//biblioteki swoje
#include "functions_system.h"
#include "functions_game.h"
#include "globals.h"

//klasy
#include "GameMap.h"
#include "Being.h"
#include "Player.h"
#include "Enemy.h"

int main() {
    
    setConsoleSize();
    hideCursor();

    GameMap map1{};
    Player p1("PlayerOne", &map1);

    map1.loadMap(0);
    map1.drawMap();
    
    p1.show();


      
    while(1){
        
        p1.moveDir(_W, _A, _S, _D, _SPACE_BAR, getKey);
        
        Sleep(100);
        
    }

    setCursorPosition(100,50);
    system("pause");

    return 0;

}

/*  ANCHOR key number list

W = 119
A = 97 
S = 115
D = 100
SPACE = 32
ENTER = 13
    
*/

