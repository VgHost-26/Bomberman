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


 
    int FakeTimer_1=1;

    string line, map_txt, p1_name="playerOne";
    int map_num{}, p1_color, p1_pozX, p1_pozY;
    int tmp1{};
  
    fstream game_session_config; 
    game_session_config.open("game_session_config.txt");


    game_session_config>>map_num;           //pobranie numeru mapy
    getline(game_session_config, p1_name);  //przejscie do nowej lini
    getline(game_session_config, p1_name);  //pobranie nazwy gracza 1
    game_session_config>>p1_color;          //pobieranie koloru gracza 1
  
    game_session_config.close();


    map1.loadMap(map_num);
    map1.drawMap();

    //wczytanie pozycji graczy dla konkretnej mapy
    fstream plPozs;
    plPozs.open("playersPositions.txt");
    
    plPozs>>p1_pozX>>p1_pozY;
    
    
    plPozs.close();


    //tworzenie graczy
    Player p1(p1_name, &map1, p1_color, &FakeTimer_1, p1_pozX, p1_pozY);
    Player p2("", &map1, 0, &FakeTimer_1);
    Scoreboard scoreboard{};

   
    
    p1.show();

    scoreboard.setBorder();
    scoreboard.show(&p1);


    //---------GRA------------//
    int key{};
    while(p1.isAlive() && p2.isAlive() && !scoreboard.isTimeOver()){

        key = getKey();    
        if(p1.control(_W, _A, _S, _D, _SPACE_BAR, key) == 6){
            for(int i = 0; i < _bombsSize; i++){
                if(!bombs_1[i].isExist()){
                    bombs_1[i].placeBomb(p1.getX(), p1.getY(), 30);	//30 - typ bomby
                    break;
                } 
		    }
        }
  

        
        
        
        
      // cout<<_getch()<<endl;

        for(int i=0;i<_bombsSize;i++){
            if(bombs_1[i].countDown(&p1, &p2) == 0){
                map1.map[bombs_1[i].getX()][bombs_1[i].getY()] = 0;
              
            }
      
            
        }
        
        p1.show();
        scoreboard.update(&p1);

        Sleep(100);
        if(p1.hitted == true) FakeTimer_1++;
        
        if(FakeTimer_1 % 11 == 0){
            FakeTimer_1 = 1;
            p1.hitted = false;
        }
    }
    //-------KONIEC-GRY------------//


    //konwersja pozostałych żyć na punkty
    p1.addScore(p1.getLifes() * 1000);



    Sleep(1000);
    changeColor(_Orange);
    coutWithBorder(" Press any button ", sizeX * 2, sizeY +1);
    coutWithBorder(" to return to menu", sizeX * 2, sizeY +2, false);
    //coutWithBorder("to go back to menu", sizeX * 2, sizeY + 2);

   _getch();
   
    


   // system("pause");

    delete [] bombs_1;
    

    system("start menu.exe");   //powrot do menu
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

