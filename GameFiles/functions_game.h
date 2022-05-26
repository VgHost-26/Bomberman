//funkcje wykorzystywane tylko do pliku game.cpp
#pragma once

void cls(int x, int y){		//wyczyszcza jeden wybrany pixel na mapie 
		setCursorPosition(x * 4,y * 2);
		cout<<" "<<" ";
		cout<<" "<<" ";
		setCursorPosition(x * 4,y * 2 + 1);
		cout<<" "<<" ";
		cout<<" "<<" ";
	}