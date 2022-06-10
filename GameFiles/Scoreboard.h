#pragma once
//28
class Scoreboard {
    friend class Player;
    friend class GameMap;

private:
	int width;
	Player p1{}, p2{};

public:
    Scoreboard(Player *p1, Player *p2);
    void setBorder();
    void show();
    void update();
    void drawLine(int, int);


};

Scoreboard::Scoreboard(Player *p1, Player *p2){

	width = getWinCols() - (sizeX * 4);
	this -> p1 = *p1;
	this -> p2 = *p2;
	
}

void Scoreboard::show(){

    setCursorPosition((sizeX * 4 ) + 1, 3);
    cout << p1.getName();
    setCursorPosition((sizeX * 4 ) + 1, 5);
	cout << "Lifes: " << p1.getLifes();
    setCursorPosition((sizeX * 4 ) + 1, 7);
	cout << "Score: " << p1.getScore();
	

	setCursorPosition((sizeX * 4 ) + 1, 1 + sizeY);
    cout << p2.getName();
    setCursorPosition((sizeX * 4 ) + 1, 3 + sizeY);
	cout << "Lifes: " << p2.getLifes();
    setCursorPosition((sizeX * 4 ) + 1, 5 + sizeY);
	cout << "Score: " << p2.getScore();
    

}
void Scoreboard::setBorder(){

    drawLine(2,0);
    drawLine(2, (sizeY * 2) -2);
	drawLine(1, sizeY-1);
    
  //  for(int i =)
    

}
void Scoreboard::update(){

    setCursorPosition(sizeX, 0);
   
    

}
void Scoreboard::drawLine(int w, int pozY){
  
    
    for(int j=0; j < w; j++){
        setCursorPosition(sizeX * 4, pozY + j);

        for(int i=0; i < width; i++){
            cout << char(219);
        }
    }
}