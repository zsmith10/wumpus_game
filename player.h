#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "events.h"

using namespace std;

class Player{

protected:
int spawn_x_point;
int spawn_y_point;
int x_pos;
int y_pos;
bool has_gold;
bool is_alive;
bool killed_wompus;
public:


/*******************************************************************
** Function: Player();
** Description: constructer
** Parameters: none
*******************************************************************/
Player();
/*******************************************************************
** Function: Player(bool,int,int,int,int,bool,bool);
** Description: non default constructer
** Parameters: bool,int,int,int,int,bool,bool
*******************************************************************/
Player(bool,int,int,int,int,bool,bool);

//~game_components();
/*******************************************************************
** Function:Wompus(const Wompus &old_obj);
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
Player(const Player &old_obj);
//game_components operator=
/*******************************************************************
** Function: get_has_gold();
** Description:gets has gold
** Parameters: none
*******************************************************************/
bool get_has_gold();
/*******************************************************************
** Function: get_spawn_point();
** Description: gets spawn point
** Parameters: none
*******************************************************************/
int get_spawn_point();
/*******************************************************************
** Function: get_x_pos();
** Description: gets x pos
** Parameters: none
*******************************************************************/
int get_x_pos();
/*******************************************************************
** Function: get_y_pos();
** Description: gets y pos
** Parameters: none
*******************************************************************/
int get_y_pos();
/*******************************************************************
** Function: get_is_alive();
** Description: gets is alive
** Parameters: none
*******************************************************************/
bool get_is_alive();
/*******************************************************************
** Function: get_spawn_y_point();
** Description: spawn y point
** Parameters: none
*******************************************************************/
int get_spawn_y_point();
/*******************************************************************
** Function: get_spawn_x_point();
** Description: gets spawn x point
** Parameters: none
*******************************************************************/
int get_spawn_x_point();
/*******************************************************************
** Function: set_x_pos(int);
** Description: sets x pos
** Parameters: none
*******************************************************************/
void set_x_pos(int);
/*******************************************************************
** Function:set_y_pos(int);
** Description: sets y pos
** Parameters: int
*******************************************************************/
void set_y_pos(int);

/*******************************************************************
** Function: set_has_gold(bool )
** Description: set has gold
** Parameters: int
*******************************************************************/
void set_has_gold(bool );
/*******************************************************************
** Function: set_is_alive(bool );
** Description: set is alive
** Parameters: bool
*******************************************************************/
void set_is_alive(bool );
/*******************************************************************
** Function: set_kill_wompus(bool );
** Description: set kill wompus
** Parameters: bool
*******************************************************************/
void set_kill_wompus(bool );
/*******************************************************************
** Function: set_spawn_point(bool );
** Description: set spawn point
** Parameters: bool
*******************************************************************/
void set_spawn_point(bool );
/*******************************************************************
** Function: encounter(int,int);
** Description: constructer
** Parameters: int,int
*******************************************************************/
int encounter(int,int);
/*******************************************************************
** Function: print_percept();
** Description: prints the percept
** Parameters: none
*******************************************************************/
void print_percept();
/*******************************************************************
** Function: call_percept(int,int,Events*);
** Description: calls the percept
** Parameters: int,int,Events*
*******************************************************************/
void call_percept(int,int,Events*);

};

#endif
