#include <iostream>
#include <string>

#include "events.h"
#include "player.h"


Player::Player(){
   this->has_gold = false;
   this->spawn_x_point = 0;
   this->spawn_y_point = 0;
}

Player::Player(bool has_gold, int spawn_x_point,int spawn_y_point, int x_pos, int y_pos, bool is_alive, bool killed_wompus){
   this->has_gold = has_gold;
   this->spawn_x_point = spawn_x_point;
   this->spawn_y_point = spawn_y_point;
   this->is_alive = is_alive;
   this->killed_wompus = killed_wompus;
}

Player::Player(const Player &old_obj){
   this->has_gold = old_obj.has_gold;
   this->spawn_x_point = old_obj.spawn_x_point;
   this->spawn_y_point = old_obj.spawn_y_point;
   this->x_pos = old_obj.x_pos;
   this->y_pos = old_obj.y_pos;
}
int Player::get_x_pos(){
   return this->x_pos;
}
int Player::get_y_pos(){
   return this->y_pos;
}
bool Player::get_is_alive(){
   return this->is_alive;
}
int Player::get_spawn_x_point(){
   return this->spawn_x_point;
}
int Player::get_spawn_y_point(){
   return this->spawn_y_point;
}
bool Player::get_has_gold(){
   return this->has_gold;
}
void Player::set_x_pos(int x_pos){
   this-> x_pos = x_pos;
}
void Player::set_y_pos(int y_pos){
   this-> y_pos = y_pos;
}
void Player::set_has_gold(bool has_gold){
   this-> has_gold = has_gold;
}
void Player::set_is_alive(bool is_alive){
   this->is_alive = is_alive;
}
void Player::set_kill_wompus(bool killed_wompus){
   this->killed_wompus = killed_wompus;
}

int Player::encounter(int player_x_pos,int player_y_pos){
   return 0;
}

void Player::print_percept(){
}

void Player::call_percept(int player_x_pos, int player_y_pos, Events* player){
}
