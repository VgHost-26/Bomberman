#pragma once
class Player{
	friend class GameMap;
//private:
public:
	string name{};
	int X{};	//pozycja ludka X
	int Y{};	//pozycja Y
	GameMap *Map = new GameMap;

public:
	//konstruktor
	Player(string name, GameMap *map1){
		X=2;
		Y=2;
		this->name=name;
		Map = map1;
	}

	//setery
	void setX(int x) {
		X = x;
	}
	void setY(int y) {
		Y = y;
	}

	//getery
	int getX() {
		return X;
	}
	int getY() {
		return Y;
	}

	//metody


	void show(){	//wy˜wietla gracza na mapie na jego aktualnej pozycji
		setCursorPosition(X * 2,Y);
		cout<<"BM";
	}

	bool moveX(int dir) {	//ruch w prawo (dir = +1) lub w lewo (dir = -1)

		
		if(Map->map[X + dir][Y] != 0 || (X + dir >= (sizeX - 1) || X + dir <= 1)){
			return false;
		}else{
			Map->cls(X * 2,Y);
			X += dir;
			show();
			return true;
		}
	

		return false;
	}
	bool moveY(int dir) {	//ruch g¢ra (dir = -1) lub d¢ˆ (dir = +1)

		if(Map->map[X][Y + dir] != 0 || (Y + dir >= (sizeY - 1) || Y + dir <= 1)){
			return false;
		}else{
			Map->cls(X * 2,Y);
			Y += dir;
			show();
			return true;
		}
		return false;
	}

	
};

