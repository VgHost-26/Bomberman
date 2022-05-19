#pragma once

class GameMap {

private:

	
public:
	int map[sizeX][sizeY];
	


	void cls(int, int);
	void loadMap(int);
	void drawMap();

	/*----------------------------------------------*/
};
	void GameMap::cls(int x, int y){		//wyczyszcza jeden wybrany pixel na mapie 
		setCursorPosition(x,y);
		cout<<" "<<" ";
	}


	void GameMap::loadMap(int name) {	//wczytuje wybraną mape
		
		string mapName = "map_";
		mapName += (name + 48);
		mapName += ".txt";

		fstream plik;
		plik.open(mapName);

		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				plik >> map[j][i];
			}
		}

		plik.close();
	}
	void GameMap::drawMap() {	//rysuje wcztaną wcześniej mape 

		
		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				
				setCursorPosition(j*2, i);

				switch (map[j][i]) {	
					/*
					case 0:	// puste pole
						cout << " " << " ";
						break;
					*/
					case 1 :	// jakaś ściana
						cout << char(219) << char(219);	// ██
						break;
					case 2 :	// inna ściana
						cout << char(176) << char(176);	//░░
						break;
					case 3 :	// i tak 
						cout << "EE";
						break;
					case 4 :	// dalej
						cout << "EE";
						break;
					case 5 :	//
						cout << "EE";
						break;
					case 6 :	//
						cout << "EE";
						break;


				}
				


			}
		}

	}
	// void drawBorder() {
	// 	for (int i = 0; i < sizeY; i++) {
	// 		for (int j = 0; j < sizeX; j++) {

	// 			if ((i == 0 || i == sizeY - 1) || (j == 0 || j == sizeX - 1)) {
	// 				setCursorPosition(j * 2, i);
	// 				cout << char(219) << char(219);	// ██
	// 			}
	// 		}
	// 	}
	// }



