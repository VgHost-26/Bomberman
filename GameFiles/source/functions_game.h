//funkcje wykorzystywane tylko do pliku game.cpp
#pragma once

//wyczyszcza jeden wybrany pixel na mapie 
void cls(int x, int y){		
		setCursorPosition(x * 4,y * 2);
		cout<<" "<<" ";
		cout<<" "<<" ";
		setCursorPosition(x * 4,y * 2 + 1);
		cout<<" "<<" ";
		cout<<" "<<" ";
}

//int na stringa
string int2string(int x){
	string str{}, strTmp{};
	while(x > 0){
		strTmp = x % 10 + 48;
		x /= 10;
		str = strTmp + str;
	}
	return str;
}

//konwertuje sekundy na format mm:ss
string secToTime(int t){
	string min="00", sec="00";
	int Imin{}, Isec{};
	
	Imin = t / 60;
	Isec = t % 60;
	
	if(Imin < 10){
		if(Imin == 0){
			min = "00";
		}else{
			min = "0" + int2string(Imin);
		}
	}else{
		min =  int2string(Imin);
	}

	if(Isec < 10){
		if(Isec == 0){
			sec = "00";
		}else{
			sec = "0" +  int2string(Isec);
		}
	}else{
		sec = int2string(Isec);
	}

	return min + ":" + sec;
}

//wyswietla tekst w ramce, ostatni parametr obcina g¢rn¥ graw©dz gdy FALSE
void coutWithBorder(string str, int x, int y, bool full = true){
	
	if(full){
		setCursorPosition(x - (str.length()/2), y);
		cout<<char(201);	// É
		
		for(int i=0; i < str.length() + 2; i++){
			cout<<char(205);
		}
		cout<< char(187); 	// »
	}

	
	
	setCursorPosition(x - (str.length()/2), y+1);
	cout<< char(186) << " " << str << " "<< char(186);
	
	setCursorPosition(x - (str.length()/2), y+2);
	cout<< char(200); 	// ¼
	for(int i=0; i < str.length() + 2; i++){
		cout<<char(205);
	}
	cout<< char(188); 	// ¼

}

