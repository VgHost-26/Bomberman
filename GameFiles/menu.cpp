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
    setColors();

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

    string mapList[4]={
        "  Kolumny",
        " Labirynt",
        "  Dust II",
        "  Powrot"
    };

    string modeList[3]={
        "     PvP",
        "Testowanie mapy",
        "    Powrot"
    };

    string playerSetList[2]={
        "   Nazwa   ",
        " <  ===  > "
    };

    string table[4]={
        "�����������ͻ",    //top
        "�           �",    //sides
        "�����������͹",    //separator
        "�����������ͼ",    //bottom
    };

    int selected{};
    int key_num{};
    int playerColor;
    bool mapsMenu=true;
    bool modeMenu=true;
    bool valid=false;
    string selected_map="";
    string playerName{};
    string playerNameTmp{};
    ofstream game_session_config;
    

    printLogo(defCol, middleCalc(winWidth, 119)); // Wyswietlanie tytulu gry w menu glownym
    printBomob();
    helpButtons(winWidth-30, winHeight-1);


    while (1) {

        mapsMenu=true;
        key_num=getKey();

        select(menuList, 3, selected, defCol, _Orange, middleCalc(winWidth, 5));

        if(key_num==72) {   //Strzalka w gore
                        
            if(selected>0) {

                selected--;
                select(menuList, 3, selected, defCol, _Orange, middleCalc(winWidth, 5));
            }

        } else if(key_num==80) {  //Strzalka w dol
                  
            if(selected<2) {

                selected++;
                select(menuList, 3, selected, defCol, _Orange, middleCalc(winWidth, 5));
            }
        } else if(key_num==13) { //ENTER

            if(selected==0){  //graj

                for (int i=15; i<winHeight-5; i++) clearLine(winWidth/3, i, 40);

                //================================================================================================= WYBOR MAPY               
                while (mapsMenu) {
                    modeMenu=true;
                    key_num=getKey();

                    select(mapList, 4, selected, defCol, _Orange, middleCalc(winWidth, 5));

                    if(key_num==72) {   //Strzalka w gore
                        
                        if(selected>0) {

                            selected--;
                            select(mapList, 4, selected, defCol, _Orange, middleCalc(winWidth, 6));
                        }

                    } else if(key_num==80) {  //Strzalka w dol
                            
                        if(selected<3) {

                            selected++;
                            select(mapList, 4, selected, defCol, _Orange, middleCalc(winWidth, 6));
                        }
                    } else if(key_num==13) { //ENTER
                        if (selected==3) {
                            for (int i=15; i<winHeight-5; i++) clearLine(winWidth/3, i, 40);
                            mapsMenu=false;
                            selected=0;
                        } else {
                            game_session_config.open("game_session_config.txt", ios::trunc);
                            game_session_config<<"map_"<<selected<<".txt"<<endl; selected=0;
                            game_session_config.close();
                            //============================================================================TRYB GRY

                            for (int i=15; i<winHeight-5; i++) clearLine(winWidth/3, i, 40);
                            select(modeList, 3, selected, defCol, _Orange, middleCalc(winWidth, 6));

                            while (modeMenu) {
                                key_num=getKey();
                                if(key_num==72) {   //Strzalka w gore
                                    
                                    if(selected>0) {

                                        selected--;
                                        select(modeList, 3, selected, defCol, _Orange, middleCalc(winWidth, 6));
                                    }

                                } else if(key_num==80) {  //Strzalka w dol
                                        
                                    if(selected<3) {

                                        selected++;
                                        select(modeList, 3, selected, defCol, _Orange, middleCalc(winWidth, 6));
                                    }
                                } else if(key_num==13) { //ENTER
                                    if (selected==2) {
                                        for (int i=15; i<winHeight-5; i++) clearLine(winWidth/3, i, 40);
                                        modeMenu=false;
                                        selected=0;
                                    } else {
                                        if (selected==0) {
                                            //==============================================================NICKNAME PvP
                                            for (int i=15; i<winHeight-5; i++) clearLine(winWidth/3, i, 40);
                                            game_session_config.open("game_session_config.txt", ios::app);

                                            for(int i=0;i<2;i++){       
                                                if(i==0)playerSetList[0]="  Gracz 1  ";
                                                if(i==1)playerSetList[0]="  Gracz 2  ";
                                                
                                                selected=1;
                                                select(playerSetList, 2, 1, _DarkGrey, selected, middleCalc(winWidth, 10));
                                                setCursorPosition(middleCalc(winWidth, -10),15+2);
                                                cout<<"  ";
                                                setCursorPosition(middleCalc(winWidth, -10)+8,15+2);
                                                cout<<"  ";
                                                                        // wybranie nazwy
                                                while(!valid){          // walidacja nazwy
                                                    setCursorPosition(middleCalc(winWidth, -7),15);
                                                    showCursor();
                                                    // if(getKey()==27){
                                                    //     system("start menu.exe");
                                                    //     return 0;
                                                    // }
                                                    getline(cin,playerName);
                                                    
                                                    if(playerName.length()>8 || includeChar(playerName,';') || playerName.length()==0){
                                                        clearLine(middleCalc(winWidth, -46), 12, 46);
                                                        clearLine(middleCalc(winWidth, -46), 13, 46);
                                                        setCursorPosition(middleCalc(winWidth, -46), 13);
                                                        SetConsoleTextAttribute(hConsole,_Red);
                                                        if(playerName.length()==0) cout<<"           ! Nazwa nie moze byc pusta !";
                                                        if(playerName.length()>8) cout<<"! Nazwa powinna byc nie dluzsza niz 8 znakow !";
                                                        if(playerName.length()>8 && includeChar(playerName,';')) setCursorPosition(middleCalc(winWidth, -46), 12); 
                                                        if(includeChar(playerName,';')) cout<<"! Nazwa nie moze zawierac znaku srednika ';' !";
                                                        SetConsoleTextAttribute(hConsole, defCol);
                                                        
                                                        clearLine(middleCalc(winWidth, -10), 15, playerName.length()+4);     //czyszczenie smieci po wpisaniu
                                                        
                                                        setCursorPosition(0,14);
                                                        
                                                        setCursorPosition(middleCalc(winWidth, -10),15);

                                                        select(playerSetList, 2, 1, _DarkGrey, selected, middleCalc(winWidth, 10));
                                                        setCursorPosition(middleCalc(winWidth, -10),15+2);
                                                        cout<<"  ";
                                                        setCursorPosition(middleCalc(winWidth, -10)+8,15+2);
                                                        cout<<"  ";
                                                        

                                                    }else if(i==1 && playerName==playerNameTmp && playerName!=""){
                                                            
                                                        clearLine(middleCalc(winWidth, -46),12,46);
                                                        clearLine(middleCalc(winWidth, -46),13,46);
                                                        setCursorPosition(middleCalc(winWidth, -28),13);
                                                        SetConsoleTextAttribute(hConsole,_Red);
                                                        cout<<"! Ta nazwa jest juz zajeta !";
                                                        SetConsoleTextAttribute(hConsole, defCol);

                                                        setCursorPosition(0,14);
                                                        setCursorPosition(middleCalc(winWidth, -10), 15);

                                                        select(playerSetList, 2, 1, _DarkGrey, selected, middleCalc(winWidth, 10));
                                                        setCursorPosition(middleCalc(winWidth, -10), 15+2);
                                                        cout<<"  ";
                                                        setCursorPosition(middleCalc(winWidth, -10)+8,15+2);
                                                        cout<<"  ";

                                                    }else{      //wszytskie dane podane prwidlowo
                                                        valid=true;
                                                        clearLine(middleCalc(winWidth, -46),12,46);
                                                        clearLine(middleCalc(winWidth, -46),13,46);
                                                    }
                                                    
                                                }
                                                
                                                //playerName=nameValidation(playerSetList,selected, alertCol, defCol)
                                                valid=false;
                                                
                                                select(playerSetList, 2, 1, selected, selected, middleCalc(winWidth, 10));
                                                setCursorPosition(middleCalc(winWidth, -10),15+2);
                                                cout<<"  ";
                                                

                                                hideCursor();
                                                playerSetList[0]=playerName;
                                                playerNameTmp=playerName;
                                                setCursorPosition(middleCalc(winWidth, -10),15);
                                                cout<<"           ";
                                                setCursorPosition(middleCalc(winWidth, -10),15);
                                                int middle=(11/2)+(playerName.length()/2)+1;
                                                cout.width(middle);
                                                cout<<playerName;

                                                selected=9;
                                                while(1){         // wybieranie koloru
                                                    key_num=getKey();
                                                    if(key_num==75){              //Strza�ka w lewo
                                                        if(selected>9){
                                                            selected--;
                                                            cout.width(middle);
                                                            select(playerSetList, 2, 1, selected, selected, middleCalc(winWidth, 10));

                                                            if(selected==9){
                                                                setCursorPosition(middleCalc(winWidth, -10),15+2);
                                                                cout<<"  "; 
                                                            }
                                                        }
                                                    }else if(key_num==77){        //Strza�ka w prawo
                                                        if(selected<13){
                                                            selected++;
                                                            cout.width(middle);
                                                            select(playerSetList, 2, 1, selected, selected, middleCalc(winWidth, 10));

                                                            if(selected==13){
                                                                setCursorPosition(middleCalc(winWidth, -10)+8,15+2);
                                                                cout<<"  "; 
                                                            }
                                                        }
                                                    }else if(key_num==13){    //ENTER
                                                        if(i==1 && selected==playerColor){
                                                            clearLine(middleCalc(winWidth, -46),13,46);
                                                            setCursorPosition(middleCalc(winWidth, -28),13);
                                                            SetConsoleTextAttribute(hConsole,_Red);
                                                            cout<<"! Ten kolor jest juz zajety !";
                                                        }else{
                                                            clearLine(middleCalc(winWidth, -46),13,46);
                                                            playerColor=selected;
                                                            break;
                                                        }
                                                    }
                                                }
                                                game_session_config<<playerName<<endl<<playerColor<<endl;
                                                
                                            }
                                            
                                            game_session_config.close();
                                            system("start game.exe");
                                            return 0;

                                        } else if (selected==1) {
                                            //==============================================================NICKNAME TEST MAPY
                                            for (int i=15; i<winHeight-5; i++) clearLine(winWidth/3, i, 40);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }               

            }

            if(selected==1){  //instrukcja
                system("start howtoplay.exe");
                return 0;
            }

            if(selected==2){  //exit
                //select(menuList, 4, selected, defCol, defCol, middleCalc(winWidth, 5));

                if(confirm(middleCalc(winWidth, -10), 25, defCol, _Orange, true, "Jestes pewien?")) return 0;  //wyswietlenie ramki z zapytaniem "czy na pewno"

                //select(menuList, 4, selected, defCol, _Orange, middleCalc(winWidth, 5));
            }
        }
    }

    return 0;
}