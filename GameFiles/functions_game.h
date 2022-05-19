//funkcje wykorzystywane tylko do pliku game.cpp
#pragma once

//void poruszanie(int, int, int, int, bool(*fa), bool(*fb), bool(*fc), bool(*fd), int(*f1));

/* 
//G¢wno nie dziaˆa
bool poruszanie(int w, int a, int s, int d, Player& pl, int(*f1)()){

    
    int key{};
    key = f1();
    
    if(key == w){       //g¢ra
        return pl.moveY(-1);

    }else if(key == a){ //lewo
        return pl.moveX(-1);

    }else if(key == s){ //d¢ˆ
        return pl.moveY(1);

    }else if(key == d){ //prawo
        return pl.moveX(1);

    }
    
    return 0;
}
*/