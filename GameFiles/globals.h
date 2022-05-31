//plik ze zmiennymi globalnymi do gry
#pragma once

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int sizeX = 50 / 2;
const int sizeY = 17;
//mapa jest 50x30 + 1 z ka�dej strony na ramk�
//NOTE wszystkei operacje na X-ach gdy co� jest wy�wietlane robimy razy 2

const int _bombsSize = 6;
const int _EnemiesCount = 8;

//ANCHOR Klawisze deklaracje
const int _W = 119;
const int _A = 97;
const int _S = 115;
const int _D = 100;
const int _SPACE_BAR = 32;
const int _ENTER = 13;

//LINK Bomberman\GameFiles\functions_system.h#color-list
const int defCol = 7;
const int _DefGrey = 1;
const int _LightGrey = 2;
const int _Yellow = 12;
const int _Orange = 13;

/*
    free space: 0
    �ciany: 1 - 5
    enemies: 6 - 9
    bombs: 30 - 39


*/


//ANCHOR sciany:
const int _SolidWall = 1;
const int _SoftWall = 2;
const int _SemiSolidWall = 3;

//ANCHOR enemies
const int _EnemyBasic = 6;
const int _EnemyFast = 7;


