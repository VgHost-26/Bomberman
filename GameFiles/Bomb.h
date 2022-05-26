#pragma once
class Bomb{
    friend class GameMap;

private:

    int x{}, y{};
    int type{};
    int timer{};
    int expSize = 4;
    

public:    

   // Bomb(int,int,int);
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
    }else if(timer <= 10){
        explode(timer);
        return timer;
        
    }else{
        return timer;
    }
    return -1;
}

bool Bomb::placeBomb(int x, int y, int type){




    timer=30;
    this->x=x;
    this->y=y;
    this->type=type;



    return false;
}

void Bomb::explode(int t){
    if(x >= 0 || y >= 0){ 
    

        for(int i = 0; i < expSize; i++){
            drawFire(x + i, y, t);
            drawFire(x - i, y, t);
            drawFire(x, y + i, t);
            drawFire(x, y - i, t);
        }
    }

   
}
void Bomb::clearExplode(){
    if(x >= 0 || y >= 0){ 
    timer = -1;
    
    
        for(int i = 0; i < expSize; i++){
            cls(x + i, y);
            cls(x - i, y);
            cls(x, y + i);
            cls(x, y - i);
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