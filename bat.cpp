#include <iostream>
#include <string>
#include "events.h"
#include "bat.h"



Bat::Bat(){
}

Bat::Bat(string type, char symbol, int x_pos,int y_pos):Events(type,symbol,x_pos,y_pos){
   this->type = type;
   this->symbol = symbol;
   this->x_pos = x_pos;
   this->y_pos = y_pos;
}

Bat::Bat(const Bat &old_obj){
   this->type = old_obj.type;
   this->symbol = old_obj.symbol;
   this-> x_pos = old_obj.x_pos;
   this-> y_pos = old_obj.y_pos;
}



void Bat::call_percept(int player_x_pos, int player_y_pos){
   if(player_x_pos == x_pos && player_y_pos == y_pos-1){
      cout << "You Hear Wings Flapping" << endl;
   }
   else if(player_x_pos == x_pos && player_y_pos == y_pos+1){
      cout << "You Hear Wings Flapping" << endl;
   }
   else if(player_x_pos == x_pos-1 && player_y_pos == y_pos){
      cout << "You Hear Wings Flapping" << endl;
   }
   else if(player_x_pos == x_pos+1 && player_y_pos == y_pos){
      cout << "You Hear Wings Flapping" << endl;
   }
}
int Bat::encounter(int player_x_pos,int player_y_pos){
   if(player_x_pos == x_pos && player_y_pos == y_pos){
      return 5;
   }
   else{
      return 0;
   }
}
