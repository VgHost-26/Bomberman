#pragma once

class GameMap {

private:

	
public:
	int map[sizeX][sizeY];
	


	void cls(int, int);
	void loadMap(int);
	void drawBrick(int, int);
	void drawMap();
	/*----------------------------------------------*/
};
	void GameMap::cls(int x, int y){		//wyczyszcza jeden wybrany pixel na mapie 
		setCursorPosition(x*2,y*2);
		cout<<" "<<" ";
		cout<<" "<<" ";
		setCursorPosition(x*2,y*2 + 1);
		cout<<" "<<" ";
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
	void GameMap::drawBrick(int i, int j){

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



