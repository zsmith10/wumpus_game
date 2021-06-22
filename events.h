#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <string>

using namespace std;

class Events{

protected:
string type;
char symbol;
int x_pos;
int y_pos;
public:


/*******************************************************************
** Function: Events
** Description: constructer
** Parameters: none
*******************************************************************/
Events();
/*******************************************************************
** Function: Events(string,char,int,int);
** Description: non default constructer
** Parameters: string,char,int,int
*******************************************************************/
Events(string,char,int,int);

//~game_components();
/*******************************************************************
** Function:Wompus(const Wompus &old_obj);
** Description: copy constructo
** Parameters: string,char,int,int
*******************************************************************/
Events(const Events &old_obj);
//game_components operator=

//string get_percept();
//void set_percept(string);

/*******************************************************************
** Function: call_percept(int,int);
** Description: prints the percept
** Parameters: int,int
*******************************************************************/
virtual void call_percept(int,int) = 0;
/*******************************************************************
** Function:encounter(int,int)
** Description: checks if encountered
** Parameters: const
*******************************************************************/
virtual int encounter(int,int) = 0;
/*******************************************************************
** Function:get_type();
** Description: checks if encountered
** Parameters: const
*******************************************************************/
string get_type();
/*******************************************************************
** Function:get_symbol();
** Description: checks if encountered
** Parameters: const
*******************************************************************/
char get_symbol();
/*******************************************************************
** Function:get_x_pos();
** Description: checks if encountered
** Parameters: const
*******************************************************************/
int get_x_pos();
/*******************************************************************
** Function:get_y_pos();
** Description: checks if encountered
** Parameters: const
*******************************************************************/
int get_y_pos();

/*******************************************************************
** Function:set_type(string);
** Description: checks if encountered
** Parameters: const
*******************************************************************/
void set_type(string);
/*******************************************************************
** Function:set_symbol(char);
** Description: checks if encountered
** Parameters: const
*******************************************************************/
void set_symbol(char);
/*******************************************************************
** Function:set_x_pos(int);
** Description: checks if encountered
** Parameters: const
*******************************************************************/
void set_x_pos(int);
/*******************************************************************
** Function:set_y_pos(int);
** Description: checks if encountered
** Parameters: const
*******************************************************************/
void set_y_pos(int);

};

#endif
