//funkcje uniwersalne/systemowe
#pragma once

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")
#pragma warning(disable:4996)

void setCursorPosition(int x, int y) {    //ustawinei pozycji kursora w konsoli
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void changeColor(int color){	//zmiana aktualnie wyswietlanego koloru
	SetConsoleTextAttribute(hConsole, color);
    
}

void setColors() {      //ustawienie domyslnej palety kolor�w dla ca�ej gry    
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	//ANCHOR[id=color-list] color_list
	info.ColorTable[1] =  RGB(204, 204, 204);   //default grey / defCol
	info.ColorTable[2] =  RGB(110, 110, 110);   //light grey
	info.ColorTable[3] =  RGB(50, 50, 70);   	//dark grey
	info.ColorTable[4] =  RGB(0, 0, 0);   //
	info.ColorTable[6] =  RGB(0, 0, 0);   //
	info.ColorTable[5] =  RGB(30, 150, 50);  	//dark green
	info.ColorTable[7] =  RGB(204, 204, 204);   //kolor na potrzeby poprawnego wyświetlania kolorów w kreatorze postaci
	info.ColorTable[8] =  RGB(255, 50, 255);	//pink
	info.ColorTable[9] =  RGB(10, 50, 255);   //blue
	info.ColorTable[10] = RGB(0, 250, 60);   	//green
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
void showCursor() {		//poka� kursor
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

void setConsoleSize() {      //ustawienie konsoli na pe�ny ekran oraz dopasowanie czcionki do ro�dzielczo�ci monitora

	int W = GetSystemMetrics(SM_CXSCREEN); //pobranie szerokosci ekranu
	int H = GetSystemMetrics(SM_CYSCREEN); //pobranie wysokosci ekranu
	int res{};

	if (W / H > 16 / 9) {     //oprymalizacja dla szerszych ekran�w ni� 16:9
		res = W - (((W * 9) - (H * 16)) / 9);
	}
	else {
		res = W;
	}

    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //ALT+ENTER
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0); //pelny ekran ... i cztery nast�pne te�
	// system("mode 650");
	// system("mode con COLS=700");
	// ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	// SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

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