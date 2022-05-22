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

void printBomob(){   //wyswietlanie kolorowej bomby w logo
    
    fstream plik;
    string line{};
    plik.open("bomb.txt");
    SetConsoleTextAttribute(hConsole, 14);
    cout<<endl<<endl;
    for(int i=0;i<12;i++){
        if (i<3) setCursorPosition(32,i+2);
        if (i>=3 & i<=6) setCursorPosition(32-i,i+2);
        if (i>6) setCursorPosition(26,i+2);
        
        getline(plik,line);
        cout<<line<<endl;
    }
    cout<<endl<<endl;
    plik.close();  
}

int middleCalc(int winWidth, int objWidth){     //obliczanie miejsca na środku ekranu dla konkretnego elementu wzgledem szerokości ekranu
    return winWidth-((winWidth-objWidth)/2);
}

void select(string tab[], int dl, int kt, int baseColor, int selectedColor, int place, int offset=0){    //podswietlanie wybranego elementu menu

    for(int i=0;i<dl;i++){
        
        if(i==kt){
            SetConsoleTextAttribute(hConsole, selectedColor);
        }else{
            SetConsoleTextAttribute(hConsole, baseColor);
        }
        setCursorPosition(place-10,15+((i+offset)*2));
        cout<<tab[i];
    }
}

void helpButtons(int x, int y)
{
    SetConsoleTextAttribute(hConsole, 8);
    setCursorPosition(x,y);
    cout<<char(30)<<" gora / "<<char(31)<<" dol / "<<"<"<<char(217)<<" zatwierdz";
    //cout<<"▲ góra | ▼ dół | <┘ zatwierdź";
}
