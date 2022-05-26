#pragma once
class Bomb{
    friend class GameMap;

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
    void explode(int);
    void clearExplode();
    int countDown();
    void drawFire(int, int, int);
    bool isExist();
    
    
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


int Bomb::countDown(){
    if(timer < 0) return -1;

    timer--;

    if(timer <= 0){
        clearExplode();
        return 0;
    }else if(timer <= 5){
        explode(timer);
        return timer;
        
    }else{
        return timer;
    }
    return -1;
}

bool Bomb::placeBomb(int x, int y, int type){


    if(Map->map[x][y] == 0) Map->map[x][y] = type;


    timer=25;

    this->x=x;
    this->y=y;
    this->type=type;



    return false;
}

void Bomb::explode(int t){

    if(x >= 0 || y >= 0){ 
        bool stopXP = false;
        bool stopXL = false;
        bool stopYP = false;
        bool stopYL = false;

        for(int i = 0; i < expSize; i++){

            if(!stopXP){
                if(Map->map[x+i][y] == 0){
                    drawFire(x + i, y, t);

                }else if(Map->map[x+i][y] == 1){
                    stopXP = true;

                }else if(Map->map[x+i][y] >= 2 && Map->map[x+i][y] <= 9){
                    stopXP = true;
                    drawFire(x + i, y, t);
                }
            }
            if(!stopXL){
                if(Map->map[x-i][y] == 0){
                    drawFire(x - i, y, t);

                }else if(Map->map[x-i][y] == 1){
                    stopXL = true;

                }else if(Map->map[x-i][y] >= 2 && Map->map[x-i][y] <= 9){
                    stopXL = true;
                    drawFire(x - i, y, t);
                }
            }
            if(!stopYP){
                if(Map->map[x][y + i] == 0){
                    drawFire(x, y + i, t);

                }else if(Map->map[x][y + i] == 1){
                    stopYP = true;

                }else if(Map->map[x][y + i] >= 2 && Map->map[x][y + i] <= 9){
                    stopYP = true;
                    drawFire(x, y + i, t);
                }
            }
            if(!stopYL){
                if(Map->map[x][y - i] == 0){
                    drawFire(x, y - i, t);

                }else if(Map->map[x][y - i] == 1){
                    stopYL = true;

                }else if(Map->map[x][y - i] >= 2 && Map->map[x][y - i] <= 9){
                    stopYL = true;
                    drawFire(x, y - i, t);
                }
            }
            
        }
      
    }

   
}
void Bomb::clearExplode(){
    if(x >= 0 || y >= 0){ 

        bool stopXP = false;
        bool stopXL = false;
        bool stopYP = false;
        bool stopYL = false;

        timer = -1;

        cls(x, y);

        for(int i = 0; i < expSize; i++){

            if(!stopXP){
                if(Map->map[x+i][y] == 0){
                    cls(x + i, y);

                }else if(Map->map[x+i][y] == 1){
                    stopXP = true;

                }else if(Map->map[x+i][y] >= 2 && Map->map[x+i][y] <= 9){
                    stopXP = true;
                    Map->map[x + i][y] = 0;
                    cls(x + i, y);
                    
                }
            }
            if(!stopXL){
                if(Map->map[x-i][y] == 0){
                    cls(x - i, y);

                }else if(Map->map[x-i][y] == 1){
                    stopXL = true;

                }else if(Map->map[x-i][y] >= 1 && Map->map[x-i][y] <= 9){
                    stopXL = true;
                    if(Map->map[x-i][y] > 1 && Map->map[x-i][y] <= 9) Map->map[x - i][y] = 0;
                    cls(x - i, y);
                }
            }
            if(!stopYP){
                if(Map->map[x][y + i] == 0){
                    cls(x, y + i);

                }else if(Map->map[x][y + i] == 1){
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

                }else if(Map->map[x][y - i] == 1){
                    stopYL = true;

                }else if(Map->map[x][y - i] >= 1 && Map->map[x][y - i] <= 9){
                    stopYL = true;
                    if(Map->map[x][y - i] > 1 && Map->map[x][y - i] <= 9)Map->map[x][y - i] = 0;
                    cls(x, y - i);
                }
            }
        
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