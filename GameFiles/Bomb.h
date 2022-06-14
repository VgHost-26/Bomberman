#pragma once
class Bomb{
    friend class GameMap;
    friend class Player;

private:

    int x{}, y{};
    int type{};
    int timer{};
    int expSize = 4;
    GameMap *Map = new GameMap;
    

public:    

    Bomb(GameMap *Map);
    Bomb();
    

    int getTime();
    int getX();
    int getY();
    bool placeBomb(int,int,int);;
    int explode(int, Player *player);
    int explode(int, Player *p1, Player *p2);
    void clearExplode(Player *p1, Player *p2);
    int countDown(Player *p1, Player *p2);
    void drawFire(int, int, int);
    bool isExist();
    int spread(bool &stop, int, int, int, Player *p1, Player *p2);
    int CLSspread(bool &stop, int, int, int, Player *p1, Player *p2);
    
};

Bomb::Bomb(){
    x = -1;
    y = -1;
    type = -1;
    timer = -1;
}

Bomb::Bomb(GameMap *map1){
    
    Map = map1; 

    x = -1;
    y = -1;
    type = -1;
    timer = -1;


}
// Bomb::Bomb(int x, int y, int type){
//     this->x=x;
//     this->y=y;
//     this->type=type;

//     if(type == 0){
//         timer = 5;
//     }else if(type == 1){
//         timer = 3;
//     }

//     placeBomb();

// }


int Bomb::getTime(){
    return timer;
}
int Bomb::getX(){
    return x;
}

int Bomb::getY(){
    return y;
}


int Bomb::countDown(Player *p1, Player *p2){
    if(timer < 0) return -1;

    timer--;

    if(timer <= 0){
        clearExplode(p1, p2);
        return 0;
    }else if(timer <= 5){
        explode(timer, p1, p2);
        return timer;
        
    }else{
        return timer;
    }
    return -1;
}

bool Bomb::placeBomb(int x, int y, int type){

    setCursorPosition(x * 4,y * 2);
    cout<<"/\"\""<<char(92);
    setCursorPosition(x * 4,y * 2 + 1);
    cout<<char(92)<<"__/";

    if(Map->map[x][y] == 0 || Map->map[x][y] == 101) Map->map[x][y] = type;


    timer=25;

    this->x=x;
    this->y=y;
    this->type=type;



    return false;
}

int Bomb::spread(bool &stop, int ix, int iy, int t, Player *p1, Player *p2){
    int score=0;
    if(!stop){
        if(Map->map[x + ix][y + iy] == 0){
            drawFire(x + ix, y + iy, t);

        }else if(Map->map[x + ix][y + iy] == 1 || Map->map[x + ix][y + iy] == 5){
            stop = true;
            

        }else if(Map->map[x + ix][y + iy] >= 2 && Map->map[x + ix][y + iy] <= 9){
            stop = true;
            //Map->map[x + ix][y + iy] = Map->map[x + ix][y + iy]* -1;
            drawFire(x + ix, y + iy, t);
          //  if((t* -1) % 5 == 0) score += _WallDestroyed;
        }
        if(x + ix == p1->getX()  &&  y + iy == p1->getY()){
            
            if(!p1->hitted){
                p1->minus1life();
                score -= (_PlayerKillScoreAmount * 0.5);    
                p1->hitted = true;  
                    
            }
            
        }
        if(x + ix == p2->getX()  &&  y + iy == p2->getY()){
            
            if(!p2->hitted){
                p2->minus1life();
                //if(p1->hitted) score += (_PlayerKillScoreAmount * 0.5);  //wyrownanie w przypadku samobojstwa z zabojstwem
                score += _PlayerKillScoreAmount;
                p2->hitted = true;  
            }
            
        }
    }
    return score;

} 

int Bomb::CLSspread(bool &stop, int ix, int iy, int t, Player *p1, Player *p2){
    int score=0;
    if(!stop){

        


        if(Map->map[x + ix][y + iy] == 0){
            cls(x + ix, y + iy);

        }else if(Map->map[x + ix][y + iy] == 1 || Map->map[x + ix][y + iy] == 5){
            stop= true;

        }else if(Map->map[x + ix][y + iy] >= 2 && Map->map[x + ix][y + iy] <= 4){
            stop = true;
            Map->map[x + ix][y + iy] = 0;
            score += _WallDestroyed;
            cls(x + ix, y + iy);
            
        }
            
    }
    return score;

} 

int Bomb::explode(int t, Player *p1, Player *p2){   //time; owner; otherPlayer

    if(x >= 0 || y >= 0){ 
        drawFire(x, y, t);
        bool stopXP = false;
        bool stopXL = false;
        bool stopYP = false;
        bool stopYL = false;

        for(int i = 0; i < expSize; i++){

            p1 -> addScore(spread(stopXP, i,      0, t, p1, p2));
            p1 -> addScore(spread(stopXL, i * -1, 0, t, p1, p2));
            p1 -> addScore(spread(stopYP, 0,      i, t, p1, p2));
            p1 -> addScore(spread(stopYL, 0, -1 * i, t, p1, p2));


        }
      
    }

    return 0;
   
}

void Bomb::clearExplode(Player *p1, Player *p2){
    if(x >= 0 || y >= 0){ 

        bool stopXP = false;
        bool stopXL = false;
        bool stopYP = false;
        bool stopYL = false;

        timer = -1;

        cls(x, y);

        for(int i = 0; i < expSize; i++){
       
            p1 -> addScore(CLSspread(stopXP, i,      0, timer, p1, p2));
            p1 -> addScore(CLSspread(stopXL, i * -1, 0, timer, p1, p2));
            p1 -> addScore(CLSspread(stopYP, 0,      i, timer, p1, p2));
            p1 -> addScore(CLSspread(stopYL, 0, -1 * i, timer, p1, p2));

/*            if(!stopXP){
                if(Map->map[x+i][y] == 0){
                    cls(x + i, y);

                }else if(Map->map[x+i][y] == 1 || Map->map[x+i][y] == 5){
                    stopXP = true;

                }else if(Map->map[x+i][y] >= 2 && Map->map[x+i][y] <= 4){
                    stopXP = true;
                    Map->map[x + i][y] = 0;
                    cls(x + i, y);
                    
                }
            }
            if(!stopXL){
                if(Map->map[x-i][y] == 0){
                    cls(x - i, y);

                }else if(Map->map[x-i][y] == 1 || Map->map[x-i][y] == 5){
                    stopXL = true;

                }else if(Map->map[x-i][y] >= 1 && Map->map[x-i][y] <= 4){
                    stopXL = true;
                    if(Map->map[x-i][y] > 1 && Map->map[x-i][y] <= 9) Map->map[x - i][y] = 0;
                    cls(x - i, y);
                }
            }
            if(!stopYP){
                if(Map->map[x][y + i] == 0){
                    cls(x, y + i);

                }else if(Map->map[x][y + i] == 1 || Map->map[x][y + i] == 5){
                    stopYP = true;

                }else if(Map->map[x][y + i] >= 1 && Map->map[x][y + i] <= 9){
                    stopYP = true;
                    if(Map->map[x][y + i] > 1 && Map->map[x][y + i] <= 9)Map->map[x][y + i] = 0;
                    cls(x, y + i);
                }
            }
            if(!stopYL){
                if(Map->map[x][y - i] == 0){
                    cls(x, y - i);

                }else if(Map->map[x][y - i] == 1 || Map->map[x][y - i] == 5){
                    stopYL = true;

                }else if(Map->map[x][y - i] >= 1 && Map->map[x][y - i] <= 9){
                    stopYL = true;
                    if(Map->map[x][y - i] > 1 && Map->map[x][y - i] <= 9)Map->map[x][y - i] = 0;
                    cls(x, y - i);
                }
            }*/
        
        }
    }
   
}

void Bomb::drawFire(int x, int y, int t){

    SetConsoleTextAttribute(hConsole, _Orange);
    setCursorPosition(x * 4,y * 2);
    if(t%2 == 0)cout<<"#@#@"; 
    if(t%2 != 0) cout<<"@#@#";
    setCursorPosition(x * 4,y * 2 +1);
    if(t%2 == 0) cout<<"@#@#";
    if(t%2 != 0)cout<<"#@#@"; 
    SetConsoleTextAttribute(hConsole, _DefGrey);


}
bool Bomb::isExist(){
    if(timer < 0 ) return false;

    return true;
}