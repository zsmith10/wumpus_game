#include <iostream>
#include <string>

#include "events.h"
#include "room.h"


Room::Room(){
   this->component = NULL;
   this->occupied = 0;
   this->c = " ";
}

Room::Room(const Room &old_obj){
   this->occupied = old_obj.occupied;
   this->component = old_obj.component;
   this->c = old_obj.c;
}

Room::~Room(){
	if (this->component != NULL){
		delete this->component;
		this->component = NULL;
	}
}
/*
Room& Room::operator=(const Room &old_obj){
   if (this != &old_obj){

      if (this->component != NULL){
         delete [] this->component;
      }
      this->component = new Events();
      for (int i = 0; i < this->monkey_num; ++i){
         this->monkeys[i] = old_obj.monkeys[i];
      }
      */
void Room::set_components(Events* component){
   this->component = component;
}

Events* Room::get_components(){
   return this->component;
}

string Room::get_c(){
   return this-> c;
}
