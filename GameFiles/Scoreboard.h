#pragma once
//28
class Scoreboard {
    friend class Player;
    friend class GameMap;

private:
	float time = 120; //sekund
	int width;
	//Player p1{}, p2{};

public:
    Scoreboard();
    void setBorder();
    void show(Player *p1, Player *p2);
    void update(Player *p1, Player *p2);
    void drawLine(int, int);
    bool isTimeOver();

};

Scoreboard::Scoreboard(){

	width = getWinCols() - (sizeX * 4);
	//p1 = p1;
	//p2 = p2;
	
}

void Scoreboard::show(Player *p1, Player *p2){

    setCursorPosition((sizeX * 4 ) + 1, 3);
	cout << "Time left: " << secToTime(time);

    changeColor(p1->getColor());
    setCursorPosition((sizeX * 4 ) + 1, 7);
    cout << p1->getName();
    setCursorPosition((sizeX * 4 ) + 1, 9);
	cout << "Lifes: " << p1->getLifes();
    setCursorPosition((sizeX * 4 ) + 1, 11);
	cout << "Score: " << p1->getScore();
	

    changeColor(p2->getColor());
	setCursorPosition((sizeX * 4 ) + 1, 2 + sizeY);
    cout << p2->getName();
    setCursorPosition((sizeX * 4 ) + 1, 4 + sizeY);
	cout << "Lifes: " << p2->getLifes();
    setCursorPosition((sizeX * 4 ) + 1, 6 + sizeY);
	cout << "Score: " << p2->getScore();
    

}
void Scoreboard::setBorder(){
    changeColor(_DarkGrey);

    drawLine(2, 0);
    drawLine(1, 5);
	drawLine(1, sizeY);
    drawLine(2, (sizeY * 2) - 2);
    
  //  for(int i =)
    changeColor(_DefGrey);
    

}
void Scoreboard::update(Player *p1, Player *p2){
	time-=1;

	if(time <= 30) changeColor(_Orange);
	if(time <= 10) changeColor(_Red);


    setCursorPosition((sizeX * 4 ) + 1 + 11, 3);
    cout<<"          ";
    setCursorPosition((sizeX * 4 ) + 1 + 11, 3);
	cout << secToTime(time);

	changeColor(_DefGrey);

    setCursorPosition((sizeX * 4 ) + 1 + 7, 9);
	cout << p1->getLifes();
    setCursorPosition((sizeX * 4 ) + 1 + 7, 11);
    cout<<"          ";
    setCursorPosition((sizeX * 4 ) + 1 + 7, 11);
	cout << p1->getScore();
	

	
    setCursorPosition((sizeX * 4 ) + 1 + 7, 4 + sizeY);
	cout << p2->getLifes();
    setCursorPosition((sizeX * 4 ) + 1 + 7, 6 + sizeY);
    cout<<"          ";
    setCursorPosition((sizeX * 4 ) + 1 + 7, 6 + sizeY);
	cout << p2->getScore();
   
    

}
void Scoreboard::drawLine(int w, int pozY){
  
    
    for(int j=0; j < w; j++){
        setCursorPosition(sizeX * 4, pozY + j);

        for(int i=0; i < width; i++){
            cout << char(219);
        }
    }
}
bool Scoreboard::isTimeOver(){
    if(time <= 0) return true;
    return false;
}