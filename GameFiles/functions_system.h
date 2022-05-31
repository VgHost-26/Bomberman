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
void setColors() {      //ustawienie domyslnej palety kolorów dla ca³ej gry    
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	//ANCHOR[id=color-list] color_list
	info.ColorTable[1] =  RGB(204, 204, 204);   //default grey
	info.ColorTable[2] =  RGB(0, 0, 0);   //
	info.ColorTable[3] =  RGB(0, 0, 0);   //
	info.ColorTable[4] =  RGB(0, 0, 0);   //
	info.ColorTable[5] =  RGB(0, 0, 0);   //
	info.ColorTable[6] =  RGB(0, 0, 0);   //
	info.ColorTable[8] =  RGB(0, 0, 0);   //
	info.ColorTable[9] =  RGB(0, 0, 0);   //
	info.ColorTable[10] = RGB(0, 0, 0);   //
	info.ColorTable[12] = RGB(255, 0, 0);   //
	info.ColorTable[13] = RGB(255,153,51);   //orange
	info.ColorTable[14] = RGB(0, 0, 255);   //

	SetConsoleScreenBufferInfoEx(hConsole, &info);

}
void hideCursor() {		//ukrycie kursora
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void showCursor() {		//poka¿ kursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void setConsoleSize() {      //ustawienie konsoli na pe³ny ekran oraz dopasowanie czcionki do roŸdzielczoœci monitora

	int W = GetSystemMetrics(SM_CXSCREEN); //pobranie szerokosci ekranu
	int H = GetSystemMetrics(SM_CYSCREEN); //pobranie wysokosci ekranu
	int res{};

	if (W / H > 16 / 9) {     //oprymalizacja dla szerszych ekranów ni¿ 16:9
		res = W - (((W * 9) - (H * 16)) / 9);
	}
	else {
		res = W;
	}

	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0); //pelny ekran ... i cztery nastêpne te¿
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