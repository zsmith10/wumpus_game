#ifndef PIT_H
#define PIT_H

#include <iostream>
#include <string>

#include "events.h"

using namespace std;

class Pit:public Events{

protected:
public:


/*******************************************************************
** Function: Pit();
** Description: constructer
** Parameters: none
*******************************************************************/
Pit();
/*******************************************************************
** Function: Pit(string,char,int,int);
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
Pit(string,char,int,int);

//~game_components();
/*******************************************************************
** Function:Pit(const Pit &old_obj);
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
Pit(const Pit &old_obj);
//game_components operator=


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
/*******************************************************************
** Function:encounter(int,int)
** Description: check is player has encounters an event
** Parameters: const
*******************************************************************/
int encounter(int,int);
};

#endif
