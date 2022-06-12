#pragma once

class Player : public Being{
	friend class GameMap;
	friend class Bomb;
private:



	string name{};
	int lifes = 3;
	int score = 0;
	int color = 1;
	int *time;

	//Bomb *bombs = new Bomb[6];


public:
	bool hitted = false;

	//konstruktor
	Player(){
		X=0;
		Y=0;
		name="";
		
	}
	Player(string name, GameMap *map1, int color, int *t){
		X=1;
		Y=1;
		this->name=name;
		Map = map1;
		this->color=color;
		time = t;
		//this->bombs = *bombs;

	}
	Player(string name, GameMap *map1, int color, int *t, int x, int y){
		X=x;
		Y=y;
		this->name=name;
		this->color=color;
		Map = map1;
		time = t;
	//	this->bombs = *bombs;

	}

	//SECTION getery:

	string getName(){
		return name;
	}
	int getLifes(){
		return lifes;
	}
	int getScore(){
		return score;
	}
	int getColor(){
		return color;
	}

	//!SECTION

	//SECTION metody

	void show();
	bool moveX(int);
	bool moveY(int);
	int control(int, int, int, int, int, int);
	bool plantBomb(int);
	int minus1life();
	bool isAlive();
	void addScore(int);
	
	//!SECTION


};
	void Player::show(){	//wy˜wietla gracza na mapie na jego aktualnej pozycji
		if(Map->map[X][Y] < 30 || Map->map[X][Y] > 39){
			if(hitted == true && *time % 2 == 0){
			SetConsoleTextAttribute(hConsole, _Red);

			}else if(hitted == true && *time % 2 == 1){
				SetConsoleTextAttribute(hConsole, 0);

			}else{
				SetConsoleTextAttribute(hConsole, color);

			}
			setCursorPosition(X * 4,Y*2);
			cout<<"BM";
			cout<<"BM";
			setCursorPosition(X * 4,Y*2 + 1);
			cout<<"BM";
			cout<<"BM";
			SetConsoleTextAttribute(hConsole, defCol);
		} 
		
	}

	bool Player::moveX(int dir) {	//ruch w prawo (dir = +1) lub w lewo (dir = -1)

		if(Map->map[X + dir][Y] != 0 || (X + dir >= (sizeX - 1) || X + dir <= 0)){
			return false;
		}else{
			if(Map -> map[X][Y] >= 30 && Map -> map[X][Y] <= 39){		// czy stoi na bombie
				X += dir;
				Map -> map[X][Y] = 101;
				show();
			}else{
				if(Map -> map[X][Y] == 101 || Map -> map[X][Y] == 0) cls(X,Y);
				Map -> map[X][Y] = 0;
				X += dir;
				Map -> map[X][Y] = 101;
				show();
				return true;
			}
			
			
			
			return true;
		}
	

		return false;
	}
	bool Player::moveY(int dir) {	//ruch g¢ra (dir = -1) lub d¢ˆ (dir = +1)

		if(Map->map[X][Y + dir] != 0 || (Y + dir >= (sizeY - 1) || Y + dir <= 0)){
			return false;
		}else{
			if(Map -> map[X][Y] >= 30 && Map -> map[X][Y] <= 39){
				Y += dir;
				Map -> map[X][Y] = 101;
				show();
			
			}else{
				if(Map -> map[X][Y] == 101 || Map -> map[X][Y] == 0) cls(X,Y);
				Map -> map[X][Y] = 0;
				Y += dir;
				Map -> map[X][Y] = 101;
				show();
				return true;
			}
		}
		return false;
	}
	int Player::control(int w, int a, int s, int d, int bombKey, int key){		// funkcja do poruszania si© //skˆadowe: klawisz w g¢re, lewo, d¢ˆ, prawo, funkcja do pobierania klawiszy
		
		

		if(key == w){
			return moveY(-1);

		}else if(key == a){ //lewo
			return moveX(-1);

		}else if(key == s){ //d¢ˆ
			return moveY(1);

		}else if(key == d){ //prawo
			return moveX(1);

		}else if(key == bombKey){
			return 6;
			//return plantBomb(10);
		}else{
			return 0;
		}
		
    	return 0;
	}

	bool Player::plantBomb(int type){	//kˆadzie bombe w aktualnym miejscu gdzie si© znajduje
		
		

		// for(int i = 0; i < _bombsSize; i++){
		// 	if(!bombs[i].isExist()){
		// 		bombs[i].placeBomb(X,Y,30);	//30 - typ bomby
		// 		break;
		// 	} 
		// }

		
		return false;
	}

	
	int Player::minus1life(){
		lifes--;
		score -= _PlayerKillScoreAmount;
		return lifes;
	}
	bool Player::isAlive(){
		if(lifes > 0) return true;

		return false;
	}
	void Player::addScore(int amount){
		score += amount;
	}

