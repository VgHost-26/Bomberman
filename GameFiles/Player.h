#pragma once
class Player : public Being{
	friend class GameMap;
	friend class Bomb;
private:

	string name{};
	Bomb *bombs = new Bomb[6];
public:

	//konstruktor
	Player(string name, GameMap *map1, Bomb *bombs[]){
		X=1;
		Y=1;
		this->name=name;
		Map = map1;
		this->bombs = *bombs;

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
	bool control(int, int, int, int, int, int(f1)());
	bool plantBomb(int);
	
	//!SECTION


};
	void Player::show(){	//wy�wietla gracza na mapie na jego aktualnej pozycji
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
			if(Map->map[X][Y]==0) cls(X,Y);
			X += dir;
			show();
			return true;
		}
	

		return false;
	}
	bool Player::moveY(int dir) {	//ruch g�ra (dir = -1) lub d�� (dir = +1)

		if(Map->map[X][Y + dir] != 0 || (Y + dir >= (sizeY - 1) || Y + dir <= 0)){
			return false;
		}else{
			if(Map->map[X][Y]==0) cls(X,Y);
			Y += dir;
			show();
			return true;
		}
		return false;
	}
	bool Player::control(int w, int a, int s, int d, int bombKey, int(f1)()){		// funkcja do poruszania si� //sk�adowe: klawisz w g�re, lewo, d��, prawo, funkcja do pobierania klawiszy
		
		int key{};
		key = f1();

		if(key == w){
			return moveY(-1);

		}else if(key == a){ //lewo
			return moveX(-1);

		}else if(key == s){ //d��
			return moveY(1);

		}else if(key == d){ //prawo
			return moveX(1);

		}else if(key == bombKey){
			return plantBomb(10);
		}
		
    	return 0;
	}

	bool Player::plantBomb(int type){	//k�adzie bombe w aktualnym miejscu gdzie si� znajduje
		
		

		for(int i = 0; i < _bombsSize; i++){
			if(!bombs[i].isExist()){


				if(Map->map[X][Y] == 0) Map->map[X][Y] = type;

				setCursorPosition(X * 4,Y * 2);
				cout<<"/  "<<char(92);
				setCursorPosition(X * 4,Y * 2 + 1);
				cout<<char(92)<<"__/";

				bombs[i].placeBomb(X,Y,1);
				Map->map[X][Y] = 30;	//30 - typ bomby
				break;
			} 
		}

		
		return false;
	}

	
	


