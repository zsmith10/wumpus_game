
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "events.h"
#include "room.h"
#include "game.h"
#include "player.h"
#include "empty_room.h"
#include "wompus.h"
#include "pit.h"
#include "gold.h"
#include "bat.h"

Game::Game(){
   this-> wompus_num = 0;
   this-> bat_num = 0;
   this-> pit_num = 0;
   this-> player_num = 0;
   this-> dimension = 0;
   this-> debug_mode = false;
   this-> player_x_pos = 0;
   this-> player_y_pos = 0;
   this-> wompus_x_pos = 0;
   this-> wompus_y_pos = 0;
   this-> size = 0;
   this-> row = 0;
   this-> col = 0;
   this-> arrow_num = 3;
}

Game::Game(int wompus_num,int bat_num, int player_num,int pit_num,int dimension, bool debug, int arrow_num){
	this->wompus_num = wompus_num;
	this->bat_num = bat_num;
	this->pit_num = pit_num;
   this->player_num = player_num;
	this->dimension = dimension;
   this->debug_mode = debug;
   this-> arrow_num = arrow_num;
}


Game::Game(const Game &old_obj){
   this->wompus_num = old_obj.wompus_num;
   this->bat_num = old_obj.bat_num;
   this->pit_num = old_obj.pit_num;
   this->player_num = old_obj.player_num;
   this->dimension = old_obj.dimension;
}

int Game::get_wompus_num(){
   return this->wompus_num;
}
int Game::get_bat_num(){
   return this->bat_num;
}
int Game::get_pit_num(){
   return this->pit_num;
}
int Game::get_player_num(){
   return this->player_num;
}
int Game::get_dimension(){
   return this->dimension;
}
bool Game::get_debug(){
   return this->debug_mode;
}
int Game::get_wompus_x_pos(){
   return this->wompus_x_pos;
}
int Game::get_wompus_y_pos(){
   return this->wompus_y_pos;
}
int Game::get_player_x_pos(){
   return this->player_x_pos;
}
int Game::get_player_y_pos(){
   return this->player_y_pos;
}

void Game::set_size(int size){
   this->size = size;
}
void Game::set_row(int row){
   this->row = row;
}
void Game::set_col(int col){
   this->col = col;
}
void Game::set_wompus_x_pos(int wompus_x_pos){
   this->wompus_x_pos = wompus_x_pos;
}
void Game::set_wompus_y_pos(int wompus_y_pos){
   this->wompus_y_pos = wompus_y_pos;
}
void Game::set_player_x_pos(int player_x_pos){
   this->player_x_pos = player_x_pos;
}
void Game::set_player_y_pos(int player_y_pos){
   this->player_y_pos = player_y_pos;
}

bool Game::is_dead(){
   if(player_num == 0){
      return true;
   }
   else{
      return false;
   }
}

void Game::swap_wompus(int x_pos ,int y_pos){
   Events* temp = rooms[wompus_y_pos][wompus_x_pos].get_components();
   rooms[wompus_y_pos][wompus_x_pos].set_components(rooms[y_pos][x_pos].get_components());
   rooms[y_pos][x_pos].set_components(temp);
   rooms[wompus_y_pos][wompus_x_pos].get_components()->set_x_pos(wompus_x_pos);
   rooms[wompus_y_pos][wompus_x_pos].get_components()->set_y_pos(wompus_y_pos);
   rooms[y_pos][x_pos].get_components()->set_x_pos(x_pos);
   rooms[y_pos][x_pos].get_components()->set_y_pos(y_pos);
   set_wompus_x_pos(x_pos);
   set_wompus_y_pos(y_pos);
}

//longer then 15 lines because it has to check the event
void Game::move_player(int x_pos, int y_pos){
   int encountered = rooms[y_pos][x_pos].get_components()->encounter(x_pos, y_pos);
   if(encountered == 1){
      rooms[y_pos][x_pos].get_components()->set_symbol('*');
      rooms[player_y_pos][player_x_pos].get_components()->set_symbol(' ');
      set_player_x_pos(x_pos);
      set_player_y_pos(y_pos);
   }
   else if(encountered == 2){
      //mem leak
      rooms[y_pos][x_pos].set_components(new empty_room("empty_room", ' ',x_pos,y_pos));
      rooms[y_pos][x_pos].get_components()->set_symbol('*');
      rooms[player_y_pos][player_x_pos].get_components()->set_symbol(' ');
      set_player_x_pos(x_pos);
      set_player_y_pos(y_pos);
      player.set_has_gold(true);
      this->message = "Picked Up Gold!";
   }
   else if(encountered == 3){
      player.set_is_alive(false);
      rooms[y_pos][x_pos].set_components(new empty_room("empty_room", ' ',x_pos,y_pos));
      rooms[y_pos][x_pos].get_components()->set_symbol('*');
      rooms[player_y_pos][player_x_pos].get_components()->set_symbol(' ');
      this->message = "The Wumpus Has Killed You";
   }
   if(encountered == 4){
      player.set_is_alive(false);
      rooms[y_pos][x_pos].set_components(new empty_room("empty_room", ' ',x_pos,y_pos));
      rooms[y_pos][x_pos].get_components()->set_symbol('*');
      rooms[player_y_pos][player_x_pos].get_components()->set_symbol(' ');
      this->message = "You Have Fallen Into a Bottomless Pit!";
   }
   if(encountered == 5){
      bool has_moved = false;
      do{
         int i = rand() % row;
         int j = rand() % col;
         if(rooms[i][j].get_components()->get_type() == "empty_room"){
            rooms[i][j].get_components()->set_symbol('*');
            rooms[player_y_pos][player_x_pos].get_components()->set_symbol(' ');
            set_player_x_pos(j);
            set_player_y_pos(i);
            has_moved = true;
         }
         }while(!has_moved);
         this->message = "Encountered a Super Bat, It Has Taken You To a Random Room!";
      }
   }

//longer then 15 lines becuase it gets the choice of the player and has to error handle
void Game::player_choice(){
   int next_pos = 0;
   char direction;
   bool got_direction = false;
   do{
      system("/bin/stty raw");
      direction = tolower(getchar());
      cout << " " << '\r';
      system("/bin/stty cooked");
      if(direction == 'w'){
         got_direction = true;
         next_pos = (get_player_y_pos() - 1);
         move_player(player_x_pos, next_pos);
      }
      else if(direction == 's'){
         got_direction = true;
         next_pos = (get_player_y_pos() + 1);
         move_player(player_x_pos, next_pos);
      }
      else if(direction == 'd'){
         got_direction = true;
         next_pos = (get_player_x_pos() + 1);
         move_player(next_pos,player_y_pos);
      }
      else if(direction == 'a'){
         got_direction = true;
         next_pos = (get_player_x_pos() - 1);
         move_player(next_pos,player_y_pos);
      }
      else if(direction == ' '){
         shoot_arrow();
      }
   }while(!got_direction);
}

//more then 15 lines because arrow must check if it encountered anything
void Game::shoot_north(){
   int encountered = 0;
   cout << "\nShooting North" << endl;
   for(int i = 1; i <= 3; i++){
      encountered = rooms[player_y_pos-i][player_x_pos].get_components()->encounter(player_x_pos,(player_y_pos-i));
      if(encountered == -1){
         break;
      }
      else if(encountered == 1){
         rooms[player_y_pos-i][player_x_pos].get_components()->set_symbol('^');
         print_map(row,col);
         usleep(500000);
         rooms[player_y_pos-i][player_x_pos].get_components()->set_symbol(' ');
         print_map(row,col);
      }
      else if(encountered == 3){
         killed_wompus = true;
         rooms[player_y_pos-i][player_x_pos].set_components(new empty_room("empty_room", ' ',player_y_pos-i,player_x_pos));
         set_wompus_x_pos(-1);
         set_wompus_y_pos(-1);
         print_map(row,col);
         cout << "Killed The Wumpus!" << endl;
         break;
      }

   }
   if(!killed_wompus){
      move_wompus();
   }
}

//longer then 15 lines because the arrow is moving and the has to check the room its in
void Game::shoot_south(){
   int encountered = 0;
   cout << "\nShooting South" << endl;
   for(int i = 1; i <= 3; i++){
      encountered = rooms[player_y_pos+i][player_x_pos].get_components()->encounter(player_x_pos,(player_y_pos+i));
      if(encountered == -1){
         break;
      }
      else if(encountered == 1){
         rooms[player_y_pos+i][player_x_pos].get_components()->set_symbol('v');
         print_map(row,col);
         usleep(500000);
         rooms[player_y_pos+i][player_x_pos].get_components()->set_symbol(' ');
         print_map(row,col);
      }
      else if(encountered == 3){
         killed_wompus = true;
         rooms[player_y_pos+i][player_x_pos].set_components(new empty_room("empty_room", ' ',player_y_pos+i,player_x_pos));
         set_wompus_x_pos(-1);
         set_wompus_y_pos(-1);
         print_map(row,col);
         cout << "Killed The Wumpus!" << endl;
         break;
      }

   }
   if(!killed_wompus){
      move_wompus();
   }
}
//longer then 15 lines because the arrow is moving and the has to check the room its in
void Game::move_wompus(){
   bool has_moved = false;
   do{
      int i = rand() % row;
      int j = rand() % col;
      if (rooms[i][j].get_components()->get_type() == "empty_room"){
         swap_wompus(j,i);
         print_map(row, col);
         has_moved = true;
      }
   }while(!has_moved);
   cout << "Wumpus Has Moved!" << endl;
}
//longer then 15 lines because the arrow is moving and the has to check the room its in
void Game::shoot_arrow(){
   if(this->arrow_num == 0){
      cout << "Out of Arrows! " << endl;
      return;
   }
   bool got_choice = false;
   char c = ' ';
   do{
      cout << "Which Direction? " << endl;
      cout << "Enter W,A,S,D: ";
      c = tolower(getchar());
      if(c == 'w'){
         shoot_north();
         this->arrow_num--;
         got_choice = true;
      }
      else if(c == 's'){
         shoot_south();
         this->arrow_num--;
         got_choice = true;
      }
      else if(c == 'd'){
         shoot_east();
         this->arrow_num--;
         got_choice = true;
      }
      else if(c == 'a'){
         shoot_west();
         this->arrow_num--;
         got_choice = true;
      }
      else{
         cout << "Invalid Choice. Try Again" << endl;
      }
   }while(!got_choice);
}
//longer then 15 lines because the arrow is moving and the has to check the room its in
void Game::shoot_west(){
   int encountered = 0;
   cout << "\nShooting West" << endl;
   for(int i = 1; i <= 3; i++){
      encountered = rooms[player_y_pos][player_x_pos-i].get_components()->encounter(player_x_pos-i,(player_y_pos));
      if(encountered == -1){
         break;
      }
      else if(encountered == 1){
         rooms[player_y_pos][player_x_pos-i].get_components()->set_symbol('<');
         print_map(row,col);
         usleep(500000);
         rooms[player_y_pos][player_x_pos-i].get_components()->set_symbol(' ');
         print_map(row,col);
      }
      else if(encountered == 3){
         killed_wompus = true;
         rooms[player_y_pos][player_x_pos-i].set_components(new empty_room("empty_room", ' ',player_y_pos,player_x_pos-i));
         set_wompus_x_pos(-1);
         set_wompus_y_pos(-1);
         print_map(row,col);
         cout << "Killed The Wumpus!" << endl;
         break;
      }

   }
   if(!killed_wompus){
      move_wompus();
   }
}
//longer then 15 lines because the arrow is moving and the has to check the room its in
void Game::shoot_east(){
   int encountered = 0;
   cout << "Shooting East" << endl;
   for(int i = 1; i <= 3; i++){
      encountered = rooms[player_y_pos][player_x_pos+i].get_components()->encounter(player_x_pos+i,(player_y_pos));
      if(encountered == -1){
         break;
      }
      else if(encountered == 1){
         rooms[player_y_pos][player_x_pos+i].get_components()->set_symbol('>');
         print_map(row,col);
         usleep(500000);
         rooms[player_y_pos][player_x_pos+i].get_components()->set_symbol(' ');
         print_map(row,col);
      }
      else if(encountered == 3){
         killed_wompus = true;
         rooms[player_y_pos][player_x_pos+i].set_components(new empty_room("empty_room", ' ',player_y_pos,player_x_pos+i));
         set_wompus_x_pos(-1);
         set_wompus_y_pos(-1);
         print_map(row,col);
         cout << "Killed The Wumpus!" << endl;
         break;
      }

   }
   if(!killed_wompus){
      move_wompus();
   }
}

void Game::add_npc(){
   for(int i = 0; i < bat_num; i++){
      spawn_npc(new Bat("bat",'B',0,0));
   }
   for(int i = 0; i < pit_num; i++){
      spawn_npc(new Pit ("pit",'P',0,0));
   }
   Gold g1("gold",'G',0,0);
      spawn_npc(new Gold("gold",'G',0,0));
}

void Game::spawn_wompus(Events* enemy){
   bool has_spawned = false;
   do{
   int i = rand() % row;
   int j = rand() % col;
   if (rooms[i][j].get_components()->get_type() == "empty_room"){
      rooms[i][j].set_components(enemy);
      rooms[i][j].get_components()->set_y_pos(i);
      rooms[i][j].get_components()->set_x_pos(j);
      set_wompus_y_pos(i);
      set_wompus_x_pos(j);
      if(debug_mode == false){
         rooms[i][j].get_components()->set_symbol(' ');
      }
      has_spawned = true;
   }
   }while(!has_spawned);
}

void Game::spawn_npc(Events* npc){
   bool has_spawned = false;
   do{
   int i = rand() % row;
   int j = rand() % col;
   if (rooms[i][j].get_components()->get_type() == "empty_room"){
      rooms[i][j].set_components(npc);
      rooms[i][j].get_components()->set_y_pos(i);
      rooms[i][j].get_components()->set_x_pos(j);
      if(debug_mode == false){
         rooms[i][j].get_components()->set_symbol(' ');
      }
      has_spawned = true;
   }
   }while(!has_spawned);
}

void Game::spawn_player(){
   bool has_spawned = false;
   do{
   int i = rand() % row;
   int j = rand() % col;
   if (rooms[i][j].get_components()->get_type() == "empty_room"){
      player = Player(0,j,i,j,i,1,0);
      rooms[i][j].get_components()->set_symbol('*');
      set_player_y_pos(i);
      set_player_x_pos(j);
      has_spawned = true;
   }
   }while(!has_spawned);
}

void Game::print_map(int row,int col){
   for(int i = 0; i < 50; i++){
      cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
   }
   for(int i = 0; i < row; i++){
      if(i == dimension+1 || i == ((dimension)*2)+1 || i == ((dimension)*3)+1) {
         for(int j = 0; j < col; j++){
            cout << setw(3) << "-";
         }
      cout << endl;
      }
      for(int j = 0; j < col; j++){
         cout << setw(3) << rooms[i][j].get_components()->get_symbol();
      }
      cout << endl;
   }
}

void Game::generate_map(int row, int col, int size){

   for (int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
      (rooms)[i][j].set_components(new empty_room("empty_room", ' ',j,i));
      if(i == 0){
         (rooms)[i][j].set_components(new empty_room("wall", '-',j,i));
      }
      else if(j == 0){
            (rooms)[i][j].set_components(new empty_room("wall", '|',j,i));
         }
      else if(j == (col-1)){
            (rooms)[i][j].set_components(new empty_room("wall", '|',j,i));
         }

         if(i == row - 1){
            (rooms)[i][j].set_components(new empty_room("wall", '-',j,i));
         }
      }
      }
   }

   bool Game::on_escape_rope(){
      if(player_x_pos == player.get_spawn_x_point() && player_y_pos == player.get_spawn_y_point()){
         return true;
      }
      else{
         return false;
      }
   }

   bool Game::has_won(){
      if(player.get_has_gold() && killed_wompus == true && on_escape_rope()){
         return true;
      }
      else{
         return false;
      }
   }
//barely longer then 15 lines because a nunch of cout and user error handling
   void Game::greeting(){
      bool chosen = false;
      cout << "Press W,A,S,D To Move Around." << endl;
      cout << "Press Space to Shoot an Arrow, and W,A,S,D to Aim" << endl;
      cout << "Find Gold, Kill The Wumpus, and Find Your Way Back to The Escape Rope to Win" << endl;
      do{
         cout << "What would you like to do?" << endl;
         cout << "(1) Play Game" << '\n' << "(2) Quit" << endl;
         cout << "Choose (1-2): ";
         int choice = 0;
         cin >> choice;
         if(choice == 1){
            play_game();
            chosen = true;
         }
         else if (choice == 2){
            return;
            chosen = true;
         }
         else{
            cout << "Invalid Choice, Try Again"<<endl;
         }
      }while(!chosen);
   }


   void Game::play_game(){
      do{
         player_choice();
         print_map(row,col);
         cout << message << endl;
         message = " ";
         for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
               rooms[i][j].get_components()->call_percept(player_x_pos, player_y_pos);
               }
            }
         if(has_won()){
            cout << "Player has Won" << endl;
         }
         if(!player.get_is_alive()){
            cout << "You Have Died" << endl;
         }
      }while(player.get_is_alive() == true && has_won() == false);
   }

   void Game::run_game(){
      srand(time(0));
      int col = dimension + 2;
      int row = (dimension * 4) + 2;
      int size = (col*row);
      set_size(size);
      set_row(row);
      set_col(col);

      for(int i = 0; i < row; i++){
         this->rooms.push_back(vector<Room>(col));
      }
      generate_map(row,col,size);
      spawn_player();
      spawn_wompus(new Wompus("wompus",'W',0,0));
      add_npc();
      print_map(row,col);
      play_game();

   }
/*
   void Game::play_again(){
      bool chosen = false;
      int choice = 0;
      do{
         cout << "Play Again?" << endl;
         cout << "Enter (1-2): ";
         cin >> choice;
         if(choice == 1){
            run_game();
            chosen = true;
         }
         else if(choice == 0){
            chosen = true;
            return;
         }
         else{
            cout << "Invalid Choice" << endl;
          }
      }while(!chosen);
   }
*/
