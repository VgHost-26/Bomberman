class Bomb{
    friend class GameMap;

private:

    int x{}, y{};
    int type{};
    int timer{};

public:    

    Bomb(int,int,int);

    int getTime();

    bool placeBomb();
    void explode();
    int countDown();

    
    ~Bomb();
};
int Bomb::getTime(){
    return timer;
}

int Bomb::countDown(){
    timer--;
    if(timer <= 0){

        return 0;
        
    }else{
        return getTime();
    }
    return -1;
}

Bomb::Bomb(int x, int y, int type){
    this->x=x;
    this->y=y;
    this->type=type;

    if(type == 0){
        timer = 5;
    }else if(type == 1){
        timer = 3;
    }

    placeBomb();

}