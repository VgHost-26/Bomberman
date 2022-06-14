/* Plik z czystą grą */

//biblioteki systemowe
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <string>


using namespace std;
//biblioteki swoje
#include "globals.h"
#include "functions_system.h"
#include "functions_game.h"

//klasya
#include "GameMap.h"
#include "Being.h"
#include "Enemy.h"
#include "Player.h"
#include "Bomb.h"
#include "Scoreboard.h"

int main() {
    
    setConsoleSize();
    hideCursor();
    setColors();
    
    GameMap map1{};

    //Tworzenie tablicy bomb
    Bomb *bombs_1 = new Bomb[_bombsSize];
    for(int i = 0; i < _bombsSize; i++){
        bombs_1[i] = Bomb(&map1);
    }
    Bomb *bombs_2 = new Bomb[_bombsSize];
    for(int i = 0; i < _bombsSize; i++){
        bombs_2[i] = Bomb(&map1);
    }


    //Tworzenie tabl`icy wrogow
    Enemy *enemies = new Enemy[_EnemiesCount];
    
    int FakeTimer_1=1;
    int FakeTimer_2=1;

    string line, map_txt, p1_name="playerOne", p2_name="playerTwo";
    int line2, p1_color=_Blue, p2_color=_Pink;

    fstream game_session_config; // to jest fest na szybko i nie dziala do konca, jak bedzie ci sie chcialo martin mozesz napisac twoje
    game_session_config.open("game_session_config.txt");
    for (int i=0; i<4; i++) {
        if (i==2 & i==4) game_session_config>>line2;
        else getline(game_session_config,line);
        if (i==0) map_txt=line;
        if (i==1) p1_name=line;
        if (i==2) p1_color=line2;
        if (i==3) p2_name=line;
        if (i==4) p2_color=line2;
    }
    game_session_config.close();

    Player p1(p1_name, &map1, p1_color, &FakeTimer_1);
    Player p2(p2_name, &map1, p2_color, &FakeTimer_2, sizeX-2, sizeY-2);
    Scoreboard scoreboard{};

    map1.loadMap(0);
    map1.drawMap();
    
    p1.show();
    p2.show();

    scoreboard.setBorder();
    scoreboard.show(&p1, &p2);

    int key{};
    while(p1.isAlive() && p2.isAlive()){


        key = getKey();    
        if(p1.control(_W, _A, _S, _D, _SPACE_BAR, key) == 6){
            for(int i = 0; i < _bombsSize; i++){
                if(!bombs_1[i].isExist()){
                    bombs_1[i].placeBomb(p1.getX(), p1.getY(), 30);	//30 - typ bomby
                    break;
                } 
		    }
        }
        if(p2.control(_NUM_UP, _NUM_LEFT, _NUM_BOT, _NUM_RIGHT, _NUM_ZERO, key) == 6){
            for(int i = 0; i < _bombsSize; i++){
                if(!bombs_2[i].isExist()){
                    bombs_2[i].placeBomb(p2.getX(), p2.getY(), 30);	//30 - typ bomby
                    break;
                } 
		    }
        }

        
        
        
        
      // cout<<_getch()<<endl;

        for(int i=0;i<_bombsSize;i++){
            if(bombs_1[i].countDown(&p1, &p2) == 0){
                map1.map[bombs_1[i].getX()][bombs_1[i].getY()] = 0;
              
            }
            if(bombs_2[i].countDown(&p2, &p1) == 0){
                map1.map[bombs_2[i].getX()][bombs_2[i].getY()] = 0;
              
            }
            
        }
        
        p1.show();
        p2.show();
        scoreboard.update(&p1, &p2);

        Sleep(100);
        if(p1.hitted == true) FakeTimer_1++;
        if(p2.hitted == true) FakeTimer_2++;
        
        if(FakeTimer_1 % 11 == 0){
            FakeTimer_1 = 1;
            p1.hitted = false;
        }
        if(FakeTimer_2 % 11 == 0){
            FakeTimer_2 = 1;
            p2.hitted = false;
        }
    }

    setCursorPosition(100,50);
   // system("pause");

    delete [] bombs_1;
    delete [] bombs_2;
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

