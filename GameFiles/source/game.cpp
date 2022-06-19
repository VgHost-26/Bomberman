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
    hideScrollbars();
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


    //Tworzenie tablicy wrogow
   // Enemy *enemies = new Enemy[_EnemiesCount];
    
    int FakeTimer_1=1;
    int FakeTimer_2=1;

    string line, map_txt, p1_name="playerOne", p2_name="playerTwo";
    int map_num{}, p1_color, p1_pozX, p1_pozY, p2_color, p2_pozX, p2_pozY;
    int tmp1{}, tmp2{};
  
    fstream game_session_config; 
    game_session_config.open("game_session_config.txt");


    game_session_config>>map_num;           //pobranie numeru mapy
    getline(game_session_config, p1_name);  //przejscie do nowej lini
    getline(game_session_config, p1_name);  //pobranie nazwy gracza 1
    game_session_config>>p1_color;          //pobieranie koloru gracza 1
    getline(game_session_config, p2_name);  //przejscie do nowej lini
    getline(game_session_config, p2_name);  //pobranie nazwy gracza 2
    game_session_config>>p2_color;          //pobranie koloru gracza 2
    
    game_session_config.close();


    map1.loadMap(map_num);
    map1.drawMap();

    //wczytanie pozycji graczy dla konkretnej mapy
    fstream plPozs;
    plPozs.open("playersPositions.txt");
    
    plPozs>>p1_pozX>>p1_pozY;
    plPozs>>p2_pozX>>p2_pozY;
    
    plPozs.close();


    //tworzenie graczy
    Player p1(p1_name, &map1, p1_color, &FakeTimer_1, p1_pozX, p1_pozY);
    Player p2(p2_name, &map1, p2_color, &FakeTimer_2, p2_pozX, p2_pozY);
    Scoreboard scoreboard{};

   
    
    p1.show();
    p2.show();

    scoreboard.setBorder();
    scoreboard.show(&p1, &p2);


    //---------GRA------------//
    int key{};
    while(p1.isAlive() && p2.isAlive() && !scoreboard.isTimeOver()){
        cout.flush();
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
    //-------KONIEC-GRY------------//


    //konwersja pozostałych żyć na punkty
    p1.addScore(p1.getLifes() * 1000);
    p2.addScore(p2.getLifes() * 1000);

    string message{};
    changeColor(_Red);

    //wiadomosc gdy skonczy sie czas
    if(scoreboard.isTimeOver())  coutWithBorder("Time is over", sizeX * 2, sizeY - 5);
    
    if(p1.getScore() > p2.getScore()){  //koniec czasu, gracz 1 ma wiecej punktow

        message = p1.getName() + " " + "win!";
        changeColor(p1.getColor());
        coutWithBorder(message, sizeX * 2, sizeY -2);

    }else if(p2.getScore() > p1.getScore()){    //gracz 2 ma wiecej punktow

        message = p2.getName() + " " + "win!";
        changeColor(p2.getColor());
        coutWithBorder(message, sizeX * 2, sizeY -2);

    }else if(p1.getScore() == p2.getScore()){   //gdyby mieli tyle samo punktow

        if(p1.getLifes() > p2.getLifes()){  //gracz 1 ma wiecej zyc
            message = p1.getName() + " " + "win!";
            changeColor(p1.getColor());
            coutWithBorder(message, sizeX * 2, sizeY -2);

        }else if(p2.getLifes() > p1.getLifes()){    //gracz 2 ma wiecej zyc

            message = p2.getName() + " " + "win!";
            changeColor(p2.getColor());
            coutWithBorder(message, sizeX * 2, sizeY -2);

        }else{
            coutWithBorder("Its a draw!", sizeX * 2, sizeY -2); 
        }
    }

   /* //wiadomosc gdy wygra gracz 2
    if(!p1.isAlive()){
        changeColor(p2.getColor());
        message = p2.getName() + " " + "win!";
        coutWithBorder(message, sizeX * 2, sizeY - 5);
    }
    //wiadomosc gdy wygra gracz 1
    if(!p2.isAlive()){
        changeColor(p1.getColor());
        message = p1.getName() + " " + "win!";
        coutWithBorder(message, sizeX * 2, sizeY - 5);
    }*/

    Sleep(1000);
    changeColor(_Orange);
    coutWithBorder(" Press any button ", sizeX * 2, sizeY +1);
    coutWithBorder(" to return to menu", sizeX * 2, sizeY +2, false);
    //coutWithBorder("to go back to menu", sizeX * 2, sizeY + 2);

    //_getch();
    Sleep(1500);
    pauza();
    

    // system("pause");

    delete [] bombs_1;
    delete [] bombs_2;
   // delete [] enemies;

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

