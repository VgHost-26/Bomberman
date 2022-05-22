#pragma once
class Player : public Being{
	friend class GameMap;
private:

	string name{};
	

public:

	//konstruktor
	Player(string name, GameMap *map1){
		X=1;
		Y=1;
		this->name=name;
		Map = map1;
	}

	//SECTION getery:

	string getName(){
		return name;
	}

	//!SECTION

	//SECTION metody

	void show();
	bool moveX(int);
	bool moveY(int);
	bool moveDir(int, int, int, int, int, int(f1)());
	bool plantBomb(int);
	
	//!SECTION


};
	void Player::show(){	//wy˜wietla gracza na mapie na jego aktualnej pozycji
		setCursorPosition(X * 4,Y*2);
		cout<<"BM";
		cout<<"BM";
		setCursorPosition(X * 4,Y*2 + 1);
		cout<<"BM";
		cout<<"BM";
	}

	bool Player::moveX(int dir) {	//ruch w prawo (dir = +1) lub w lewo (dir = -1)

		if(Map->map[X + dir][Y] != 0 || (X + dir >= (sizeX - 1) || X + dir <= 0)){
			return false;
		}else{
			if(Map->map[X][Y]==0) Map->cls(X * 2,Y);
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
			if(Map->map[X][Y]==0) Map->cls(X * 2,Y);
			Y += dir;
			show();
			return true;
		}
		return false;
	}
	bool Player::moveDir(int w, int a, int s, int d, int bomb, int(f1)()){		// funkcja do poruszania si© //skˆadowe: klawisz w g¢re, lewo, d¢ˆ, prawo, funkcja do pobierania klawiszy
		
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

		}else if(key == bomb){
			return plantBomb(10);
		}
		
    	return 0;
	}

	bool Player::plantBomb(int type){	//kˆadzie bombe w aktualnym miejscu gdzie si© znajduje
		
		if(Map->map[X][Y] == 0) Map->map[X][Y] = type;

		setCursorPosition(X * 4,Y * 2);
		cout<<"/  "<<char(92);
		setCursorPosition(X * 4,Y * 2 + 1);
		cout<<char(92)<<"__/";
		
		return false;
	}

	
	


