#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>

#include "events.h"

using namespace std;

class Room{

protected:
bool occupied;
Events* component;
string c;

public:


/*******************************************************************
** Function: Room()
** Description: constructer
** Parameters: none
*******************************************************************/
 Room();
 /*******************************************************************
 ** Function: Room(bool,Events*);
 ** Description: non default constructer
 ** Parameters: bool,Events*
 *******************************************************************/
 Room(bool,Events*);

 //~Room();
 /*******************************************************************
 ** Function: ~Room();
 ** Description: deletes room
 ** Parameters: none
 *******************************************************************/
~Room();
/*******************************************************************
** Function:  Room(const Room &old_obj);
** Description: const room
** Parameters: const Room &old_obj
*******************************************************************/
 Room(const Room &old_obj);
 /*******************************************************************
 ** Function: Room& operator=(const Room &old_obj);
 ** Description: operatror overload
 ** Parameters: const Room &old_obj
 *******************************************************************/
 Room& operator=(const Room &old_obj);
// Room operator=
/*******************************************************************
** Function: get_occupied();
** Description: get occupied
** Parameters: none
*******************************************************************/
bool get_occupied();
/*******************************************************************
** Function:  get_components();
** Description:gets compoinents
** Parameters: none
*******************************************************************/
Events* get_components();
/*******************************************************************
** Function: get_c();
** Description: gets c
** Parameters: none
*******************************************************************/
string get_c();

/*******************************************************************
** Function: set_components(Events*);
** Description: sets componetns
** Parameters: Events
*******************************************************************/
void set_components(Events*);
/*******************************************************************
** Function: set_occupied(bool);
** Description: sets occupied
** Parameters: bool
*******************************************************************/
void set_occupied(bool);


};

#endif
