#ifndef WOMPUS_H
#define WOMPUS_H

#include <iostream>
#include <string>

#include "events.h"

using namespace std;

class Wompus:public Events{

protected:
public:


/*******************************************************************
** Function: Wompus()
** Description: constructer
** Parameters: none
*******************************************************************/
Wompus();
/*******************************************************************
** Function: Wompus(string,char,int,int);
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
Wompus(string,char,int,int);

//~game_components();
/*******************************************************************
** Function:Wompus(const Wompus &old_obj);
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
Wompus(const Wompus &old_obj);
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
** Description: checks if encounters
** Parameters: const
*******************************************************************/
int encounter(int,int);
};

#endif
