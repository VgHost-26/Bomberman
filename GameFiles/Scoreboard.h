#pragma once
//28
class Scoreboard {

private:


public:
    void setBorder();
    void show();
    void update();
    void drawLine(int, int);


};

void Scoreboard::show(){

    setCursorPosition(sizeX, 0);
    cout << "123456789";
  //  for(int i =)
    

}
void Scoreboard::setBorder(){

    drawLine(2,0);
    drawLine(2, (sizeY * 2) -2);
    
  //  for(int i =)
    

}
void Scoreboard::update(){

    setCursorPosition(sizeX, 0);
    cout << "123456789";
  //  for(int i =)
    

}
void Scoreboard::drawLine(int w, int pozY){
   
    
    for(int j=0; j < w; j++){
        setCursorPosition(sizeX * 4, pozY + j);

        for(int i=0; i < 28; i++){
            cout << char(219);
        }
    }
}