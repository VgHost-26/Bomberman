//funkcje wykorzystywane w pliku menu.cpp
#pragma once

void printLogo(int color, int place){   //wyswietlanie logo na środku ekranu   
    
    fstream plik;
    string line{};
    plik.open("logo.txt");
    SetConsoleTextAttribute(hConsole, color);
    cout<<endl<<endl;
    for(int i=0;i<13;i++){
        cout.width(place);
        
        getline(plik,line);
        cout<<line<<endl;
    }
    cout<<endl<<endl;
    plik.close();  
}

int middleCalc(int winWidth, int objWidth){     //obliczanie miejsca na środku ekranu dla konkretnego elementu wzgledem szerokości ekranu
    return winWidth-((winWidth-objWidth)/2);
}
