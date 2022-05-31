//plik ze zmiennymi globalnymi do gry
#pragma once

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int sizeX = 50 / 2;
const int sizeY = 15;
//mapa jest 50x30 + 1 z kaï¿½dej strony na ramkï¿½
//NOTE wszystkei operacje na X-ach gdy coï¿½ jest wyï¿½wietlane robimy razy 2

const int _bombsSize = 6;
const int _EnemiesCount = 8;

//ANCHOR Klawisze deklaracje
const int _W = 119;
const int _A = 97;
const int _S = 115;
const int _D = 100;
const int _SPACE_BAR = 32;

const int _I = 105;
const int _J = 106;
const int _K = 107;
const int _L = 108;

const int _NUM_UP = 56;
const int _NUM_LEFT = 52;
const int _NUM_MID = 53;
const int _NUM_RIGHT = 54;
const int _NUM_ZERO = 48;

const int _ENTER = 13;

//LINK Bomberman\GameFiles\functions_system.h#color-list
const int defCol = 7;
const int _DefGrey = 1;
const int _Orange = 13;

/*
    free space: 0
    ˜ciany: 1 - 5
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


