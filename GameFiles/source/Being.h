#pragma once

class Being{
	friend class GameMap;
//private:
public:
	int X{};	//pozycja ludka X
	int Y{};	//pozycja Y
	GameMap *Map = new GameMap;

public:
	

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


	void show(){	//wy�wietla ludka na mapie na jego aktualnej pozycji
		setCursorPosition(X * 4,Y * 2);
		cout<<" "<<" ";
		setCursorPosition(X * 4,Y * 2 + 1);
		cout<<" "<<" ";
	}

	bool moveX(int dir, void show()) {	//ruch w prawo (dir = +1) lub w lewo (dir = -1)

		
		if(Map->map[X + dir][Y] != 0 || (X + dir >= (sizeX - 1) || X + dir <= 1)){
			return false;
		}else{
			cls(X * 2,Y);
			X += dir;
			show();
			return true;
		}
	

		return false;
	}
	bool moveY(int dir, void show()) {	//ruch g�ra (dir = -1) lub d�� (dir = +1)

		if(Map->map[X][Y + dir] != 0 || (Y + dir >= (sizeY - 1) || Y + dir <= 1)){
			return false;
		}else{
			cls(X * 2,Y);
			Y += dir;
			show();
			return true;
		}
		return false;
	}

	
};

