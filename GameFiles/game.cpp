/* Plik z czystą grą */

//biblioteki systemowe
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>


using namespace std;
//biblioteki swoje
#include "globals.h"
#include "functions_system.h"
#include "functions_game.h"

//klasy
#include "GameMap.h"
#include "Bomb.h"
#include "Being.h"
#include "Player.h"
#include "Enemy.h"

int main() {
    
    setConsoleSize();
    hideCursor();
    
    GameMap map1{};

    //Tworzenie tablicy bomb
    Bomb *bombs = new Bomb[_bombsSize];
    for(int i = 0; i < _bombsSize; i++){
        bombs[i] = Bomb(&map1);
    }

    //Tworzenie tablicy wrogow
    Enemy *enemies = new Enemy[_EnemiesCount];
    

    Player p1("PlayerZero", &map1, &bombs);

    map1.loadMap(0);
    map1.drawMap();
    
    p1.show();
    setColors();

      
    while(1){
        
        p1.control(_W, _A, _S, _D, _SPACE_BAR, getKey);
        

        for(int i=0;i<_bombsSize;i++){
            if(bombs[i].countDown() == 0){
                map1.map[bombs[i].getX()][bombs[i].getY()] = 0;
              
            }
            
            
        }

        Sleep(100);
        
    }

    setCursorPosition(100,50);
    system("pause");

    delete [] bombs;
    delete [] enemies;

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

