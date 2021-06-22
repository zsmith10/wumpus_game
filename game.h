#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>

#include "events.h"
#include "room.h"
#include "player.h"

using namespace std;

class Game{
std::vector<vector<Room> >rooms;
Player player;
int wompus_num;
int bat_num;
int pit_num;
int player_num;
int dimension;
int size;
int row;
int col;
int player_x_pos;
int player_y_pos;
int wompus_x_pos;
int wompus_y_pos;
bool debug_mode;
bool has_gold;
bool killed_wompus;
string message;
int arrow_num;
protected:

public:


/*******************************************************************
** Function: Game()
** Description: constructer
** Parameters: none
*******************************************************************/
Game();
/*******************************************************************
** Function: Game(int, int, int, int,int,bool)
** Description: non default constructer
** Parameters: none
*******************************************************************/
Game(int, int, int, int,int,bool,int);

//~Game();

/*******************************************************************
** Function:Game(const Game &old_obj)
** Description: copy contstructor
** Parameters: none
*******************************************************************/
Game(const Game &old_obj);
//game_components operator=
/*******************************************************************
** Function: get_wompus_num()
** Description:  get wompus num
** Parameters: none
*******************************************************************/
int get_wompus_num();
/*******************************************************************
** Function: get_bat_num()
** Description: get bat nbum
** Parameters: none
*******************************************************************/
int get_bat_num();
/*******************************************************************
** Function: get_pit_num()
** Description: get pit num
** Parameters: none
*******************************************************************/
int get_pit_num();
/*******************************************************************
** Function: get_player_num()
** Description: get player num
** Parameters: none
*******************************************************************/
int get_player_num();
/*******************************************************************
** Function: get_dimension()
** Description: get dimension
** Parameters: none
*******************************************************************/
int get_dimension();
/*******************************************************************
** Function: get_debug()
** Description: get debug
** Parameters: none
*******************************************************************/
bool get_debug();
/*******************************************************************
** Function: get_wompus_x_pos()
** Description: get wompus x pos
** Parameters: none
*******************************************************************/
int get_wompus_x_pos();
/*******************************************************************
** Function: get_wompus_y_pos()
** Description: get wompus y pos
** Parameters: none
*******************************************************************/
int get_wompus_y_pos();
/*******************************************************************
** Function: get_player_x_pos()
** Description: get player x pos
** Parameters: none
*******************************************************************/
int get_player_x_pos();
/*******************************************************************
** Function: get_player_y_pos(
** Description: get player y pos
** Parameters: none
*******************************************************************/
int get_player_y_pos();


/*******************************************************************
** Function: set_wompus_num(int)
** Description: set wompous num
** Parameters: int
*******************************************************************/
void set_wompus_num(int);
/*******************************************************************
** Function: set_bat_num(int)
** Description: set batr num
** Parameters: int
*******************************************************************/
void set_bat_num(int);
/*******************************************************************
** Function: set_pit_num(int)
** Description:set oit num
** Parameters: int
*******************************************************************/
void set_pit_num(int);
/*******************************************************************
** Function: set_player_num(int)
** Description: set player num
** Parameters: int
*******************************************************************/
void set_player_num(int);
/*******************************************************************
** Function: set_dimension(int)
** Description: set dimesnion
** Parameters: int
*******************************************************************/
void set_dimension(int);
/*******************************************************************
** Function: set_wompus_x_pos(int)
** Description: set woimopus x pos
** Parameters: none
*******************************************************************/
void set_wompus_x_pos(int);
/*******************************************************************
** Function: set_wompus_y_pos(int)
** Description: set wompous y pos
** Parameters: none
*******************************************************************/
void set_wompus_y_pos(int);
/*******************************************************************
** Function: set_player_x_pos(int)
** Description: set player x pos
** Parameters: none
*******************************************************************/
void set_player_x_pos(int);
/*******************************************************************
** Function: set_player_y_pos(int)
** Description: set player y pos
** Parameters: none
*******************************************************************/
void set_player_y_pos(int);
/*******************************************************************
** Function: set_size(int)
** Description: sets the size
** Parameters: none
*******************************************************************/
void set_size(int);
/*******************************************************************
** Function: set_row(int)
** Description: sets the row
** Parameters: none
*******************************************************************/
void set_row(int);
/*******************************************************************
** Function: set_col(int)
** Description: sets the col
** Parameters: none
*******************************************************************/
void set_col(int);

/*******************************************************************
** Function: has_won()
** Description: check the win conditions
** Parameters: none
*******************************************************************/
bool has_won();
/*******************************************************************
** Function: on_escape_rope()
** Description: check if on excape rope
** Parameters: none
*******************************************************************/
bool on_escape_rope();
/*******************************************************************
** Function: is_debug()
** Description: checks if in debug mode
** Parameters: none
*******************************************************************/
bool is_debug();
/*******************************************************************
** Function: spawn_player()
** Description: spawnx the player
** Parameters: none
*******************************************************************/
void spawn_player();
/*******************************************************************
** Function: spawn_wompus(Events*)
** Description:
** Parameters: none
*******************************************************************/
void spawn_wompus(Events*);

/*******************************************************************
** Function: spawn_npc(Events*)
** Description: spawns the npc
** Parameters: none
*******************************************************************/
void spawn_npc(Events*);
/*******************************************************************
** Function: greeting()
** Description: the greeting
** Parameters: none
*******************************************************************/
void greeting();
/*******************************************************************
** Function:play_again()
** Description: asks users if they want to play again
** Parameters: none
*******************************************************************/
void play_again();
/*******************************************************************
** Function: add_npc()
** Description: adds the npc
** Parameters: none
*******************************************************************/
void add_npc();
/*******************************************************************
** Function: run_game()
** Description: runs the game
** Parameters: none
*******************************************************************/
void run_game();
/*******************************************************************
** Function: player_choice()
** Description: ghets play choice
** Parameters: none
*******************************************************************/
void player_choice();
/*******************************************************************
** Function: shoot_arrow()
** Description: gest the arrow direstion
** Parameters: none
*******************************************************************/
void shoot_arrow();
/*******************************************************************
** Function: shoot_north()
** Description: shoots the arrow north
** Parameters: none
*******************************************************************/
void shoot_north();
/*******************************************************************
** Function: shoot_south()
** Description: shoots the arrow south
** Parameters: none
*******************************************************************/
void shoot_south();
/*******************************************************************
** Function: shoot_east()
** Description: shoots the arrow east
** Parameters: none
*******************************************************************/
void shoot_east();
/*******************************************************************
** Function: move_wompus()
** Description: moves the wumpus
** Parameters: none
*******************************************************************/
void move_wompus();
/*******************************************************************
** Function: shoot_west()
** Description: shoots arrow west
** Parameters: none
*******************************************************************/
void shoot_west();
/*******************************************************************
** Function: move_player(int,int)
** Description: moves the player
** Parameters: none
*******************************************************************/
void move_player(int,int);
/*******************************************************************
** Function: is_dead()
** Description: check if player is dead
** Parameters: none
*******************************************************************/
bool is_dead();
/*******************************************************************
** Function: swap_wompus(int,int)
** Description: swaps the wumpus pos
** Parameters: none
*******************************************************************/
void swap_wompus(int,int);

/*******************************************************************
** Function: play_game()
** Description: plays the game
** Parameters: none
*******************************************************************/
void play_game();
/*******************************************************************
** Function: generate_map(int,int,int)
** Description:generate the map
** Parameters: none
*******************************************************************/
void generate_map(int,int,int);
/*******************************************************************
** Function: print_map(int,int)
** Description: pritns the map
** Parameters: none
*******************************************************************/
void print_map(int,int);

};

#endif
