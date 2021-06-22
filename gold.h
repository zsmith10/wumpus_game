#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include <string>

#include "events.h"

using namespace std;

class Gold:public Events{

protected:
public:


/*******************************************************************
** Function: Gold()
** Description: constructer
** Parameters: none
*******************************************************************/
Gold();
/*******************************************************************
** Function: Gold(string,char,int,int);
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
Gold(string,char,int,int);

//~game_components();
/*******************************************************************
** Function:Gold(const Gold &old_obj);
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
Gold(const Gold &old_obj);
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
