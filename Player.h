#pragma once
class Player{
	friend class GameMap;
//private:
public:
	string name{};
	int X{};	//pozycja ludka X
	int Y{};	//pozycja Y
	GameMap Map{};

public:

	Player(string name, GameMap Map){
		X=0 + marginLeft*2;
		Y=0 + marginTop;
		this->name=name;
		this->Map=Map;
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
		setCursorPosition(X,Y);
		cout<<"BM";
	}

	bool ruchX(int dir) {	//ruch w prawo (dir = +1) lub w lewo (dir = -1)

		
		if(Map.map[X + dir][Y] != 0 || X + dir >= (sizeX + 2) || X + dir <= 1){
			return false;
		}else{
			Map.cls(X,Y);
			X += dir;
			show();
			return true;
		}
	

		return false;
	}
	bool ruchY(int dir) {	//ruch g¢ra (dir = -1) lub d¢ˆ (dir = +1)

		if(Map.map[X][Y + dir] != 0 || Y + dir >= sizeY || Y + dir <= 1){
			return false;
		}else{
			Map.cls(X,Y);
			Y += dir;
			show();
			return true;
		}
		return false;
	}

};

