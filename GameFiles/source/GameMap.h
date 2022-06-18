#pragma once

class GameMap {
	friend class Enemy;
private:
	int timer{};
	
public:
	int map[sizeX][sizeY];
	


	//void cls(int, int);
	void loadMap(int);
	void drawBrick(int, int, int);
	void drawMap();
	/*----------------------------------------------*/
};
	


	void GameMap::loadMap(int name) {	//wczytuje wybraną mape
		
		string mapName = "maps/map_";
		mapName += (name + 48);
		mapName += ".txt";

		fstream plik;
		ofstream plikPozycje;
		plik.open(mapName);
		plikPozycje.open("playersPositions.txt");
		string tmp;

		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				plik >> map[j][i];
			}
		}
		getline(plik, tmp);	//next line
		getline(plik, tmp);
		plikPozycje<<tmp<<endl;
		getline(plik, tmp);
		plikPozycje<<tmp<<endl;

		plik.close();
	}
	void GameMap::drawBrick(int i, int j, int r = 0){

		switch (map[j][i]) {	
					/*
					case 0:	// puste pole
						cout << " " << " ";
						break;
					*/
					case _SolidWall :	// solid wall
						changeColor(_LightGrey);
						
						cout << char(219) << char(219);	// ██
						cout << char(219) << char(219);	// ██
						
						break;
					case _SoftWall :	// soft wall
						cout << char(176) << char(176);	//░░
						cout << char(176) << char(176);	//░░
						
						break;
					case _SemiSolidWall :	//
						cout << "EE";
						break;
					case _Border :	//
						
						changeColor(_DarkGrey);
						cout << char(219) << char(219);	// ██
						cout << char(219) << char(219);	// ██
						
						
						
						break;
					

				}

	}
	void GameMap::drawMap() {	//rysuje wcztaną wcześniej mape 

		int r{};
		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				
				
				setCursorPosition(j*4, i*2);
				drawBrick(i,j, r);
				
				r++;

				setCursorPosition(j*4, i*2 + 1);
				drawBrick(i,j, r);
				

				changeColor(_DefGrey);
				
				


			}
		}

	}



