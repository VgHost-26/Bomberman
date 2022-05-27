#pragma once

class GameMap {
	friend class Enemy;
private:

	
public:
	int map[sizeX][sizeY];
	


	//void cls(int, int);
	void loadMap(int);
	void drawBrick(int, int);
	void drawMap();
	/*----------------------------------------------*/
};
	


	void GameMap::loadMap(int name) {	//wczytuje wybraną mape
		
		string mapName = "maps/map_";
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
	void GameMap::drawBrick(int i, int j){

		switch (map[j][i]) {	
					/*
					case 0:	// puste pole
						cout << " " << " ";
						break;
					*/
					case _SolidWall :	// solid wall
						cout << char(219) << char(219);	// ██
						break;
					case _SoftWall :	// soft wall
						cout << char(176) << char(176);	//░░
						break;
					case _SemiSolidWall :	//
						cout << "EE";
						break;
					case 4 :	//
						cout << "EE";
						break;
					case 5 :	//
						cout << "EE";
						break;

				}

	}
	void GameMap::drawMap() {	//rysuje wcztaną wcześniej mape 

		
		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				
				
				setCursorPosition(j*4, i*2);
				drawBrick(i,j);
				drawBrick(i,j);
				
				setCursorPosition(j*4, i*2 + 1);
				drawBrick(i,j);
				drawBrick(i,j);
				

				
				


			}
		}

	}



