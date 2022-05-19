//funkcje wykorzystywane tylko do pliku game.cpp
#pragma once

//void poruszanie(int, int, int, int, bool(*fa), bool(*fb), bool(*fc), bool(*fd), int(*f1));
/*
//czemu ten shit nie działa
bool poruszanie(int w, int a, int s, int d, bool(*fws)(int), bool(*fad)(int), int(*f1)()){

    int key{};
    key = f1();
    
    if(key == w){       //g˘ra
        return fws(-1);

    }else if(key == a){ //lewo
        return fad(-1);

    }else if(key == s){ //d˘
        return fws(1);

    }else if(key == d){ //prawo
        return fad(1);

    }
    
    return 0;
}
*/
