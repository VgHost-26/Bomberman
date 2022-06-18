//funkcje uniwersalne/systemowe
#pragma once

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")
#pragma warning(disable:4996)

void setCursorPosition(int x, int y) {    //ustawinie pozycji kursora w konsoli
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //<mamy to juz w globalsach, Martin fixnij prosze kod
	cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void changeColor(int color){	//zmiana aktualnie wyswietlanego koloru
	SetConsoleTextAttribute(hConsole, color);
    
}

void setColors() {      //ustawienie domyslnej palety kolorï¿½w dla caï¿½ej gry    
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	//ANCHOR[id=color-list] color_list
	info.ColorTable[1] =  RGB(204, 204, 204);   //default grey / defCol
	info.ColorTable[2] =  RGB(110, 110, 110);   //light grey
	info.ColorTable[3] =  RGB(50, 50, 70);   	//dark grey
	info.ColorTable[4] =  RGB(0, 0, 0);   		//wolne miejsce
	info.ColorTable[5] =  RGB(205, 180, 250);  	//light
	info.ColorTable[6] =  RGB(190, 0, 255);  	//purple
	info.ColorTable[7] =  RGB(20, 204, 204);   	//teal
	info.ColorTable[8] =  RGB(255, 50, 255);	//pink
	info.ColorTable[9] =  RGB(10, 50, 255);   	//blue
	info.ColorTable[10] = RGB(0, 250, 60);   	//green
	info.ColorTable[11] = RGB(255, 0, 145);   	//plasma
	info.ColorTable[12] = RGB(255, 255, 0);  	//yellow
	info.ColorTable[13] = RGB(255,153,51);   	//orange
	info.ColorTable[14] = RGB(255, 40, 0);   	//red

	SetConsoleScreenBufferInfoEx(hConsole, &info);

}

void hideCursor() {		//ukrycie kursora
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void showCursor() {		//pokaï¿½ kursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int getWinCols(){

	CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return columns;
}

void setConsoleSize() {      //ustawienie konsoli na peï¿½ny ekran oraz dopasowanie czcionki do roï¿½dzielczoï¿½ci monitora

	int W = GetSystemMetrics(SM_CXSCREEN); //pobranie szerokosci ekranu
	int H = GetSystemMetrics(SM_CYSCREEN); //pobranie wysokosci ekranu
	int res{};

	if (W / H > 16 / 9) {     //oprymalizacja dla szerszych ekranï¿½w niï¿½ 16:9
		res = W - (((W * 9) - (H * 16)) / 9);
	}
	else {
		res = W;
	}

    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //ALT+ENTER
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0); //pelny ekran
	// system("mode 650");
	// system("mode con COLS=700");
	// ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);  //schowania scrollbara

	//ustawienia czcionki
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	//cfi.dwFontSize.Y = 27;                  
	cfi.dwFontSize.Y = res / 56.8;                  // wysokosc znaku
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Consolas"); // domyslna czcionka
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);  //zatwierdzenie zmian
}

int getKey() {		//pobranie klawisza z klawiatury
	if (_kbhit()) {
		return _getch();
	}
	return 0;
}

/*gdzie sie znajduje aktualnie kursor [input]*/
COORD getCursorPosition() {
    if (GetConsoleScreenBufferInfo(hConsole, &consoleScreenBufferInfo)) {
        return consoleScreenBufferInfo.dwCursorPosition;
    }
    else {
        COORD cordy = {0, 0}; //fail
        return cordy;
    }
}

/*ukrycie scrolbara, moze sie pokazywac bo w setConsoleSize nie fixujemy bufora;
dzialanie zalezne od domyslnych ustawien konlosi w systemie*/
void hideScrollbars() {

    GetConsoleScreenBufferInfo(hConsole, &consoleScreenBufferInfo);

    COORD new_screen_buffer_size;

    new_screen_buffer_size.X = consoleScreenBufferInfo.srWindow.Right - consoleScreenBufferInfo.srWindow.Left + 1; // kolumn
    new_screen_buffer_size.Y = consoleScreenBufferInfo.srWindow.Bottom - consoleScreenBufferInfo.srWindow.Top + 1; // wierszy

    SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);

}

/*centrowanie textu - wystarczy podac dlugosc textu; 
czym wi©cej tym bardziej w lewo przesuni©te, jak co*/
void setCenter(int length) {

    GetConsoleScreenBufferInfo(hConsole, &consoleScreenBufferInfo);

    int width = consoleScreenBufferInfo.dwMaximumWindowSize.X;

    setCursorPosition((width / 2) - (length / 2), getCursorPosition().Y);
}

/*wycentrowany text z pliku*/
void writeFromFile(string nazwa) {

    ifstream plik;
    plik.open(nazwa);
    string str{};

    if (plik.is_open()) {

        while (!plik.eof()) {
            getline(plik, str);
            setCenter(str.length());
            cout << str << endl;
        }

        plik.close();
    }
    else {
        cout << "Bˆ¥d przy otwaciu pliku !" <<endl;
    }

}

/*system("pause") bez komunikatu*/
void pauza(){
	system("pause > nul");
}
