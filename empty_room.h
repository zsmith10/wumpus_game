#ifndef EMPTY_ROOM_H
#define EMPTY_ROOM_H

#include <iostream>
#include <string>

#include "events.h"

using namespace std;

class empty_room:public Events{

protected:

public:


/*******************************************************************
** Function: empty_room();
** Description: constructer
** Parameters: none
*******************************************************************/
empty_room();
/*******************************************************************
** Function: empty_room(string,char,int,int
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
empty_room(string,char,int,int);

//~game_components();
/*******************************************************************
** Function:empty_room(const empty_room &old_obj);
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
empty_room(const empty_room &old_obj);
/*******************************************************************
** Function:encounter(int,int)
** Description: copy constructor
** Parameters: const
*******************************************************************/
int encounter(int,int);
/*******************************************************************
** Function: print_percept();
** Description: checks if player has encountered event
** Parameters: none
*******************************************************************/
void print_percept();
/*******************************************************************
** Function: call_percept(int,int);
** Description: prints the percept
** Parameters: int,int
*******************************************************************/
void call_percept(int,int);
//game_components operator=

};

#endif
