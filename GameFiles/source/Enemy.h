#pragma once

class Enemy : public Being{
    friend class GameMap;
private:
        int type{};
        string typeName{};

public:
    Enemy(int, int, GameMap *map1);
    Enemy();
    void show();
    bool moveX(int, void show());
    bool moveY(int, void show());
    void place(int x, int y, int type);

        

};

Enemy::Enemy(int x, int y, GameMap *map1){
    this->X = x;
    this->Y = y;
    this->Map = map1;
}

Enemy::Enemy(){
    this->X = -1;
    this->Y = -1;
}


void Enemy::show(){	//wy˜wietla ludka na mapie na jego aktualnej pozycji
    setCursorPosition(X * 4,Y * 2);
    cout<<"<[";
    cout<<"]>";
    setCursorPosition(X * 4,Y * 2 + 1);
    cout<<"//";
    cout<<char(92)<<char(92);
}

bool Enemy::moveX(int dir, void show()) {	//ruch w prawo (dir = +1) lub w lewo (dir = -1)

    
    if(Map->map[X + dir][Y] != 0 || (X + dir >= (sizeX - 1) || X + dir <= 1)){
        return false;
    }else{
        cls(X * 2,Y);
        X += dir;
        show();
        return true;
    }


    return false;
}
bool Enemy::moveY(int dir, void show()) {	//ruch g¢ra (dir = -1) lub d¢ˆ (dir = +1)

    if(Map->map[X][Y + dir] != 0 || (Y + dir >= (sizeY - 1) || Y + dir <= 1)){
        return false;
    }else{
        cls(X * 2,Y);
        Y += dir;
        show();
        return true;
    }
    return false;
}

void Enemy::place(int x, int y, int type){

    
      

}