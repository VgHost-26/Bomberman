#pragma once
class Player : public Being{
	friend class GameMap;
private:

	string name{};
	

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
	string getName(){
		return name;
	}

	//metody

	void show();
	bool moveX(int);
	bool moveY(int);
	bool moveDir(int, int, int, int, int(f1)());



};
	void Player::show(){	//wy˜wietla gracza na mapie na jego aktualnej pozycji
		setCursorPosition(X * 2,Y);
		cout<<"BM";
	}

	bool Player::moveX(int dir) {	//ruch w prawo (dir = +1) lub w lewo (dir = -1)

		if(Map->map[X + dir][Y] != 0 || (X + dir >= (sizeX - 1) || X + dir <= 0)){
			return false;
		}else{
			Map->cls(X * 2,Y);
			X += dir;
			show();
			return true;
		}
	

		return false;
	}
	bool Player::moveY(int dir) {	//ruch g¢ra (dir = -1) lub d¢ˆ (dir = +1)

		if(Map->map[X][Y + dir] != 0 || (Y + dir >= (sizeY - 1) || Y + dir <= 0)){
			return false;
		}else{
			Map->cls(X * 2,Y);
			Y += dir;
			show();
			return true;
		}
		return false;
	}
	bool Player::moveDir(int w, int a, int s, int d, int(f1)()){		// funkcja do poruszania si© //skˆadowe: klawisz w g¢re, lewo, d¢ˆ, prawo, funkcja do pobierania klawiszy
		
		int key{};
		key = f1();

		if(key == w){
			return moveY(-1);

		}else if(key == a){ //lewo
			return moveX(-1);

		}else if(key == s){ //d¢ˆ
			return moveY(1);

		}else if(key == d){ //prawo
			return moveX(1);

		}
		
    	return 0;
	}

	
	


