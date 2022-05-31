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
    SetConsoleTextAttribute(hConsole, _Yellow);
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
    SetConsoleTextAttribute(hConsole, _LightGrey);
    setCursorPosition(x,y);
    cout<<char(30)<<" gora / "<<char(31)<<" dol / "<<"<"<<char(217)<<" zatwierdz";
    //cout<<"▲ góra | ▼ dół | <┘ zatwierdź";
}

void clearLine(int x, int y, int width){    //czy�ci wybran� linie
    setCursorPosition(x,y);
    for(int i=0;i<width;i++) cout<<" ";

}

bool confirm(int x, int y, int dCol, int sCol, bool border=0, string msg=""){ //wypisanei na ekranie funkcjonalnego tak/nie z mo�liwoscia wyboru
            // pozycja,     kolor,   kolor wybranego el, czy ramka, wiadomosc
    if(border){
        //rysowanie ramki jesli tak wybrano
        int tmp=1;
        if(msg!=""){
            setCursorPosition(x - 3, y - 1);
            cout.width( 16 - (16 - msg.length())/2 );
            cout<<msg;
            cout.width( (16 - msg.length())/2 +1 );
            tmp=2;
        }
    }

    setCursorPosition(x,y);
    SetConsoleTextAttribute(hConsole, dCol);
    cout<<"Tak"<<"   ";
    SetConsoleTextAttribute(hConsole, sCol);
    cout<<"Nie";
    int tn=0;
    int k{};
    while(1){
        k=getKey();
        if(k==77){   // w prawo
            setCursorPosition(x,y);
            SetConsoleTextAttribute(hConsole, dCol);
            cout<<"Tak   ";
            SetConsoleTextAttribute(hConsole, sCol);
            cout<<"Nie";
            tn=0;
        }
        if(k==75){   // w lewo
            setCursorPosition(x,y);
            SetConsoleTextAttribute(hConsole, sCol);
            cout<<"Tak   ";
            SetConsoleTextAttribute(hConsole, dCol);
            cout<<"Nie";
            tn=1;
        }
        if(k==13){   //enter
            clearLine(x-2,y,  17);
            clearLine(x-2,y-2,17);
            clearLine(x-2,y-1,17);
            clearLine(x-2,y+1,17);
            return tn;
        }
    }
    return 0;
}
