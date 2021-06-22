#include <iostream>
#include <string>

#include "events.h"
#include "empty_room.h"


empty_room::empty_room(){
}


empty_room::empty_room(string type,char symbol,int x_pos,int y_pos):Events(type,symbol,x_pos,x_pos){
   this->type = type;
   this->symbol = symbol;
   this->x_pos = x_pos;
   this->y_pos = y_pos;
}

empty_room::empty_room(const empty_room &old_obj){
   this->type = old_obj.type;
   this->symbol = old_obj.symbol;
}




int empty_room::encounter(int player_x_pos,int player_y_pos){
   if(this->type == "i_wall"){
      return -1;
   }
   else if(this->type == "wall"){
      return -1;
   }
   else if(player_x_pos == x_pos && player_y_pos == y_pos){
      return 1;
   }
   else{
      return 0;
   }
}

void empty_room::print_percept(){
}

void empty_room::call_percept(int x,int y){
}
