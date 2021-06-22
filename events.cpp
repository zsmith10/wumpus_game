#include <iostream>
#include <string>

#include "events.h"


Events::Events(){
   this-> type = " ";
   this-> symbol = ' ';
   this->  x_pos = 0;
   this->  y_pos = 0;
}

Events::Events(string type,char symbol, int x_pos,int y_pos){
   this-> type = type;
   this-> symbol = symbol;
   this->  x_pos = x_pos;
   this->  y_pos = y_pos;
}

Events::Events(const Events &old_obj){
   this->type = old_obj.type;
   this->symbol = old_obj.symbol;
   this-> x_pos = old_obj.x_pos;
   this-> y_pos = old_obj.y_pos;
}

string Events::get_type(){
   return this->type;
}

char Events::get_symbol(){
   return this->symbol;
}

int Events::get_x_pos(){
   return this->x_pos;
}

int Events::get_y_pos(){
   return this->y_pos;
}
void Events::set_type(string type){
   this->type = type;
}

void Events::set_symbol(char symbol){
   this->symbol = symbol;
}

void Events::set_x_pos(int x_pos){
   this-> x_pos = x_pos;
}
void Events::set_y_pos(int y_pos){
   this-> y_pos = y_pos;
}
